using System;
namespace Lab7
{
    public static class Lab7
    {
        static int count = 0;
        public static bool PlayGame(uint[] array)
        {
            count = 0;
            if (PlayGame2(array) == true)
            {
                Console.WriteLine("True");
                return true;
            }
            Console.WriteLine("False");
            return false;
        }

        public static bool PlayGame2(uint[] array)
        {
            for (int i = 0; i < array.GetLength(0); i++)
            {
                Console.Write("{0}", array[i]);
            }
            Console.WriteLine();

            if (count > 30)
            {
                Console.WriteLine("InfinityStop");
                return false;
            }
            if (array.GetLength(0) < 2 || array[0] >= array.GetLength(0) || array[0] <= 0 || array[array.GetLength(0) - 1] != 0)
            {
                Console.WriteLine("Error");
                return false;
            }

            uint shift = array[0] + array[array[0]];
            uint shift2 = array[0] - array[array[0]];

            if (shift2 > 0 && shift2 < array.GetLength(0) && count < 15)
            {
                if (array[shift2] == 0)
                {
                    Console.WriteLine("Tr");
                    return true;
                }
                else
                {
                    count++;
                    Console.WriteLine("LShift");
                    uint[] newArray = array;
                    newArray[0] = shift2;

                    if (PlayGame2(newArray) == true)
                    {
                        return true;
                    }
                }
            }
            if (shift < array.GetLength(0))
            {
                if (array[shift] == 0)
                {
                    Console.WriteLine("Tr");
                    return true;
                }
                else
                {
                    count++;
                    Console.WriteLine("RShift");
                    uint[] newArray = array;
                    newArray[0] = shift;
                    if (PlayGame2(newArray) == true)
                    {
                        return true;
                    }
                }
            }
            Console.WriteLine("Fa");
            return false;
        }
    }
}


