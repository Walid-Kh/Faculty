namespace Lab2
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
            this.CourseNameLabel = new System.Windows.Forms.Label();
            this.MinStudentCapacityLabel = new System.Windows.Forms.Label();
            this.MaxStudentCapacityLabel = new System.Windows.Forms.Label();
            this.CoursesComboBox = new System.Windows.Forms.ComboBox();
            this.MinStudentCapacityUpDown = new System.Windows.Forms.NumericUpDown();
            this.MaxStudentCapacityUpDown = new System.Windows.Forms.NumericUpDown();
            this.AddCourseBtn = new System.Windows.Forms.Button();
            this.RemoveCourseBtn = new System.Windows.Forms.Button();
            this.ClearBtn = new System.Windows.Forms.Button();
            this.CourseGrid = new System.Windows.Forms.DataGridView();
            this.CourseCol = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.MinStudentCapacityCol = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.MaxStudentCapacityCol = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.MinStudentCapacityUpDown)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.MaxStudentCapacityUpDown)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.CourseGrid)).BeginInit();
            this.SuspendLayout();
            // 
            // CourseNameLabel
            // 
            this.CourseNameLabel.AutoSize = true;
            this.CourseNameLabel.Location = new System.Drawing.Point(194, 9);
            this.CourseNameLabel.Name = "CourseNameLabel";
            this.CourseNameLabel.Size = new System.Drawing.Size(79, 15);
            this.CourseNameLabel.TabIndex = 0;
            this.CourseNameLabel.Text = "Course Name";
            // 
            // MinStudentCapacityLabel
            // 
            this.MinStudentCapacityLabel.AutoSize = true;
            this.MinStudentCapacityLabel.Location = new System.Drawing.Point(194, 38);
            this.MinStudentCapacityLabel.Name = "MinStudentCapacityLabel";
            this.MinStudentCapacityLabel.Size = new System.Drawing.Size(121, 15);
            this.MinStudentCapacityLabel.TabIndex = 1;
            this.MinStudentCapacityLabel.Text = "Min Student Capacity";
            // 
            // MaxStudentCapacityLabel
            // 
            this.MaxStudentCapacityLabel.AutoSize = true;
            this.MaxStudentCapacityLabel.Location = new System.Drawing.Point(194, 67);
            this.MaxStudentCapacityLabel.Name = "MaxStudentCapacityLabel";
            this.MaxStudentCapacityLabel.Size = new System.Drawing.Size(123, 15);
            this.MaxStudentCapacityLabel.TabIndex = 2;
            this.MaxStudentCapacityLabel.Text = "Max Student Capacity";
            // 
            // CoursesComboBox
            // 
            this.CoursesComboBox.FormattingEnabled = true;
            this.CoursesComboBox.Items.AddRange(new object[] {
            "Statistics",
            "Math ",
            "Programming"});
            this.CoursesComboBox.Location = new System.Drawing.Point(321, 6);
            this.CoursesComboBox.Name = "CoursesComboBox";
            this.CoursesComboBox.Size = new System.Drawing.Size(121, 23);
            this.CoursesComboBox.TabIndex = 3;
            // 
            // MinStudentCapacityUpDown
            // 
            this.MinStudentCapacityUpDown.Location = new System.Drawing.Point(322, 36);
            this.MinStudentCapacityUpDown.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.MinStudentCapacityUpDown.Minimum = new decimal(new int[] {
            256,
            0,
            0,
            -2147483648});
            this.MinStudentCapacityUpDown.Name = "MinStudentCapacityUpDown";
            this.MinStudentCapacityUpDown.Size = new System.Drawing.Size(120, 23);
            this.MinStudentCapacityUpDown.TabIndex = 4;
            // 
            // MaxStudentCapacityUpDown
            // 
            this.MaxStudentCapacityUpDown.Location = new System.Drawing.Point(323, 65);
            this.MaxStudentCapacityUpDown.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.MaxStudentCapacityUpDown.Minimum = new decimal(new int[] {
            256,
            0,
            0,
            -2147483648});
            this.MaxStudentCapacityUpDown.Name = "MaxStudentCapacityUpDown";
            this.MaxStudentCapacityUpDown.Size = new System.Drawing.Size(120, 23);
            this.MaxStudentCapacityUpDown.TabIndex = 5;
            // 
            // AddCourseBtn
            // 
            this.AddCourseBtn.Location = new System.Drawing.Point(473, 6);
            this.AddCourseBtn.Name = "AddCourseBtn";
            this.AddCourseBtn.Size = new System.Drawing.Size(117, 23);
            this.AddCourseBtn.TabIndex = 6;
            this.AddCourseBtn.Text = "Add Course";
            this.AddCourseBtn.UseVisualStyleBackColor = true;
            this.AddCourseBtn.Click += new System.EventHandler(this.AddCourseBtn_Click);
            // 
            // RemoveCourseBtn
            // 
            this.RemoveCourseBtn.Location = new System.Drawing.Point(473, 36);
            this.RemoveCourseBtn.Name = "RemoveCourseBtn";
            this.RemoveCourseBtn.Size = new System.Drawing.Size(117, 23);
            this.RemoveCourseBtn.TabIndex = 7;
            this.RemoveCourseBtn.Text = "Remove Course";
            this.RemoveCourseBtn.UseVisualStyleBackColor = true;
            this.RemoveCourseBtn.Click += new System.EventHandler(this.RemoveCourseBtn_Click);
            // 
            // ClearBtn
            // 
            this.ClearBtn.Location = new System.Drawing.Point(473, 65);
            this.ClearBtn.Name = "ClearBtn";
            this.ClearBtn.Size = new System.Drawing.Size(117, 23);
            this.ClearBtn.TabIndex = 8;
            this.ClearBtn.Text = "Clear";
            this.ClearBtn.UseVisualStyleBackColor = true;
            this.ClearBtn.Click += new System.EventHandler(this.ClearBtn_Click);
            // 
            // CourseGrid
            // 
            this.CourseGrid.AllowUserToAddRows = false;
            this.CourseGrid.AllowUserToDeleteRows = false;
            this.CourseGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.CourseGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.CourseCol,
            this.MinStudentCapacityCol,
            this.MaxStudentCapacityCol});
            this.CourseGrid.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.CourseGrid.Location = new System.Drawing.Point(12, 94);
            this.CourseGrid.Name = "CourseGrid";
            this.CourseGrid.ReadOnly = true;
            this.CourseGrid.RowTemplate.Height = 25;
            this.CourseGrid.Size = new System.Drawing.Size(776, 297);
            this.CourseGrid.TabIndex = 9;
            // 
            // CourseCol
            // 
            this.CourseCol.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.CourseCol.HeaderText = "Course";
            this.CourseCol.Name = "CourseCol";
            this.CourseCol.ReadOnly = true;
            // 
            // MinStudentCapacityCol
            // 
            this.MinStudentCapacityCol.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.MinStudentCapacityCol.HeaderText = "Min Student Capacity";
            this.MinStudentCapacityCol.Name = "MinStudentCapacityCol";
            this.MinStudentCapacityCol.ReadOnly = true;
            // 
            // MaxStudentCapacityCol
            // 
            this.MaxStudentCapacityCol.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.MaxStudentCapacityCol.HeaderText = "Max Student Capacity";
            this.MaxStudentCapacityCol.Name = "MaxStudentCapacityCol";
            this.MaxStudentCapacityCol.ReadOnly = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 408);
            this.Controls.Add(this.CourseGrid);
            this.Controls.Add(this.ClearBtn);
            this.Controls.Add(this.RemoveCourseBtn);
            this.Controls.Add(this.AddCourseBtn);
            this.Controls.Add(this.MaxStudentCapacityUpDown);
            this.Controls.Add(this.MinStudentCapacityUpDown);
            this.Controls.Add(this.CoursesComboBox);
            this.Controls.Add(this.MaxStudentCapacityLabel);
            this.Controls.Add(this.MinStudentCapacityLabel);
            this.Controls.Add(this.CourseNameLabel);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.MinStudentCapacityUpDown)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.MaxStudentCapacityUpDown)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.CourseGrid)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Label CourseNameLabel;
        private Label MinStudentCapacityLabel;
        private Label MaxStudentCapacityLabel;
        private ComboBox CoursesComboBox;
        private NumericUpDown MinStudentCapacityUpDown;
        private NumericUpDown MaxStudentCapacityUpDown;
        private Button AddCourseBtn;
        private Button RemoveCourseBtn;
        private Button ClearBtn;
        private DataGridView CourseGrid;
        private DataGridViewTextBoxColumn CourseCol;
        private DataGridViewTextBoxColumn MinStudentCapacityCol;
        private DataGridViewTextBoxColumn MaxStudentCapacityCol;
    }
}