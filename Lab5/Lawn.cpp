#include "Lawn.h"
#include <cmath>
namespace lab5
{
	Lawn::Lawn() : mGrassArea(0)
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		double price = 0;
		switch (grassType)
		{
		case BERMUDA:
			price = mGrassArea * 8;
			break;
		case BAHIA:
			price = mGrassArea * 5;
			break;
		case BENTGRASS:
			price = mGrassArea * 3;
			break;
		case PERENNIAL_RYEGRASS:
			price = mGrassArea * 2.5;
			break;
		case ST_AUGUSTINE:
			price = mGrassArea * 4.5;
			break;
		default:
			break;
		}
		return static_cast<unsigned int>(price + 0.5);
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		double rCount = mGrassArea / 0.3;
		return static_cast<unsigned int>(ceil(rCount));
	}
}