#ifndef INC_32_EX3_312391774_WALL_H
#define INC_32_EX3_312391774_WALL_H

#include "Vector2D.h"
class Wall {

public:
    explicit Wall(double x1=0, double y1=0, double x2=0, double y2=0); // ctor
    Wall(const Wall& other); // copy ctor
    Wall& operator=(const Wall& rhs);

    double getX1() const; // returns x1

    double getY1() const; // returns y1

    double getX2() const; //returns vx

    double getY2() const; // returns vy

     Vector2D getStartLocation() const; // getter of startlocation vector, created from x1,y1

     Vector2D getEndLocation() const; // getter of endlocation vector, created from x2,y2

    void setStartLocation(const Vector2D &startLocation); // startlocation setter

    void setEndLocation(const Vector2D &endLocation); // end location setter

private:
    Vector2D start_location;
    Vector2D end_location;
};


#endif //INC_32_EX3_312391774_WALL_H
