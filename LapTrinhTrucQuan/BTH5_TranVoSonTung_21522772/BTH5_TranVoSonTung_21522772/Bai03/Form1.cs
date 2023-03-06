using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Bai03
{
    public partial class Form1 : Form
    {
        private int r = 15;
        private int x = -100;
        private int y = -100;

        public Form1()
        {
            InitializeComponent();
            DoubleBuffered = true;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            if (x != -100)
            {
                g.FillEllipse(Brushes.Green, new Rectangle(x - r, y - r, r * 2, r * 2));
            }
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            if (x == -100)
            {
                x = e.X;
                y = e.Y;
                Refresh();
            }
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (x != -100)
            {
                if (e.KeyChar == '+')
                    r += 10;
                if (e.KeyChar == '-')
                    r -= 10;
                if (r < 0)
                    r += 10;
                if (r > 200)
                    r -= 10;
                Refresh();
            }
        }
    }
}