using System;
using System.Collections.Generic;
using System.Text;

namespace Lab5
{
    public static class Lab5
    {
        public static bool TryFixData(uint[] usersPerDay, double[] revenuePerDay)
        {
            if (usersPerDay.Length != revenuePerDay.Length)
            {
                return false;
            }
            int count = 0;
            for (int i = 0; i < usersPerDay.Length; i++)
            {
                if (usersPerDay[0] >= 0 && usersPerDay[i] <= 10)
                {
                    if (revenuePerDay[i] != usersPerDay[i] / 2)
                    {
                        revenuePerDay[i] = usersPerDay[i] / 2;
                        count++;
                    }
                }
                else if (usersPerDay[i] <= 100)
                {
                    if (revenuePerDay[i] != 16 * usersPerDay[i] / 5 - 27)
                    {
                        revenuePerDay[i] = 16 * usersPerDay[i] / 5 - 27;
                        count++;
                    }
                }
                else if (usersPerDay[i] <= 1000)
                {
                    if (revenuePerDay[i] != usersPerDay[i] * usersPerDay[i] / 4 - 2 * usersPerDay[i] - 2007)
                    {
                        revenuePerDay[i] = usersPerDay[i] * usersPerDay[i] / 4 - 2 * usersPerDay[i] - 2007;
                        count++;
                    }
                }
                else if (usersPerDay[i] > 1000)
                {
                    if (revenuePerDay[i] != 245743 + usersPerDay[i] / 4)
                    {
                        revenuePerDay[i] = 245743 + usersPerDay[i] / 4;
                        count++;
                    }
                }
            }
            if (count == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static int GetInvalidEntryCount(uint[] usersPerDay, double[] revenuePerDay)
        {
            return -1;
        }

        public static double CalculateTotalRevenue(double[] revenuePerDay, uint start, uint end)
        {
            return 0.0;
        }
    }
}