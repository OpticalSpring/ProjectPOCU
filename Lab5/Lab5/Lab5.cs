using System;
using System.Collections.Generic;
using System.Text;

namespace Lab5
{
    public static class Lab5
    {
        public static bool TryFixData(uint[] usersPerDay, double[] revenuePerDay)
        {
            if (usersPerDay.Length != revenuePerDay.Length || usersPerDay.Length == 0 || revenuePerDay.Length == 0)
            {
                return false;
            }
            int count = 0;
            for (int i = 0; i < usersPerDay.Length; i++)
            {
                if (usersPerDay[0] >= 0 && usersPerDay[i] <= 10)
                {
                    if (revenuePerDay[i] != MathF.Round((usersPerDay[i] / 2)*100)/100)
                    {
                        revenuePerDay[i] = MathF.Round((usersPerDay[i] / 2) * 100) / 100;
                        count++;
                    }
                }
                else if (usersPerDay[i] <= 100)
                {
                    if (revenuePerDay[i] != MathF.Round((16 * usersPerDay[i] / 5 - 27) * 100) / 100) 
                    {
                        revenuePerDay[i] = MathF.Round((16 * usersPerDay[i] / 5 - 27) * 100) / 100;
                        count++;
                    }
                }
                else if (usersPerDay[i] <= 1000)
                {
                    if (revenuePerDay[i] != MathF.Round((usersPerDay[i] * usersPerDay[i] / 4 - 2 * usersPerDay[i] - 2007)*100)/100)
                    {
                        revenuePerDay[i] = MathF.Round((usersPerDay[i] * usersPerDay[i] / 4 - 2 * usersPerDay[i] - 2007) * 100) / 100;
                        count++;
                    }
                }
                else if (usersPerDay[i] > 1000)
                {
                    if (revenuePerDay[i] != MathF.Round((245743 + usersPerDay[i] / 4)*100)/100)
                    {
                        revenuePerDay[i] = MathF.Round((245743 + usersPerDay[i] / 4) * 100) / 100;
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
            if (usersPerDay.Length != revenuePerDay.Length)
            {
                return -1;
            }
            int count = 0;
            for (int i = 0; i < usersPerDay.Length; i++)
            {
                if (usersPerDay[0] >= 0 && usersPerDay[i] <= 10)
                {
                    if (revenuePerDay[i] != MathF.Round((usersPerDay[i] / 2) * 100) / 100)
                    {
                        count++;
                    }
                }
                else if (usersPerDay[i] <= 100)
                {
                    if (revenuePerDay[i] != MathF.Round((16 * usersPerDay[i] / 5 - 27) * 100) / 100)
                    {
                        count++;
                    }
                }
                else if (usersPerDay[i] <= 1000)
                {
                    if (revenuePerDay[i] != MathF.Round((usersPerDay[i] * usersPerDay[i] / 4 - 2 * usersPerDay[i] - 2007) * 100) / 100)
                    {
                        count++;
                    }
                }
                else if (usersPerDay[i] > 1000)
                {
                    if (revenuePerDay[i] != MathF.Round((245743 + usersPerDay[i] / 4) * 100) / 100)
                    {
                        count++;
                    }
                }
            }
            return count;
        }

        public static double CalculateTotalRevenue(double[] revenuePerDay, uint start, uint end)
        {
            if (start < 0 || end > revenuePerDay.Length-1)
            {
                return -1;
            }
            double allRevenue = 0.0f;
            for (uint i = start; i < end + 1; i++) 
            {
                allRevenue += revenuePerDay[i];
            }
            return allRevenue;
        }
    }
}