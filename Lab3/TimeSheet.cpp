#include "TimeSheet.h"

namespace lab3
{
    TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
    {
        sheetName = new char[strlen(name)+1];
        strcpy(sheetName, name);
        sheetTime = new int[maxEntries];
        sheetTimeLength = maxEntries;
        sheetTimeNow = 0;
    }

    void TimeSheet::AddTime(int timeInHours)
    {
        if (timeInHours < 1 || timeInHours > 10) 
        {
            return;
        }
        if (sheetTimeNow > sheetTimeLength) 
        {
            return;
        }
        sheetTime[sheetTimeNow] = timeInHours;
        sheetTimeNow++;
    }

    int TimeSheet::GetTimeEntry(unsigned int index) const
    {
        if (index < 0 || index > sheetTimeLength - 1) 
        {
            return -1;
        }
        else 
        {
            return sheetTime[index];
        }
    }

    int TimeSheet::GetTotalTime() const
    {
        int sum = 0;
        for (size_t i = 0; i < sheetTimeLength; i++)
        {
            sum += sheetTime[i];
        }
        return sum;
    }

    float TimeSheet::GetAverageTime() const
    {
        float avg = GetTotalTime()/sheetTimeLength;
        return avg;
    }

    float TimeSheet::GetStandardDeviation() const
    {
        return 0.0f;
    }

    const std::string& TimeSheet::GetName() const
    {
        return sheetName;
    }
}