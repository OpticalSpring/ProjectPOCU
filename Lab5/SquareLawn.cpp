#include "SquareLawn.h"
namespace lab5
{
	SquareLawn::SquareLawn(unsigned int input) 
	{
		mInput = input;
		mGrassArea = input * input;
	}
	SquareLawn::~SquareLawn()
	{
	}
	unsigned int SquareLawn::GetArea() const
	{
		return mGrassArea;
	}
	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		return (mInput * 4) * 4;
	}
	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case lab5::RED_CEDAR:
			return GetMinimumFencesCount() * 6 / 4;
			break;
		case lab5::SPRUCE:
			return GetMinimumFencesCount() * 7 / 4;
			break;
		default:
			break;
		}
		return 0;
	}
}