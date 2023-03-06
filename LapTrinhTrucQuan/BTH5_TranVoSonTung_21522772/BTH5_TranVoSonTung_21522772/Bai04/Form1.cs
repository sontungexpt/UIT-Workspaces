using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Bai04
{
    public partial class Form1 : Form
    {
        private FontFamily fontFam;
        private int fontSize = 12;
        private bool isBold = false;
        private bool isItalic = false;
        private bool isUnderline = false;
        private string textAlign = "left";
        private Color color;

        public Form1()
        {
            InitializeComponent();
            fontFam = new FontFamily("Arial");
            foreach (FontFamily font in System.Drawing.FontFamily.Families)
            {
                cmbFont.Items.Add(font.Name);
            }
            cmbFont.SelectedItem = "Arial";

            comboBoxSize.SelectedItem = "12";
            color = Color.Black;
            DoubleBuffered = true;
        }

        private void checkBoxBold_CheckedChanged(object sender, EventArgs e)
        {
            if (ckbBold.Checked)
                isBold = true;
            else
                isBold = false;
            panel1.Invalidate();
        }

        private void checkBoxItalic_CheckedChanged(object sender, EventArgs e)
        {
            if (ckbItalic.Checked)
                isItalic = true;
            else
                isItalic = false;
            panel1.Invalidate();
        }

        private void checkBoxUnderline_CheckedChanged(object sender, EventArgs e)
        {
            if (ckbUnderline.Checked)
                isUnderline = true;
            else
                isUnderline = false;
            panel1.Invalidate();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Font font = new Font(fontFam, fontSize, FontStyle.Regular);
            if (isBold)
                font = new Font(font, font.Style ^ FontStyle.Bold);
            if (isItalic)
                font = new Font(font, font.Style ^ FontStyle.Italic);
            if (isUnderline)
                font = new Font(font, font.Style ^ FontStyle.Underline);

            StringFormat sf = new StringFormat();
            if (textAlign == "left")
                sf.Alignment = StringAlignment.Near;
            if (textAlign == "center")
                sf.Alignment = StringAlignment.Center;
            if (textAlign == "right")
                sf.Alignment = StringAlignment.Far;
            sf.LineAlignment = StringAlignment.Center;
            g.DrawString("Hello", font, new SolidBrush(color), new RectangleF(0, 0, panel1.ClientSize.Width, panel1.ClientSize.Height), sf);
        }

        private void comboBoxFont_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cmbFont.SelectedItem != null)
            {
                fontFam = new FontFamily(cmbFont.SelectedItem.ToString());
                panel1.Invalidate();
            }
        }

        private void comboBoxSize_TextChanged(object sender, EventArgs e)
        {
            int number;
            bool isParsable = Int32.TryParse(comboBoxSize.Text, out number);

            if (isParsable)
            {
                fontSize = number;
                panel1.Invalidate();
            }
        }

        private void radioLeft_CheckedChanged(object sender, EventArgs e)
        {
            if (radioLeft.Checked)
            {
                textAlign = "left";
                panel1.Invalidate();
            }
        }

        private void radioCenter_CheckedChanged(object sender, EventArgs e)
        {
            if (radioCenter.Checked)
            {
                textAlign = "center";
                panel1.Invalidate();
            }
        }

        private void radioRight_CheckedChanged(object sender, EventArgs e)
        {
            if (radioRight.Checked)
            {
                textAlign = "right";
                panel1.Invalidate();
            }
        }

        private void buttonColor_Click(object sender, EventArgs e)
        {
            ColorDialog colorDlg = new ColorDialog();
            if (colorDlg.ShowDialog() == DialogResult.OK)
            {
                btnColor.BackColor = colorDlg.Color;
                color = colorDlg.Color;
                panel1.Invalidate();
            }
        }
    }
}