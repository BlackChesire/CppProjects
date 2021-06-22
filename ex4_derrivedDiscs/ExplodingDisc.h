
#ifndef INC_32_EX3_EXPLODINGDISC_H
#define INC_32_EX3_EXPLODINGDISC_H


#include "Disc.h"
#include "DiscLinkedList.h"

class ExplodingDisc: public Disc {
public:
    ExplodingDisc(double x1, double y1, double vx, double vy, double radius,double mass,int life_counter);
    ExplodingDisc(const ExplodingDisc& other);
    ExplodingDisc &operator=(const ExplodingDisc &rhs);
    virtual ~ExplodingDisc(){};
    void explode(DiscLinkedList &secondDL);
    virtual ExplodingDisc* clone() const;
    int getLifeCounter() const; // returns life_count
    void setLifeCounter(int lifeCounter); // setter for life count
    bool isExploded() const; // marking if the disc exploded
    virtual Disc_Type getDiscType() const;
private:
    int life_counter; // counts the life of the disc
    bool exploded;
    Disc_Type discType;
};


#endif //INC_32_EX3_EXPLODINGDISC_H
