#include "Boat.h"
#include "Airplane.h"
#include "Boatplane.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount) :Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(mMaxPassengersCount + plane.GetMaxPassengersCount());
		for (size_t i = 0; i < plane.GetPassengersCount(); i++)
		{
			bp.AddPassenger(plane.GetPassenger(i));
		}
		for (size_t i = 0; i < mSize; i++)
		{
			bp.AddPassenger(GetPassenger(i));
		}

		for (size_t i = 0; i < plane.GetPassengersCount(); i++)
		{
			bp.RemovePassenger(i);
		}
		for (size_t i = 0; i < mSize; i++)
		{
			RemovePassenger(i);
		}

		return bp;
	}
	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}
	unsigned int Boat::GetSailSpeed() const
	{
		double x = static_cast<double>(GetWeight());
		unsigned int speed = std::max((800 - 1.7 * x), 20.0);

		return speed;
	}
}