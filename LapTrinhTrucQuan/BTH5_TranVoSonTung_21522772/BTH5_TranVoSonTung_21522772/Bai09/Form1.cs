using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Bai09
{
    public partial class Form1 : Form
    {
        private int idShape = 0;

        public Form1()
        {
            InitializeComponent();
            comboBox1.SelectedIndex = 0;
            DoubleBuffered = true;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            idShape = comboBox1.SelectedIndex;
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            Pen pen = new Pen(Brushes.Blue, 2);
            switch (idShape)
            {
                case 0:
                    g.DrawEllipse(pen, new Rectangle(70, 70, 150, 150));
                    break;

                case 1:
                    g.DrawRectangle(pen, new Rectangle(70, 70, 150, 150));
                    break;

                case 2:
                    g.DrawEllipse(pen, new Rectangle(70, 70, 180, 140));
                    break;

                case 3:
                    g.FillEllipse(Brushes.Violet, new Rectangle(70, 70, 150, 150));
                    break;

                case 4:
                    g.FillRectangle(Brushes.Violet, new Rectangle(70, 70, 150, 150));
                    break;

                case 5:
                    g.FillEllipse(Brushes.Violet, new Rectangle(70, 70, 180, 140));
                    break;
            }
        }
    }
}