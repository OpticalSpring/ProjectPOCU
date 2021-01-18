#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
	{
		mSheetName = new char[strlen(name) + 1];
		strcpy(mSheetName, name);
		mSheetTime = new int[maxEntries];
		mSheetTimeLength = maxEntries;
		mSheetTimeNow = 0;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours < 1 || timeInHours > 10)
		{
			return;
		}
		if (mSheetTimeNow > mSheetTimeLength)
		{
			return;
		}
		mSheetTime[mSheetTimeNow] = timeInHours;
		mSheetTimeNow++;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index < 0 || index > mSheetTimeLength - 1)
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
		for (size_t i = 0; i < mSheetTimeLength; i++)
		{
			sum += mSheetTime[i];
		}
		return sum;
	}

	float TimeSheet::GetAverageTime() const
	{
		float avg = GetTotalTime() / mSheetTimeLength;
		return avg;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float avg = GetAverageTime();
		float var = 0;
		for (size_t i = 0; i < mSheetTimeLength; i++)
		{
			var += pow(mSheetTime[i] - avg, 2);
		}
		var = sqrt(var);

		return var;
	}

	const std::string& TimeSheet::GetName() const
	{
		return mSheetName;
	}
}