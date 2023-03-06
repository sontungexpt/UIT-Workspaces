namespace Bai11
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
            this.DrawingSpace = new System.Windows.Forms.Panel();
            this.btnColor = new System.Windows.Forms.Button();
            this.txbLineWidth = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.cmbShape = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // DrawingSpace
            // 
            this.DrawingSpace.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.DrawingSpace.Location = new System.Drawing.Point(12, 12);
            this.DrawingSpace.Name = "DrawingSpace";
            this.DrawingSpace.Size = new System.Drawing.Size(631, 426);
            this.DrawingSpace.TabIndex = 0;
            this.DrawingSpace.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseDown);
            this.DrawingSpace.MouseMove += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseMove);
            this.DrawingSpace.MouseUp += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseUp);
            // 
            // btnColor
            // 
            this.btnColor.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.btnColor.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btnColor.Location = new System.Drawing.Point(667, 12);
            this.btnColor.Name = "btnColor";
            this.btnColor.Size = new System.Drawing.Size(121, 46);
            this.btnColor.TabIndex = 0;
            this.btnColor.Text = "Black";
            this.btnColor.UseVisualStyleBackColor = false;
            this.btnColor.Click += new System.EventHandler(this.btnColor_Click);
            // 
            // txbLineWidth
            // 
            this.txbLineWidth.Location = new System.Drawing.Point(665, 93);
            this.txbLineWidth.Name = "txbLineWidth";
            this.txbLineWidth.Size = new System.Drawing.Size(123, 26);
            this.txbLineWidth.TabIndex = 1;
            this.txbLineWidth.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(677, 70);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(80, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "Line width";
            // 
            // cmbShape
            // 
            this.cmbShape.FormattingEnabled = true;
            this.cmbShape.Location = new System.Drawing.Point(663, 186);
            this.cmbShape.Name = "cmbShape";
            this.cmbShape.Size = new System.Drawing.Size(125, 28);
            this.cmbShape.TabIndex = 3;
            this.cmbShape.SelectedIndexChanged += new System.EventHandler(this.cmbShape_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(663, 152);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 20);
            this.label2.TabIndex = 4;
            this.label2.Text = "Shape";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.cmbShape);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txbLineWidth);
            this.Controls.Add(this.btnColor);
            this.Controls.Add(this.DrawingSpace);
            this.Name = "Form1";
            this.Text = "Line width";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel DrawingSpace;
        private System.Windows.Forms.Button btnColor;
        private System.Windows.Forms.TextBox txbLineWidth;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cmbShape;
        private System.Windows.Forms.Label label2;
    }
}

