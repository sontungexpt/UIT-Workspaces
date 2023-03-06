namespace Bai08
{
    public partial class Form1 : Form
    {
        private App _app;
        private int _index;

        public Form1()
        {
            InitializeComponent();
        }

        public void Form1_Loaded(object sender, EventArgs e)
        {
            _app = new App();
            _index = 0;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
        }

        private void label5_Click(object sender, EventArgs e)
        {
        }

        private void btnAdd_Clicked(object sender, EventArgs e)
        {
            try
            {
                string? id = GetTextFromTextBox(txbIdAccount);
                string? name = GetTextFromTextBox(txbName);
                string? address = GetTextFromTextBox(txbAddress);
                string? strAccountBalance = GetTextFromTextBox(txbAccountBalance);
                double? accountBalance = double.Parse(strAccountBalance);

                int state = _app.AddAccount(new AccountInfo(id, name, address, accountBalance));

                if (state == 1)
                {
                    _index++;
                    string[] row = { _index.ToString(),
                                     id,
                                     name,
                                     address,
                                     accountBalance.ToString()
                    };
                    ListViewItem item = new(row);
                    listViewAccount.Items.Add(item);
                    ResetValue();
                }
                else if (state == 0)
                {
                    foreach (ListViewItem item in listViewAccount.Items)
                    {
                        if (item.SubItems[1].Text == id)
                        {
                            //found the item and update it
                            item.SubItems[2].Text = name;
                            item.SubItems[3].Text = address;
                            item.SubItems[4].Text = (Convert.ToDouble(item.SubItems[4].Text) + accountBalance).ToString();
                        }
                    }
                }
            }
            catch (FormatException formatException)
            {
                MessageBox.Show("Số dư tài khoản phải là số thực!");
                txbAccountBalance.Text = "";
                txbAccountBalance.Focus();
            }
            catch (Exception exception)
            {
                MessageBox.Show("Vui lòng nhập đầy đủ thông tin!");
            }
        }

        private void txbAccountBalance_TextChanged(object sender, EventArgs e)
        {
        }

        public string GetTextFromTextBox(TextBox textBox)
        {
            return textBox.Text.Trim() == "" || textBox.Text.Trim() == null ? null : textBox.Text.Trim();
        }

        public void ResetValue()
        {
            txbIdAccount.Text = "";
            txbName.Text = "";
            txbAddress.Text = "";
            txbAccountBalance.Text = "";
        }

        private void removeBtn_Clicked(object sender, EventArgs e)
        {
            string? id = txbIdAccount.Text.Trim() == "" ||
            txbIdAccount.Text.Trim() == null ? null : txbIdAccount.Text.Trim();

            if (id != null)
            {
                bool success = _app.RemoveAccount(id);
                if (success)
                {
                    int _indexRemoved = 0;

                    foreach (ListViewItem item in listViewAccount.Items)
                    {
                        if (item.SubItems[1].Text == id)
                        {
                            _indexRemoved = item.Index;
                            listViewAccount.Items.Remove(item);
                            break;
                        }
                    }
                    //update the index
                    int currentLength = listViewAccount.Items.Count;
                    for (int i = _indexRemoved; i < currentLength; i++)
                    {
                        listViewAccount.Items[i].SubItems[0].Text = (i + 1).ToString();
                    }
                    ResetValue();
                }
            }

            if (listViewAccount.SelectedItems.Count > 0)
            {
                bool success = _app.RemoveAccount(listViewAccount.SelectedItems[0].SubItems[1].Text);
                if (success)
                {
                    listViewAccount.Items.RemoveAt(listViewAccount.SelectedItems[0].Index);
                }
            }
        }

        private void listViewAccount_MouseClick(object sender, MouseEventArgs e)
        {
            txbIdAccount.Text = listViewAccount.GetItemAt(e.X, e.Y).SubItems[1].Text;
            txbName.Text = listViewAccount.GetItemAt(e.X, e.Y).SubItems[2].Text;
            txbAddress.Text = listViewAccount.GetItemAt(e.X, e.Y).SubItems[3].Text;
            txbAccountBalance.Text = listViewAccount.GetItemAt(e.X, e.Y).SubItems[4].Text;
        }
    }
}