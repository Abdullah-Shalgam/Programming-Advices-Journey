using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace UnitAndBaseConverter
{
    internal static class Program
    {
        [DllImport("user32.dll")]
        private static extern bool SetProcessDPIAware();

        [STAThread]
        static void Main()
        {
            try
            {
                // Ensure High DPI scaling is aware on Windows 10/11
                if (Environment.OSVersion.Version.Major >= 6)
                {
                    SetProcessDPIAware();
                }
            }
            catch
            {
                // Fallback for earlier environments
            }

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}