using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Bai06
{
    public partial class Form1 : Form
    {
        private BackgroundWorker worker;

        public Form1()
        {
            InitializeComponent();
            worker = new BackgroundWorker();
            worker.WorkerSupportsCancellation = true;
            worker.WorkerReportsProgress = true;

            worker.DoWork += Worker_DoWork;
            worker.ProgressChanged += Worker_ProgressChanged;
            worker.RunWorkerCompleted += Worker_RunWorkerCompleted;
        }

        private void Worker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            MessageBox.Show("Copy completed!");
        }

        private void Worker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            progressBar.Value = e.ProgressPercentage;
        }

        private void Worker_DoWork(object sender, DoWorkEventArgs e)
        {
            CopyFile(txbSourcePath.Text, txbDestPath.Text);
        }

        private string OpenFileDialog()
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
            openFileDialog.FilterIndex = 2;
            openFileDialog.RestoreDirectory = true;
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                return openFileDialog.FileName;
            }
            return null;
        }

        private string FolderBrowserDialog()
        {
            if (txbSourcePath.Text == "")
            {
                MessageBox.Show("Please choose source path");
                return null;
            }
            else
            {
                FolderBrowserDialog folderBrowserDialog = new FolderBrowserDialog();
                if (folderBrowserDialog.ShowDialog() == DialogResult.OK)
                    return Path.Combine(folderBrowserDialog.SelectedPath, Path.GetFileName(txbSourcePath.Text));
                return null;
            }
        }

        private void btnSourcePath_Click(object sender, EventArgs e)
        {
            string _sourcePath = OpenFileDialog();
            txbSourcePath.Text = _sourcePath;
        }

        private void btnDestPath_Click(object sender, EventArgs e)
        {
            string _destPath = FolderBrowserDialog();
            if (_destPath == txbSourcePath.Text)
            {
                MessageBox.Show("Your path is existed please choose another path to copy file");
                txbDestPath.Text = "";
                txbDestPath.Focus();
            }
            else
                txbDestPath.Text = _destPath;
        }

        private void CopyBtn_Click(object sender, EventArgs e)
        {
            worker.RunWorkerAsync();
        }

        private void CopyFile(string source, string dest)
        {
            const int bufferSize = 1024 * 1024;  //1MB

            using (FileStream fsIn = new FileStream(source, FileMode.Open))
            using (FileStream fsOut = new FileStream(dest, FileMode.Create))
            {
                byte[] buffer = new byte[bufferSize];
                int readByte;
                while ((readByte = fsIn.Read(buffer, 0, buffer.Length)) > 0)
                {
                    fsOut.Write(buffer, 0, readByte);
                    int progress = (int)(fsIn.Position * 100 / fsIn.Length);
                    worker.ReportProgress(progress);
                }
            }
        }
    }
}