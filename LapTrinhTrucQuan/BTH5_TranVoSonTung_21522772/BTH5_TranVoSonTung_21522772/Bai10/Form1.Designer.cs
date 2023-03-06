namespace Bai10
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.cbDashStyle = new System.Windows.Forms.ComboBox();
            this.cbWidth = new System.Windows.Forms.ComboBox();
            this.cbLineJoin = new System.Windows.Forms.ComboBox();
            this.cbDashCap = new System.Windows.Forms.ComboBox();
            this.cbStartCap = new System.Windows.Forms.ComboBox();
            this.cbEndCap = new System.Windows.Forms.ComboBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(16, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(64, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Dash Style: ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(42, 65);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(38, 13);
            this.label2.TabIndex = 0;
            this.label2.Text = "Width:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(28, 102);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(52, 13);
            this.label3.TabIndex = 0;
            this.label3.Text = "Line Join:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(23, 139);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(57, 13);
            this.label4.TabIndex = 0;
            this.label4.Text = "Dash Cap:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(26, 176);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(54, 13);
            this.label5.TabIndex = 0;
            this.label5.Text = "Start Cap:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(29, 213);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(51, 13);
            this.label6.TabIndex = 0;
            this.label6.Text = "End Cap:";
            // 
            // cbDashStyle
            // 
            this.cbDashStyle.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbDashStyle.FormattingEnabled = true;
            this.cbDashStyle.Items.AddRange(new object[] {
            "Custom",
            "Dash",
            "Dot",
            "DashDot",
            "DashDotDot",
            "Solid"});
            this.cbDashStyle.Location = new System.Drawing.Point(86, 25);
            this.cbDashStyle.Name = "cbDashStyle";
            this.cbDashStyle.Size = new System.Drawing.Size(121, 21);
            this.cbDashStyle.TabIndex = 1;
            this.cbDashStyle.SelectedIndexChanged += new System.EventHandler(this.cbDashStyle_SelectedIndexChanged);
            // 
            // cbWidth
            // 
            this.cbWidth.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbWidth.FormattingEnabled = true;
            this.cbWidth.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13"});
            this.cbWidth.Location = new System.Drawing.Point(86, 62);
            this.cbWidth.Name = "cbWidth";
            this.cbWidth.Size = new System.Drawing.Size(121, 21);
            this.cbWidth.TabIndex = 1;
            this.cbWidth.SelectedIndexChanged += new System.EventHandler(this.cbWidth_SelectedIndexChanged);
            // 
            // cbLineJoin
            // 
            this.cbLineJoin.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbLineJoin.FormattingEnabled = true;
            this.cbLineJoin.Items.AddRange(new object[] {
            "Bevel",
            "Miter",
            "MiterClipped",
            "Round"});
            this.cbLineJoin.Location = new System.Drawing.Point(86, 99);
            this.cbLineJoin.Name = "cbLineJoin";
            this.cbLineJoin.Size = new System.Drawing.Size(121, 21);
            this.cbLineJoin.TabIndex = 1;
            this.cbLineJoin.SelectedIndexChanged += new System.EventHandler(this.cbLineJoin_SelectedIndexChanged);
            // 
            // cbDashCap
            // 
            this.cbDashCap.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbDashCap.FormattingEnabled = true;
            this.cbDashCap.Items.AddRange(new object[] {
            "Round",
            "Flat",
            "Triangle"});
            this.cbDashCap.Location = new System.Drawing.Point(86, 136);
            this.cbDashCap.Name = "cbDashCap";
            this.cbDashCap.Size = new System.Drawing.Size(121, 21);
            this.cbDashCap.TabIndex = 1;
            this.cbDashCap.SelectedIndexChanged += new System.EventHandler(this.cbDashCap_SelectedIndexChanged);
            // 
            // cbStartCap
            // 
            this.cbStartCap.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbStartCap.FormattingEnabled = true;
            this.cbStartCap.Items.AddRange(new object[] {
            "AnchorMask",
            "ArrowAnchor",
            "Custom",
            "DiamondAnchor",
            "Flat",
            "NoAnchor",
            "Round",
            "RoundAnchor",
            "Square",
            "SquareAnchor",
            "Triangle"});
            this.cbStartCap.Location = new System.Drawing.Point(86, 173);
            this.cbStartCap.Name = "cbStartCap";
            this.cbStartCap.Size = new System.Drawing.Size(121, 21);
            this.cbStartCap.TabIndex = 1;
            this.cbStartCap.SelectedIndexChanged += new System.EventHandler(this.cbStartCap_SelectedIndexChanged);
            // 
            // cbEndCap
            // 
            this.cbEndCap.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbEndCap.FormattingEnabled = true;
            this.cbEndCap.Items.AddRange(new object[] {
            "AnchorMask",
            "ArrowAnchor",
            "Custom",
            "DiamondAnchor",
            "Flat",
            "NoAnchor",
            "Round",
            "RoundAnchor",
            "Square",
            "SquareAnchor",
            "Triangle"});
            this.cbEndCap.Location = new System.Drawing.Point(86, 210);
            this.cbEndCap.Name = "cbEndCap";
            this.cbEndCap.Size = new System.Drawing.Size(121, 21);
            this.cbEndCap.TabIndex = 1;
            this.cbEndCap.SelectedIndexChanged += new System.EventHandler(this.cbEndCap_SelectedIndexChanged);
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Location = new System.Drawing.Point(232, 25);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(332, 295);
            this.panel1.TabIndex = 2;
            this.panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.panel1_Paint);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(589, 347);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.cbEndCap);
            this.Controls.Add(this.cbStartCap);
            this.Controls.Add(this.cbLineJoin);
            this.Controls.Add(this.cbDashCap);
            this.Controls.Add(this.cbWidth);
            this.Controls.Add(this.cbDashStyle);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox cbDashStyle;
        private System.Windows.Forms.ComboBox cbWidth;
        private System.Windows.Forms.ComboBox cbLineJoin;
        private System.Windows.Forms.ComboBox cbDashCap;
        private System.Windows.Forms.ComboBox cbStartCap;
        private System.Windows.Forms.ComboBox cbEndCap;
        private System.Windows.Forms.Panel panel1;
    }
}

