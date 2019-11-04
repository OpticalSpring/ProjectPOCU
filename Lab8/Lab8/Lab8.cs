namespace Lab8
{
    public static class Lab8
    {
        public static string PrettifyList(string s)
        {
            int n1Count = 1;
            string rString = "1) ";
            for(int i = 0; i < s.Length; i++)
            {
                if(s[i] == '|')
                {
                    n1Count++;
                    rString += "\n";
                    rString += n1Count;
                    rString += ") ";
                }
                else
                {
                    rString += s[i];
                }
            }
            rString += "\n";
            return rString;
        }
    }
}