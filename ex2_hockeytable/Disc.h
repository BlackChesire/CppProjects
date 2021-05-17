//
// Created by Asaf-PC on 02/05/2021.
//

#ifndef INC_32_EX3_312391774_DISC_H
#define INC_32_EX3_312391774_DISC_H
#include <iostream>
#include <iomanip>
#include "Vector2D.h"
using namespace std;

class Disc
{

public:
	explicit Disc(double x1 = 0, double y1 = 0, double vx = 0, double vy = 0, double radius = 0);

	double getMass() const; // discs mass getter

	Disc(const Disc &other); // copy ctor
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

	friend std::ostream &operator<<(std::ostream &os, const Disc &disc); // prints the disc by (X,Y)

private:
	Vector2D location_vector; // Vector2d created by x1,y1
	Vector2D speed_vector; // Vector2d created by vx,vy
	double radius; // radius getter
	double mass; // mass = radius**2
};

#endif //INC_32_EX3_312391774_DISC_H
