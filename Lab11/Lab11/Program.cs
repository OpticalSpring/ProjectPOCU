using System.Diagnostics;
using System.IO;

namespace Lab11
{
    class Program
    {
        private const string ENCODE_TEST1 = "encode1.txt";
        private const string ENCODE_TEST2 = "encode2.txt";

        private const string DECODE_TEST1 = "decode1.bin";
        private const string DECODE_TEST2 = "decode2.bin";

        private const string EMPTY_ENCODE_TEST = "empty_encode.txt";
        private const string EMPTY_DECODE_TEST = "empty_decode.bin";

        static void Main(string[] args)
        {
            setup();

            using (Stream read = File.OpenRead(ENCODE_TEST1))
            using (Stream write = File.OpenWrite($"{ENCODE_TEST1}.output.bin"))
            {
                bool bEncoded = Encoder.TryEncode(read, write);
                Debug.Assert(bEncoded);
            }

            using (Stream read = File.OpenRead(DECODE_TEST1))
            using (Stream write = File.OpenWrite($"{DECODE_TEST1}.output.txt"))
            {
                bool bEncoded = Encoder.TryDecode(read, write);
                // Check decode1.bin.output.txt. The content should be the same as encode1.txt
                Debug.Assert(bEncoded);
            }

            using (Stream read = File.OpenRead(ENCODE_TEST2))
            using (Stream write = File.OpenWrite($"{ENCODE_TEST2}.output.bin"))
            {
                bool bEncoded = Encoder.TryEncode(read, write);
                Debug.Assert(bEncoded);
            }

            using (Stream read = File.OpenRead(DECODE_TEST2))
            using (Stream write = File.OpenWrite($"{DECODE_TEST2}.output.txt"))
            {
                bool bEncoded = Encoder.TryDecode(read, write);
                // Check decode2.bin.output.txt. The content should be the same as encode2.txt
                Debug.Assert(bEncoded);
            }

            using (Stream read = File.OpenRead(EMPTY_ENCODE_TEST))
            using (Stream write = File.OpenWrite($"{EMPTY_ENCODE_TEST}.output.bin"))
            {
                bool bEncoded = Encoder.TryEncode(read, write);
                Debug.Assert(!bEncoded);
            }

            using (Stream read = File.OpenRead(EMPTY_DECODE_TEST))
            using (Stream write = File.OpenWrite($"{EMPTY_DECODE_TEST}.output.txt"))
            {
                bool bEncoded = Encoder.TryDecode(read, write);
                // Check empty_decode.bin.output.txt. The content should be empty.
                Debug.Assert(!bEncoded);
            }
        }

        private static void setup()
        {
            if (File.Exists($"{ENCODE_TEST1}.output.bin"))
            {
                File.Delete($"{ENCODE_TEST1}.output.bin");
            }

            if (File.Exists($"{DECODE_TEST1}.output.txt"))
            {
                File.Delete($"{DECODE_TEST1}.output.txt");
            }

            if (File.Exists($"{ENCODE_TEST2}.output.bin"))
            {
                File.Delete($"{ENCODE_TEST2}.output.bin");
            }

            if (File.Exists($"{DECODE_TEST2}.output.txt"))
            {
                File.Delete($"{DECODE_TEST2}.output.txt");
            }

            if (File.Exists($"{EMPTY_ENCODE_TEST}.output.bin"))
            {
                File.Delete($"{EMPTY_ENCODE_TEST}.output.bin");
            }

            if (File.Exists($"{EMPTY_DECODE_TEST}.output.txt"))
            {
                File.Delete($"{EMPTY_DECODE_TEST}.output.txt");
            }
        }
    }
}