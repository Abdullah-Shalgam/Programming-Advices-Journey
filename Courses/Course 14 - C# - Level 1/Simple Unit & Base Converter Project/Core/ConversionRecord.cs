using System;

namespace UnitAndBaseConverter.Core
{
    public class ConversionRecord
    {
        public string Id { get; set; } = Guid.NewGuid().ToString("N").Substring(0, 8);
        public DateTime Timestamp { get; set; } = DateTime.Now;
        public string OperationType { get; set; }
        public string SourceValue { get; set; }
        public string SourceType { get; set; }
        public string ResultValue { get; set; }
        public string ResultType { get; set; }

        public string Summary => $"{SourceValue} [{SourceType}] ➔ {ResultValue} [{ResultType}]";

        public override string ToString()
        {
            return $"[{Timestamp:HH:mm:ss}] ({OperationType}) {Summary}";
        }

        public string ToCsvLine()
        {
            return $"\"{Timestamp:yyyy-MM-dd HH:mm:ss}\",\"{OperationType}\",\"{SourceValue}\",\"{SourceType}\",\"{ResultValue}\",\"{ResultType}\"";
        }
    }
}