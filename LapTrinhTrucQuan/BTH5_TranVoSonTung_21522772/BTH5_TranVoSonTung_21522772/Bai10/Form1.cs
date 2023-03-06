using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace Bai10
{
    public partial class Form1 : Form
    {
        private Pen pen = new Pen(Brushes.Blue);

        public Form1()
        {
            InitializeComponent();
            cbDashCap.SelectedIndex = 0;
            cbDashStyle.SelectedIndex = 0;
            cbEndCap.SelectedIndex = 0;
            cbLineJoin.SelectedIndex = 0;
            cbStartCap.SelectedIndex = 0;
            cbWidth.SelectedIndex = 0;
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawLine(pen, new Point(20, 20), new Point(100, 100));
            GraphicsPath path = new GraphicsPath();
            path.AddLine(new Point(150, 150), new Point(230, 230));
            path.AddLine(new Point(230, 230), new Point(310, 150));
            e.Graphics.DrawPath(pen, path);
        }

        private void cbDashStyle_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (cbDashStyle.SelectedItem.ToString())
            {
                case "Custom":
                    pen.DashStyle = DashStyle.Custom;
                    break;

                case "Dash":
                    pen.DashStyle = DashStyle.Dash;
                    break;

                case "Dot":
                    pen.DashStyle = DashStyle.Dot;
                    break;

                case "DashDot":
                    pen.DashStyle = DashStyle.DashDot;
                    break;

                case "DashDotDot":
                    pen.DashStyle = DashStyle.DashDotDot;
                    break;

                case "Solid":
                    pen.DashStyle = DashStyle.Solid;
                    break;
            }
            panel1.Invalidate();
        }

        private void cbWidth_SelectedIndexChanged(object sender, EventArgs e)
        {
            int num = cbWidth.SelectedIndex + 1;
            pen.Width = num;
            panel1.Invalidate();
        }

        private void cbLineJoin_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (cbLineJoin.SelectedItem.ToString())
            {
                case "Bevel":
                    pen.LineJoin = LineJoin.Bevel;
                    break;

                case "Miter":
                    pen.LineJoin = LineJoin.Miter;
                    break;

                case "MiterClipped":
                    pen.LineJoin = LineJoin.MiterClipped;
                    break;

                case "Round":
                    pen.LineJoin = LineJoin.Round;
                    break;
            }
            panel1.Invalidate();
        }

        private void cbDashCap_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (cbDashCap.SelectedItem.ToString())
            {
                case "Round":
                    pen.DashCap = DashCap.Round;
                    break;

                case "Flat":
                    pen.DashCap = DashCap.Flat;
                    break;

                case "Triangle":
                    pen.DashCap = DashCap.Triangle;
                    break;
            }
            panel1.Invalidate();
        }

        private void cbEndCap_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (cbEndCap.SelectedItem.ToString())
            {
                case "AnchorMask":
                    pen.EndCap = LineCap.AnchorMask;
                    break;

                case "ArrowAnchor":
                    pen.EndCap = LineCap.ArrowAnchor;
                    break;

                case "DiamondAnchor":
                    pen.EndCap = LineCap.DiamondAnchor;
                    break;

                case "Flat":
                    pen.EndCap = LineCap.Flat;
                    break;

                case "NoAnchor":
                    pen.EndCap = LineCap.NoAnchor;
                    break;

                case "Round":
                    pen.EndCap = LineCap.Round;
                    break;

                case "RoundAnchor":
                    pen.EndCap = LineCap.RoundAnchor;
                    break;

                case "Square":
                    pen.EndCap = LineCap.Square;
                    break;

                case "SquareAnchor":
                    pen.EndCap = LineCap.SquareAnchor;
                    break;

                case "Triangle":
                    pen.EndCap = LineCap.Triangle;
                    break;
            }
            panel1.Invalidate();
        }

        private void cbStartCap_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (cbStartCap.SelectedItem.ToString())
            {
                case "AnchorMask":
                    pen.StartCap = LineCap.AnchorMask;
                    break;

                case "ArrowAnchor":
                    pen.StartCap = LineCap.ArrowAnchor;
                    break;

                case "DiamondAnchor":
                    pen.StartCap = LineCap.DiamondAnchor;
                    break;

                case "Flat":
                    pen.StartCap = LineCap.Flat;
                    break;

                case "NoAnchor":
                    pen.StartCap = LineCap.NoAnchor;
                    break;

                case "Round":
                    pen.StartCap = LineCap.Round;
                    break;

                case "RoundAnchor":
                    pen.StartCap = LineCap.RoundAnchor;
                    break;

                case "Square":
                    pen.StartCap = LineCap.Square;
                    break;

                case "SquareAnchor":
                    pen.StartCap = LineCap.SquareAnchor;
                    break;

                case "Triangle":
                    pen.StartCap = LineCap.Triangle;
                    break;
            }
            panel1.Invalidate();
        }
    }
}