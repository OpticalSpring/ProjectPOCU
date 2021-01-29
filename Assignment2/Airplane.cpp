#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(mMaxPassengersCount + boat.GetMaxPassengersCount());
		for (size_t i = 0; i < mSize; i++)
		{
			bp.AddPassenger(GetPassenger(i));
		}
		for (size_t i = 0; i < boat.GetPassengersCount(); i++)
		{
			bp.AddPassenger(boat.GetPassenger(i));
		}

		if (mSize + boat.GetPassengersCount() > 100)
		{
			ReplacePassenger(mSize);
			boat.ReplacePassenger(100 - mSize);
		}
		else
		{
			ReplacePassenger(mSize);
			boat.ReplacePassenger(boat.GetPassengersCount());
		}
		return bp;
	}
	unsigned int Airplane::GetMaxSpeed() const
	{
		if (GetFlySpeed() > GetDriveSpeed())
		{
			return GetFlySpeed();
		}
		else
		{
			return GetDriveSpeed();
		}
	}
	unsigned int Airplane::GetFlySpeed() const
	{
		double x = static_cast<double>(GetWeight());
		double speed = 200.0 * pow(M_E, ((-x + 800.0) / 500.0));

		return static_cast<unsigned int>(speed + 0.5);
	}
	unsigned int Airplane::GetDriveSpeed() const
	{
		double x = static_cast<double>(GetWeight());
		double speed = 4.0 * pow(M_E, ((-x + 400.0) / 70.0));
		return static_cast<unsigned int>(speed + 0.5);
	}
	void Airplane::Move()
	{
		switch (mCount % 4)
		{
		case 0:
			mDistance += GetMaxSpeed();
			break;
		case 1:
		case 2:
		case 3:
			break;
		}
		mCount++;
	}
}