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


            List<string> dd1 = new List<string>();
            List<int> dd2 = new List<int>();

            for (int i = 0; i < co; i++)
            {
                if (!dd1.Equals(keys[i]) && !dd2.Equals(values[i]))
                {
                    dd1.Add(keys[i]);
                    dd2.Add(values[i]);
                    reDic.Add(keys[i], values[i]);
                }
            }
            return reDic;
        }

        public static Dictionary<string, decimal> MergeDictionaries(Dictionary<string, int> numerators, Dictionary<string, int> denominators)
        {
            Dictionary<string, decimal> reDic = new Dictionary<string, decimal>();
            foreach (KeyValuePair<string, int> i in numerators)
            {

                if (denominators.ContainsKey(i.Key))
                {
                    int c;
                    denominators.TryGetValue(i.Key, out c);
                    if (c != 0)
                    {
                        int d;
                        denominators.TryGetValue(i.Key, out d);

                        decimal e = (decimal)i.Value / d;
                        if (e < 0)
                        {
                            e *= -1;
                        }
                        reDic.Add(i.Key, e);
                    }
                }
            }
            return reDic;
        }
    }
}