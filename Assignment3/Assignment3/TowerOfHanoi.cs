using System.Collections.Generic;
using System;

namespace Assignment3
{
    public static class TowerOfHanoi
    {

        public static int GetNumberOfSteps(int numDiscs)
        {
            if (numDiscs < 0)
            {
                return -1;
            }
            int count = 0;
            CountHanoi(ref count, numDiscs, 1, 3, 2);
            return count;
        }

        public static void CountHanoi(ref int count, int num, int from, int to, int other)
        {
            if (num == 0) { return; }
            CountHanoi(ref count, num - 1, from, other, to);
            count++;
            CountHanoi(ref count, num - 1, other, to, from);
        }
        public static List<List<int>[]> SolveTowerOfHanoi(int numDiscs)
        {
            
            List<List<int>[]> nSnapshot = new List<List<int>[]>();
            nSnapshot.Add(new List<int>[3]);
            nSnapshot[0] = new List<int>[]
            {
                new List<int> {  },
                 new List<int> {  },
                  new List<int> {  },
            };

            if (numDiscs < 1)
            {
                return nSnapshot;
            }
            for (int i = 0; i < numDiscs; i++)
            {
                nSnapshot[0][0].Add(numDiscs - i);
            }
            int count = 0;

            PlusHanoi(ref count, numDiscs, 1, 3, 2, ref nSnapshot);
            return nSnapshot;
        }


        public static void PlusHanoi(ref int count, int num, int from, int to, int other, ref List<List<int>[]> nSnapshot)
        {
            if (num == 0) { return; }
            PlusHanoi(ref count, num - 1, from, other, to, ref nSnapshot);
            count++;
            nSnapshot.Add(new List<int>[3]);
            nSnapshot[count] = new List<int>[]
            {
                new List<int> {  },
                 new List<int> {  },
                  new List<int> {  },
            };
            int[] a1 = nSnapshot[count - 1][0].ToArray();
            int[] a2 = nSnapshot[count - 1][1].ToArray();
            int[] a3 = nSnapshot[count - 1][2].ToArray();
            for (int i = 0; i < a1.Length; i++)
            {
                nSnapshot[count][0].Add(a1[i]);
            }
            for (int i = 0; i < a2.Length; i++)
            {
                nSnapshot[count][1].Add(a2[i]);
            }
            for (int i = 0; i < a3.Length; i++)
            {
                nSnapshot[count][2].Add(a3[i]);
            }

            nSnapshot[count][to - 1].Add(num);
            nSnapshot[count][from - 1].Remove(num);
            PlusHanoi(ref count, num - 1, other, to, from, ref nSnapshot);
        }
    }
}