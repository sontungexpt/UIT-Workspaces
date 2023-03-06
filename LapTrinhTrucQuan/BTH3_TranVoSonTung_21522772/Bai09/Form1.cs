namespace Bai09
{
    public partial class Form1 : Form
    {
        private List<Student> _students;
        private int _length = 0;

        public Form1()
        {
            InitializeComponent();
        }

        public void Form1_Load(object sender, EventArgs e)
        {
            _students = new List<Student>();
        }

        private void label1_Click(object sender, EventArgs e)
        {
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {
        }

        private void label2_Click(object sender, EventArgs e)
        {
        }

        private void label3_Click(object sender, EventArgs e)
        {
        }

        private void txbStudentId_TextChanged(object sender, EventArgs e)
        {
        }

        private void btnSave_Clicked(object sender, EventArgs e)
        {
            string studentId = txbStudentId.Text;
            string studentName = txbStudentFullName.Text;
            string studentSpecilized = txbStudentSpecilized.Text;
            bool studentSex = chkbNamSex.Checked;
            string studentSubject = rtxbSubjectInfoOutput.Text.Trim();

            int numberOfSubject =
                studentSubject == null || studentSubject == "" ? 0 : studentSubject.Trim().Split('\n').Length;

            _students.Add(new Student(studentId, studentName, studentSpecilized, studentSex, numberOfSubject));
            txbStudentFullName.Text = "";
            txbStudentId.Text = "";
            txbStudentSpecilized.Text = "";
            chkbNamSex.Checked = false;
            rtxbSubjectInfoInput.Text = "";
            rtxbSubjectInfoOutput.Text = "";

            _length++;
            ListViewItem item = new(_length.ToString());
            item.SubItems.Add(studentId);
            item.SubItems.Add(studentName);
            item.SubItems.Add(studentSpecilized);
            item.SubItems.Add(studentSex ? "Nam" : "Nữ");
            item.SubItems.Add(numberOfSubject.ToString());
            listViewStudent.Items.Add(item);
        }

        private void toLeftBtn_CLicked(object sender, EventArgs e)
        {
            rtxbSubjectInfoOutput.Text = rtxbSubjectInfoInput.Text;
        }

        private void ToRightBtn_Clicked(object sender, EventArgs e)
        {
            rtxbSubjectInfoOutput.Text = "";
            rtxbSubjectInfoInput.Focus();
        }

        private void removeBtnClicked(object sender, EventArgs e)
        {
            rtxbSubjectInfoOutput.Text = "";
            rtxbSubjectInfoInput.Text = "";
            rtxbSubjectInfoInput.Focus();
        }

        private void NuCkb_Changed(object sender, EventArgs e)
        {
            if (chkbNuSex.Checked)
            {
                chkbNamSex.Checked = false;
            }
        }

        private void NamCkb_Changed(object sender, EventArgs e)
        {
            if (chkbNamSex.Checked)
            {
                chkbNuSex.Checked = false;
            }
        }
    }
}