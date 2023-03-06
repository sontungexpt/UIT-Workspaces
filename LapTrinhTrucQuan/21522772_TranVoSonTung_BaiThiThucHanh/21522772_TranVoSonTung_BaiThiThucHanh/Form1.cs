namespace _21522772_TranVoSonTung_BaiThiThucHanh
{
    public partial class Form1 : Form
    {
        private int index;

        private string[] CMB_INFOS =
        {
            "2014","2015","2016","2017","2018","2019","2020"
        };

        public Form1()
        {
            InitializeComponent();
            LoadCombobox();
            index = 0;
        }

        public void LoadCombobox()
        {
            cmbCourse.Items.AddRange(CMB_INFOS);
        }

        public string GetResultRadioButton(Label lb, Panel pnl)
        {
            RadioButton cxb = null;
            foreach (Control c in pnl.Controls)
            {
                if (c is RadioButton)
                {
                    cxb = (RadioButton)c;
                    if (cxb.Checked)
                    {
                        return cxb.Text;
                    }
                }
            }
            return "";
        }

        public void Close_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Bạn có chắc chắn muốn thoát khỏi chương trình không?",
                                                   "Thông báo",
                                                   MessageBoxButtons.YesNo,
                                                   MessageBoxIcon.Question);
            if (result == DialogResult.Yes)
                this.Close();
        }

        public int CalculateTotalAmountToPay()
        {
            int numberOfCreditsInt = 0;
            string numberOfCredits = txbNumberOfCredits.Text;
            string dongia = txbDonGia.Text;
            if (!String.IsNullOrEmpty(numberOfCredits) && !String.IsNullOrEmpty(dongia))
            {
                if (int.TryParse(numberOfCredits, out numberOfCreditsInt))
                    return numberOfCreditsInt * int.Parse(dongia);
                else
                {
                    Validate(txbNumberOfCredits, "int", "Số tín chỉ");
                    return 0;
                }
            }
            return 0;
        }

        public void Validate(TextBox txb, string condition, string name)
        {
            if (String.IsNullOrEmpty(txb.Text))
            {
                MessageBox.Show("Không được bỏ trống");
                txb.Focus();
            }
            if (condition == "float")
            {
                MessageBox.Show($"{name} phải là số thực");
                txb.Text = "";
                txb.Focus();
            }

            if (condition == "int")
            {
                MessageBox.Show($"{name} phải là số nguyên");
                txb.Text = "";
                txb.Focus();
            }
        }

        private void AddItemToListView()
        {
            string studentName = txbStudent.Text;
            string course = cmbCourse.Text;
            string location = GetResultRadioButton(label3, panel1);
            string numberOfCredits = txbNumberOfCredits.Text;
            string donGia = txbDonGia.Text;
            string thanhTien = txbThanhTien.Text;
            string vat = txbVAT.Text;
            string sale = txbSale.Text;
            string tongTien = txbSumMoney.Text;
            index++;
            var item = new ListViewItem(index.ToString());
            item.SubItems.Add(studentName);
            item.SubItems.Add(course);
            item.SubItems.Add(location);
            item.SubItems.Add(numberOfCredits);
            item.SubItems.Add(donGia);
            item.SubItems.Add(thanhTien);
            item.SubItems.Add(vat);
            item.SubItems.Add(sale);
            item.SubItems.Add(tongTien);
            listView.Items.Add(item);
        }

        private void Add_Click(object sender, EventArgs e)
        {
            AddItemToListView();
            listView.Sorting = SortOrder.Ascending;
            this.listView.Sort();
        }

        private void NumberOfCredits_Change(object sender, EventArgs e)
        {
            txbThanhTien.Text = CalculateTotalAmountToPay().ToString();
        }

        private void ThanhTien_Change(object sender, EventArgs e)
        {
            txbVAT.Text = (int.Parse(txbThanhTien.Text) * 0.1).ToString();
            if (txbThanhTien.Text != "" && txbVAT.Text != "" && txbSale.Text != "")
            {
                if (txbSale.Text == "10%")
                    txbSumMoney.Text = (double.Parse(txbThanhTien.Text) + double.Parse(txbVAT.Text) - double.Parse(txbThanhTien.Text) * 0.1).ToString();
                else
                    txbSumMoney.Text = (double.Parse(txbThanhTien.Text) + double.Parse(txbVAT.Text) - double.Parse(txbThanhTien.Text) * 0.05).ToString();
            }
        }

        private void Check_Change(object sender, EventArgs e)
        {
            if (GetResultRadioButton(label3, panel1) == "Nông thôn")
            {
                txbSale.Text = "10%";
            }
            else
            {
                txbSale.Text = "5%";
            }
        }

        private void GiamGia_Change(object sender, EventArgs e)
        {
            if (txbThanhTien.Text != "" && txbVAT.Text != "" && txbSale.Text != "")
            {
                if (txbSale.Text == "10%")
                    txbSumMoney.Text = (double.Parse(txbThanhTien.Text) + double.Parse(txbVAT.Text) - double.Parse(txbThanhTien.Text) * 0.1).ToString();
                else
                    txbSumMoney.Text = (double.Parse(txbThanhTien.Text) + double.Parse(txbVAT.Text) - double.Parse(txbThanhTien.Text) * 0.05).ToString();
            }
        }

        private void VAT_Change(object sender, EventArgs e)
        {
            if (txbThanhTien.Text != "" && txbVAT.Text != "" && txbSale.Text != "")
            {
                if (txbSale.Text == "10%")
                    txbSumMoney.Text = (double.Parse(txbThanhTien.Text) + double.Parse(txbVAT.Text) - double.Parse(txbThanhTien.Text) * 0.1).ToString();
                else
                    txbSumMoney.Text = (double.Parse(txbThanhTien.Text) + double.Parse(txbVAT.Text) - double.Parse(txbThanhTien.Text) * 0.05).ToString();
            }
        }

        private void Column_Click(object sender, ColumnClickEventArgs e)
        {
            //sort the colum by the text in the colum
            listView.Sorting = SortOrder.Ascending;
            this.listView.Sort();
        }
    }
}