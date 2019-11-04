namespace Lab8
{
    public static class Lab8
    {
        public static string PrettifyList(string s)
        {

            int n1Count = 1;
            int n2Count = 96;
            string rString = "1) ";
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == '|')
                {
                    n1Count++;
                    n2Count = 96;
                    rString += "\r\n";
                    rString += n1Count;
                    rString += ") ";
                }
                else if (s[i] == '_')
                {
                    n2Count++;
                    rString += "\r\n    ";
                    rString += (char)n2Count;
                    rString += ") ";
                }
                else if (s[i] == '/')
                {
                    rString += "\r\n        ";
                    rString += "- ";
                }
                else
                {
                    rString += s[i];
                }
            }
            rString += "\r\n";
            return rString;
        }
    }
}