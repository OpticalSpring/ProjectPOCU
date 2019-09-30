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

                    if (revenuePerDay[i] != (double)usersPerDay[i] / 2)
                    {
                        Console.WriteLine("{0}번째 데이터 수정", i);
                        Console.Write(revenuePerDay[i]);
                        Console.Write("->");
                        revenuePerDay[i] = (double)usersPerDay[i] / 2;
                        count++;
                        Console.WriteLine(revenuePerDay[i]);
                    }
                }
                else if (usersPerDay[i] <= 100)
                {
                    if (revenuePerDay[i] != 16 * (double)usersPerDay[i] / 5 - 27)
                    {
                        Console.WriteLine("{0}번째 데이터 수정", i);
                        Console.Write(revenuePerDay[i]);
                        Console.Write("->");
                        revenuePerDay[i] = 16 * (double)usersPerDay[i] / 5 - 27;
                        count++;
                        Console.WriteLine(revenuePerDay[i]);
                    }
                }
                else if (usersPerDay[i] <= 1000)
                {
                    if (revenuePerDay[i] != (double)usersPerDay[i] * (double)usersPerDay[i] / 4 - 2 * (double)usersPerDay[i] - 2007)
                    {
                        Console.WriteLine("{0}번째 데이터 수정", i);
                        Console.Write(revenuePerDay[i]);
                        Console.Write("->");
                        revenuePerDay[i] = (double)usersPerDay[i] * (double)usersPerDay[i] / 4 - 2 * (double)usersPerDay[i] - 2007;
                        count++;
                        Console.WriteLine(revenuePerDay[i]);
                    }
                }
                else if (usersPerDay[i] > 1000)
                {
                    if (revenuePerDay[i] != 245743 + (double)usersPerDay[i] / 4)
                    {
                        Console.WriteLine("{0}번째 데이터 수정", i);
                        Console.Write(revenuePerDay[i]);
                        Console.Write("->");
                        revenuePerDay[i] = 245743 + (double)usersPerDay[i] / 4;
                        count++;
                        Console.WriteLine(revenuePerDay[i]);
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

                    if (revenuePerDay[i] != (double)usersPerDay[i] / 2)
                    {
                        Console.WriteLine("{0}번째 데이터 수정", i);
                        Console.Write(revenuePerDay[i]);
                        Console.Write("->");
                        count++;
                        Console.WriteLine(revenuePerDay[i]);
                    }
                }
                else if (usersPerDay[i] <= 100)
                {
                    if (revenuePerDay[i] != 16 * (double)usersPerDay[i] / 5 - 27)
                    {
                        Console.WriteLine("{0}번째 데이터 수정", i);
                        Console.Write(revenuePerDay[i]);
                        Console.Write("->");
                        count++;
                        Console.WriteLine(revenuePerDay[i]);
                    }
                }
                else if (usersPerDay[i] <= 1000)
                {
                    if (revenuePerDay[i] != (double)usersPerDay[i] * (double)usersPerDay[i] / 4 - 2 * (double)usersPerDay[i] - 2007)
                    {
                        Console.WriteLine("{0}번째 데이터 수정", i);
                        Console.Write(revenuePerDay[i]);
                        Console.Write("->");
                        count++;
                        Console.WriteLine(revenuePerDay[i]);
                    }
                }
                else if (usersPerDay[i] > 1000)
                {
                    if (revenuePerDay[i] != 245743 + (double)usersPerDay[i] / 4)
                    {
                        Console.WriteLine("{0}번째 데이터 수정", i);
                        Console.Write(revenuePerDay[i]);
                        Console.Write("->");
                        count++;
                        Console.WriteLine(revenuePerDay[i]);
                    }
                }
            }
            return count;
        }

        public static double CalculateTotalRevenue(double[] revenuePerDay, uint start, uint end)
        {
            if (start < 0 || end > revenuePerDay.Length - 1 || start > end) 
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