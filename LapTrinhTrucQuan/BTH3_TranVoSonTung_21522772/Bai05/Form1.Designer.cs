namespace Bai5
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
            this.lbl1 = new System.Windows.Forms.Label();
            this.lbl2 = new System.Windows.Forms.Label();
            this.txbNumber1 = new System.Windows.Forms.TextBox();
            this.txbNumber2 = new System.Windows.Forms.TextBox();
            this.txtkq = new System.Windows.Forms.TextBox();
            this.btncong = new System.Windows.Forms.Button();
            this.btntru = new System.Windows.Forms.Button();
            this.btnnhan = new System.Windows.Forms.Button();
            this.btnchia = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lbl1
            // 
            this.lbl1.AutoSize = true;
            this.lbl1.Font = new System.Drawing.Font("Segoe UI", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.lbl1.Location = new System.Drawing.Point(141, 141);
            this.lbl1.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.lbl1.Name = "lbl1";
            this.lbl1.Size = new System.Drawing.Size(142, 38);
            this.lbl1.TabIndex = 0;
            this.lbl1.Text = "Number 1";
            // 
            // lbl2
            // 
            this.lbl2.AutoSize = true;
            this.lbl2.Font = new System.Drawing.Font("Segoe UI", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.lbl2.Location = new System.Drawing.Point(141, 229);
            this.lbl2.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.lbl2.Name = "lbl2";
            this.lbl2.Size = new System.Drawing.Size(142, 38);
            this.lbl2.TabIndex = 1;
            this.lbl2.Text = "Number 2";
            // 
            // txbNumber1
            // 
            this.txbNumber1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txbNumber1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.txbNumber1.Font = new System.Drawing.Font("Segoe UI", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.txbNumber1.Location = new System.Drawing.Point(339, 133);
            this.txbNumber1.Margin = new System.Windows.Forms.Padding(6);
            this.txbNumber1.Name = "txbNumber1";
            this.txbNumber1.Size = new System.Drawing.Size(293, 51);
            this.txbNumber1.TabIndex = 2;
            // 
            // txbNumber2
            // 
            this.txbNumber2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txbNumber2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.txbNumber2.Font = new System.Drawing.Font("Segoe UI", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.txbNumber2.Location = new System.Drawing.Point(339, 225);
            this.txbNumber2.Margin = new System.Windows.Forms.Padding(6);
            this.txbNumber2.Name = "txbNumber2";
            this.txbNumber2.Size = new System.Drawing.Size(293, 51);
            this.txbNumber2.TabIndex = 3;
            // 
            // txtkq
            // 
            this.txtkq.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtkq.Font = new System.Drawing.Font("Segoe UI", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.txtkq.Location = new System.Drawing.Point(242, 507);
            this.txtkq.Margin = new System.Windows.Forms.Padding(6);
            this.txtkq.Name = "txtkq";
            this.txtkq.ReadOnly = true;
            this.txtkq.Size = new System.Drawing.Size(334, 51);
            this.txtkq.TabIndex = 4;
            // 
            // btncong
            // 
            this.btncong.Font = new System.Drawing.Font("Segoe UI", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.btncong.Location = new System.Drawing.Point(146, 372);
            this.btncong.Margin = new System.Windows.Forms.Padding(6);
            this.btncong.Name = "btncong";
            this.btncong.Size = new System.Drawing.Size(77, 81);
            this.btncong.TabIndex = 5;
            this.btncong.Text = "+";
            this.btncong.UseVisualStyleBackColor = true;
            this.btncong.Click += new System.EventHandler(this.btncong_Click);
            // 
            // btntru
            // 
            this.btntru.Font = new System.Drawing.Font("Segoe UI", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.btntru.Location = new System.Drawing.Point(298, 372);
            this.btntru.Margin = new System.Windows.Forms.Padding(6);
            this.btntru.Name = "btntru";
            this.btntru.Size = new System.Drawing.Size(77, 81);
            this.btntru.TabIndex = 6;
            this.btntru.Text = "-";
            this.btntru.UseVisualStyleBackColor = true;
            this.btntru.Click += new System.EventHandler(this.btntru_Click);
            // 
            // btnnhan
            // 
            this.btnnhan.Font = new System.Drawing.Font("Segoe UI", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.btnnhan.Location = new System.Drawing.Point(450, 372);
            this.btnnhan.Margin = new System.Windows.Forms.Padding(6);
            this.btnnhan.Name = "btnnhan";
            this.btnnhan.Size = new System.Drawing.Size(77, 81);
            this.btnnhan.TabIndex = 7;
            this.btnnhan.Text = "*";
            this.btnnhan.UseVisualStyleBackColor = true;
            this.btnnhan.Click += new System.EventHandler(this.btnnhan_Click);
            // 
            // btnchia
            // 
            this.btnchia.Font = new System.Drawing.Font("Segoe UI", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.btnchia.Location = new System.Drawing.Point(602, 372);
            this.btnchia.Margin = new System.Windows.Forms.Padding(6);
            this.btnchia.Name = "btnchia";
            this.btnchia.Size = new System.Drawing.Size(77, 81);
            this.btnchia.TabIndex = 8;
            this.btnchia.Text = "/";
            this.btnchia.UseVisualStyleBackColor = true;
            this.btnchia.Click += new System.EventHandler(this.btnchia_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(18F, 45F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(829, 579);
            this.Controls.Add(this.btnchia);
            this.Controls.Add(this.btnnhan);
            this.Controls.Add(this.btntru);
            this.Controls.Add(this.btncong);
            this.Controls.Add(this.txtkq);
            this.Controls.Add(this.txbNumber2);
            this.Controls.Add(this.txbNumber1);
            this.Controls.Add(this.lbl2);
            this.Controls.Add(this.lbl1);
            this.Font = new System.Drawing.Font("Segoe UI", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Margin = new System.Windows.Forms.Padding(6);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Label lbl1;
        private Label lbl2;
        private TextBox txbNumber1;
        private TextBox txbNumber2;
        private TextBox txtkq;
        private Button btncong;
        private Button btntru;
        private Button btnnhan;
        private Button btnchia;
    }
}