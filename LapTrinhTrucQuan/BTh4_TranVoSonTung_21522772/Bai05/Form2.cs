using System;
using System.Linq.Expressions;
using System.Windows.Forms;

namespace Bai05
{
    internal class Form2 : Form
    {
        private Label label2;
        private Label label3;
        private Label label4;
        private TextBox txbStudentId;
        private TextBox txbStudentName;
        private TextBox txbAvergageScore;
        private ComboBox cmbFaculity;
        private Button button1;
        private Button button2;
        private Label label1;

        private Student _student;

        private string[] FACULITYS =
        {
            "Công nghệ thông tin",
            "Kĩ thuật phần mềm",
            "Mạng máy tính và truyền thông",
            "Khoa học máy tính",
            "Kĩ thuật máy tính",
            "Khoa học và kỹ thuật máy tính",
            "Khoa học và kỹ thuật thông tin",
        };

        public Student Student
        {
            get => _student;
            set => _student = value;
        }

        public Form2(Student student)
        {
            InitializeComponent();
            _student = student;
            AddFaculity();
        }

        public Form2()
        {
            InitializeComponent();
            _student = new Student();
            AddFaculity();
        }

        private void AddFaculity()
        {
            cmbFaculity.Items.AddRange(FACULITYS);
        }

        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.txbStudentId = new System.Windows.Forms.TextBox();
            this.txbStudentName = new System.Windows.Forms.TextBox();
            this.txbAvergageScore = new System.Windows.Forms.TextBox();
            this.cmbFaculity = new System.Windows.Forms.ComboBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // label1
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(23, 38);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(127, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Mã Số Sinh Viên";
            // label2
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(23, 79);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(101, 20);
            this.label2.TabIndex = 1;
            this.label2.Text = "Tên sinh viên";
            // label3
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(23, 167);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(70, 20);
            this.label3.TabIndex = 2;
            this.label3.Text = "Điểm TB";
            // label4
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(23, 125);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(46, 20);
            this.label4.TabIndex = 3;
            this.label4.Text = "Khoa";
            // txbStudentId
            this.txbStudentId.Location = new System.Drawing.Point(173, 38);
            this.txbStudentId.Name = "txbStudentId";
            this.txbStudentId.Size = new System.Drawing.Size(480, 26);
            this.txbStudentId.TabIndex = 4;
            this.txbStudentId.TextChanged += new System.EventHandler(this.StudentId_Change);
            // txbStudentName
            this.txbStudentName.Location = new System.Drawing.Point(173, 79);
            this.txbStudentName.Name = "txbStudentName";
            this.txbStudentName.Size = new System.Drawing.Size(480, 26);
            this.txbStudentName.TabIndex = 5;
            this.txbStudentName.TextChanged += new System.EventHandler(this.StudentName_Change);
            // txbAvergageScore
            this.txbAvergageScore.Location = new System.Drawing.Point(173, 167);
            this.txbAvergageScore.Name = "txbAvergageScore";
            this.txbAvergageScore.Size = new System.Drawing.Size(480, 26);
            this.txbAvergageScore.TabIndex = 6;
            this.txbAvergageScore.TextChanged += new System.EventHandler(this.Score_Change);
            // cmbFaculity
            this.cmbFaculity.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.cmbFaculity.FormattingEnabled = true;
            this.cmbFaculity.Location = new System.Drawing.Point(173, 125);
            this.cmbFaculity.Name = "cmbFaculity";
            this.cmbFaculity.Size = new System.Drawing.Size(480, 28);
            this.cmbFaculity.TabIndex = 7;
            this.cmbFaculity.SelectedIndexChanged += new System.EventHandler(this.Faculity_Change);
            this.cmbFaculity.SelectedValueChanged += new System.EventHandler(this.Faculity_Change);
            this.cmbFaculity.TextChanged += new System.EventHandler(this.Faculity_Change);
            // button1
            this.button1.BackColor = System.Drawing.Color.Lime;
            this.button1.Location = new System.Drawing.Point(296, 212);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(173, 36);
            this.button1.TabIndex = 8;
            this.button1.Text = "Thêm mới";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.AddStudent_Click);
            // button2
            this.button2.BackColor = System.Drawing.Color.Coral;
            this.button2.Location = new System.Drawing.Point(480, 212);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(173, 36);
            this.button2.TabIndex = 9;
            this.button2.Text = "Thoát";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.ExitForm2_Click);
            // Form2
            this.ClientSize = new System.Drawing.Size(666, 263);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.cmbFaculity);
            this.Controls.Add(this.txbAvergageScore);
            this.Controls.Add(this.txbStudentName);
            this.Controls.Add(this.txbStudentId);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form2";
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        private void StudentId_Change(object sender, EventArgs e)
        {
            _student.Id = txbStudentId.Text;
        }

        private void StudentName_Change(object sender, EventArgs e)
        {
            _student.Name = txbStudentName.Text;
        }

        private void Faculity_Change(object sender, EventArgs e)
        {
            _student.Faculity = cmbFaculity.Text;
        }

        private void AddStudent_Click(object sender, EventArgs e)
        {
            if (txbStudentId.Text.Trim() == "")
            {
                MessageBox.Show("Mã số sinh viên không dược bỏ trống");
                txbStudentId.Text = "";
                txbStudentId.Focus();
                return;
            }
            else
                _student.Id = txbStudentId.Text.Trim();

            if (txbStudentName.Text.Trim() == "")
            {
                MessageBox.Show("Tên không được bỏ trống");
                txbStudentName.Text = "";
                txbStudentName.Focus();
                return;
            }
            else
                _student.Name = txbStudentName.Text.Trim();

            if (cmbFaculity.Text.Trim() == "")
            {
                MessageBox.Show("Khoa không dược bỏ trống");
                cmbFaculity.Text = "";
                cmbFaculity.Focus();
                return;
            }
            else
                _student.Faculity = cmbFaculity.Text.Trim();

            if (txbAvergageScore.Text.Trim() == "")
            {
                MessageBox.Show("Điểm trung bình không dược bỏ trống");
                txbAvergageScore.Text = "";
                txbAvergageScore.Focus();
                return;
            }
            else
                _student.AverageScore = float.Parse(txbAvergageScore.Text.Trim());
            this.Close();
        }

        private void ExitForm2_Click(object sender, EventArgs e)
        {
            if (txbStudentId.Text.Trim() == ""
                || txbStudentName.Text.Trim() == ""
                || cmbFaculity.Text.Trim() == ""
                || txbAvergageScore.Text.Trim() == "")
            {
                DialogResult result = MessageBox.Show("Bạn chưa nhập đủ thông tin, bạn có chắc muốn thoát!",
                                                      "Thông báo",
                                                      MessageBoxButtons.YesNo,
                                                      MessageBoxIcon.Question);
                if (result == DialogResult.Yes)
                    this.Close();

                return;
            }
        }

        private void Score_Change(object sender, EventArgs e)
        {
            try
            {
                if (txbAvergageScore.Text != "")
                    _student.AverageScore = float.Parse(txbAvergageScore.Text);
            }
            catch (Exception)
            {
                MessageBox.Show("Điểm TB phải là số thực");
                txbAvergageScore.Text = "";
                txbAvergageScore.Focus();
            }
        }
    }
}