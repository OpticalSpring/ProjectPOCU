#include "Lawn.h"
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
		switch (grassType)
		{
		case BERMUDA:
			return mGrassArea * 8;
			break;
		case BAHIA:
			return mGrassArea * 5;
			break;
		case BENTGRASS:
			return mGrassArea * 3;
			break;
		case PERENNIAL_RYEGRASS:
			return mGrassArea * 2.5;
			break;
		case ST_AUGUSTINE:
			return mGrassArea * 4.5;
			break;
		default:
			break;
		}
		return 0;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		double rCount = mGrassArea / 0.3;
		return static_cast<unsigned int>(rCount+0.5);
	}
}