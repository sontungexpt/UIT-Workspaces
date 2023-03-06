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
            this.FontArea = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // FontArea
            // 
            this.FontArea.Location = new System.Drawing.Point(2, 2);
            this.FontArea.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.FontArea.Name = "FontArea";
            this.FontArea.ReadOnly = true;
            this.FontArea.Size = new System.Drawing.Size(511, 786);
            this.FontArea.TabIndex = 0;
            this.FontArea.Text = "";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(516, 786);
            this.Controls.Add(this.FontArea);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.MinimumSize = new System.Drawing.Size(529, 816);
            this.Name = "Form1";
            this.Text = "All font";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RichTextBox FontArea;
    }
}

