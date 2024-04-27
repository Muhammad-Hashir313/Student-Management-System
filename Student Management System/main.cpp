#include <iostream>
#include <string>
#include <vector>

#include "Student.h"
#include "StudentManager.h"
using namespace std;

int main() {
	StudentManager studentmanager;
	do {
		studentmanager.StudentDataToFile();
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
			system("pasue");
		}
	} while (true);
	
	return 0;
}