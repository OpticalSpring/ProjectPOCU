#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat() :Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}
	unsigned int UBoat::GetMaxSpeed() const
	{
		if (GetDiveSpeed() > GetSailSpeed())
		{
			return GetDiveSpeed();
		}
		else
		{
			return GetSailSpeed();
		}
	}
	unsigned int UBoat::GetDiveSpeed() const
	{
		double x = static_cast<double>(GetWeight());
		unsigned int speed = 500 * log((x + 150) / 150) + 30 + 0.5;

		return speed;
	}
	unsigned int UBoat::GetSailSpeed() const
	{
		double x = static_cast<double>(GetWeight());
		unsigned int speed = std::max((550 - x / 10), 200.0);

		return speed;
	}
}