#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
	{
		mSheetName = name;
		mSheetTime = new int[maxEntries]();
		mSheetTimeLength = maxEntries;
		mSheetTimeNow = 0;

	}

	TimeSheet::TimeSheet(const TimeSheet& other)
	{
		mSheetName = other.GetName();
		mSheetTime = new int[other.GetLength()]();
		mSheetTimeLength = other.GetLength();
		mSheetTimeNow = other.GetNow();
		for (int i = 0; i < static_cast<int>(mSheetTimeLength); i++)
		{
			mSheetTime[i] = other.GetTimeEntry(i);
		}
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours < 1 || timeInHours > 10)
		{
			return;
		}
		if (mSheetTimeNow > mSheetTimeLength - 1)
		{
			return;
		}
		mSheetTime[mSheetTimeNow] = timeInHours;
		mSheetTimeNow++;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index < 0 || index > mSheetTimeNow - 1)
		{
			return -1;
		}
		else
		{
			return mSheetTime[index];
		}
	}

	int TimeSheet::GetTotalTime() const
	{
		if (mSheetTimeNow == 0)
		{
			return 0;
		}
		int sum = 0;
		for (size_t i = 0; i < mSheetTimeNow; i++)
		{
			sum += mSheetTime[i];
		}
		return sum;
	}

	float TimeSheet::GetAverageTime() const
	{
		if (mSheetTimeNow == 0)
		{
			return 0;
		}
		float avg = static_cast<float>(GetTotalTime()) / static_cast<float>(mSheetTimeNow);
		return avg;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		if (mSheetTimeNow == 0)
		{
			return 0;
		}

		float avg = GetAverageTime();
		float var = 0;
		for (size_t i = 0; i < mSheetTimeNow; i++)
		{
			var += static_cast<float>(pow(mSheetTime[i] - avg, 2));
		}
		var = var / mSheetTimeNow;
		float std = static_cast<float>(sqrt(var));

		return std;
	}

	const unsigned int TimeSheet::GetLength() const
	{
		return mSheetTimeLength;
	}

	const unsigned int TimeSheet::GetNow() const
	{
		return mSheetTimeNow;
	}

	const std::string& TimeSheet::GetName() const
	{
		return mSheetName;
	}
	TimeSheet::~TimeSheet()
	{
		delete[] mSheetTime;
	}
}