using System;
using System.Collections.Generic;
using System.Text;

namespace Lab5
{
    public static class Lab5
    {
        
        
        public static bool TryFixData(uint[] usersPerDay, double[] revenuePerDay)
        {
            double trueValue = 0.0;
            if (usersPerDay.Length != revenuePerDay.Length || usersPerDay.Length == 0 || revenuePerDay.Length == 0)
            {
                Console.WriteLine("Return False");
                return false;
            }
            int count = 0;
            for (int i = 0; i < usersPerDay.Length; i++)
            {
                if (usersPerDay[0] >= 0 && usersPerDay[i] <= 10)
                {
                    trueValue = Math.Round(((double)usersPerDay[i] / 2) * 100) / 100;
                    Console.WriteLine(trueValue);
                    if (revenuePerDay[i] != trueValue)
                    {
                        Console.WriteLine("{0}번째 데이터 수정", i);
                        revenuePerDay[i] = trueValue;
                        count++;
                    }
                }
                else if (usersPerDay[i] <= 100)
                {
                    trueValue = Math.Round((16 * (double)usersPerDay[i] / 5 - 27) * 100) / 100;
                    Console.WriteLine(trueValue);
                    if (revenuePerDay[i] != trueValue)
                    {
                        Console.WriteLine("{0}번째 데이터 수정", i);
                        revenuePerDay[i] = trueValue;
                        count++;
                    }
                }
                else if (usersPerDay[i] <= 1000)
                {
                    trueValue = Math.Round(((double)usersPerDay[i] * (double)usersPerDay[i] / 4 - 2 * (double)usersPerDay[i] - 2007) * 100) / 100;
                    Console.WriteLine(trueValue);
                    if (revenuePerDay[i] != trueValue)
                    {
                        Console.WriteLine("{0}번째 데이터 수정", i);
                        revenuePerDay[i] = trueValue;
                        count++;
                    }
                }
                else if (usersPerDay[i] > 1000)
                {
                    trueValue = Math.Round((245743 + (double)usersPerDay[i] / 4) * 100) / 100;
                    Console.WriteLine(trueValue);
                    if (revenuePerDay[i] != trueValue)
                    {
                        Console.WriteLine("{0}번째 데이터 수정", i);
                        revenuePerDay[i] = trueValue;
                        count++;
                    }
                }
            }
            if (count != 0)
            {
                Console.WriteLine("Return True");
                return true;
            }
            else
            {
                Console.WriteLine("Return False");
                return false;
            }
        }

        public static int GetInvalidEntryCount(uint[] usersPerDay, double[] revenuePerDay)
        {
            double trueValue = 0.0;
            if (usersPerDay.Length != revenuePerDay.Length)
            {
                return -1;
            }
            int count = 0;
            for (int i = 0; i < usersPerDay.Length; i++)
            {
                if (usersPerDay[0] >= 0 && usersPerDay[i] <= 10)
                {
                    trueValue = Math.Round(((double)usersPerDay[i] / 2) * 100) / 100;
                    Console.WriteLine(trueValue);
                    if (revenuePerDay[i] != trueValue)
                    {
                        Console.WriteLine("{0}번째 데이터", i);
                        count++;
                    }
                }
                else if (usersPerDay[i] <= 100)
                {
                    trueValue = Math.Round((16 * (double)usersPerDay[i] / 5 - 27) * 100) / 100;
                    Console.WriteLine(trueValue);
                    if (revenuePerDay[i] != trueValue)
                    {
                        Console.WriteLine("{0}번째 데이터", i);
                        count++;
                    }
                }
                else if (usersPerDay[i] <= 1000)
                {
                    trueValue = Math.Round(((double)usersPerDay[i] * (double)usersPerDay[i] / 4 - 2 * (double)usersPerDay[i] - 2007) * 100) / 100;
                    Console.WriteLine(trueValue);
                    if (revenuePerDay[i] != trueValue)
                    {
                        Console.WriteLine("{0}번째 데이터", i);
                        count++;
                    }
                }
                else if (usersPerDay[i] > 1000)
                {
                    trueValue = Math.Round((245743 + (double)usersPerDay[i] / 4) * 100) / 100;
                    Console.WriteLine(trueValue);
                    if (revenuePerDay[i] != trueValue)
                    {
                        Console.WriteLine("{0}번째 데이터", i);
                        count++;
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