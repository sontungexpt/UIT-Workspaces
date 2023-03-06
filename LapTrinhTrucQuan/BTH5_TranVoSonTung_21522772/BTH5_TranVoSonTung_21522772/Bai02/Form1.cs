using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Bai02
{
    public partial class Form1 : Form
    {
        private int size = 50;
        private int x = 0;
        private int y = 0;
        private bool isPress = false;
        private int offsetX = 0;
        private int offsetY = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.FillRectangle(Brushes.BlueViolet, new Rectangle(x, y, size, size));
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.X >= x && e.X <= x + size && e.Y >= y && e.Y <= y + size)
            {
                isPress = true;
                offsetX = e.X - x;
                offsetY = e.Y - y;
            }
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            isPress = false;
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (isPress)
            {
                x = e.X - offsetX;
                y = e.Y - offsetY;
                Refresh();
            }
        }
    }
}