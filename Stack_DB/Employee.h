#pragma once
#include <iostream>
using namespace std;

class Employee
{
private:
	string name;
	int salary;
	int ID;
	string department;

public:
	Employee(): name("Unknown"), salary(999), ID(0), department("Unknown"){}
	Employee(string nom, int s, int id, string dep): ID(id), salary(s) {
		name = nom;
		department = dep;
	}
	friend ostream& operator << (ostream& out, const Employee& emp) {
		out << "Name: " << emp.name << ", Department: " << emp.department;
		out << "\nID: " << emp.ID << ", Salary: " << emp.salary << ".\n\n";
		return out;
	}

	void display() const {
		cout << "\n\n------------------------------------------------------\n";
		cout << "Name: " << name << ", Department: " << department;
		cout << "\nID: " << ID << ", Salary: " << salary << ".\n\n";
		cout << "------------------------------------------------------\n";
	}

	bool operator == (const Employee& emp) {
		return this->ID == emp.ID;
	}

	void setName(string nom) { name = nom; }
	void setSalary(int s) { salary = s; }
	void setDepartment(string dep) { department = dep; }

	string getName() const { return name; }
	string getDepartment() const { return department; }
	int getSalary() const { return salary; }
	int getID() const { return ID; }

	
};
