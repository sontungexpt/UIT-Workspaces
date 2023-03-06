using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Bai05
{
    internal static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        private static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }

    public class Student
    {
        private string _id;
        private string _name;
        private string _faculity;

        private float _averageScore;

        public string Id
        {
            get => _id;
            set => _id = value;
        }

        public string Name
        {
            get => _name;
            set => _name = value;
        }

        public string Faculity
        {
            get => _faculity;
            set => _faculity = value;
        }

        public float AverageScore { get => _averageScore; set => _averageScore = value; }

        public Student()
        {
            _id = "";
            _name = "";
            _faculity = "";
            _averageScore = 0;
        }

        public Student(Student student)
        {
            _id = student.Id;
            _name = student.Name;
            _faculity = student.Faculity;
            _averageScore = student.AverageScore;
        }

        public Student(string id, string name, string faculity, bool sex, int numberOfSubjects)
        {
            _id = id;
            _name = name;
            _faculity = faculity;

            _averageScore = numberOfSubjects;
        }

        public bool HasValue()
        {
            return _id != "" && _name != "" && _faculity != "" && _averageScore != 0;
        }
    }
}