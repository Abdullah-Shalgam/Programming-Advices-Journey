
//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

using System;

namespace Main
{
    internal class Program
    {

        static void Main(string[] args)
        {

            //  String Interpolation

            string firstName = "Mohammed";
            string lastName = "Abu-Hadhoud";
            int code = 107;

            //You shold use $ to $ to identify an interpolated string 
            string fullName = $"Mr. {firstName} {lastName}, Code: {code:D4}";

            Console.WriteLine(fullName);

            Console.ReadKey();

        }
    }
}

