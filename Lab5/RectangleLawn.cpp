#include "RectangleLawn.h"
namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int input1, unsigned int input2)
	{
		mInput1 = input1;
		mInput2 = input2;
		mGrassArea = input1 * input2;
	}
	RectangleLawn::~RectangleLawn()
	{

	}
	unsigned int RectangleLawn::GetArea() const
	{
		return mGrassArea;
	}
	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		return (mInput1 * 2 + mInput2 * 2) * 4;
	}
	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
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