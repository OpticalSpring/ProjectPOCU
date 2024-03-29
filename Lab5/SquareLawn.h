#pragma once
#include "RectangleLawn.h"
namespace lab5
{
	class SquareLawn : public RectangleLawn
	{
	public:
		SquareLawn(unsigned int input);
		virtual ~SquareLawn();

		virtual unsigned int GetArea() const;
		virtual unsigned int GetMinimumFencesCount() const;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const;
	private:
		unsigned int mInput;
	};

}