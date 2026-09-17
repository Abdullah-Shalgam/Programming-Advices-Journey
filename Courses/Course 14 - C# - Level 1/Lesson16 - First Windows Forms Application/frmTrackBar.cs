using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace Lesson16___First_Windows_Forms_Application
{
    public partial class frmTrackBar : Form
    {
        [DllImport("user32.dll")]
        public static extern IntPtr SendMessageW(IntPtr hWnd, int Msg, IntPtr wParam, IntPtr lParam);

        private const int WM_APPCOMMAND = 0x319;
        private const int APPCOMMAND_VOLUME_UP = 0xA0000;
        private const int APPCOMMAND_VOLUME_DOWN = 0x90000;

        private int lastValue = 0;



        public frmTrackBar()
        {
            InitializeComponent();
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            int difference = trackBar1.Value - lastValue;

            if (difference > 0)
            {
                for (int i = 0; i < difference; i++)
                {
                    SendMessageW(this.Handle, WM_APPCOMMAND, this.Handle, (IntPtr)APPCOMMAND_VOLUME_UP);
                }
            }
            else if (difference < 0)
            {
                for (int i = 0; i < Math.Abs(difference); i++)
                {
                    SendMessageW(this.Handle, WM_APPCOMMAND, this.Handle, (IntPtr)APPCOMMAND_VOLUME_DOWN);
                }
            }

            lastValue = trackBar1.Value;
        }

        private void frmTrackBar_Load(object sender, EventArgs e)
        {
            trackBar1.Minimum = 0;
            trackBar1.Maximum = 100;

            int currentSystemVolume = GetSystemVolumePercentage();

            trackBar1.Value = currentSystemVolume;
            lastValue = trackBar1.Value;
        }

        private static int GetSystemVolumePercentage()
        {
            try
            {
                Type MMDeviceEnumeratorType = Type.GetTypeFromProgID("MMDeviceEnumerator") ??
                    Type.GetTypeFromCLSID(new Guid("BCDE0395-E52F-467C-8E3D-C4579291692E"));

                if (MMDeviceEnumeratorType == null) return 50;

                dynamic enumerator = Activator.CreateInstance(MMDeviceEnumeratorType);
                dynamic device = enumerator.GetDefaultAudioEndpoint(0, 1);
                dynamic volume = device.Activate(new Guid("5CDF2C82-841E-4546-9722-0CF74078229A"), 7, IntPtr.Zero);

                float currentVolumeScalar = volume.GetMasterVolumeLevelScalar();
                return (int)(currentVolumeScalar * 100);
            }
            catch
            {
                return 50;
            }
        }
    }
}
