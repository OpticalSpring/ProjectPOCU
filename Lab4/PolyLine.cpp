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
			mPointLine[i] = new Point(other[i]->GetX(), other[i]->GetY());
		}
	}

	PolyLine::~PolyLine()
	{
		for (size_t i = 0; i < mSize; i++)
		{
			delete mPointLine[i];
		}
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

	bool PolyLine::AddPoint(const Point* point)
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
		if (&other == this)
		{
			return *this;
		}

		for (size_t i = 0; i < mSize; i++)
		{
			delete mPointLine[i];
		}
		mSize = other.GetSize();
		for (size_t i = 0; i < mSize; i++)
		{
			mPointLine[i] = new Point(other[i]->GetX(), other[i]->GetY());
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
		for (size_t j = i; j < mSize - 1; j++)
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
		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mSize || i < 0)
		{
			return nullptr;
		}
		return mPointLine[i];
	}

	unsigned int PolyLine::GetSize() const
	{
		return mSize;
	}
}