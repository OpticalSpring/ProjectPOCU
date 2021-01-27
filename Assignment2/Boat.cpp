#include "Boat.h"
#include "Airplane.h"
#include "Boatplane.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
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

		ReplacePassenger(0);
		plane.ReplacePassenger(0);

		return bp;
	}
	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}
	unsigned int Boat::GetSailSpeed() const
	{
		double x = static_cast<double>(GetWeight());
		double speed = std::max((800 - 10 * x), 20.0);

		return static_cast<unsigned int>(speed + 0.5);
	}
	void Boat::Move()
	{
		switch (mCount % 3) {
		case 0:
		case 1:
			mDistance += GetMaxSpeed();
			break;
		case 2:
			break;
		}
		mCount++;
	}
}