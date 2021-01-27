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
		unsigned int speed = 200.0 * pow(M_E, ((-x + 800.0) / 500.0)) +0.5;
		
		return speed;
	}
	unsigned int Airplane::GetDriveSpeed() const
	{
		double x = static_cast<double>(GetWeight());
		unsigned int speed = 4.0 * pow(M_E, ((-x + 400.0) / 70.0)) + 0.5;
		return speed;
	}
}