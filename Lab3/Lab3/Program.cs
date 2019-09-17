using System.Diagnostics;
using System.IO;
using System.Text;

namespace Lab3
{
    class Program
    {
        static void Main(string[] args)
        {
            string itemCostsInput = "25.34\n10.99\n250.22\n21.87\n50.24\n15";
            string payerCountInput = "8\n";
            string individualCostInput = "52.24\n";

            byte[] buffer1 = Encoding.UTF8.GetBytes(itemCostsInput);
            byte[] buffer2 = Encoding.UTF8.GetBytes(payerCountInput);
            byte[] buffer3 = Encoding.UTF8.GetBytes(individualCostInput);

            // using 문에 대해서는 아직 걱정하지 마세요. 나중에 배울 겁니다
            using (StreamReader reader1 = new StreamReader(new MemoryStream(buffer1)))
            using (StreamReader reader2 = new StreamReader(new MemoryStream(buffer2)))
            using (StreamReader reader3 = new StreamReader(new MemoryStream(buffer3)))
            {
                double totalCost = RestaurantBillCalculator.CalculateTotalCost(reader1);
                Debug.Assert(totalCost == 433.08);

                double individualCost = RestaurantBillCalculator.CalculateIndividualCost(reader2, totalCost);
                Debug.Assert(individualCost == 54.14);

                uint payerCount = RestaurantBillCalculator.CalculatePayerCount(reader3, totalCost);
                Debug.Assert(payerCount == 9);
            }
        }
    }
}