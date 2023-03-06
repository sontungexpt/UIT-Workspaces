namespace Bai08
{
    internal static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        private static void Main()
        {
            // To customize application configuration such as set high DPI settings or default font,
            // see https://aka.ms/applicationconfiguration.
            ApplicationConfiguration.Initialize();
            Application.Run(new Form1());
        }
    }

    public class AccountInfo
    {
        private string? _id;
        private string? _name;
        private string? _address;
        private double? _accountBalance;

        public string? Id
        {
            get => _id;
            set
            {
                if (value == null)
                {
                    throw new Exception("ID is not null");
                }
                else
                {
                    _id = value;
                }
            }
        }

        public string? Name
        {
            get => _name;
            set
            {
                if (value == null)
                {
                    throw new Exception("Name is not null");
                }
                else
                {
                    _name = value;
                }
            }
        }

        public string? Address
        {
            get => _address;
            set
            {
                if (value == null)
                {
                    throw new Exception("Address is not null");
                }
                else
                {
                    _address = value;
                }
            }
        }

        public double? AccountBalance
        {
            get => _accountBalance;
            set
            {
                if (value == null)
                {
                    throw new Exception("AccountBalance is not null");
                }
                else
                {
                    _accountBalance = value;
                }
            }
        }

        public AccountInfo()
        {
            _id = null;
            _name = null;
            _address = null;
            _accountBalance = null;
        }

        public AccountInfo(string? id, string? name, string? address, double? accountBalance)
        {
            Id = id;
            Name = name;
            Address = address;
            AccountBalance = accountBalance;
        }
    }

    public class App
    {
        private Dictionary<string, AccountInfo> accountInfos;

        public App()
        {
            accountInfos = new();
        }

        //result return true if add success and false if add fail or update data
        public int AddAccount(AccountInfo accountInfo)
        {
            if (accountInfo.Id != null)
            {
                if (accountInfos.ContainsKey(accountInfo.Id))
                {
                    accountInfo.AccountBalance += accountInfos[accountInfo.Id].AccountBalance;
                    accountInfos[accountInfo.Id] = accountInfo;
                    MessageBox.Show("Cập nhật dữ liệu thành công!");
                    return 0;
                }
                else
                {
                    accountInfos.Add(accountInfo.Id, accountInfo);
                    MessageBox.Show("Thêm mới dữ liệu thành công");

                    return 1;
                }
            }
            return -1;
        }

        public bool RemoveAccount(string id)
        {
            if (accountInfos.ContainsKey(id))
            {
                DialogResult dialogResult = MessageBox.Show("Bạn chắc chắn muốn xoá tài khoản này?", "Xoá tài khoản", MessageBoxButtons.YesNo);
                if (dialogResult == DialogResult.Yes)
                {
                    accountInfos.Remove(id);
                    MessageBox.Show("Xoá tài khoản thành công!");
                    return true;
                }
                else
                    return false;
            }
            else
            {
                MessageBox.Show("Không tìm thấy số tài khoản cần xóa");
                return false;
            }
        }
    }
}