#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
	int rollno, age;
	string name;

public:
	Student(int rNo, int a, string n) {
		rollno = rNo;
		age = a;
		name = n;
	}

	int getRNo() { return rollno; }
	int getAge() { return age; }
	string getName() { return name; }

	void setName(string newName) { name = newName; }
	void setAge(int newAge) { age = newAge; }
};

class StudentManager {
private:
	vector<Student> students;

public:
	void addStudent() {
		system("cls");
		string name;
		int age, rollno;

		cout << "========== ADD STUDENT ==========\n";
		cout << "Enter Name: ";
		cin >> name;
		do {
			cout << "Enter Roll no: ";
			cin >> rollno;

			bool exists = false;
			for (int i = 0; i < students.size(); i++)
			{
				if (rollno == students[i].getRNo())
				{
					cout << "\nStudent with this roll number already exists!\n";
					exists = true;
					break;
				}
			}
			if (!exists) {
				break;
			}

		} while (true);

		cout << "Enter Age: ";
		cin >> age;

		Student new_student(rollno, age, name);
		students.push_back(new_student);
		cout << "Student added Successfully!\n";
	}

	void showStudents() {
		system("cls");
		cout << "========== STUDENTS RECORD ==========\n";
		for (int i = 0; i < students.size(); i++) {
			cout << "S.No: " << i + 1 << endl;
			cout << "Name: " << students[i].getName() << endl;
			cout << "Roll Number: " << students[i].getRNo() << endl;
			cout << "Age: " << students[i].getAge() << endl;
			cout << "---------------------\n\n";
		}
	}

	void searchStudents() {
		system("cls");
		int rollno;

		cout << "========== SEARCH STUDENT ==========\n";
		cout << "Enter Roll no: ";
		cin >> rollno;

		for (int i = 0; i < students.size(); i++) {
			if (rollno == students[i].getRNo())
			{
				cout << "S.No: " << i + 1 << endl;
				cout << "Name: " << students[i].getName() << endl;
				cout << "Roll Number: " << students[i].getRNo() << endl;
				cout << "Age: " << students[i].getAge() << endl;
				cout << "---------------------\n\n";
				return;
			}
		}
		cout << "No student with this roll number exist!\n";
	}

	void updateStudent() {
		system("cls");
		int rollno, age;
		string name;

		cout << "========== UPDATE STUDENT ==========\n";
		cout << "Enter Roll no of Student to Update: ";
		cin >> rollno;

		for (int i = 0; i < students.size(); i++) {
			if (rollno == students[i].getRNo())
			{
				cout << "Enter Name: ";
				cin >> name;
				cout << "Enter Age: ";
				cin >> age;

				students[i].setName(name);
				students[i].setAge(age);
				cout << "Student Record Updated!\n";
				return;
			}
		}
		cout << "No student with this roll number exist!\n";
	}

	void deleteStudent() {
		system("cls");
		int rollno;

		cout << "========== SEARCH STUDENT ==========\n";
		cout << "Enter Roll no: ";
		cin >> rollno;

		for (int i = 0; i < students.size(); i++) {
			if (rollno == students[i].getRNo())
			{
				students.erase(students.begin() + i);
				cout << "Student deleted successfully!\n";
				return;
			}
		}
		cout << "No student with this roll number exist!\n";
	}
};

int main() {
	StudentManager studentmanager;
	do {
		char choice;
		system("cls");
		cout << "========== STUDENT MANAGEMENT SYSTEM ==========\n";
		cout << "1. Add Student\n";
		cout << "2. Show Students\n";
		cout << "3. Search Student\n";
		cout << "4. Update Student\n";
		cout << "5. Delete Student\n";
		cout << "6. Exit\n";
		cout << "Enter your Choice: ";
		cin >> choice;

		switch (choice) {
		case '1':
			studentmanager.addStudent();
			system("pause");
			break;

		case '2':
			studentmanager.showStudents();
			system("pause");
			break;

		case '3':
			studentmanager.searchStudents();
			system("pause");
			break;

		case '4':
			studentmanager.updateStudent();
			system("pause");
			break;

		case '5':
			studentmanager.deleteStudent();
			system("pause");
			break;

		case '6':
			cout << "Good Bye :)\n";
			exit(1);

		default:
			cout << "Invalid Choice!";
		}
	} while (true);
	
	return 0;
}