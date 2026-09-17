using System;
using System.Collections.Generic;

namespace UnitAndBaseConverter.Core
{
    public static class UnitConverter
    {
        private static readonly Dictionary<string, double> LengthFactors = new Dictionary<string, double>
        {
            { "Meter (m)", 1.0 },
            { "Kilometer (km)", 1000.0 },
            { "Centimeter (cm)", 0.01 },
            { "Millimeter (mm)", 0.001 },
            { "Micrometer (μm)", 1e-6 },
            { "Nanometer (nm)", 1e-9 },
            { "Mile (mi)", 1609.344 },
            { "Yard (yd)", 0.9144 },
            { "Foot (ft)", 0.3048 },
            { "Inch (in)", 0.0254 },
            { "Nautical Mile (NM)", 1852.0 }
        };

        private static readonly Dictionary<string, double> MassFactors = new Dictionary<string, double>
        {
            { "Kilogram (kg)", 1.0 },
            { "Gram (g)", 0.001 },
            { "Milligram (mg)", 1e-6 },
            { "Metric Ton (t)", 1000.0 },
            { "Pound (lb)", 0.45359237 },
            { "Ounce (oz)", 0.028349523125 },
            { "Stone (st)", 6.35029318 },
            { "Carat (ct)", 0.0002 }
        };

        private static readonly Dictionary<string, double> DigitalStorageFactors = new Dictionary<string, double>
        {
            { "Bit (b)", 0.125 },
            { "Byte (B)", 1.0 },
            { "Kilobyte (KB)", 1024.0 },
            { "Megabyte (MB)", Math.Pow(1024, 2) },
            { "Gigabyte (GB)", Math.Pow(1024, 3) },
            { "Terabyte (TB)", Math.Pow(1024, 4) },
            { "Petabyte (PB)", Math.Pow(1024, 5) }
        };

        private static readonly Dictionary<string, double> DataSpeedFactors = new Dictionary<string, double>
        {
            { "Bits per second (bps)", 1.0 },
            { "Kilobits per sec (Kbps)", 1000.0 },
            { "Megabits per sec (Mbps)", 1000000.0 },
            { "Gigabits per sec (Gbps)", 1000000000.0 },
            { "Bytes per second (B/s)", 8.0 },
            { "Kilobytes per sec (KB/s)", 8000.0 },
            { "Megabytes per sec (MB/s)", 8000000.0 },
            { "Gigabytes per sec (MB/s)", 8000000000.0 }
        };

        private static readonly Dictionary<string, double> TimeFactors = new Dictionary<string, double>
        {
            { "Nanosecond (ns)", 1e-9 },
            { "Microsecond (μs)", 1e-6 },
            { "Millisecond (ms)", 0.001 },
            { "Second (s)", 1.0 },
            { "Minute (min)", 60.0 },
            { "Hour (hr)", 3600.0 },
            { "Day (d)", 86400.0 },
            { "Week (wk)", 604800.0 },
            { "Year (yr)", 31536000.0 }
        };

        private static readonly Dictionary<string, double> PressureFactors = new Dictionary<string, double>
        {
            { "Pascal (Pa)", 1.0 },
            { "Kilopascal (kPa)", 1000.0 },
            { "Bar", 100000.0 },
            { "PSI (lbf/in²)", 6894.75729 },
            { "Atmosphere (atm)", 101325.0 },
            { "Torr / mmHg", 133.322368 }
        };

        private static readonly Dictionary<string, double> PowerFactors = new Dictionary<string, double>
        {
            { "Watt (W)", 1.0 },
            { "Kilowatt (kW)", 1000.0 },
            { "Megawatt (MW)", 1000000.0 },
            { "Mechanical Horsepower (hp)", 745.699872 },
            { "Metric Horsepower (PS)", 735.49875 },
            { "BTU / Hour", 0.293071 }
        };

        public static List<string> GetUnits(UnitCategory category)
        {
            switch (category)
            {
                case UnitCategory.Length:
                    return new List<string>(LengthFactors.Keys);
                case UnitCategory.Mass:
                    return new List<string>(MassFactors.Keys);
                case UnitCategory.Temperature:
                    return new List<string> { "Celsius (°C)", "Fahrenheit (°F)", "Kelvin (K)", "Rankine (°R)" };
                case UnitCategory.DigitalStorage:
                    return new List<string>(DigitalStorageFactors.Keys);
                case UnitCategory.DataSpeed:
                    return new List<string>(DataSpeedFactors.Keys);
                case UnitCategory.Time:
                    return new List<string>(TimeFactors.Keys);
                case UnitCategory.Pressure:
                    return new List<string>(PressureFactors.Keys);
                case UnitCategory.Power:
                    return new List<string>(PowerFactors.Keys);
                default:
                    return new List<string>();
            }
        }

        public static double ConvertUnit(double value, string fromUnit, string toUnit, UnitCategory category)
        {
            if (string.Equals(fromUnit, toUnit, StringComparison.OrdinalIgnoreCase))
                return value;

            if (category == UnitCategory.Temperature)
            {
                return ConvertTemperature(value, fromUnit, toUnit);
            }

            Dictionary<string, double> factors;
            switch (category)
            {
                case UnitCategory.Length:
                    factors = LengthFactors;
                    break;
                case UnitCategory.Mass:
                    factors = MassFactors;
                    break;
                case UnitCategory.DigitalStorage:
                    factors = DigitalStorageFactors;
                    break;
                case UnitCategory.DataSpeed:
                    factors = DataSpeedFactors;
                    break;
                case UnitCategory.Time:
                    factors = TimeFactors;
                    break;
                case UnitCategory.Pressure:
                    factors = PressureFactors;
                    break;
                case UnitCategory.Power:
                    factors = PowerFactors;
                    break;
                default:
                    throw new ArgumentException("Unsupported unit category");
            }

            if (!factors.TryGetValue(fromUnit, out double fromFactor) || !factors.TryGetValue(toUnit, out double toFactor))
                return value;

            double baseValue = value * fromFactor;
            return baseValue / toFactor;
        }

        private static double ConvertTemperature(double value, string fromUnit, string toUnit)
        {
            double celsius = value;
            switch (fromUnit)
            {
                case "Fahrenheit (°F)":
                    celsius = (value - 32.0) * 5.0 / 9.0;
                    break;
                case "Kelvin (K)":
                    celsius = value - 273.15;
                    break;
                case "Rankine (°R)":
                    celsius = (value - 491.67) * 5.0 / 9.0;
                    break;
                default:
                    celsius = value;
                    break;
            }

            switch (toUnit)
            {
                case "Fahrenheit (°F)":
                    return (celsius * 9.0 / 5.0) + 32.0;
                case "Kelvin (K)":
                    return celsius + 273.15;
                case "Rankine (°R)":
                    return (celsius + 273.15) * 9.0 / 5.0;
                default:
                    return celsius;
            }
        }
    }
}