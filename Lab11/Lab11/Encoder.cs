using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace Lab11
{
    public static class Encoder
    {
        public static bool TryEncode(Stream input, Stream output)
        {
            if(input.Length == 0 || input == null)
            {
                return false;
            }
            char[] charArray = new char[input.Length + 1];
            for (int i = 0; i < input.Length; i++)
            {
                charArray[i] = (char)input.ReadByte();
            }
            charArray[input.Length] = ' ';
            Console.WriteLine(charArray);

            string rStr = "";
            int count = 0;
            char lastChar = charArray[1];
            for (int i = 0; i < charArray.Length; i++)
            {
                if(charArray[i] != lastChar)
                {
                    rStr += Convert.ToString(count, 16).PadLeft(2, '0') + " " + Convert.ToString(lastChar, 16).PadLeft(2, '0') + " ";
                    lastChar = charArray[i];
                    count = 1;
                }
                else
                {
                    count++;
                }
            }
            Console.WriteLine(rStr);
            for (int i = 0; i < rStr.Length; i++)
            {
                output.WriteByte((byte)rStr[i]);
            }
            input.Position = 0;
            output.Position = 0;

            Console.WriteLine(output);
            return true;
        }

        public static bool TryDecode(Stream input, Stream output)
        {
            return false;
        }
    }
}
