

#include "ExplodingDisc.h"


ExplodingDisc::ExplodingDisc(double x1, double y1, double vx, double vy, double radius, double mass, int life_counter)
        : Disc(x1, y1, vx, vy, radius, mass), life_counter(life_counter), exploded(false), discType(Exploding) {

}


ExplodingDisc::ExplodingDisc(const ExplodingDisc &other)
        : Disc(other), life_counter(other.getLifeCounter()), exploded(other.isExploded()),
          discType(other.getDiscType()) {

}

ExplodingDisc &ExplodingDisc::operator=(const ExplodingDisc &rhs) {
    if (this == &rhs) {
        return *this;
    }
    location_vector = rhs.location_vector;
    speed_vector = rhs.speed_vector;
    radius = rhs.radius;
    mass = rhs.mass;
    life_counter = rhs.getLifeCounter();
    exploded = rhs.isExploded();
    return *this;

}

int ExplodingDisc::getLifeCounter() const {
    return life_counter;
}

void ExplodingDisc::setLifeCounter(int lifeCounter) {
    life_counter = lifeCounter;
}

bool ExplodingDisc::isExploded() const {
    return exploded;
}


void ExplodingDisc::explode(DiscLinkedList &secondDL) {


    double c = 0.99;
    double r_tag = ((2 * std::sqrt(3.0) - 3) * c * radius);
    double a = (4 - 2 * std::sqrt(3.0)) * radius;
    //1st "Child"
    Vector2D p0 = location_vector + Vector2D(0, a);
    Vector2D v0 = speed_vector + Vector2D(0, 1);
    ExplodingDisc ed0(
            p0.getX(), p0.getY(),
            v0.getX(), v0.getY(),
            r_tag, mass / 3.0,
            life_counter);
    //2nd "Child"
    Vector2D p1 = location_vector + Vector2D(radius - a, -a / 2);
    Vector2D v1 = speed_vector + Vector2D(std::sqrt(3.0) / 2.0, -0.5);
    ExplodingDisc ed1(
            p1.getX(), p1.getY(),
            v1.getX(), v1.getY(),
            r_tag, mass / 3.0,
            life_counter);
    //3rd "Child"
    Vector2D p2 = location_vector + Vector2D(-(radius - a), -(a / 2));
    Vector2D v2 = speed_vector + Vector2D(-std::sqrt(3.0) / 2, -(1.0 / 2.0));
    ExplodingDisc ed2(
            p2.getX(), p2.getY(),
            v2.getX(), v2.getY(),
            r_tag, mass / 3.0,
            life_counter);

    secondDL.add_disc(ed0);
    secondDL.add_disc(ed1);
    secondDL.add_disc(ed2);

}

ExplodingDisc *ExplodingDisc::clone() const {
    return new ExplodingDisc(*this);
}

Disc_Type ExplodingDisc::getDiscType() const {
    return discType;
}
