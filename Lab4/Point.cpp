#include "Point.h"

namespace lab4
{
	Point::Point() : mX(0), mY(0)
	{

	}
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

	Point& Point::operator=(const Point& other)
	{
		mX = other.GetX();
		mY = other.GetY();
		return *this;
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

	void Point::SetX(float n)
	{
		mX = n;
	}

	void Point::SetY(float n)
	{
		mY = n;
	}

	
	
	Point operator*(float operand, const Point& other)
	{
		float x = other.GetX() * operand;
		float y = other.GetY() * operand;
		return Point(x, y);
	}

}