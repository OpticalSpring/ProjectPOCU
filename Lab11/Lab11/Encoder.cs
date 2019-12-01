﻿using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace Lab11
{
    public static class Encoder
    {
        public static bool TryEncode(Stream input, Stream output)
        {
            if (input.Length == 0 || input == null)
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
                if (charArray[i] != lastChar)
                {
                    
                    rStr += count.ToString("X2").PadLeft(2, '0') + " " + ((int)lastChar).ToString("X2").PadLeft(2, '0') + " ";
                    lastChar = charArray[i];
                    count = 1;
                }
                else
                {
                    if (count >= 255)
                    {
                        rStr += count.ToString("X2").PadLeft(2, '0') + " " + ((int)lastChar).ToString("X2").PadLeft(2, '0') + " ";
                        lastChar = charArray[i];
                        count = 1;
                    }
                    else
                    {
                        count++;
                    }
                }
            }
            Console.WriteLine(rStr);
            for (int i = 0; i < rStr.Length; i++)
            {
                output.WriteByte((byte)rStr[i]);
            }
            input.Position = 0;
            output.Position = 0;

            return true;
        }

        public static bool TryDecode(Stream input, Stream output)
        {
            if (input.Length == 0 || input == null)
            {
                return false;
            }
            string str = "";
            for (int i = 0; i < input.Length; i++)
            {
                str += input.ReadByte() + "/";
            }
            //Console.WriteLine(str);
            string rStr = "";
            string nav = "";
            int count = 0;
            int a = 0;

            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == '/')
                {
                    a++;
                    if (a % 2 == 1)
                    {
                        count = int.Parse(nav);
                        nav = "";
                    }
                    else
                    {
                        for (int j = 0; j < count; j++)
                        {
                            rStr += (char)int.Parse(nav);
                        }
                        nav = "";
                    }

                }
                else
                {
                    nav += str[i];
                }
            }
            //Console.WriteLine(rStr);

            for (int i = 0; i < rStr.Length; i++)
            {
                output.WriteByte((byte)rStr[i]);
            }
            input.Position = 0;
            output.Position = 0;
            return true;
        }
    }
}