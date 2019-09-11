using System;
using System.IO;

namespace Assignment1
{
    class Program
    {
        static void Main(string[] args)
        {
            // using 문에 대해서는 아직 고민하지 마세요. 나중에 배웁니다.
            using (StreamReader READER = new StreamReader(Console.OpenStandardInput()))
            using (StreamWriter WRITER = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = true })
            {
                Console.WriteLine("Enter your 5 digits for PrintIntegers():");
                Assignment1.PrintIntegers(READER, WRITER);

                Console.WriteLine("Enter your 5 digits for PrintStats():");
                Assignment1.PrintStats(READER, WRITER);
            }
        }
    }
}