#pragma once
#include <string>


namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& other);
		~TimeSheet();
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const unsigned int GetLength() const;
		const unsigned int GetNow() const;
		const std::string& GetName() const;

	private:
		std::string mSheetName;
		int* mSheetTime;
		unsigned int mSheetTimeLength;
		unsigned int mSheetTimeNow;
	};
}