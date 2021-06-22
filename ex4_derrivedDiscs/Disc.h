
#ifndef INC_32_EX3_DISC_H
#define INC_32_EX3_DISC_H
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
    explicit Disc(double x1 = 0, double y1 = 0, double vx = 0, double vy = 0, double radius = 0);
    Disc(double x1, double y1, double vx , double vy, double radius,double mass);
	Disc(const Disc &other); // copy ctor
	virtual ~Disc(); // virtual dtor.
    Disc &operator=(const Disc &rhs);
	virtual Disc* clone() const{ return new Disc(*this);} // allowing polymorphism at the DiscLinkedList
	void disc_location_update(double dt); // disc location updater by delta time

	//* Setters & Getters
    void setIsBumped(bool isBumped);
    void setMass(double mass);
	void setRadius(double radius); // radius setter
	void setLocationVector(const Vector2D &locationVector); // Location vector setter
	void setSpeedVector(const Vector2D &speedVector); // speed vector setter

	double getMass() const; // discs mass getter
	double getX1() const; // x1 getter
	double getY1() const; // y1 getter
	double getVx() const; // vx getter
	double getVy() const; // vy getter
	double getRadius() const; // radius getter
    virtual Disc_Type getDiscType() const; // returns the type of the disc
	const Vector2D &getLocationVector() const; // location vector getter
	const Vector2D &getSpeedVector() const; // speed vector getter.
    virtual bool isBumped() const; // indicator which tells if the disc got bumped.


	friend std::ostream &operator<<(std::ostream &os, const Disc &disc); // prints disc's (x,y) \ radius
protected:
	Vector2D location_vector; // Vector2d created by x1,y1
	Vector2D speed_vector; // Vector2d created by vx,vy
	double radius; // radius getter
	double mass; // mass = radius**2
	Disc_Type discType;
	bool  is_bumped;
};

#endif //INC_32_EX3_DISC_H
