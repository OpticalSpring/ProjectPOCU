#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat() : Vehicle(50)
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
		double speed = 500 * log((x + 150) / 150) + 30;

		return static_cast<unsigned int>(speed + 0.5);
	}
	unsigned int UBoat::GetSailSpeed() const
	{
		double x = static_cast<double>(GetWeight());
		double speed = std::max((550 - x / 10), 200.0);

		return static_cast<unsigned int>(speed + 0.5);
	}
	void UBoat::Move()
	{
		switch (mCount % 6) 
		{
		case 0:
		case 1:
			mDistance += GetMaxSpeed();
			break;
		case 2:
		case 3:
		case 4:
		case 5:
			break;
		}
		mCount++;
	}
}