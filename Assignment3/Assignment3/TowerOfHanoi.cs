using System.Collections.Generic;
using System;

namespace Assignment3
{
    public static class TowerOfHanoi
    {

        public static int GetNumberOfSteps(int numDiscs)
        {
            if(numDiscs < 0)
            {
                return -1;
            }
            int count = 0;
            hanoi(ref count, numDiscs, 1,3,2);
            return count;
        }

        public static void hanoi(ref int count,int num, int from, int to, int other)
        {
            if (num == 0) { return; }
            hanoi(ref count, num - 1, from, other, to);
            count++;
            Console.WriteLine("{0}->{1} - {2}", from, to, count);
            hanoi(ref count, num - 1, other, to,from);
        }
        public static List<List<int>[]> SolveTowerOfHanoi(int numDiscs)
        {
            List<int> snapshot = new List<int>();
            for (int i = numDiscs-1; i > 0; i--)
            {
                snapshot.Add(i);
            }
            List<List<int>[]> nSnapshot = new List<List<int>[]>();
            nSnapshot.Add(new List<int>[] { });
            return nSnapshot;
        }
    }
}