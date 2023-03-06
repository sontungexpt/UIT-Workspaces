namespace _21522772_TranVoSonTung_BaiThiThucHanh
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.ListViewItem listViewItem1 = new System.Windows.Forms.ListViewItem("");
            this.txbStudent = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.cmbCourse = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.rdbCountry = new System.Windows.Forms.RadioButton();
            this.rdbCity = new System.Windows.Forms.RadioButton();
            this.panel1 = new System.Windows.Forms.Panel();
            this.txbNumberOfCredits = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.txbDonGia = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.txbThanhTien = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.listView = new System.Windows.Forms.ListView();
            this.columnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader2 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader3 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader4 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader5 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader6 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader7 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader8 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader9 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader10 = new System.Windows.Forms.ColumnHeader();
            this.btnClose = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.txbVAT = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.txbSale = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.txbSumMoney = new System.Windows.Forms.TextBox();
            this.btnAdd = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // txbStudent
            // 
            this.txbStudent.Location = new System.Drawing.Point(143, 12);
            this.txbStudent.Name = "txbStudent";
            this.txbStudent.Size = new System.Drawing.Size(272, 31);
            this.txbStudent.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(18, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(112, 25);
            this.label1.TabIndex = 1;
            this.label1.Text = "Tên sinh viên";
            // 
            // cmbCourse
            // 
            this.cmbCourse.FormattingEnabled = true;
            this.cmbCourse.Location = new System.Drawing.Point(143, 60);
            this.cmbCourse.Name = "cmbCourse";
            this.cmbCourse.Size = new System.Drawing.Size(272, 33);
            this.cmbCourse.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(18, 68);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(86, 25);
            this.label2.TabIndex = 3;
            this.label2.Text = "Khoá học";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(18, 123);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(75, 25);
            this.label3.TabIndex = 4;
            this.label3.Text = "Khu vực";
            // 
            // rdbCountry
            // 
            this.rdbCountry.AutoSize = true;
            this.rdbCountry.Location = new System.Drawing.Point(0, 13);
            this.rdbCountry.Name = "rdbCountry";
            this.rdbCountry.Size = new System.Drawing.Size(124, 29);
            this.rdbCountry.TabIndex = 5;
            this.rdbCountry.TabStop = true;
            this.rdbCountry.Text = "Nông thôn";
            this.rdbCountry.UseVisualStyleBackColor = true;
            this.rdbCountry.CheckedChanged += new System.EventHandler(this.Check_Change);
            this.rdbCountry.TextChanged += new System.EventHandler(this.Check_Change);
            // 
            // rdbCity
            // 
            this.rdbCity.AutoSize = true;
            this.rdbCity.Location = new System.Drawing.Point(147, 13);
            this.rdbCity.Name = "rdbCity";
            this.rdbCity.Size = new System.Drawing.Size(122, 29);
            this.rdbCity.TabIndex = 6;
            this.rdbCity.TabStop = true;
            this.rdbCity.Text = "Thành phố";
            this.rdbCity.UseVisualStyleBackColor = true;
            this.rdbCity.CheckedChanged += new System.EventHandler(this.Check_Change);
            this.rdbCity.TextChanged += new System.EventHandler(this.Check_Change);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.rdbCity);
            this.panel1.Controls.Add(this.rdbCountry);
            this.panel1.Location = new System.Drawing.Point(143, 110);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(272, 61);
            this.panel1.TabIndex = 7;
            // 
            // txbNumberOfCredits
            // 
            this.txbNumberOfCredits.Location = new System.Drawing.Point(143, 182);
            this.txbNumberOfCredits.Name = "txbNumberOfCredits";
            this.txbNumberOfCredits.Size = new System.Drawing.Size(272, 31);
            this.txbNumberOfCredits.TabIndex = 8;
            this.txbNumberOfCredits.TextChanged += new System.EventHandler(this.NumberOfCredits_Change);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(18, 188);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(85, 25);
            this.label4.TabIndex = 9;
            this.label4.Text = "Số tín chỉ";
            // 
            // txbDonGia
            // 
            this.txbDonGia.Location = new System.Drawing.Point(142, 238);
            this.txbDonGia.Name = "txbDonGia";
            this.txbDonGia.Size = new System.Drawing.Size(273, 31);
            this.txbDonGia.TabIndex = 10;
            this.txbDonGia.TextChanged += new System.EventHandler(this.NumberOfCredits_Change);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(19, 244);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(75, 25);
            this.label5.TabIndex = 11;
            this.label5.Text = "Đơn giá";
            // 
            // txbThanhTien
            // 
            this.txbThanhTien.Location = new System.Drawing.Point(618, 12);
            this.txbThanhTien.Name = "txbThanhTien";
            this.txbThanhTien.Size = new System.Drawing.Size(262, 31);
            this.txbThanhTien.TabIndex = 12;
            this.txbThanhTien.TextChanged += new System.EventHandler(this.ThanhTien_Change);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(490, 18);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(94, 25);
            this.label6.TabIndex = 13;
            this.label6.Text = "Thành tiền";
            // 
            // listView
            // 
            this.listView.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4,
            this.columnHeader5,
            this.columnHeader6,
            this.columnHeader7,
            this.columnHeader8,
            this.columnHeader9,
            this.columnHeader10});
            listViewItem1.IndentCount = 1;
            this.listView.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem1});
            this.listView.Location = new System.Drawing.Point(1, 368);
            this.listView.Name = "listView";
            this.listView.Size = new System.Drawing.Size(914, 276);
            this.listView.TabIndex = 14;
            this.listView.UseCompatibleStateImageBehavior = false;
            this.listView.View = System.Windows.Forms.View.Details;
            this.listView.ColumnClick += new System.Windows.Forms.ColumnClickEventHandler(this.Column_Click);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "STT";
            this.columnHeader1.Width = 50;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Tên sinh viên";
            this.columnHeader2.Width = 120;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Khoá học";
            this.columnHeader3.Width = 90;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Khu vực";
            this.columnHeader4.Width = 80;
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "Số tín chỉ";
            this.columnHeader5.Width = 90;
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "Đơn giá";
            this.columnHeader6.Width = 80;
            // 
            // columnHeader7
            // 
            this.columnHeader7.Text = "Thành tiền";
            this.columnHeader7.Width = 100;
            // 
            // columnHeader8
            // 
            this.columnHeader8.Text = "Thuế VAT";
            this.columnHeader8.Width = 100;
            // 
            // columnHeader9
            // 
            this.columnHeader9.Text = "Giảm giá";
            this.columnHeader9.Width = 100;
            // 
            // columnHeader10
            // 
            this.columnHeader10.Text = "Tổng tiền";
            this.columnHeader10.Width = 110;
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(800, 650);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(115, 36);
            this.btnClose.TabIndex = 15;
            this.btnClose.Text = "Thoát";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.Close_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(490, 66);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(85, 25);
            this.label7.TabIndex = 17;
            this.label7.Text = "Thuế VAT";
            // 
            // txbVAT
            // 
            this.txbVAT.Location = new System.Drawing.Point(618, 60);
            this.txbVAT.Name = "txbVAT";
            this.txbVAT.Size = new System.Drawing.Size(262, 31);
            this.txbVAT.TabIndex = 16;
            this.txbVAT.TextChanged += new System.EventHandler(this.VAT_Change);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(490, 123);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(82, 25);
            this.label8.TabIndex = 19;
            this.label8.Text = "Giảm giá";
            // 
            // txbSale
            // 
            this.txbSale.Location = new System.Drawing.Point(618, 117);
            this.txbSale.Name = "txbSale";
            this.txbSale.Size = new System.Drawing.Size(262, 31);
            this.txbSale.TabIndex = 18;
            this.txbSale.TextChanged += new System.EventHandler(this.GiamGia_Change);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(490, 188);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(87, 25);
            this.label9.TabIndex = 21;
            this.label9.Text = "Tổng tiền";
            // 
            // txbSumMoney
            // 
            this.txbSumMoney.Location = new System.Drawing.Point(618, 182);
            this.txbSumMoney.Name = "txbSumMoney";
            this.txbSumMoney.Size = new System.Drawing.Size(262, 31);
            this.txbSumMoney.TabIndex = 20;
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(767, 238);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(113, 44);
            this.btnAdd.TabIndex = 22;
            this.btnAdd.Text = "Thêm";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.Add_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(916, 688);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.txbSumMoney);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.txbSale);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.txbVAT);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.listView);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.txbThanhTien);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.txbDonGia);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txbNumberOfCredits);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.cmbCourse);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txbStudent);
            this.Name = "Form1";
            this.Text = "Form1";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private TextBox txbStudent;
        private Label label1;
        private ComboBox cmbCourse;
        private Label label2;
        private Label label3;
        private RadioButton rdbCountry;
        private RadioButton rdbCity;
        private Panel panel1;
        private TextBox txbNumberOfCredits;
        private Label label4;
        private TextBox txbDonGia;
        private Label label5;
        private TextBox txbThanhTien;
        private Label label6;
        private ListView listView;
        private Button btnClose;
        private Label label7;
        private TextBox txbVAT;
        private Label label8;
        private TextBox txbSale;
        private Label label9;
        private TextBox txbSumMoney;
        private Button btnAdd;
        private ColumnHeader columnHeader1;
        private ColumnHeader columnHeader2;
        private ColumnHeader columnHeader3;
        private ColumnHeader columnHeader4;
        private ColumnHeader columnHeader5;
        private ColumnHeader columnHeader6;
        private ColumnHeader columnHeader7;
        private ColumnHeader columnHeader8;
        private ColumnHeader columnHeader9;
        private ColumnHeader columnHeader10;
    }
}