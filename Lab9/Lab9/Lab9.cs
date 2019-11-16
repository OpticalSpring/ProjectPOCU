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
            int co;
            if (keys.Count < values.Count)
            {
                 co = keys.Count;
            }
            else
            {
                co = values.Count;
            }

            Dictionary<string, int> reDic = new Dictionary<string, int>();


            List<string> dd = new List<string>();

            for (int i = 0; i < co; i++)
            {
                if (!dd.Equals(keys[i]))
                {
                    dd.Add(keys[i]);
                    reDic.Add(keys[i], values[i]);
                }
            }
            return reDic;
        }

        public static Dictionary<string, decimal> MergeDictionaries(Dictionary<string, int> numerators, Dictionary<string, int> denominators)
        {

            return null;
        }
    }
}