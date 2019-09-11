using System.IO;

namespace Assignment1
{
    public static class Assignment1
    {
        public static void PrintIntegers(StreamReader input, StreamWriter output)
        {
            int[] str = new int[5];
            for (int i = 0; i < 5; i++)
            {
                str[i] = int.Parse(input.ReadLine());
            }
            string str2 = "oct";
            str2 = str2.PadLeft(12);
            output.Write(str2);
            str2 = "dec";
            str2 = str2.PadLeft(11);
            output.Write(str2);
            str2 = "hex";
            str2 = str2.PadLeft(9);
            output.WriteLine(str2);
            output.WriteLine("------------ ---------- --------");
            for(int i = 0; i < 5; i++)
            {
                str2 = System.Convert.ToString(str[i],8);
                str2 = str2.PadLeft(12);
                output.Write(str2);

                str2 = str[i].ToString();
                str2 = str2.PadLeft(11);
                output.Write(str2);

                str2 = System.Convert.ToString(str[i], 16);
                str2 = str2.PadLeft(9);
                output.WriteLine(str2);
            }
        }

        public static void PrintStats(StreamReader input, StreamWriter output)
        {
            float[] flo = new float[5];
            string str2;
            for (int i = 0; i < 5; i++)
            {
                flo[i] = float.Parse(input.ReadLine());
            }
            for (int i = 0; i < 5; i++)
            {
                str2 = flo[i].ToString("F3");
                str2 = str2.PadLeft(20);
                output.WriteLine(str2);
            }
            float min = 10000, max = -10000, sum = 0, average = 0;
            for(int i = 0; i< 5; i++)
            {
                if (flo[i] < min) min = flo[i];
                if (flo[i] > max) max = flo[i];
                sum += flo[i];
            }
            average = sum / 5;

            str2 = min.ToString("F3");
            str2 = str2.PadLeft(17);
            output.Write("Min");
            output.WriteLine(str2);

            str2 = max.ToString("F3");
            str2 = str2.PadLeft(17);
            output.Write("Max");
            output.WriteLine(str2);

            str2 = sum.ToString("F3");
            str2 = str2.PadLeft(17);
            output.Write("Sum");
            output.WriteLine(str2);

            str2 = average.ToString("F3");
            str2 = str2.PadLeft(13);
            output.Write("Average");
            output.WriteLine(str2);
        }
    }
}