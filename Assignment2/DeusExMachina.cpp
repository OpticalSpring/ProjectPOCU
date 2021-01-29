#include "DeusExMachina.h"
#include "Vehicle.h"
#include <iostream>
using namespace std;
namespace assignment2
{
	DeusExMachina* DeusExMachina::GetInstance()
	{
		static DeusExMachina ins;
		return &ins;
	}

	DeusExMachina::~DeusExMachina()
	{
		for (size_t i = 0; i < mSize; i++)
		{
			delete mVehicle[i];
		}
		cout << "des" << endl;
	}

	void DeusExMachina::Travel() const
	{
		for (size_t i = 0; i < mSize; i++)
		{
			mVehicle[i]->Move();
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
		if (mSize == 0) 
		{
			return nullptr;
		}
		unsigned int dis = 0;
		int a = 0;
		for (size_t i = 0; i < mSize; i++)
		{
			if (mVehicle[i]->GetDistance() > dis) 
			{
				dis = mVehicle[i]->GetDistance();
				a = i;
			}
		}
		return mVehicle[a];
	}
}