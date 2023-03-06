using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Bai11
{
    public partial class Form1 : Form
    {
        private Color _lineColor = Color.Black;
        private int _lineWidth = 2;
        private Graphics _graphics;
        private int x = -1, y = -1;
        private bool _isMoving = false;
        private Pen _pen;
        private string[] _shapes = { "Free", "Line", "Rectangle", "Ellipse", "Filled Rectangle", "Filled Ellipse" };
        private int _shapeIndex = 0;
        private Point _startPoint;
        private Point _endPoint;

        public Form1()
        {
            InitializeComponent();
            _graphics = DrawingSpace.CreateGraphics();
            _pen = new Pen(_lineColor, _lineWidth);
            _graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            cmbShape.DataSource = _shapes;
        }

        private void btnColor_Click(object sender, EventArgs e)
        {
            ColorDialog colorDialog = new ColorDialog();
            if (colorDialog.ShowDialog() == DialogResult.OK)
            {
                _lineColor = colorDialog.Color;
                btnColor.Text = _lineColor.Name;
                btnColor.BackColor = _lineColor;
            }
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            _isMoving = true;
            _startPoint = e.Location;

            x = e.X;
            y = e.Y;
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            _endPoint = e.Location;

            switch (_shapeIndex)
            {
                case 0:
                    if (_isMoving && x != -1 && y != -1)
                    {
                        _pen.Color = _lineColor;
                        _graphics.DrawLine(_pen, new Point(x, y), e.Location);
                        x = e.X;
                        y = e.Y;
                    }
                    break;

                default:
                    break;
            }
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            _isMoving = false;

            x = -1;
            y = -1;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void cmbShape_SelectedIndexChanged(object sender, EventArgs e)
        {
            _shapeIndex = cmbShape.SelectedIndex;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            switch (_shapeIndex)
            {
                case 1:
                    e.Graphics.DrawLine(_pen, _startPoint, _endPoint);

                    break;

                case 2:
                    e.Graphics.DrawRectangle(_pen, new Rectangle(_startPoint.X, _startPoint.Y, _endPoint.X - _startPoint.X, _endPoint.Y - _startPoint.Y));

                    break;

                case 3:
                    e.Graphics.DrawEllipse(_pen, new Rectangle(_startPoint.X, _startPoint.Y, _endPoint.X - _startPoint.X, _endPoint.Y - _startPoint.Y));
                    break;

                case 4:
                    e.Graphics.FillRectangle(new SolidBrush(_lineColor), new Rectangle(_startPoint.X, _startPoint.Y, _endPoint.X - _startPoint.X, _endPoint.Y - _startPoint.Y));
                    break;

                case 5:
                    e.Graphics.FillEllipse(new SolidBrush(_lineColor), new Rectangle(_startPoint.X, _startPoint.Y, _endPoint.X - _startPoint.X, _endPoint.Y - _startPoint.Y));
                    break;

                default:
                    break;
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (int.TryParse(txbLineWidth.Text, out _lineWidth))
            {
                _pen.Width = _lineWidth;
            }
        }
    }
}