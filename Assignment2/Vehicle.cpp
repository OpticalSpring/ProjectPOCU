#include "Vehicle.h"
#include <iostream>
using namespace std;
namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
	{
		for (size_t i = 0; i < 100; i++)
		{
			mPassengers[i] = nullptr;
		}
		mMaxPassengersCount = maxPassengersCount;
		if (mMaxPassengersCount > 100) 
		{
			mMaxPassengersCount = 100;
		}
		mSize = 0;
		mWeight = 0;
		mDistance = 0;
		mCount = 0;
	}

	Vehicle::Vehicle(const Vehicle& other)
	{
		mSize = other.GetPassengersCount();
		mMaxPassengersCount = other.GetMaxPassengersCount();
		mWeight = other.GetWeight();
		mDistance = other.GetDistance();
		mCount = other.GetDistance();
		for (size_t i = 0; i < mSize; i++)
		{
			mPassengers[i] = new Person(other.GetPassenger(i));
		}
		cout << "Vcopy" << endl;
	}

	Vehicle& Vehicle::operator=(const Vehicle& other)
	{
		if (&other == this)
		{
			cout << "ME" << endl;
			return *this;
		}

		for (size_t i = 0; i < mSize; i++)
		{
			delete mPassengers[i];
		}
		mSize = other.GetPassengersCount();
		mMaxPassengersCount = other.GetMaxPassengersCount();
		mWeight = other.GetWeight();
		mDistance = other.GetDistance();
		for (size_t i = 0; i < mSize; i++)
		{
			mPassengers[i] = new Person(other.GetPassenger(i));
		}
		cout << "V=" << endl;
		return *this;
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
		if (i > mSize || i < 0)
		{
			return false;
		}
		
		for (size_t j = i-1; j < i; j++)
		{
			mWeight -= mPassengers[j]->GetWeight();
			mPassengers[j] = nullptr;
		}
		for (size_t j = i - 1; j < mSize; j++)
		{
			mPassengers[j-i] = mPassengers[j];
		}
		mSize -= i;
		
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

	unsigned int Vehicle::GetCount() const
	{
		return mCount;
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