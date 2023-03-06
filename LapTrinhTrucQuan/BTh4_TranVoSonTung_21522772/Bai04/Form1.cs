using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Bai04
{
    public partial class Form1 : Form
    {
        private FontFamily[] fontFamilies;
        private const string FONT_NAME_DEFAULT = "Tahoma";
        private const FontStyle FONT_STYLE_DEFAULT = FontStyle.Regular;
        private const float FONT_SIZE_DEFAULT = 14;
        private string _path;
        private bool _isSaved;

        public Form1()
        {
            InitializeComponent();
            fontFamilies = FontFamily.Families;
            SetDefaut();
            AddFontBoxItem();
            AddSizeBoxItem();
            _path = String.Empty;
            _isSaved = false;
        }

        private void AddSizeBoxItem()
        {
            for (int sizeItem = 8; sizeItem <= 72; sizeItem++)
            {
                if (sizeItem > 12)
                    sizeItem++;
                SizeDropDownBtn.Items.Add(sizeItem);
            }
        }

        private void AddFontBoxItem()
        {
            for (int fontItem = 0; fontItem < fontFamilies.Length; fontItem++)
            {
                FontDropDownBtn.Items.Add(fontFamilies[fontItem].Name);
            }
        }

        private void SetFontBoxTitle(string font)
        {
            foreach (FontFamily fontFamily in fontFamilies)
            {
                if (fontFamily.Name == font)
                {
                    FontDropDownBtn.Text = fontFamily.Name;
                    return;
                }
            }
        }

        private void SetDefaut()
        {
            SizeDropDownBtn.Text = FONT_SIZE_DEFAULT.ToString();
            FontDropDownBtn.Text = FONT_NAME_DEFAULT;
            richText.Font = new Font(FONT_NAME_DEFAULT, FONT_SIZE_DEFAULT, FONT_STYLE_DEFAULT);
        }

        private void FormatBtn_Click(object sender, EventArgs e)
        {
            FontDialog fontDialog = new FontDialog();
            fontDialog.ShowDialog();
            richText.Font = fontDialog.Font;
            FontDropDownBtn.Text = fontDialog.Font.Name;
            SizeDropDownBtn.Text = fontDialog.Font.Size.ToString();
        }

        private void BoldText_Click(object sender, EventArgs e)
        {
            richText.Font = new Font(FontDropDownBtn.Text, float.Parse(SizeDropDownBtn.Text), FontStyle.Bold);
        }

        private void ItalicText_Click(object sender, EventArgs e)
        {
            richText.Font = new Font(FontDropDownBtn.Text, float.Parse(SizeDropDownBtn.Text), FontStyle.Italic);
        }

        private void UnderlineText_Click(object sender, EventArgs e)
        {
            richText.Font = new Font(FontDropDownBtn.Text, float.Parse(SizeDropDownBtn.Text), FontStyle.Underline);
        }

        private void Save_Click(object sender, EventArgs e)
        {
            if (File.Exists(_path) || _isSaved)
            {
                richText.SaveFile(_path, RichTextBoxStreamType.PlainText);
                MessageBox.Show("Save file thành công");
            }
            else
            {
                SaveFileDialog saveFileDialog = new SaveFileDialog();
                saveFileDialog.Filter = "Text File (*.rtf)|*.rtf|All Files (*.*)|*.*";
                saveFileDialog.FilterIndex = 1;
                saveFileDialog.RestoreDirectory = true;
                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    _path = saveFileDialog.FileName;
                    _isSaved = true;
                    richText.SaveFile(saveFileDialog.FileName, RichTextBoxStreamType.PlainText);
                }
            }
        }

        private void NewPage_Click(object sender, EventArgs e)
        {
            richText.Text = "";
            SetDefaut();
        }

        private void OpenFolder_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Text File (*.txt, *.rtf)|*.txt;*.rtf|All Files (*.*)|*.*";
            openFileDialog.FilterIndex = 1;
            openFileDialog.RestoreDirectory = true;
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                _path = openFileDialog.FileName;
                richText.LoadFile(_path, RichTextBoxStreamType.PlainText);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            richText.Width = Form1.ActiveForm.Width;
            richText.Height = Form1.ActiveForm.Height;
        }

        private void Size_Change(object sender, EventArgs e)
        {
            richText.Font = new Font(FontDropDownBtn.Text, float.Parse(SizeDropDownBtn.Text));
        }

        private void Font_Change(object sender, EventArgs e)
        {
            richText.Font = new Font(FontDropDownBtn.Text, float.Parse(SizeDropDownBtn.Text));
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}