using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.StartPanel;

namespace Bai03
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.Width = 800;
            this.Height = 500;
        }

        private void fileToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }

        private void OpenFile_Click(object sender, EventArgs e)
        {
            mediaPlayer.Ctlcontrols.stop();
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "MP3, MP4 files (*.mp3, *.mp4)|*.mp3;*.mp4|All files (*.*)|*.*";
            openFileDialog.FilterIndex = 1;
            if (openFileDialog.ShowDialog() == DialogResult.OK)
                PlayFile(openFileDialog.FileName);
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void MediaState_Change(object sender, AxWMPLib._WMPOCXEvents_PlayStateChangeEvent e)
        {
        }

        private void PlayFile(string url)
        {
            mediaPlayer.URL = url;
        }

        private void ShowFileName(Label name)
        {
            //string file = Path.GetFileName(PlayList.SelectedItem.ToString());
            //name.Text = "Currently Playing: " + file;
        }

        public void timer1_Tick(object sender, EventArgs e)
        {
            statusStrip.Text = $"Hôm nay là ngày: {DateTime.Now.ToString("dd/MM/yyyy")} - Bây giờ là: {DateTime.Now.ToString("T")}";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            System.Timers.Timer timer = new System.Timers.Timer(1000);
            timer.Elapsed += new ElapsedEventHandler(timer1_Tick);
        }
    }
}