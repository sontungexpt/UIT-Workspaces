using System.Diagnostics;

namespace Bai7
{
    public partial class Form1 : Form
    {
        private int priceA = 5000;
        private int priceB = 6500;
        private int priceC = 8000;

        private Color colorSelected = Color.Blue;
        private Color colorSold = Color.Yellow;

        private bool[] isSelected = Enumerable.Repeat<bool>(false, 15).ToArray();
        private bool[] isSold = Enumerable.Repeat<bool>(false, 15).ToArray();

        private int intoMoney = 0;
        public Form1()
        {
            Enumerable.Repeat(false, 15).ToArray();
            InitializeComponent();
        }

        public void SelectTicket_Funtion(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            int index = Convert.ToInt32(btn.Text) - 1;
            label2.Visible = false;
            if(!isSold[index])
            {
                if (isSelected[index])
                {
                    isSelected[index]= false;
                    btn.BackColor = Color.White;
                    if(index < 5)
                    {
                        intoMoney -= priceA;
                    }
                    else if(index < 10)
                    {
                        intoMoney -= priceB;
                    }
                    else
                    {
                        intoMoney -= priceC;
                    }
                }
                else
                {
                    isSelected[index]= true;
                    btn.BackColor = colorSelected;
                    if (index < 5)
                    {
                        intoMoney += priceA;
                    }
                    else if (index < 10)
                    {
                        intoMoney += priceB;
                    }
                    else
                    {
                        intoMoney += priceC;
                    }
                }
            }
            else
            {
                MessageBox.Show("Vé tại vị trí này đã được bán!");
            }
            textBox2.Text = intoMoney +"";
        }

        private void btnbook_Click(object sender, EventArgs e)
        {  
            for(int i = 0; i < 15; i++)
            {
                if (isSelected[i])
                {
                    isSold[i] = true;
                    foreach (var button in this.Controls.OfType<Button>())
                    {
                        if (button.Text == $"{i+1}")
                        {
                            button.BackColor = colorSold;
                        }
                    }
                }
            }
            textBox2.Text = "0";
            label2.Visible = true;
            label2.Text = $"Tổng tiền phải trả là {intoMoney}" ;
            intoMoney = 0;
        }

        private void btncancel_Click(object sender, EventArgs e)
        {
            foreach (var button in this.Controls.OfType<Button>())
            {
                if(int.TryParse(button.Text, out int n))
                {
                    int index = Convert.ToInt32(button.Text) - 1;
                    if (isSelected[index] && !isSold[index])
                    {
                        button.BackColor = Color.White;
                        isSelected[index] = false;
                    }
                }
            }
            intoMoney = 0;
            textBox2.Text = "0";
        }

        private void btnexit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}