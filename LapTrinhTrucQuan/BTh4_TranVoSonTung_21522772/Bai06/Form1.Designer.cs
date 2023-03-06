namespace Bai06
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.CopyBtn = new System.Windows.Forms.Button();
            this.btnDestPath = new System.Windows.Forms.Button();
            this.btnSourcePath = new System.Windows.Forms.Button();
            this.txbDestPath = new System.Windows.Forms.TextBox();
            this.txbSourcePath = new System.Windows.Forms.TextBox();
            this.destPath = new System.Windows.Forms.Label();
            this.sourcePath = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.progressBar = new System.Windows.Forms.ProgressBar();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.CopyBtn);
            this.panel1.Controls.Add(this.btnDestPath);
            this.panel1.Controls.Add(this.btnSourcePath);
            this.panel1.Controls.Add(this.txbDestPath);
            this.panel1.Controls.Add(this.txbSourcePath);
            this.panel1.Controls.Add(this.destPath);
            this.panel1.Controls.Add(this.sourcePath);
            this.panel1.Location = new System.Drawing.Point(38, 40);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(722, 230);
            this.panel1.TabIndex = 0;
            // 
            // CopyBtn
            // 
            this.CopyBtn.BackColor = System.Drawing.SystemColors.ControlLight;
            this.CopyBtn.Location = new System.Drawing.Point(240, 165);
            this.CopyBtn.Name = "CopyBtn";
            this.CopyBtn.Size = new System.Drawing.Size(189, 36);
            this.CopyBtn.TabIndex = 6;
            this.CopyBtn.Text = "Sao chép";
            this.CopyBtn.UseVisualStyleBackColor = false;
            this.CopyBtn.Click += new System.EventHandler(this.CopyBtn_Click);
            // 
            // btnDestPath
            // 
            this.btnDestPath.BackColor = System.Drawing.SystemColors.ControlLight;
            this.btnDestPath.ForeColor = System.Drawing.SystemColors.Highlight;
            this.btnDestPath.Location = new System.Drawing.Point(636, 109);
            this.btnDestPath.Name = "btnDestPath";
            this.btnDestPath.Size = new System.Drawing.Size(51, 30);
            this.btnDestPath.TabIndex = 5;
            this.btnDestPath.Text = "...";
            this.btnDestPath.UseVisualStyleBackColor = false;
            this.btnDestPath.Click += new System.EventHandler(this.btnDestPath_Click);
            // 
            // btnSourcePath
            // 
            this.btnSourcePath.BackColor = System.Drawing.SystemColors.ControlLight;
            this.btnSourcePath.ForeColor = System.Drawing.SystemColors.Highlight;
            this.btnSourcePath.Location = new System.Drawing.Point(637, 39);
            this.btnSourcePath.Name = "btnSourcePath";
            this.btnSourcePath.Size = new System.Drawing.Size(51, 30);
            this.btnSourcePath.TabIndex = 4;
            this.btnSourcePath.Text = "...";
            this.btnSourcePath.UseVisualStyleBackColor = false;
            this.btnSourcePath.Click += new System.EventHandler(this.btnSourcePath_Click);
            // 
            // txbDestPath
            // 
            this.txbDestPath.Location = new System.Drawing.Point(240, 106);
            this.txbDestPath.Name = "txbDestPath";
            this.txbDestPath.Size = new System.Drawing.Size(366, 26);
            this.txbDestPath.TabIndex = 3;
            // 
            // txbSourcePath
            // 
            this.txbSourcePath.Location = new System.Drawing.Point(240, 35);
            this.txbSourcePath.Name = "txbSourcePath";
            this.txbSourcePath.Size = new System.Drawing.Size(366, 26);
            this.txbSourcePath.TabIndex = 2;
            // 
            // destPath
            // 
            this.destPath.AutoSize = true;
            this.destPath.Location = new System.Drawing.Point(25, 106);
            this.destPath.Name = "destPath";
            this.destPath.Size = new System.Drawing.Size(182, 20);
            this.destPath.TabIndex = 1;
            this.destPath.Text = "Đường dẫn thư mục đích";
            // 
            // sourcePath
            // 
            this.sourcePath.AutoSize = true;
            this.sourcePath.Location = new System.Drawing.Point(25, 41);
            this.sourcePath.Name = "sourcePath";
            this.sourcePath.Size = new System.Drawing.Size(202, 20);
            this.sourcePath.TabIndex = 0;
            this.sourcePath.Text = "Đường dẫn thư mục nguồn ";
            // 
            // panel2
            // 
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel2.Controls.Add(this.progressBar);
            this.panel2.Location = new System.Drawing.Point(38, 340);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(722, 86);
            this.panel2.TabIndex = 1;
            // 
            // progressBar
            // 
            this.progressBar.Location = new System.Drawing.Point(43, 23);
            this.progressBar.Name = "progressBar";
            this.progressBar.Size = new System.Drawing.Size(644, 44);
            this.progressBar.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.label1.Location = new System.Drawing.Point(64, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(125, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "Sao chép tập tin";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.label2.Location = new System.Drawing.Point(64, 326);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(143, 20);
            this.label2.TabIndex = 3;
            this.label2.Text = "Tiến trình sao chép";
            // 
            // backgroundWorker1
            // 
            
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.panel2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnDestPath;
        private System.Windows.Forms.Button btnSourcePath;
        private System.Windows.Forms.TextBox txbDestPath;
        private System.Windows.Forms.TextBox txbSourcePath;
        private System.Windows.Forms.Label destPath;
        private System.Windows.Forms.Label sourcePath;
        private System.Windows.Forms.ProgressBar progressBar;
        private System.Windows.Forms.Button CopyBtn;
        
    }
}

