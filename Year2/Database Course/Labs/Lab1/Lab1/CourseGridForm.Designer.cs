namespace Lab2
{
    partial class CourseGridForm
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
            this.CoursesGrid = new System.Windows.Forms.DataGridView();
            this.CourseCol = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.MinNumberStudentsCol = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.MaxNumberStudentsCol = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.CoursesGrid)).BeginInit();
            this.SuspendLayout();
            // 
            // CoursesGrid
            // 
            this.CoursesGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.CoursesGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.CourseCol,
            this.MinNumberStudentsCol,
            this.MaxNumberStudentsCol});
            this.CoursesGrid.Location = new System.Drawing.Point(12, 12);
            this.CoursesGrid.Name = "CoursesGrid";
            this.CoursesGrid.RowTemplate.Height = 25;
            this.CoursesGrid.Size = new System.Drawing.Size(776, 271);
            this.CoursesGrid.TabIndex = 0;
            // 
            // CourseCol
            // 
            this.CourseCol.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.CourseCol.HeaderText = "Course";
            this.CourseCol.Name = "CourseCol";
            // 
            // MinNumberStudentsCol
            // 
            this.MinNumberStudentsCol.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.MinNumberStudentsCol.HeaderText = "Min Number Students ";
            this.MinNumberStudentsCol.Name = "MinNumberStudentsCol";
            // 
            // MaxNumberStudentsCol
            // 
            this.MaxNumberStudentsCol.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.MaxNumberStudentsCol.HeaderText = "Max Number Students ";
            this.MaxNumberStudentsCol.Name = "MaxNumberStudentsCol";
            // 
            // CourseGridForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.CoursesGrid);
            this.Name = "CourseGridForm";
            this.Text = "CourseGridForm";
            ((System.ComponentModel.ISupportInitialize)(this.CoursesGrid)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private DataGridView CoursesGrid;
        private DataGridViewTextBoxColumn CourseCol;
        private DataGridViewTextBoxColumn MinNumberStudentsCol;
        private DataGridViewTextBoxColumn MaxNumberStudentsCol;
    }
}