using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Bai08
{
    public partial class Form1 : Form
    {
        private int rClock = 160;
        private int center = 200;
        private DateTime now;

        public Form1()
        {
            InitializeComponent();
            this.ClientSize = new Size(400, 400);
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
            this.BackColor = Color.Black;
            now = DateTime.Now;
            timer1.Start();
            DoubleBuffered = true;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            g.FillRectangle(Brushes.White, new Rectangle(center - 2, center - 2, 4, 4));
            // Ve mat dong ho
            for (int angle = 0; angle < 360; angle += 6)
            {
                int x = (int)(rClock * Math.Cos(angle * Math.PI / 180)) + center;
                int y = (int)(rClock * Math.Sin(angle * Math.PI / 180)) + center;
                g.FillRectangle(Brushes.White, new Rectangle(x - 2, y - 2, 4, 4));
            }
            for (int angle = 0; angle < 360; angle += 30)
            {
                int x = (int)(rClock * Math.Cos(angle * Math.PI / 180)) + center;
                int y = (int)(rClock * Math.Sin(angle * Math.PI / 180)) + center;
                g.FillEllipse(Brushes.White, new Rectangle(x - 6, y - 6, 12, 12));
            }

            // Ve kim giay
            int angleSec = now.Second * 6 - 90;
            int xSec = (int)((rClock - 10) * Math.Cos(angleSec * Math.PI / 180)) + center;
            int ySec = (int)((rClock - 10) * Math.Sin(angleSec * Math.PI / 180)) + center;
            Pen thinLine = new Pen(Color.White, 1);
            g.DrawLine(thinLine, new Point(center, center), new Point(xSec, ySec));
            drawMin(g);
            drawHour(g);
        }

        private void drawMin(Graphics g)
        {
            double angleMin = now.Minute * 6 + ((double)now.Second / 60) * 6 - 90;

            Pen thinLine = new Pen(Color.Violet, 1);
            Point point1 = new Point(
                (int)((rClock - 30) * Math.Cos(angleMin * Math.PI / 180)) + center,
                (int)((rClock - 30) * Math.Sin(angleMin * Math.PI / 180)) + center
            );
            Point point2 = new Point(
                -(int)(40 * Math.Cos(angleMin * Math.PI / 180)) + center,
                -(int)(40 * Math.Sin(angleMin * Math.PI / 180)) + center
            );
            Point point3 = new Point(
                (int)(6 * Math.Cos((angleMin + 90) * Math.PI / 180)) + center,
                (int)(6 * Math.Sin((angleMin + 90) * Math.PI / 180)) + center
            );
            Point point4 = new Point(
                (int)(6 * Math.Cos((angleMin - 90) * Math.PI / 180)) + center,
                (int)(6 * Math.Sin((angleMin - 90) * Math.PI / 180)) + center
            );
            g.DrawLine(thinLine, point4, point1);
            g.DrawLine(thinLine, point4, point2);
            g.DrawLine(thinLine, point3, point1);
            g.DrawLine(thinLine, point3, point2);
        }

        private void drawHour(Graphics g)
        {
            double angleHour = now.Hour * 30 + ((double)now.Minute / 60) * 30 - 90;
            Pen thinLine = new Pen(Color.Purple, 1);
            Point point1 = new Point(
                (int)((rClock - 60) * Math.Cos(angleHour * Math.PI / 180)) + center,
                (int)((rClock - 60) * Math.Sin(angleHour * Math.PI / 180)) + center
            );
            Point point2 = new Point(
                -(int)(20 * Math.Cos(angleHour * Math.PI / 180)) + center,
                -(int)(20 * Math.Sin(angleHour * Math.PI / 180)) + center
            );
            Point point3 = new Point(
                (int)(10 * Math.Cos((angleHour + 90) * Math.PI / 180)) + center,
                (int)(10 * Math.Sin((angleHour + 90) * Math.PI / 180)) + center
            );
            Point point4 = new Point(
                (int)(10 * Math.Cos((angleHour - 90) * Math.PI / 180)) + center,
                (int)(10 * Math.Sin((angleHour - 90) * Math.PI / 180)) + center
            );
            g.DrawLine(thinLine, point4, point1);
            g.DrawLine(thinLine, point4, point2);
            g.DrawLine(thinLine, point3, point1);
            g.DrawLine(thinLine, point3, point2);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            now = DateTime.Now;
            this.Invalidate();
        }
    }
}