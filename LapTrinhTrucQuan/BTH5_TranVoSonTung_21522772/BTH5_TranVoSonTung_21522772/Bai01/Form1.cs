using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Bai01
{
    public partial class Form1 : Form
    {
        private float x = 80;
        private float y = 80;

        public Form1()
        {
            InitializeComponent();
            DoubleBuffered = true;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.DrawString("Tôi là tùng", new Font(new FontFamily("Arial"), 15, FontStyle.Regular), Brushes.Red, new PointF(x, y));
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Left)
                x -= 5;
            if (e.KeyCode == Keys.Right)
                x += 5;
            if (e.KeyCode == Keys.Up)
                y -= 5;
            if (e.KeyCode == Keys.Down)
                y += 5;
            Refresh();
        }
    }
}