#include "Boat.h"

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
		Boatplane bp(5);
		return bp;
	}
	unsigned int Boat::GetMaxSpeed() const
	{
		return 0;
	}
	unsigned int Boat::GetSailSpeed() const
	{
		return 0;
	}
}