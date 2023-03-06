using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Bai07
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Text = "Clock";
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.Clock.Text = DateTime.Now.ToString("HH:mm:ss");
        }
    }
}