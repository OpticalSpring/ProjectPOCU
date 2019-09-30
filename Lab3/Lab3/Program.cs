using System;
using System.IO;

namespace Lab3
{
    class Program
    {
        static void Main(string[] args)
        {
            // using 문에 대해서는 아직 걱정하지 마세요. 나중에 배울 겁니다
            using (StreamReader READER = new StreamReader(Console.OpenStandardInput()))
            {
                double totalCost = RestaurantBillCalculator.CalculateTotalCost(READER);

                double individualCost = RestaurantBillCalculator.CalculateIndividualCost(READER, totalCost);

                uint payerCount = RestaurantBillCalculator.CalculatePayerCount(READER, totalCost);
            }
        }
    }
}