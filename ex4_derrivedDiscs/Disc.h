
#ifndef INC_32_EX3_312391774_DISC_H
#define INC_32_EX3_312391774_DISC_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Vector2D.h"
using namespace std;
// indicates the disc type.
enum Disc_Type {Regular,Exploding,Shrinking};
class Disc
{

public:
    void setMass(double mass);

    void setIsBumped(bool isBumped);

    explicit Disc(double x1 = 0, double y1 = 0, double vx = 0, double vy = 0, double radius = 0);
    Disc(double x1, double y1, double vx , double vy, double radius,double mass);
	double getMass() const; // discs mass getter

	Disc(const Disc &other); // copy ctor

	virtual ~Disc(); // virtual dtor.

    Disc &operator=(const Disc &rhs);

	double getX1() const; // x1 getter

	double getY1() const; // y1 getter

	double getVx() const; // vx getter

	double getVy() const; // vy getter

	double getRadius() const; // radius getter

	void setRadius(double radius); // radius setter

	const Vector2D &getLocationVector() const; // location vector getter

	void setLocationVector(const Vector2D &locationVector); // Location vector setter

	const Vector2D &getSpeedVector() const; // speed vector getter.

	void setSpeedVector(const Vector2D &speedVector); // speed vector setter

	void disc_location_update(double dt); // disc location updater by delta time

	virtual Disc* clone() const{ return new Disc(*this);}

	friend std::ostream &operator<<(std::ostream &os, const Disc &disc);

    virtual Disc_Type getDiscType() const;

   virtual bool isBumped() const; // indicator which tells if the disc got bumped.
    // prints the disc by (X,Y)/radius
    virtual int do_special(); // for each disc , does it uniq effect
protected:
	Vector2D location_vector; // Vector2d created by x1,y1
	Vector2D speed_vector; // Vector2d created by vx,vy
	double radius; // radius getter
	double mass; // mass = radius**2
	Disc_Type discType;
	bool  is_bumped;
};

#endif //INC_32_EX3_312391774_DISC_H
