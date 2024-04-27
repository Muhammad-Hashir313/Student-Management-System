#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class StudentManager {
private:
	vector<Student> students;

public:
	void addStudent() {
		system("cls");
		string name;
		int age, rollno;

		cout << "========== ADD STUDENT ==========\n";
		
		do {
			cout << "Enter Name: ";
			cin.ignore();
			getline(cin, name);
		} while (name.empty());
		
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

		cout << "========== DELETE STUDENT ==========\n";
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

	void StudentDataToFile() {
		ofstream outFile("student.txt");
		outFile << "=============== STUDENTS RECORD ===============\n\n";
		for (int i = 0; i < students.size(); i++) {
			outFile << "S.No: " << i + 1 << endl;
			outFile << "Name: " << students[i].getName() << endl;
			outFile << "Roll Number: " << students[i].getRNo() << endl;
			outFile << "Age: " << students[i].getAge() << endl;
			outFile << "---------------------\n\n";
		}
		outFile.close();
	}
};