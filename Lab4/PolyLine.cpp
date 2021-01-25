#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
	{
		mSize = 0;
		for (size_t i = 0; i < 10; i++)
		{
			mPointLine[i] = nullptr;
		}
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		
		mSize = other.GetSize();
		for (size_t i = 0; i < 10; i++)
		{
			mPointLine[i] = nullptr;
		}
		for (size_t i = 0; i < mSize; i++)
		{
			mPointLine[i] = &other.GetPointLine()[i];
		}
	}

	PolyLine::~PolyLine()
	{
		//delete[] &mPointLine;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mSize >= 10)
		{
			return false;
		}
		mPointLine[mSize] = new Point(x, y);
		mSize++;
		return true;
	}

	bool PolyLine::AddPoint( Point* point)
	{
		if (mSize >= 10)
		{
			return false;
		}
		mPointLine[mSize] = point;
		mSize++;
		return true;
	}

	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		mSize = other.GetSize();
		for (size_t i = 0; i < mSize; i++)
		{
			mPointLine[i] = &other.GetPointLine()[i];
		}
		return *this;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mSize || i < 0)
		{
			return false;
		}
		delete mPointLine[i];
		for (size_t j = i; j < mSize-1; j++)
		{
			mPointLine[j] = mPointLine[j + 1];
		}
		mSize--;
		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mSize == 0) 
		{
			return false;
		}
		float xMin = mPointLine[0]->GetX();
		float yMin = mPointLine[0]->GetY();
		float xMax = mPointLine[0]->GetX();
		float yMax = mPointLine[0]->GetY();
		for (size_t i = 0; i < mSize; i++)
		{
			if (mPointLine[i]->GetX() < xMin)
			{
				xMin = mPointLine[i]->GetX();
			}
			if (mPointLine[i]->GetY() < yMin)
			{
				yMin = mPointLine[i]->GetY();
			}
			if (mPointLine[i]->GetX() > xMax)
			{
				xMax = mPointLine[i]->GetX();
			}
			if (mPointLine[i]->GetY() > yMax)
			{
				yMax = mPointLine[i]->GetY();
			}
		}

		outMin->SetX(xMin);
		outMin->SetY(yMin); 
		outMax->SetX(xMax);
		outMax->SetY(yMax);
		//outMin = new Point(xMin, yMin);
		//outMax = new Point(xMax, yMax);
		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mSize || i < 0)
		{
			return nullptr;
		}
		//return new Point(mPointLine[i]->GetX(), mPointLine[i]->GetY());
		return mPointLine[i];
	}
	Point* PolyLine::GetPointLine() const
	{
		return *mPointLine;
	}
	unsigned int PolyLine::GetSize() const
	{
		return mSize;
	}
}