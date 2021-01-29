#include "Vehicle.h"
namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
	{
		mMaxPassengersCount = maxPassengersCount;
		mPassengers = new const Person * [mMaxPassengersCount];

		for (size_t i = 0; i < mMaxPassengersCount; i++)
		{
			mPassengers[i] = nullptr;
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
		mPassengers = new const Person * [mMaxPassengersCount];

		for (size_t i = 0; i < mMaxPassengersCount; i++)
		{
			mPassengers[i] = nullptr;
		}
		for (size_t i = 0; i < mSize; i++)
		{
			mPassengers[i] = new Person(other.GetPassenger(i));
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& other)
	{
		if (&other == this)
		{
			return *this;
		}

		for (size_t i = 0; i < mMaxPassengersCount; i++)
		{
			delete mPassengers[i];
		}
		delete[] mPassengers;
		mSize = other.GetPassengersCount();
		mMaxPassengersCount = other.GetMaxPassengersCount();
		mWeight = other.GetWeight();
		mDistance = other.GetDistance();
		mPassengers = new const Person * [mMaxPassengersCount];

		for (size_t i = 0; i < mMaxPassengersCount; i++)
		{
			mPassengers[i] = nullptr;
		}
		for (size_t i = 0; i < mSize; i++)
		{
			mPassengers[i] = new Person(other.GetPassenger(i));
		}
		return *this;
	}

	Vehicle::~Vehicle()
	{
		for (size_t i = 0; i < mSize; i++)
		{
			delete mPassengers[i];
			mPassengers[i] = nullptr;
		}
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mSize >= mMaxPassengersCount || person == nullptr)
		{
			return false;
		}
		if (IsOverlap(person))
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
		mPassengers[mSize] = nullptr;
		return true;
	}

	bool Vehicle::ReplacePassenger(unsigned int i)
	{
		if (i > mSize || i < 0)
		{
			return false;
		}

		for (size_t j = 0; j < i; j++)
		{
			mWeight -= mPassengers[j]->GetWeight();
			mPassengers[j] = nullptr;
		}
		for (size_t j = i; j < mSize; j++)
		{
			mPassengers[j - i] = mPassengers[j];
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

	bool Vehicle::IsOverlap(const Person* person) const
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			if (mPassengers[i] == person)
			{
				return true;
			}
		}
		return false;
	}

}