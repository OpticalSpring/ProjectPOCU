using System.Collections.Generic;

namespace Lab9
{
    public static class Lab9
    {
        public static List<int> MergeLists(List<int> sortedList1, List<int> sortedList2)
        {
            List<int> reList = new List<int>();

            reList.AddRange(sortedList1);
            reList.AddRange(sortedList2);
            for (int j = 0; j < reList.Count; j++)
            {
                for (int i = 0; i < reList.Count - 1; i++)
                {
                    if (reList[i] > reList[i + 1])
                    {
                        int temp = reList[i + 1];
                        reList[i + 1] = reList[i];
                        reList[i] = temp;
                    }
                }
            }

            return reList;
        }

        public static Dictionary<string, int> CombineListsToDictionary(List<string> keys, List<int> values)
        {

            return null;
        }

        public static Dictionary<string, decimal> MergeDictionaries(Dictionary<string, int> numerators, Dictionary<string, int> denominators)
        {

            return null;
        }
    }
}