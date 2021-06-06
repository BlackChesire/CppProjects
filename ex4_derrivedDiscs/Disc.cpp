#include "Disc.h"

Disc::Disc(double x1, double y1, double vx, double vy, double radius)
	: location_vector(x1, y1), speed_vector(vx, vy), radius(radius), mass(radius * radius)
{
}

Disc::Disc(double x1, double y1, double vx, double vy, double radius, double mass) :location_vector(x1, y1), speed_vector(vx, vy), radius(radius), mass(mass),discType(Regular),is_bumped(
        false) {

}

Disc::Disc(const Disc &other)
	: location_vector(other.location_vector), speed_vector(other.speed_vector), radius(other.radius), mass(other.mass),discType(other.discType),is_bumped(other.is_bumped)
{
}



double Disc::getX1() const
{
	return location_vector.getX();
}

double Disc::getY1() const
{
	return location_vector.getY();
}

double Disc::getVx() const
{
	return speed_vector.getX();
}

double Disc::getVy() const
{
	return speed_vector.getY();
}

Disc &Disc::operator=(const Disc &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	location_vector = rhs.location_vector;
	speed_vector = rhs.speed_vector;
	radius = rhs.radius;
	mass = rhs.mass;
	return *this;
}

double Disc::getRadius() const
{
	return radius;
}

void Disc::setRadius(double radius)
{
	Disc::radius = radius;
}

const Vector2D &Disc::getLocationVector() const
{
	return location_vector;
}

void Disc::setLocationVector(const Vector2D &locationVector)
{
	this->location_vector = locationVector;
}

const Vector2D &Disc::getSpeedVector() const
{
	return speed_vector;
}

void Disc::setSpeedVector(const Vector2D &speedVector)
{
	this->speed_vector = speedVector;
}

double Disc::getMass() const
{
	return mass;
}

void Disc::disc_location_update(double dt)
{
	location_vector += (speed_vector * dt);
}

std::ostream &operator<<(ostream &os, const Disc &disc)
{

    os << setprecision(4) << "(" << disc.getX1() << "," << disc.getY1() << ")" << "/"<<disc.getRadius()<<fixed;
		return os;

}

Disc_Type Disc::getDiscType() const {
    return discType;
}

Disc::~Disc() {

}

bool Disc::isBumped() const {
    return is_bumped;
}

void Disc::setMass(double mass) {
    Disc::mass = mass;
}

void Disc::setIsBumped(bool isBumped) {
    is_bumped = isBumped;
}

int Disc::do_special() {
    is_bumped = false;
    return 0;
}
