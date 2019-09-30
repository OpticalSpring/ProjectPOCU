namespace Lab4
{
    public static class Calendar
    {
        public static bool IsLeapYear(uint year)
        {
            if (year % 4 == 0) 
            {
                if (year % 100 != 0 || year % 400 == 0) 
                {
                    return true;
                }
            }
            return false;
        }

        public static int GetDaysInMonth(uint year, uint month)
        {
            if (year > 9999) return -1;
            if (month < 1 || month > 12) return -1;
            switch (month)
            {
                case 1:
                    return 31;
                case 2:
                    if (IsLeapYear(year) == true) 
                    {
                        return 29;
                    }
                    else
                    {
                        return 28;
                    }
                case 3:
                    return 31;
                case 4:
                    return 30;
                case 5:
                    return 31;
                case 6:
                    return 30;
                case 7:
                    return 31;
                case 8:
                    return 31;
                case 9:
                    return 30;
                case 10:
                    return 31;
                case 11:
                    return 30;
                case 12:
                    return 31;
            }
            return -1;
        }
    }
}