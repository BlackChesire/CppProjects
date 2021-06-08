#include "Vector2D.h"
#include <cmath>
Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

Vector2D::Vector2D(const Vector2D &other) : x(other.x), y(other.y)
{
}

double Vector2D::getX() const
{
	return x;
}

double Vector2D::getY() const
{
	return y;
}
Vector2D &Vector2D::operator=(const Vector2D &v2)
{
	if (this == &v2)
		return *this;

	x = v2.x;
	y = v2.y;

	return *this;
}

Vector2D &Vector2D::operator+=(const Vector2D &v2)
{
	x += v2.x;
	y += v2.y;

	return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &v2)
{
	x -= v2.x;
	y -= v2.y;

	return *this;
}

Vector2D &Vector2D::operator*=(const double scalar)
{
	x *= scalar;
	y *= scalar;

	return *this;
}

Vector2D &Vector2D::operator/=(const double scalar)
{
	x /= scalar;
	y /= scalar;
	return *this;
}

Vector2D Vector2D::operator+(const Vector2D &v2) const
{
	return Vector2D(x + v2.x, y + v2.y);
}

Vector2D Vector2D::operator-(const Vector2D &v2) const
{
	return Vector2D(x - v2.x, y - v2.y);
}

Vector2D Vector2D::operator*(const double scalar) const
{
	return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator/(const double scalar) const
{
	return *this * (1 / scalar);
}

bool Vector2D::operator==(const Vector2D &v2) const
{
	return ((x == v2.x) && (y == v2.y));
}

bool Vector2D::operator!=(const Vector2D &v2) const
{
	return !(*this == v2);
}

double Vector2D::normalize() const
{
	double sum = (x * x) + (y * y);
	return std::sqrt(sum);
}

double Vector2D::operator*(const Vector2D &v2) const
{
	return (x * v2.x) + (y * v2.y);
}

Vector2D operator*(double scalar, const Vector2D &v2)
{
	return Vector2D(v2.x * scalar, v2.y * scalar);
}
