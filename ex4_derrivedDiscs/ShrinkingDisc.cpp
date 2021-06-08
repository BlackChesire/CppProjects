
#include "ShrinkingDisc.h"

ShrinkingDisc::ShrinkingDisc(double x1, double y1, double vx, double vy, double radius,int lives_count,bool is_shrinked)
: Disc(x1, y1,vx, vy,radius), lives_count(lives_count), is_Shrank(false), discType(Shrinking) {}

ShrinkingDisc::ShrinkingDisc(const ShrinkingDisc &other)
: Disc(other), lives_count(other.getLivesCount()), is_Shrank(other.isShrank()), discType(other.getDiscType()) {

}

ShrinkingDisc &ShrinkingDisc::operator=(const ShrinkingDisc &rhs) {
    if (this == &rhs)
    {
        return *this;
    }
    location_vector = rhs.location_vector;
    speed_vector = rhs.speed_vector;
    radius = rhs.radius;
    mass = rhs.mass;
    lives_count = rhs.lives_count;
    is_Shrank = rhs.is_Shrank;
    discType = rhs.discType;
    return *this;
}

ShrinkingDisc *ShrinkingDisc::clone() const {
    return new ShrinkingDisc(*this);
}

std::ostream &operator<<(ostream &os, const ShrinkingDisc &sd) {

    os << setprecision(4) << "(" << sd.getX1() << "," << sd.getY1() << ")" << "/"<<sd.getRadius()<<fixed;
    return os;

}

/*GETTERS AND SETTER*/
int ShrinkingDisc::getLivesCount() const {
    return lives_count;
}


void ShrinkingDisc::setLivesCount(int livesCount) {
    lives_count = livesCount;
}

bool ShrinkingDisc::isShrank() const {
    return is_Shrank;
}

Disc_Type ShrinkingDisc::getDiscType() const {
    return discType;
}

void ShrinkingDisc::shrink() {
    radius *= 0.9;
    lives_count++;
    is_Shrank = false;
}

