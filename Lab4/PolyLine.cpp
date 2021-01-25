#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
	}

	PolyLine::~PolyLine()
	{
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		return false;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		return false;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		return false;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		return false;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		return new Point(0.0f, 0.0f);
	}
}