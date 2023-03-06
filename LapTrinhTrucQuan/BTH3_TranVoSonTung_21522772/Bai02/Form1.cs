using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Design;
using System.Diagnostics;

namespace Bai2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        public void Form1_Paint(object sender, PaintEventArgs e)
        {
            Random r = new Random();
            int x = r.Next(0, 400);
            int y = r.Next(0, 200);
            Graphics g = e.Graphics;
            Brush brush = new SolidBrush(Color.Red);
            g.DrawString("Paint Event ", new Font("Time New Roman", 12), brush, x, y);
        }
        private void f_Activated(object sender, EventArgs e)
        {
            Debug.WriteLine("Su kien paint hoat dong");
        }
        private void f_deactivated(object sender, EventArgs e)
        {
            Debug.WriteLine("su kien paint ko hoat dong");
        }
        private void f_shown(object sender, EventArgs e)
        {
            Debug.WriteLine("Su kien Paint xay ra");
        }
    }
}