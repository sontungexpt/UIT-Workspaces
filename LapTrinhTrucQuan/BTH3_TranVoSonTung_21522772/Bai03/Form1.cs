namespace Bai3
{
    public partial class Form1 : Form
    {
        private readonly Random randomNumber = new Random();

        public Form1()
        {
            InitializeComponent();
        }

        private void btn_Click(object sender, EventArgs e)
        {
            Color randomColor = Color.FromArgb(randomNumber.Next(256), randomNumber.Next(256), randomNumber.Next(256));

            this.BackColor = randomColor;
        }
    }
}