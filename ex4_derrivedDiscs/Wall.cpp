#include "Wall.h"

Wall::Wall(double x1, double y1, double x2, double y2) : start_location(x1, y1), end_location(x2, y2)
{
}
Wall::Wall(const Wall &other) : start_location(other.getX1(), other.getY1()), end_location(other.getX2(), other.getY2()) {}

Wall &Wall::operator=(const Wall &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	this->setStartLocation(rhs.getStartLocation());

	this->setEndLocation(rhs.getEndLocation());
	return *this;
}
double Wall::getX1() const
{
	return start_location.getX();
}

double Wall::getY1() const
{
	return start_location.getY();
}

double Wall::getX2() const
{
	return end_location.getX();
}

double Wall::getY2() const
{
	return end_location.getY();
}

Vector2D Wall::getStartLocation() const
{
	return start_location;
}

Vector2D Wall::getEndLocation() const
{
	return end_location;
}

void Wall::setStartLocation(const Vector2D &startLocation)
{
	start_location = startLocation;
}

void Wall::setEndLocation(const Vector2D &endLocation)
{
	end_location = endLocation;
}
