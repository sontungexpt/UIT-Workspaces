using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

using System.Linq;

namespace Bai05
{
    public partial class Form1 : Form
    {
        private Form2 _form2;
        private List<Student> _students;
        private int _studentsLength;

        public Form1()
        {
            InitializeComponent();
            _students = new List<Student>();
            _studentsLength = 0;
        }

        private void btnAddNewItem_Click(object sender, EventArgs e)
        {
            _form2 = new Form2();
            if (_form2.ShowDialog() == DialogResult.Cancel)
            {
                if (_form2.Student.HasValue())
                {
                    Student student = new Student(_form2.Student);
                    _students.Add(student);
                    _studentsLength++;
                    AddStudentToListView(student);
                }
            }
        }

        private void ShowAllStudentInListView()
        {
            foreach (Student student in _students)
            {
                AddStudentToListView(student);
            }
        }

        private void AddStudentToListView(Student student)
        {
            int index = 1;
            var item = new ListViewItem(index.ToString());
            item.SubItems.Add(student.Id);
            item.SubItems.Add(student.Name);
            item.SubItems.Add(student.Faculity);
            item.SubItems.Add(student.AverageScore.ToString());
            studentListView.Items.Add(item);
        }

        private void txbSearchName_Change(object sender, EventArgs e)
        {
            string name = txbSearch.Text.Trim();
            if (name != "" && _studentsLength > 0)
            {
                studentListView.Items.Clear();
                foreach (Student student in FilterByName(name))
                    AddStudentToListView(student);
                return;
            }
            else
            {
                studentListView.Items.Clear();
                ShowAllStudentInListView();
            }
        }

        private Student[] FilterByName(string name)
        {
            string lowerName = name.ToLower();
            if (_students != null && _studentsLength > 0)
                return _students.Where((student)
                                    => student.Name.ToLower().Trim().Contains(lowerName))
                                .ToArray();

            return null;
        }

        private void search_Click(object sender, EventArgs e)
        {
            txbSearch.Focus();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Modifiers == Keys.Control && e.KeyCode == Keys.N)
            {
                btnAddNewItem_Click(sender, e);
            }
            if (e.Modifiers == Keys.Control && e.KeyCode == Keys.F)
            {
                txbSearch.Focus();
            }
        }
    }
}