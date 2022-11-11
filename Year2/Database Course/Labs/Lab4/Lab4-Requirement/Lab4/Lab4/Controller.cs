using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public class Controller
    {
        DBManager dbMan;
        public Controller()
        {
            dbMan = new DBManager();
        }
        //TODO: functions in the requirement
        public DataTable getAthlete (int aID)
        {
            string query = string.Format(format: "SELECT Name, Age, S_ID From Athlete WHERE A_ID = {0}", aID); 
            return dbMan.ExecuteReader(query);
        }
        public int updateAthlete (int aID, int SportID, string Name, int Age)
        {
            string query = String.Format("UPDATE Athlete SET S_ID='{0}',Name='{1}',Age={2} WHERE A_ID = {3};", SportID, Name, Age, aID);
            return dbMan.ExecuteNonQuery(query);
        }
        public void TerminateConnection()
        {
            dbMan.CloseConnection();
        }
    }
}
