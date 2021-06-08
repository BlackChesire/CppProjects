#ifndef INC_32_EX3_312391774_VECTOR2D_H
#define INC_32_EX3_312391774_VECTOR2D_H
/*
 *  Vector2D implements 2D vector.
 *  Every operator works as defined for vectors actions
 */
class Vector2D
{
public:
	Vector2D(double x, double y);
	Vector2D(const Vector2D &other);
	Vector2D &operator=(const Vector2D &v2);

	double getX() const;
	double getY() const;

	Vector2D &operator+=(const Vector2D &v2);
	Vector2D &operator-=(const Vector2D &v2);
	Vector2D &operator*=(double scalar);
	Vector2D &operator/=(double scalar);
	Vector2D operator+(const Vector2D &v2) const;
	Vector2D operator-(const Vector2D &v2) const;
	Vector2D operator*(double scalar) const;
	Vector2D operator/(double scalar) const;
	friend Vector2D operator*(double scalar, const Vector2D &); // multiply by scalar
	double operator*(const Vector2D &v2) const;
	bool operator==(const Vector2D &v2) const;
	bool operator!=(const Vector2D &v2) const;
	double normalize() const; // normalize the vector

private:
	double x, y;
};

Vector2D operator*(double scalar, const Vector2D &v2);

#endif //INC_32_EX3_312391774_VECTOR2D_H
