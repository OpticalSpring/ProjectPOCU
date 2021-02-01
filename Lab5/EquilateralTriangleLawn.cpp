#include "EquilateralTriangleLawn.h"
#include <cmath>
namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int input)
	{
		mInput = input;
		double area = sqrt(3) / 4 * input * input;
		mGrassArea = static_cast<unsigned int>(area + 0.5);
	}
	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}
	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return mGrassArea;
	}
	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return (mInput * 3) * 4;
	}
	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
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