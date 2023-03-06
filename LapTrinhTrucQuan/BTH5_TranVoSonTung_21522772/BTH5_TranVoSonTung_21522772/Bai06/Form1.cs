using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Bai06
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            List<string> fonts = new List<string>();
            foreach (FontFamily font in System.Drawing.FontFamily.Families)
            {
                fonts.Add(font.Name);
            }
            foreach (string fontFam in fonts)
            {
                try
                {
                    FontArea.SelectionFont = new Font(new FontFamily(fontFam), 16);
                    FontArea.AppendText(fontFam + "\n");
                }
                catch (ArgumentException ex) { }
            }
        }
    }
}