using System.CodeDom;

namespace Bai06
{
    public partial class Form1 : Form
    {
        private object[] _buffers;

        private string[] keyNames =
            {
                "MC", "7", "8", "9", "÷", "√", "MR", "4", "5", "6", "×", "%", "MS", "1", "2", "3", "-", "1/x", "M+", "0", "+/-", ".", "+", "="
            };

        public Form1()
        {
            InitializeComponent();
            this.Text = "Caculator";
        }

        private void SetStateBtn(bool state)
        {
            foreach (Button btn in flowLayoutPanel1.Controls)
            {
                if (btn.Text == "+/-" || btn.Text == "1/x" || btn.Text == "÷" || btn.Text == "-" || btn.Text == "×" || btn.Text == "/" || btn.Text == "=" || btn.Text == "√" || btn.Text == "1/x" || btn.Text == "%" || btn.Text == "MC" || btn.Text == "MR" || btn.Text == "MS" || btn.Text == "M+" || btn.Text == "M-" || btn.Text == "BackSpace" || btn.Text == "+")
                {
                    btn.Enabled = state;
                }
            }
        }

        public string GetTextFromTextBox(TextBox textBox)
        {
            return textBox.Text.Trim() == "" || textBox.Text.Trim() == null ? null : textBox.Text.Trim();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            _buffers = new object[3];
            for (int i = 0; i < _buffers.Length; i++)
            {
                _buffers[i] = null;
            }

            for (int j = 0; j < keyNames.Length; j++)
            {
                Button b = new Button();
                b.Text = keyNames[j];
                b.Location = new Point(j * 55);
                b.Name = keyNames[j];
                b.Size = new Size(55, 50);
                b.Click += btnKey_Clicked;
                flowLayoutPanel1.Controls.Add(b);
                if (txbValue.Text == "")
                {
                    SetStateBtn(false);
                }
            }
        }

        private void SetBuffer(int index)
        {
            try
            {
                string txt = GetTextFromTextBox(txbValue);

                if (txt != null)
                {
                    if (txt[0] == '.')
                        txt.Insert(0, "0");

                    if (index == 1)
                        MessageBox.Show("error index cannot = 1");
                    _buffers[index] = double.Parse(txt);
                }
            }
            catch (FormatException ex)
            {
                MessageBox.Show("Giá trị nhập vào không hợp lệ");
            }
        }

        private void btnKey_Clicked(object sender, EventArgs e)
        {
            Button b = (Button)sender;
            string key = b.Text;
            switch (key)
            {
                case "MC":
                case "MR":
                case "MS":
                case "M+":
                case "1/x":
                case "M-":
                case "←":
                case "CE":
                case "+/-":
                case "C":
                    break;

                case "√":
                    SetBuffer(0);
                    _buffers[1] = 's';

                    break;

                case "÷":
                    SetBuffer(0);
                    _buffers[1] = '/';
                    txbValue.Text = "";
                    break;

                case "×":
                    SetBuffer(0);
                    _buffers[1] = '*';
                    txbValue.Text = "";
                    break;

                case "-":
                    SetBuffer(0);
                    _buffers[1] = '-';
                    txbValue.Text = "";
                    break;

                case "%":
                    SetBuffer(0);
                    _buffers[1] = '%';
                    txbValue.Text = "";
                    break;

                case "+":
                    SetBuffer(0);
                    _buffers[1] = '+';
                    txbValue.Text = "";
                    break;

                case "=":
                    try
                    {
                        SetBuffer(2);
                        if ((char)(_buffers[1] ?? ' ') == 's')
                            txbValue.Text = (Math.Sqrt((double)_buffers[0])).ToString();
                        if (_buffers[0] != null && _buffers[1] != null && _buffers[2] != null)
                        {
                            if ((char)_buffers[1] == '+')
                                txbValue.Text = ((double)_buffers[0] + (double)_buffers[2]).ToString();
                            if ((char)_buffers[1] == '-')
                                txbValue.Text = ((double)_buffers[0] - (double)_buffers[2]).ToString();
                            if ((char)_buffers[1] == '*')
                                txbValue.Text = ((double)_buffers[0] * (double)_buffers[2]).ToString();
                            if ((char)_buffers[1] == '/')
                                txbValue.Text = ((double)_buffers[0] / (double)_buffers[2]).ToString();
                            if ((char)_buffers[1] == '%')
                                txbValue.Text = ((double)_buffers[0] % (double)_buffers[2]).ToString();
                            if ((char)_buffers[1] == '%')
                                txbValue.Text = ((double)_buffers[0] % (double)_buffers[2]).ToString();
                        }
                    }
                    catch (Exception error)
                    {
                        MessageBox.Show("Can not calculate");
                        txbValue.Text = "";
                        txbValue.Focus();
                    }
                    break;

                default:
                    try
                    {
                        txbValue.Text += key;
                    }
                    catch (Exception error)
                    {
                        MessageBox.Show("Can not calculate");
                        txbValue.Text = "";
                    }
                    break;
            }
            txbValue.Focus();
        }

        private void txbValue_Changed(object sender, EventArgs e)
        {
            if (GetTextFromTextBox(txbValue) == null && _buffers[0] == null)
            {
                SetStateBtn(false);
            }
            else
            {
                SetStateBtn(true);
            }
        }

        private void AC_Clicked(object sender, EventArgs e)
        {
            txbValue.Text = "";
            for (int i = 0; i < _buffers.Length; i++)
            {
                _buffers[i] = null;
            }
        }
    }
}