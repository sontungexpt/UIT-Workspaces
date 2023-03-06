using System.Diagnostics;

namespace Bai1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Move(object sender, EventArgs e)
        {
            Debug.WriteLine("Move event");
            sr.WriteLine("Move event");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Debug.WriteLine("Load event");
            sr.WriteLine("Load event");
        }

        private void Form1_Activated(object sender, EventArgs e)
        {
            Debug.WriteLine("Activated event");
            sr.WriteLine("Activated event");
        }

        private void Form1_VisibleChanged(object sender, EventArgs e)
        {
            Debug.WriteLine("VisibleChanged event");
            sr.WriteLine("VisibleChanged event");
        }

        private void Form1_Shown(object sender, EventArgs e)
        {
            Debug.WriteLine("Shown event");
            sr.WriteLine("Shown event");
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Debug.WriteLine("Paint event");
            sr.WriteLine("Paint event");
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            Debug.WriteLine("FormClosed event");
            sr.WriteLine("FormClosed event");
        }

        private void Form1_Deactivate(object sender, EventArgs e)
        {
            Debug.WriteLine("Deactivate");
            sr.WriteLine("Deactivate");
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            Debug.WriteLine("FormClosing");
            sr.WriteLine("FormClosing");
        }
    }
}