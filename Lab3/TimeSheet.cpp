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
		int sum = 0;
		for (size_t i = 0; i < mSheetTimeNow; i++)
		{
			sum += mSheetTime[i];
		}
		return sum;
	}

	float TimeSheet::GetAverageTime() const
	{
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

	const std::string& TimeSheet::GetName() const
	{
		return mSheetName;
	}
}