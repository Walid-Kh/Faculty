using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class AppForm : Form
    {
        Controller controllerObj;
        public AppForm()
        {
            controllerObj = new Controller(); ;
            InitializeComponent();
        }


        private void GetButton_Click(object sender, EventArgs e)
        {
            int AID = (int)AthleteNumericUpDown.Value;
            DataTable athleteInfo =  controllerObj.getAthlete(AID);
            if (athleteInfo.Rows.Count != 0)
            {
                NameTextBox.Text = athleteInfo.Rows[0][0].ToString();
                AgeNumericUpDown.Value = (int)athleteInfo.Rows[0][1]; 
                SportNumericUpDown.Value = (int)athleteInfo.Rows[0][2];
            }
            else
            {
                MessageBox.Show("an Error has occured"); 
            }
        }

        private void UpdateBtn_Click(object sender, EventArgs e)
        {
            int AID = (int)AthleteNumericUpDown.Value;
            int SportID = (int)SportNumericUpDown.Value; 
            string Name = NameTextBox.Text;
            int age = (int)AgeNumericUpDown.Value;
            if (controllerObj.updateAthlete(AID, SportID, Name, age) == 0)
            {
                MessageBox.Show("an error has occured");
                    return; 
            }
            else
            {
                MessageBox.Show("updated successfully"); 
            }
        }
    }
}
