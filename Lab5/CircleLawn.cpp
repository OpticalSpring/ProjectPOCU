#include "CircleLawn.h"
namespace lab5
{
	CircleLawn::CircleLawn(unsigned int input)
	{
		mInput = input;
		double area = input * input * 3.14;
		mGrassArea = static_cast<unsigned int>(area + 0.5);
	}
	CircleLawn::~CircleLawn()
	{
	}
	unsigned int CircleLawn::GetArea() const
	{
		return mGrassArea;
	}
}
