#include "Point.h"

namespace lab4
{
	Point::Point(float x, float y) : mX(x), mY(y)
	{
	}

	Point::~Point()
	{
	}

	Point Point::operator+(const Point& other) const
	{
		float x = mX + other.GetX();
		float y = mY + other.GetY();
		return Point(x, y);
	}

	Point Point::operator-(const Point& other) const
	{
		float x = mX - other.GetX();
		float y = mY - other.GetY();
		return Point(x, y);
	}

	float Point::Dot(const Point& other) const
	{
		float dot = mX * other.GetX() + mY * other.GetY();
		return dot;
	}

	Point Point::operator*(float operand) const
	{
		float x = mX * operand;
		float y = mY * operand;
		return Point(x, y);
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}
}