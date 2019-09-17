using System;
using System.IO;


namespace Lab3
{
    public static class RestaurantBillCalculator
    {
        public static double CalculateTotalCost(StreamReader input)
        {
            double[] str = new double[6];
            double sum = 0;
            for (int i = 0; i < 5; i++)
            {
                str[i] = double.Parse(input.ReadLine());
                sum += str[i];
            }
            str[5] = double.Parse(input.ReadLine());
            double tax = sum * 0.05;
            double tip = (sum + tax) * str[5] / 100;
            double all = sum + tax + tip;


            Console.WriteLine("음식 가격 = " + Math.Round(sum, 2));
            Console.WriteLine("세금 = " + Math.Round(tax, 2));
            Console.WriteLine("팁 = " + Math.Round(tip, 2));
            Console.WriteLine("세금 및 팁까지 포함한 가격 = " + Math.Round(all,2));
            return all;
        }

        public static double CalculateIndividualCost(StreamReader input, double totalCost)
        {
            int cost = int.Parse(input.ReadLine());
            return Math.Round(totalCost / cost, 2);
        }

        public static uint CalculatePayerCount(StreamReader input, double totalCost)
        {
            double count = double.Parse(input.ReadLine());
            uint a = (uint)(totalCost / count);
            return a+1;
        }
    }
}