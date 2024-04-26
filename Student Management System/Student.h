#pragma once
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