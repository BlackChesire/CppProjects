#include "Hockey_table.h"
#include <cmath>
#include <cstdlib>
#include "ExplodingDisc.h"
#include "ShrinkingDisc.h"
#include <iostream>

using namespace std;

Hockey_table::Hockey_table(const DiscLinkedList &discLinkedlist, const WallLinkedList &wallLinkedlist) : discLinkedlist(
        discLinkedlist),
                                                                                                         wallLinkedlist(
                                                                                                                 wallLinkedlist) {
}

Hockey_table::Hockey_table(Hockey_table &other) : discLinkedlist(other.getDiscLinkedlist()),
                                                  wallLinkedlist(other.getWallLinkedlist()) {
}

Hockey_table &Hockey_table::operator=(const Hockey_table &rhs) {
    if (this == &rhs) {
        return *this;
    }
    this->discLinkedlist = rhs.getDiscLinkedlist();
    this->wallLinkedlist = rhs.getWallLinkedlist();
    return *this;
}

bool Hockey_table::check_discs_collison(Disc &disc1, Disc &disc2) const {
    Vector2D d = disc1.getLocationVector();
    Vector2D d_tag = disc2.getLocationVector();
    double r1 = disc1.getRadius();
    double r2 = disc2.getRadius();
    return (d - d_tag).normalize() <= (r1 + r2);
}

Vector2D Hockey_table::find_closet_point(const Wall &wall, const Disc &disc) {
    Vector2D p1 = wall.getStartLocation();
    Vector2D p2 = wall.getEndLocation();
    Vector2D p = disc.getLocationVector();
    if (p1 == p2) {
        return p1;
    }
    double k = (p1 - p2).normalize();
    double alpha = ((p - p1) * (p2 - p1)) / (k * k);
    if (alpha < 0) {
        return p1;
    }
    if (alpha > 1) {
        return p2;
    }

    return p1 + (alpha * (p2 - p1));
}

bool Hockey_table::check_disc_to_wall_bump(Disc &disc, Wall &wall) {
    Vector2D p = disc.getLocationVector();
    Vector2D q = find_closet_point(wall, disc);
    double r = disc.getRadius();
    return (p - q).normalize() <= r;
}

void Hockey_table::speed_update_after_bump(Disc &disc1, Disc &disc2) {
    Vector2D p = disc1.getLocationVector();
    Vector2D p_tag = disc2.getLocationVector();
    Vector2D v = disc1.getSpeedVector();
    Vector2D v_tag = disc2.getSpeedVector();
    double m = disc1.getMass();
    double m_tag = disc2.getMass();
    Vector2D d = (p - p_tag) / ((p - p_tag).normalize());
    Vector2D delta = ((v - v_tag) * d) * d;
    Vector2D v_new = v - ((2 * m_tag) / (m + m_tag)) * delta;
    Vector2D v_tag_new = v_tag + ((2 * m) / (m + m_tag)) * delta;
    //updating speed vectors
    disc1.setSpeedVector(v_new);
    disc2.setSpeedVector(v_tag_new);
}

void Hockey_table::speed_update_after_wall_bump(Disc &disc, Wall &wall) {
    Vector2D q = find_closet_point(wall, disc);
    Vector2D p = disc.getLocationVector();

    Vector2D d = (p - q) / ((p - q).normalize());
    Vector2D v = disc.getSpeedVector();
    Vector2D updated_speed = v - (2 * (v * d) * d);
    disc.setSpeedVector(updated_speed); //updating discs speed vector
}

//  d*(2*(disc->getSpeedVector()*d);
void Hockey_table::simulate(double t, double dt) {

    cout << "0: " << *this << endl;
    for (double i = dt; i <= t; i += dt) {
        step_simulation(dt, i);
        cout << setprecision(4) << fixed << i << ": " << *this << endl;
    }
}

void Hockey_table::step_simulation(double dt, double time) {
    DiscLinkedList templist;
    for (int i = 0; i < discLinkedlist.getCount(); ++i) {
        bool hit_disc = false, hit_wall = false;
        Disc &original = discLinkedlist[i];
        Vector2D backup = original.getLocationVector();
        original.disc_location_update(dt);

        // two discs collide
        for (int j = 0; j < discLinkedlist.getCount(); ++j) {
            Disc &d_tag = discLinkedlist[j];
            if (i != j) {
                if (check_discs_collison(original, d_tag)) {
                    speed_update_after_bump(original, d_tag);
                    original.setIsBumped(true);
                    d_tag.setIsBumped(true);
                    hit_disc = true;
                }
            }
        }
        // disc with wall
        for (int m = 0; m < wallLinkedlist.getCount(); ++m) {
            Wall &wall = wallLinkedlist[m];
            if (check_disc_to_wall_bump(original, wall)) {
                hit_wall = true;
                speed_update_after_wall_bump(original, wall);
                original.setIsBumped(true);
            }
        }
        if (hit_disc || hit_wall) {
            original.setLocationVector(backup);
        }


    }
    for (int k = 0; k < discLinkedlist.getCount(); ++k) {
        if (!discLinkedlist[k].isBumped()) {
            templist.add_disc(&discLinkedlist[k]);
            continue;
        }
        if (discLinkedlist[k].getDiscType() == Regular) {
            discLinkedlist[k].setIsBumped(false);
            templist.add_disc(&discLinkedlist[k]);
            continue;
        }
        if (discLinkedlist[k].getDiscType() == Shrinking) {
            discLinkedlist[k].setIsBumped(false);
            ShrinkingDisc &sd = dynamic_cast<ShrinkingDisc &>(discLinkedlist[k]);
            sd.shrink();
            if (dynamic_cast<ShrinkingDisc &>(discLinkedlist[k]).getLivesCount() < 3) {
                templist.add_disc(&discLinkedlist[k]);
            }
            continue;
        }
        if (discLinkedlist[k].getDiscType() == Exploding) {
            discLinkedlist[k].setIsBumped(false);
            ExplodingDisc &ed = dynamic_cast<ExplodingDisc &>(discLinkedlist[k]);
            ed.setLifeCounter(ed.getLifeCounter() + 1);
            if (ed.getLifeCounter() < 3) {
                ed.explode(templist);
            }
        }
    }

    discLinkedlist = templist;

}


const DiscLinkedList &Hockey_table::getDiscLinkedlist() const {
    return discLinkedlist;
}

const WallLinkedList &Hockey_table::getWallLinkedlist() const {
    return wallLinkedlist;
}

ostream &operator<<(ostream &out, const Hockey_table &table) {
    for (int j = 0; j < table.discLinkedlist.getCount(); j++) {
        out << setprecision(4) << fixed << table.discLinkedlist[j] << " ";
    }
    return out;
}

void Hockey_table::check_stepover(Disc disc) {
    for (int i = 0; i < discLinkedlist.getCount(); i++) {
        if (check_discs_collison(discLinkedlist[i], disc)) {
            cerr << "Error: disc to disc collision detected in initial configuration" << endl;
            exit(-1);
        }
    }

}

void Hockey_table::check_stepover(Wall wall) {
    for (int i = 0; i < discLinkedlist.getCount(); i++) {
        if (check_disc_to_wall_bump(discLinkedlist[i], wall)) {
            cerr << "Error: disc to wall collision detected in initial configuration" << endl;
            exit(-1);
        }
    }

}
