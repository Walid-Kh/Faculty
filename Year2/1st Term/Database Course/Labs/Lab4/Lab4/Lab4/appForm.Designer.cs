namespace WindowsFormsApplication1
{
    partial class AppForm
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.UpdateBtn = new System.Windows.Forms.Button();
            this.GetButton = new System.Windows.Forms.Button();
            this.AgeNumericUpDown = new System.Windows.Forms.NumericUpDown();
            this.AgeLabel = new System.Windows.Forms.Label();
            this.NameTextBox = new System.Windows.Forms.TextBox();
            this.NameLabel = new System.Windows.Forms.Label();
            this.SportNumericUpDown = new System.Windows.Forms.NumericUpDown();
            this.SportIDLabel = new System.Windows.Forms.Label();
            this.AthIDLabel = new System.Windows.Forms.Label();
            this.AthleteNumericUpDown = new System.Windows.Forms.NumericUpDown();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.AgeNumericUpDown)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.SportNumericUpDown)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.AthleteNumericUpDown)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.UpdateBtn);
            this.groupBox1.Controls.Add(this.GetButton);
            this.groupBox1.Controls.Add(this.AgeNumericUpDown);
            this.groupBox1.Controls.Add(this.AgeLabel);
            this.groupBox1.Controls.Add(this.NameTextBox);
            this.groupBox1.Controls.Add(this.NameLabel);
            this.groupBox1.Controls.Add(this.SportNumericUpDown);
            this.groupBox1.Controls.Add(this.SportIDLabel);
            this.groupBox1.Controls.Add(this.AthIDLabel);
            this.groupBox1.Controls.Add(this.AthleteNumericUpDown);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(521, 327);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Athletes";
            // 
            // UpdateBtn
            // 
            this.UpdateBtn.Location = new System.Drawing.Point(282, 88);
            this.UpdateBtn.Name = "UpdateBtn";
            this.UpdateBtn.Size = new System.Drawing.Size(75, 23);
            this.UpdateBtn.TabIndex = 9;
            this.UpdateBtn.Text = "Update";
            this.UpdateBtn.UseVisualStyleBackColor = true;
            this.UpdateBtn.Click += new System.EventHandler(this.UpdateBtn_Click);
            // 
            // GetButton
            // 
            this.GetButton.Location = new System.Drawing.Point(201, 88);
            this.GetButton.Name = "GetButton";
            this.GetButton.Size = new System.Drawing.Size(75, 23);
            this.GetButton.TabIndex = 8;
            this.GetButton.Text = "Get";
            this.GetButton.UseVisualStyleBackColor = true;
            this.GetButton.Click += new System.EventHandler(this.GetButton_Click);
            // 
            // AgeNumericUpDown
            // 
            this.AgeNumericUpDown.Location = new System.Drawing.Point(334, 53);
            this.AgeNumericUpDown.Name = "AgeNumericUpDown";
            this.AgeNumericUpDown.Size = new System.Drawing.Size(181, 20);
            this.AgeNumericUpDown.TabIndex = 7;
            // 
            // AgeLabel
            // 
            this.AgeLabel.AutoSize = true;
            this.AgeLabel.Location = new System.Drawing.Point(293, 55);
            this.AgeLabel.Name = "AgeLabel";
            this.AgeLabel.Size = new System.Drawing.Size(26, 13);
            this.AgeLabel.TabIndex = 6;
            this.AgeLabel.Text = "Age";
            // 
            // NameTextBox
            // 
            this.NameTextBox.Location = new System.Drawing.Point(334, 18);
            this.NameTextBox.Name = "NameTextBox";
            this.NameTextBox.Size = new System.Drawing.Size(181, 20);
            this.NameTextBox.TabIndex = 5;
            // 
            // NameLabel
            // 
            this.NameLabel.AutoSize = true;
            this.NameLabel.Location = new System.Drawing.Point(293, 21);
            this.NameLabel.Name = "NameLabel";
            this.NameLabel.Size = new System.Drawing.Size(35, 13);
            this.NameLabel.TabIndex = 4;
            this.NameLabel.Text = "Name";
            // 
            // SportNumericUpDown
            // 
            this.SportNumericUpDown.Location = new System.Drawing.Point(48, 53);
            this.SportNumericUpDown.Name = "SportNumericUpDown";
            this.SportNumericUpDown.Size = new System.Drawing.Size(239, 20);
            this.SportNumericUpDown.TabIndex = 3;
            // 
            // SportIDLabel
            // 
            this.SportIDLabel.AutoSize = true;
            this.SportIDLabel.Location = new System.Drawing.Point(0, 55);
            this.SportIDLabel.Name = "SportIDLabel";
            this.SportIDLabel.Size = new System.Drawing.Size(46, 13);
            this.SportIDLabel.TabIndex = 2;
            this.SportIDLabel.Text = "Sport ID";
            // 
            // AthIDLabel
            // 
            this.AthIDLabel.AutoSize = true;
            this.AthIDLabel.Location = new System.Drawing.Point(7, 21);
            this.AthIDLabel.Name = "AthIDLabel";
            this.AthIDLabel.Size = new System.Drawing.Size(37, 13);
            this.AthIDLabel.TabIndex = 1;
            this.AthIDLabel.Text = "Ath ID";
            // 
            // AthleteNumericUpDown
            // 
            this.AthleteNumericUpDown.Location = new System.Drawing.Point(48, 19);
            this.AthleteNumericUpDown.Name = "AthleteNumericUpDown";
            this.AthleteNumericUpDown.Size = new System.Drawing.Size(239, 20);
            this.AthleteNumericUpDown.TabIndex = 0;
            // 
            // AppForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(545, 351);
            this.Controls.Add(this.groupBox1);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "AppForm";
            this.Text = "AppForm";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.AgeNumericUpDown)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.SportNumericUpDown)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.AthleteNumericUpDown)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.NumericUpDown AgeNumericUpDown;
        private System.Windows.Forms.Label AgeLabel;
        private System.Windows.Forms.TextBox NameTextBox;
        private System.Windows.Forms.Label NameLabel;
        private System.Windows.Forms.NumericUpDown SportNumericUpDown;
        private System.Windows.Forms.Label SportIDLabel;
        private System.Windows.Forms.Label AthIDLabel;
        private System.Windows.Forms.NumericUpDown AthleteNumericUpDown;
        private System.Windows.Forms.Button UpdateBtn;
        private System.Windows.Forms.Button GetButton;
    }
}