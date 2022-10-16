namespace Lab2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void AddCourseBtn_Click(object sender, EventArgs e)
        {
            int minStudent = ((int)MinStudentCapacityUpDown.Value); 
            int maxStudent = (int)MaxStudentCapacityUpDown.Value;
            if (minStudent <= 0)
            {
                MessageBox.Show("Min Number of Student Must Be Positive", "Erorr", MessageBoxButtons.OK);
                return;
            }
            if (maxStudent <= 0)
            {
                MessageBox.Show("Max Number of Student Must Be Positive", "Erorr", MessageBoxButtons.OK);
                return;
            }
            if (minStudent > maxStudent)
            {
                MessageBox.Show("Min Number of Student Can't be larger than the Min Number of Students", "Error", MessageBoxButtons.OK);
                return;
            }
            if (CoursesComboBox.SelectedItem is null)
            {
                MessageBox.Show("Please Select A Course", "Error", MessageBoxButtons.OK);
                return;
            }
            string courseName = CoursesComboBox.SelectedItem.ToString();   
            string[] row = new string[] {courseName, minStudent.ToString(), maxStudent.ToString()};
            CourseGrid.Rows.Add(row);
            CoursesComboBox.Items.Remove(courseName);
        }

        private void RemoveCourseBtn_Click(object sender, EventArgs e)
        {
            if (CourseGrid.SelectedRows.Count == 0 )
            {
                MessageBox.Show("Please select what course you want to remove", "Error", MessageBoxButtons.OK);
                return;
            }
            else
            {
                CoursesComboBox.Items.Add(CourseGrid.SelectedRows[0].Cells[0].Value);
                CourseGrid.Rows.Remove(CourseGrid.SelectedRows[0]);
            }
        }

        private void ClearBtn_Click(object sender, EventArgs e)
        {
            foreach (DataGridViewRow i in CourseGrid.Rows)
            {
                CoursesComboBox.Items.Add(i.Cells[0].Value);
            }
            CourseGrid.Rows.Clear();
        }

        
    }
}