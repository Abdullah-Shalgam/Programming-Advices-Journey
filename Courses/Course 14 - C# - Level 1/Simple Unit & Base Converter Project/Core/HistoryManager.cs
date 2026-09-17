using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace UnitAndBaseConverter.Core
{
    public class HistoryManager
    {
        private readonly List<ConversionRecord> _records = new List<ConversionRecord>();
        private readonly object _lock = new object();

        public event EventHandler HistoryChanged;

        public void AddRecord(string operationType, string sourceVal, string sourceType, string resultVal, string resultType)
        {
            lock (_lock)
            {
                var record = new ConversionRecord
                {
                    OperationType = operationType,
                    SourceValue = sourceVal,
                    SourceType = sourceType,
                    ResultValue = resultVal,
                    ResultType = resultType
                };

                _records.Insert(0, record);

                if (_records.Count > 500)
                {
                    _records.RemoveAt(_records.Count - 1);
                }
            }

            HistoryChanged?.Invoke(this, EventArgs.Empty);
        }

        public IReadOnlyList<ConversionRecord> GetRecords(string filterText = null)
        {
            lock (_lock)
            {
                if (string.IsNullOrWhiteSpace(filterText))
                    return _records.ToList();

                string term = filterText.Trim().ToLowerInvariant();
                return _records.Where(r =>
                    r.OperationType.ToLowerInvariant().Contains(term) ||
                    r.SourceValue.ToLowerInvariant().Contains(term) ||
                    r.SourceType.ToLowerInvariant().Contains(term) ||
                    r.ResultValue.ToLowerInvariant().Contains(term) ||
                    r.ResultType.ToLowerInvariant().Contains(term)).ToList();
            }
        }

        public void Clear()
        {
            lock (_lock)
            {
                _records.Clear();
            }
            HistoryChanged?.Invoke(this, EventArgs.Empty);
        }

        public void ExportToCsv(string filePath)
        {
            var sb = new StringBuilder();
            sb.AppendLine("Timestamp,OperationType,SourceValue,SourceType,ResultValue,ResultType");

            lock (_lock)
            {
                foreach (var record in _records)
                {
                    sb.AppendLine(record.ToCsvLine());
                }
            }

            File.WriteAllText(filePath, sb.ToString(), Encoding.UTF8);
        }

        public void ExportToJson(string filePath)
        {
            var sb = new StringBuilder();
            sb.AppendLine("[");

            lock (_lock)
            {
                for (int i = 0; i < _records.Count; i++)
                {
                    var r = _records[i];
                    sb.AppendLine("  {");
                    sb.AppendLine($"    \"id\": \"{r.Id}\",");
                    sb.AppendLine($"    \"timestamp\": \"{r.Timestamp:O}\",");
                    sb.AppendLine($"    \"operationType\": \"{EscapeJson(r.OperationType)}\",");
                    sb.AppendLine($"    \"sourceValue\": \"{EscapeJson(r.SourceValue)}\",");
                    sb.AppendLine($"    \"sourceType\": \"{EscapeJson(r.SourceType)}\",");
                    sb.AppendLine($"    \"resultValue\": \"{EscapeJson(r.ResultValue)}\",");
                    sb.AppendLine($"    \"resultType\": \"{EscapeJson(r.ResultType)}\"");
                    sb.Append(i == _records.Count - 1 ? "  }" : "  },");
                    sb.AppendLine();
                }
            }

            sb.AppendLine("]");
            File.WriteAllText(filePath, sb.ToString(), Encoding.UTF8);
        }

        private static string EscapeJson(string s) => s?.Replace("\\", "\\\\").Replace("\"", "\\\"") ?? string.Empty;
    }
}