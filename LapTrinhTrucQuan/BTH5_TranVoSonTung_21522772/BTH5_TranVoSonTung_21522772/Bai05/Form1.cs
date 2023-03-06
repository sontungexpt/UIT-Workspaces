using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Bai05
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.DrawString("ĐH CNTT",
                new Font(new FontFamily("Times new roman"), 12),
                Brushes.LightCoral,
                new PointF(10, 10));
            g.DrawString("ĐH CNTT",
                new Font(new FontFamily("Arial"), 28),
                Brushes.Blue,
                new PointF(10, 30));
            g.DrawString("ĐH CNTT",
                new Font(new FontFamily("Arial"), 34, FontStyle.Italic),
                Brushes.PowderBlue,
                new PointF(10, 70));
            g.DrawString("ĐH CNTT",
                new Font(new FontFamily("Arial"), 60, FontStyle.Bold),
                Brushes.HotPink,
                new PointF(10, 110));
        }
    }
}