#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//prototypes
void input_user(string file, int n);
void read_from_file(string file, int n);
void search(double cgpa, string file);
void deleteInfo(int idd);
void update(int idd);
//main function
int main()
{
	string file_name = "student_database.txt";
	int no_of_students = 0;
	double Cgpa = 0.0;
	int id = 0;

	cout << "Enter the no of students: ";
	cin >> no_of_students;
	//input function call
	input_user(file_name, no_of_students);
	//read function call
	read_from_file(file_name, no_of_students);
	//search function call
	cout << "Enter the cgpa you want to search: ";
	cin >> Cgpa;
	search(Cgpa,file_name);
	//update function call
	cout << "Enter the ID of the student you want to update: ";
	cin >> id;
	update(id);
	//delete function call
	cout << "Enter the ID of the student you want to delete: ";
	cin >> id;
	deleteInfo(id);
	return 0;
}
void input_user(string file, int n)
{
	ofstream fout;
	fout.open(file);

	if (!fout)
	{
		cout << "Error opening file: student_database.txt" << endl;
		return;
	}

	int Id = 0;
	string name;
	int age = 0;
	double cgpa = 0.0;
	int creditHours = 0;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter your Student ID: ";
		cin >> Id;
		fout << Id << " ";
		cout << "Enter your Name: ";
		cin >> name;
		fout << name << " ";
		cout << "Enter your age: ";
		cin >> age;
		fout << age << " ";
		cout << "Enter your CGPA: ";
		cin >> cgpa;
		fout << cgpa << " ";
		cout << "Enter your Credit Hours: ";
		cin >> creditHours;
		fout << creditHours << " " << endl;
	}
	fout.close();
}
void read_from_file(string file, int n)
{
	ifstream fin;
	fin.open(file);
	int Id = 0;
	string name;
	int age = 0;
	double cgpa = 0.0;
	int creditHours = 0;

	cout << "___________Student Information__________" << endl;;
	for(int i = 0;i < n;i++)
	{
		fin >> Id;
		fin >> name;
		fin >> age;
		fin >> cgpa;
		fin >> creditHours;
		cout << "ID: " << Id << " Name:  " << name << " Age: " << age << " CGPA: " << cgpa << " Credit Hours:" << creditHours << endl;
	}
	cout << "____________________________" << endl;

	fin.close();
}
void search(double cgpa, string file)
{
	ifstream fin(file);
	if (!fin)
	{
		cout << "Error opening file: student_database.txt" << endl;
		return;
	}

	int id = 0;
	string name;
	int age = 0;
	double student_cgpa = 0.0;
	int creditHours = 0;
	bool found = false;

	while (fin >> id >> name >> age >> student_cgpa >> creditHours)
	{
		if (cgpa == student_cgpa) 
		{
			cout << "Found - ID: " << id << " Name: " << name << " Age: " << age << " CGPA: " << student_cgpa << " Credit Hours: " << creditHours << endl;
			found = true;
		}
	}

	if (!found)
	{
		cout << "No student found with CGPA (" << cgpa << ")." << endl;
	}
	fin.close();
}

void update(int idd) 
{
	ofstream tem;
	tem.open("tem.txt", ios::app);
	ifstream fin;
	fin.open("student_database.txt");

	if (!fin) 
	{
		cout << "Error opening file: student_database.txt" << endl;
		return;
	}
	if (!tem)
	{
		cout << "Error creating temporary file: tem.txt" << endl;
		return;
	}

	int id;
	string name = "";
	float cgpa = 0.0;
	int creditHours = 0;
	int age = 0;
	string uname = "";
	float ucgpa = 0.0;
	int ucd = 0;
	int uage = 0;
	bool updated = false;

	while (fin >> id >> name >> age >> cgpa >> creditHours)
	{
		if (id == idd)
		{
			cout << "Current details - ID: " << id << " Name: " << name << " Age: " << age << " CGPA: " << cgpa << " Credit Hours: " << creditHours << endl;
			cout << "Enter new name of ID(" << id << "): ";
			cin >> uname;
			cout << "Enter new age of ID(" << id << "): ";
			cin >> uage;
			cout << "Enter new cgpa of ID(" << id << "): ";
			cin >> ucgpa;
			cout << "Enter new credit hours of ID(" << id << "): ";
			cin >> ucd;
			tem << id << " " << uname << " " << uage << " " << ucgpa << " " << ucd << endl;
			updated = true;
		}
		else
		{
			tem << id << " " << name << " " << age << " " << cgpa << " " << creditHours << endl;
		}
	}

	if (!updated)
	{
		cout << "No student found with ID (" << idd << ")." << endl;
	}

	fin.close();
	tem.close();

	remove("student_database.txt");
	rename("tem.txt", "student_database.txt");
}
void deleteInfo(int idd)
{
	ofstream tem;
	tem.open("tem.txt", ios::app);
	ifstream fin;
	fin.open("student_database.txt");

	if (!fin) 
	{
		cout << "Error opening file: student_database.txt" << endl;
		return;
	}
	if (!tem) 
	{
		cout << "Error creating temporary file: tem.txt" << endl;
		return;
	}

	int Id = 0;
	string name;
	int age = 0;
	double cgpa = 0.0;
	int creditHours = 0;
	bool deleted = false;

	while (fin >> Id >> name >> age >> cgpa >> creditHours)
	{
		if (Id != idd)
		{
			tem << Id << " " << name << " " << age << " " << cgpa << " " << creditHours << endl;
		}
		else
		{
			deleted = true;
		}
	}

	if (!deleted)
	{
		cout << "No student found with ID (" << idd << ")." << endl;
	}
	else
	{
		cout << "Record with ID (" << idd << ") has been deleted." << endl;
	}

	fin.close();
	tem.close();
	
	remove("student_database.txt");
	rename("tem.txt", "student_database.txt");
}