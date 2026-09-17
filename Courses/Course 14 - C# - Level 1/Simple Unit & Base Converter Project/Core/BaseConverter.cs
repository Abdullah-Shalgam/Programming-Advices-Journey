using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace UnitAndBaseConverter.Core
{
    public static class BaseConverter
    {
        private static readonly Dictionary<NumBase, Regex> BaseValidationRules = new Dictionary<NumBase, Regex>
        {
            { NumBase.Binary, new Regex("^[01]+$", RegexOptions.Compiled) },
            { NumBase.Octal, new Regex("^[0-7]+$", RegexOptions.Compiled) },
            { NumBase.Decimal, new Regex("^[0-9]+$", RegexOptions.Compiled) },
            { NumBase.Hexadecimal, new Regex("^[0-9a-fA-F]+$", RegexOptions.Compiled) }
        };

        public static bool IsValidChar(char c, NumBase currentBase)
        {
            if (char.IsControl(c)) return true;

            switch (currentBase)
            {
                case NumBase.Binary:
                    return c == '0' || c == '1';
                case NumBase.Octal:
                    return c >= '0' && c <= '7';
                case NumBase.Decimal:
                    return char.IsDigit(c);
                case NumBase.Hexadecimal:
                    return char.IsDigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
                default:
                    return false;
            }
        }

        public static bool IsValidInput(string input, NumBase currentBase)
        {
            if (string.IsNullOrWhiteSpace(input)) return false;
            return BaseValidationRules[currentBase].IsMatch(input.Trim());
        }

        public static bool TryConvertBase(string inputNumber, NumBase fromBase, NumBase toBase, out string result)
        {
            result = string.Empty;
            if (string.IsNullOrWhiteSpace(inputNumber)) return false;

            try
            {
                inputNumber = inputNumber.Trim();
                if (!IsValidInput(inputNumber, fromBase)) return false;

                ulong decimalValue = ParseToUInt64(inputNumber, (int)fromBase);
                result = ToBaseString(decimalValue, (int)toBase);
                return true;
            }
            catch
            {
                result = string.Empty;
                return false;
            }
        }

        public static Dictionary<NumBase, string> ConvertToAllBases(string inputNumber, NumBase fromBase)
        {
            Dictionary<NumBase, string> results = new Dictionary<NumBase, string>
            {
                { NumBase.Binary, "0" },
                { NumBase.Octal, "0" },
                { NumBase.Decimal, "0" },
                { NumBase.Hexadecimal, "0" }
            };

            if (string.IsNullOrWhiteSpace(inputNumber) || !IsValidInput(inputNumber, fromBase))
                return results;

            try
            {
                ulong decimalVal = ParseToUInt64(inputNumber.Trim(), (int)fromBase);
                results[NumBase.Binary] = FormatBinary(ToBaseString(decimalVal, 2));
                results[NumBase.Octal] = ToBaseString(decimalVal, 8);
                results[NumBase.Decimal] = decimalVal.ToString("N0");
                results[NumBase.Hexadecimal] = "0x" + ToBaseString(decimalVal, 16);
            }
            catch
            {
                // Fallback on overflow
            }

            return results;
        }

        private static ulong ParseToUInt64(string value, int fromBase)
        {
            return Convert.ToUInt64(value, fromBase);
        }

        private static string ToBaseString(ulong value, int toBase)
        {
            if (value == 0) return "0";

            const string chars = "0123456789ABCDEF";
            string result = string.Empty;

            while (value > 0)
            {
                result = chars[(int)(value % (ulong)toBase)] + result;
                value /= (ulong)toBase;
            }

            return result;
        }

        private static string FormatBinary(string binary)
        {
            int mod = binary.Length % 4;
            if (mod > 0) binary = new string('0', 4 - mod) + binary;

            List<string> chunks = new List<string>();
            for (int i = 0; i < binary.Length; i += 4)
            {
                chunks.Add(binary.Substring(i, 4));
            }
            return string.Join(" ", chunks.ToArray());
        }
    }
}