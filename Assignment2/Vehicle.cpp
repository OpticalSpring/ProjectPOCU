#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
	{
		for (size_t i = 0; i < 100; i++)
		{
			mPassengers[i] = nullptr;
		}
		mMaxPassengersCount = maxPassengersCount;
		mSize = 0;
		mWeight = 0;
		mDistance = 0;
	}

	Vehicle::~Vehicle()
	{
		for (size_t i = 0; i < mSize; i++)
		{
			delete mPassengers[i];
		}
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mSize >= mMaxPassengersCount)
		{
			return false;
		}
		mPassengers[mSize] = person;
		mWeight += person->GetWeight();
		mSize++;
		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= mSize || i < 0)
		{
			return false;
		}
		mWeight -= mPassengers[i]->GetWeight();
		delete mPassengers[i];
		for (size_t j = i; j < mSize - 1; j++)
		{
			mPassengers[j] = mPassengers[j + 1];
		}
		mSize--;
		return true;
	}

	bool Vehicle::ReplacePassenger(unsigned int i)
	{
		if (i >= mSize || i < 0)
		{
			return false;
		}
		mWeight = 0;
		for (size_t j = i; j < mSize; j++)
		{
			mPassengers[j] = nullptr;
		}
		mSize = 0;
		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mSize;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	unsigned int Vehicle::GetWeight() const
	{
		return mWeight;
	}

	unsigned int Vehicle::GetDistance() const
	{
		return mDistance;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i >= mSize || i < 0)
		{
			return nullptr;
		}
		return mPassengers[i];
	}
}