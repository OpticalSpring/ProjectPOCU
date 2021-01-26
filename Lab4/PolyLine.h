#pragma once

#include "Point.h"

namespace lab4
{
	class PolyLine
	{
	public:
		PolyLine();
		PolyLine(const PolyLine& other);
		~PolyLine();

		bool AddPoint(float x, float y);
		bool AddPoint(const Point* point);
		PolyLine& operator=(const PolyLine& other);
		bool RemovePoint(unsigned int i);
		bool TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const;
		const Point* operator[](unsigned int i) const;
		const Point* GetPointLine() const;
		unsigned int GetSize() const;
	private:
		const Point* mPointLine[10];
		unsigned int mSize;
	};
}