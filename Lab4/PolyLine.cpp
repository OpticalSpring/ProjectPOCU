#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
	{
		mSize = 0;
		mPointLine = new Point[mSize];
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		
		mSize = other.GetSize();
		mPointLine = other.GetPointLine();
	}

	PolyLine::~PolyLine()
	{
		delete[] mPointLine;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mSize >= 10)
		{
			return false;
		}
		Point* nPointLine = new Point[mSize + 1];
		for (size_t i = 0; i < mSize; i++)
		{
			nPointLine[i] = mPointLine[i];
		}
		nPointLine[mSize] = Point(x, y);
		mPointLine = nPointLine;
		mSize++;
		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mSize >= 10)
		{
			return false;
		}
		Point* nPointLine = new Point[mSize + 1];
		for (size_t i = 0; i < mSize; i++)
		{
			nPointLine[i] = mPointLine[i];
		}
		nPointLine[mSize] = Point(point->GetX(), point->GetY());
		mPointLine = nPointLine;
		mSize++;
		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mSize || i < 0)
		{
			return false;
		}
		Point* nPointLine = new Point[mSize - 1];
		for (size_t j = 0; j < i; j++)
		{
			nPointLine[j] = mPointLine[j];
		}
		for (size_t j = i + 1; j < mSize; j++)
		{
			nPointLine[j - 1] = mPointLine[j];
		}
		
		mPointLine = nPointLine;
		mSize--;
		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mSize == 0) 
		{
			return false;
		}
		float xMin = mPointLine[0].GetX();
		float yMin = mPointLine[0].GetY();
		float xMax = mPointLine[0].GetX();
		float yMax = mPointLine[0].GetY();
		for (size_t i = 0; i < mSize; i++)
		{
			if (mPointLine[i].GetX() < xMin) 
			{
				xMin = mPointLine[i].GetX();
			}
			if (mPointLine[i].GetY() < yMin)
			{
				yMin = mPointLine[i].GetY();
			}
			if (mPointLine[i].GetX() > xMax)
			{
				xMax = mPointLine[i].GetX();
			}
			if (mPointLine[i].GetY() > yMax)
			{
				yMax = mPointLine[i].GetY();
			}
		}

		outMin->SetX(xMin);
		outMin->SetY(yMin); 
		outMax->SetX(xMax);
		outMax->SetY(yMax);
		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mSize || i < 0)
		{
			return nullptr;
		}
		return new Point(mPointLine[i].GetX(), mPointLine[i].GetY());
	}
	Point* PolyLine::GetPointLine() const
	{
		return mPointLine;
	}
	unsigned int PolyLine::GetSize() const
	{
		return mSize;
	}
}