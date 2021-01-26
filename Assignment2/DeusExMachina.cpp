#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::GetInstance()
	{
		static DeusExMachina ins;
		return &ins;
	}

	void DeusExMachina::Travel() const
	{
		for (size_t i = 0; i < mSize; i++)
		{
			
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mSize >= 10)
		{
			return false;
		}
		mVehicle[mSize] = vehicle;
		mSize++;
		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mSize || i < 0)
		{
			return false;
		}
		delete mVehicle[i];
		for (size_t j = i; j < mSize - 1; j++)
		{
			mVehicle[j] = mVehicle[j + 1];
		}
		mSize--;
		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		return NULL;
	}
}