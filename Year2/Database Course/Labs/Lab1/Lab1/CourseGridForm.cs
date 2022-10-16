using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2
{
    public partial class CourseGridForm : Form
    {
        public CourseGridForm()
        {
            InitializeComponent();
        }
        public void addRow (string[] row)
        {
            CoursesGrid.Rows.Add(row);
        }
        public void removeRow ()
        {

        }
    }
}
