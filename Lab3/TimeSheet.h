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
        char* mSheetName;
        int* mSheetTime;
        int mSheetTimeLength;
        int mSheetTimeNow;
        // �ʿ信 ���� private ������ �޼��带 �߰��ϼ���.
    };
}