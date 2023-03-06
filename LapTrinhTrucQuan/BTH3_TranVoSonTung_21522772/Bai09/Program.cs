using System;
using System.Reflection.Metadata.Ecma335;

namespace Bai09
{
    internal static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        private static void Main()
        {
            // To customize application configuration such as set high DPI settings or default font,
            // see https://aka.ms/applicationconfiguration.
            ApplicationConfiguration.Initialize();
            Application.Run(new Form1());
        }
    }
}

internal class Student
{
    private string? _id;
    private string? _name;
    private string? _specilized;
    private bool? _sex;
    private int? _numberOfSubject;

    public string? Id
    {
        get => _id;
        set
        {
            if (_id == null)
            {
                throw new Exception("ID is not null");
            }
            else
            {
                _id = value;
            }
        }
    }

    public string? Name
    {
        get => _name;
        set => _name = value;
    }

    public string? Specilized
    {
        get => _specilized;
        set => _specilized = value;
    }

    public string? Sex
    {
        get => _sex == true ? "Nam" : "Nu";
        set
        {
            if (value == "Nam" || value == "Nu")
                _sex = value == "Nam" ? true : false;
            else
                _sex = null;
        }
    }

    public int? NumberOfSubjects { get => _numberOfSubject; set => _numberOfSubject = value; }

    public Student(string id, string name, string specilized, bool sex, int numberOfSubjects)
    {
        _id = id;
        _name = name;
        _specilized = specilized;
        _sex = sex;
        _numberOfSubject = numberOfSubjects;
    }
}