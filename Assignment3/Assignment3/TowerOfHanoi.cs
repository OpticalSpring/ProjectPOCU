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
            hanoi(ref count, numDiscs, 1, 3, 2);
            return count;
        }

        public static void hanoi(ref int count, int num, int from, int to, int other)
        {
            if (num == 0) { return; }
            hanoi(ref count, num - 1, from, other, to);
            count++;
            Console.WriteLine("{0}->{1} - {2}", from, to, count);
            hanoi(ref count, num - 1, other, to, from);
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
            for (int i = 0; i < numDiscs; i++)
            {
                nSnapshot[0][0].Add(numDiscs - i);
            }
            int count = 0;
            
            hanoiPlus(ref count, numDiscs, 1, 3, 2, ref nSnapshot);
            return nSnapshot;
        }


        public static void hanoiPlus(ref int count, int num, int from, int to, int other, ref List<List<int>[]> nSnapshot)
        {
            if (num == 0) { return; }
            hanoiPlus(ref count, num - 1, from, other, to, ref nSnapshot);
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
            Console.WriteLine("Copy {0}->{1}", count - 1, count);

            nSnapshot[count][to - 1].Add(num);
            nSnapshot[count][from - 1].Remove(num);
            Console.WriteLine($"Step {count}. --------------------------------------");
            Console.WriteLine($"Start: [ {string.Join(", ", nSnapshot[count][0])} ]");
            Console.WriteLine($"Aux: [ {string.Join(", ", nSnapshot[count][1])} ]");
            Console.WriteLine($"End: [ {string.Join(", ", nSnapshot[count][2])} ]");
            hanoiPlus(ref count, num - 1, other, to, from, ref nSnapshot);
        }

        private static void printSnapshots(List<List<int>[]> snapshots)
        {
            for (int i = 0; i < snapshots.Count; i++)
            {
                if (i == 0)
                {
                    Console.WriteLine($"Initial State --------------------------------------");
                }
                else
                {
                    Console.WriteLine($"Step {i}. --------------------------------------");
                }

                Console.WriteLine($"Start: [ {string.Join(", ", snapshots[i][0])} ]");
                Console.WriteLine($"Aux: [ {string.Join(", ", snapshots[i][1])} ]");
                Console.WriteLine($"End: [ {string.Join(", ", snapshots[i][2])} ]");
            }
        }
    }
}