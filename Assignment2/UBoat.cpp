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
		return 0;
	}
	unsigned int UBoat::GetDiveSpeed() const
	{
		return 0;
	}
	unsigned int UBoat::GetSailSpeed() const
	{
		return 0;
	}
}