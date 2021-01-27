#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount) :Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}
	unsigned int Boatplane::GetMaxSpeed() const
	{
		if (GetFlySpeed() > GetSailSpeed())
		{
			return GetFlySpeed();
		}
		else
		{
			return GetSailSpeed();
		}
	}
	unsigned int Boatplane::GetFlySpeed() const
	{
		double x = static_cast<double>(GetWeight());
		unsigned int speed = 150.0 * pow(M_E, ((-x + 500.0) / 300.0)) + 0.5;

		return speed;
	}
	unsigned int Boatplane::GetSailSpeed() const
	{
		double x = static_cast<double>(GetWeight());
		unsigned int speed = std::max((800 - 1.7 * x), 20.0);

		return speed;
	}
}