namespace Bai5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btncong_Click(object sender, EventArgs e)
        {
            if (txbNumber1.Text == "" || txbNumber2.Text == "")
            {
                MessageBox.Show("Hay nhap so nguyen!");
            }
            else
            {
                int Tong;
                Tong = int.Parse(txbNumber1.Text) + int.Parse(txbNumber2.Text);
                txtkq.Text = $"{Tong}";
            }
        }

        private void btntru_Click(object sender, EventArgs e)
        {
            if (txbNumber1.Text == "" || txbNumber2.Text == "")
            {
                MessageBox.Show("Hay nhap so nguyen!");
            }
            else
            {
                int Hieu;
                Hieu = int.Parse(txbNumber1.Text) - int.Parse(txbNumber2.Text);
                txtkq.Text = $"{Hieu}";
            }
        }

        private void btnnhan_Click(object sender, EventArgs e)
        {
            if (txbNumber1.Text == "" || txbNumber2.Text == "")
            {
                MessageBox.Show("Hay nhap so nguyen!");
            }
            else
            {
                int Tich;
                Tich = int.Parse(txbNumber1.Text) * int.Parse(txbNumber2.Text);
                txtkq.Text = $"{Tich}";
            }
        }

        private void btnchia_Click(object sender, EventArgs e)
        {
            if (txbNumber1.Text == "" || txbNumber2.Text == "")
            {
                MessageBox.Show("Hay nhap so nguyen!");
            }
            else
            {
                if (int.Parse(txbNumber2.Text) == 0)
                {
                    MessageBox.Show("Hay nhap so nguyen thu 2 khac 0!");
                    return;
                }
                double Thuong;
                Thuong = double.Parse(txbNumber1.Text) / double.Parse(txbNumber2.Text);
                txtkq.Text = $"{Thuong}";
            }
        }
    }
}