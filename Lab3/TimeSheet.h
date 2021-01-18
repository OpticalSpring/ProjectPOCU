#pragma once
#include <string>


namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;

	private:
		~TimeSheet();
		std::string mSheetName;
		int* mSheetTime;
		unsigned int mSheetTimeLength;
		unsigned int mSheetTimeNow;
	};
}