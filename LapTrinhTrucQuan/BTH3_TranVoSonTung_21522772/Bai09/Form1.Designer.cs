namespace Bai09
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.chkbNuSex = new System.Windows.Forms.CheckBox();
            this.chkbNamSex = new System.Windows.Forms.CheckBox();
            this.btnRemove = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.btnToLeft = new System.Windows.Forms.Button();
            this.btnToRight = new System.Windows.Forms.Button();
            this.rtxbSubjectInfoOutput = new System.Windows.Forms.RichTextBox();
            this.rtxbSubjectInfoInput = new System.Windows.Forms.RichTextBox();
            this.txbStudentFullName = new System.Windows.Forms.TextBox();
            this.txbStudentSpecilized = new System.Windows.Forms.TextBox();
            this.txbStudentId = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.listViewStudent = new System.Windows.Forms.ListView();
            this.columnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader2 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader3 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader4 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader5 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader6 = new System.Windows.Forms.ColumnHeader();
            this.label1 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.chkbNuSex);
            this.panel1.Controls.Add(this.chkbNamSex);
            this.panel1.Controls.Add(this.btnRemove);
            this.panel1.Controls.Add(this.btnSave);
            this.panel1.Controls.Add(this.btnToLeft);
            this.panel1.Controls.Add(this.btnToRight);
            this.panel1.Controls.Add(this.rtxbSubjectInfoOutput);
            this.panel1.Controls.Add(this.rtxbSubjectInfoInput);
            this.panel1.Controls.Add(this.txbStudentFullName);
            this.panel1.Controls.Add(this.txbStudentSpecilized);
            this.panel1.Controls.Add(this.txbStudentId);
            this.panel1.Controls.Add(this.label6);
            this.panel1.Controls.Add(this.label5);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Location = new System.Drawing.Point(12, 25);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(838, 405);
            this.panel1.TabIndex = 0;
            this.panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.panel1_Paint);
            // 
            // chkbNuSex
            // 
            this.chkbNuSex.AutoSize = true;
            this.chkbNuSex.Location = new System.Drawing.Point(419, 158);
            this.chkbNuSex.Name = "chkbNuSex";
            this.chkbNuSex.Size = new System.Drawing.Size(62, 29);
            this.chkbNuSex.TabIndex = 18;
            this.chkbNuSex.Text = "Nữ";
            this.chkbNuSex.UseVisualStyleBackColor = true;
            this.chkbNuSex.CheckedChanged += new System.EventHandler(this.NuCkb_Changed);
            // 
            // chkbNamSex
            // 
            this.chkbNamSex.AutoSize = true;
            this.chkbNamSex.Location = new System.Drawing.Point(308, 158);
            this.chkbNamSex.Name = "chkbNamSex";
            this.chkbNamSex.Size = new System.Drawing.Size(76, 29);
            this.chkbNamSex.TabIndex = 17;
            this.chkbNamSex.Text = "Nam";
            this.chkbNamSex.UseVisualStyleBackColor = true;
            this.chkbNamSex.CheckedChanged += new System.EventHandler(this.NamCkb_Changed);
            // 
            // btnRemove
            // 
            this.btnRemove.BackColor = System.Drawing.Color.Silver;
            this.btnRemove.Location = new System.Drawing.Point(502, 347);
            this.btnRemove.Name = "btnRemove";
            this.btnRemove.Size = new System.Drawing.Size(146, 37);
            this.btnRemove.TabIndex = 16;
            this.btnRemove.Text = "Xoá chọn";
            this.btnRemove.UseVisualStyleBackColor = false;
            this.btnRemove.Click += new System.EventHandler(this.removeBtnClicked);
            // 
            // btnSave
            // 
            this.btnSave.BackColor = System.Drawing.Color.Silver;
            this.btnSave.Location = new System.Drawing.Point(210, 347);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(146, 37);
            this.btnSave.TabIndex = 15;
            this.btnSave.Text = "Lưu thông tin";
            this.btnSave.UseVisualStyleBackColor = false;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Clicked);
            // 
            // btnToLeft
            // 
            this.btnToLeft.BackColor = System.Drawing.Color.Silver;
            this.btnToLeft.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnToLeft.Location = new System.Drawing.Point(393, 292);
            this.btnToLeft.Name = "btnToLeft";
            this.btnToLeft.Size = new System.Drawing.Size(62, 37);
            this.btnToLeft.TabIndex = 14;
            this.btnToLeft.Text = "<";
            this.btnToLeft.UseVisualStyleBackColor = false;
            this.btnToLeft.Click += new System.EventHandler(this.ToRightBtn_Clicked);
            // 
            // btnToRight
            // 
            this.btnToRight.BackColor = System.Drawing.Color.Silver;
            this.btnToRight.Location = new System.Drawing.Point(393, 249);
            this.btnToRight.Name = "btnToRight";
            this.btnToRight.Size = new System.Drawing.Size(62, 37);
            this.btnToRight.TabIndex = 13;
            this.btnToRight.Text = ">";
            this.btnToRight.UseVisualStyleBackColor = false;
            this.btnToRight.Click += new System.EventHandler(this.toLeftBtn_CLicked);
            // 
            // rtxbSubjectInfoOutput
            // 
            this.rtxbSubjectInfoOutput.Location = new System.Drawing.Point(469, 240);
            this.rtxbSubjectInfoOutput.Name = "rtxbSubjectInfoOutput";
            this.rtxbSubjectInfoOutput.Size = new System.Drawing.Size(206, 101);
            this.rtxbSubjectInfoOutput.TabIndex = 12;
            this.rtxbSubjectInfoOutput.Text = "";
            // 
            // rtxbSubjectInfoInput
            // 
            this.rtxbSubjectInfoInput.Location = new System.Drawing.Point(176, 240);
            this.rtxbSubjectInfoInput.Name = "rtxbSubjectInfoInput";
            this.rtxbSubjectInfoInput.Size = new System.Drawing.Size(206, 101);
            this.rtxbSubjectInfoInput.TabIndex = 11;
            this.rtxbSubjectInfoInput.Text = "";
            // 
            // txbStudentFullName
            // 
            this.txbStudentFullName.Location = new System.Drawing.Point(308, 75);
            this.txbStudentFullName.Name = "txbStudentFullName";
            this.txbStudentFullName.Size = new System.Drawing.Size(232, 31);
            this.txbStudentFullName.TabIndex = 8;
            // 
            // txbStudentSpecilized
            // 
            this.txbStudentSpecilized.Location = new System.Drawing.Point(308, 112);
            this.txbStudentSpecilized.Name = "txbStudentSpecilized";
            this.txbStudentSpecilized.Size = new System.Drawing.Size(232, 31);
            this.txbStudentSpecilized.TabIndex = 6;
            // 
            // txbStudentId
            // 
            this.txbStudentId.Location = new System.Drawing.Point(308, 35);
            this.txbStudentId.Name = "txbStudentId";
            this.txbStudentId.Size = new System.Drawing.Size(232, 31);
            this.txbStudentId.TabIndex = 5;
            this.txbStudentId.TextChanged += new System.EventHandler(this.txbStudentId_TextChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(176, 159);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(78, 25);
            this.label6.TabIndex = 4;
            this.label6.Text = "Giới tính";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(176, 118);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(126, 25);
            this.label5.TabIndex = 3;
            this.label5.Text = "Chuyên ngành";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(176, 201);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(235, 25);
            this.label4.TabIndex = 2;
            this.label4.Text = "Chọn các môn học tham gia";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(176, 76);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(66, 25);
            this.label3.TabIndex = 1;
            this.label3.Text = "Họ tên";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(176, 41);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(111, 25);
            this.label2.TabIndex = 0;
            this.label2.Text = "Mã sinh viên";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // listViewStudent
            // 
            this.listViewStudent.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4,
            this.columnHeader5,
            this.columnHeader6});
            this.listViewStudent.GridLines = true;
            this.listViewStudent.Location = new System.Drawing.Point(12, 436);
            this.listViewStudent.Name = "listViewStudent";
            this.listViewStudent.Size = new System.Drawing.Size(838, 170);
            this.listViewStudent.TabIndex = 17;
            this.listViewStudent.UseCompatibleStateImageBehavior = false;
            this.listViewStudent.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "";
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "MSSV";
            this.columnHeader2.Width = 73;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Họ tên";
            this.columnHeader3.Width = 250;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Chuyên ngành";
            this.columnHeader4.Width = 250;
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "Giới tính";
            this.columnHeader5.Width = 100;
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "Số môn";
            this.columnHeader6.Width = 100;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label1.Location = new System.Drawing.Point(9, 2);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(142, 21);
            this.label1.TabIndex = 0;
            this.label1.Text = "Thông tin sinh viên";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.label1);
            this.panel2.Location = new System.Drawing.Point(45, 12);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(159, 34);
            this.panel2.TabIndex = 1;
            this.panel2.Paint += new System.Windows.Forms.PaintEventHandler(this.panel2_Paint);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(862, 618);
            this.Controls.Add(this.listViewStudent);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private Panel panel1;
        private Label label1;
        private Panel panel2;
        private Label label2;
        private Label label6;
        private Label label5;
        private Label label4;
        private Label label3;
        private TextBox txbStudentFullName;
        private TextBox txbStudentSpecilized;
        private TextBox txbStudentId;
        private RichTextBox rtxbSubjectInfoInput;
        private RichTextBox rtxbSubjectInfoOutput;
        private Button btnToRight;
        private Button btnToLeft;
        private Button btnRemove;
        private Button btnSave;
        private ListView listViewStudent;
        private ColumnHeader columnHeader1;
        private ColumnHeader columnHeader2;
        private ColumnHeader columnHeader3;
        private ColumnHeader columnHeader4;
        private ColumnHeader columnHeader5;
        private ColumnHeader columnHeader6;
        private CheckBox chkbNamSex;
        private CheckBox chkbNuSex;
    }
}