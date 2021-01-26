#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount) :Vehicle(maxPassengersCount)
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

		for (size_t i = 0; i < mSize; i++)
		{
			RemovePassenger(i);
		}
		for (size_t i = 0; i < boat.GetPassengersCount(); i++)
		{
			bp.RemovePassenger(i);
		}

		return bp;
	}
	unsigned int Airplane::GetMaxSpeed() const
	{
		return 0;
	}
	unsigned int Airplane::GetFlySpeed() const
	{
		return 0;
	}
	unsigned int Airplane::GetDriveSpeed() const
	{
		return 0;
	}
}