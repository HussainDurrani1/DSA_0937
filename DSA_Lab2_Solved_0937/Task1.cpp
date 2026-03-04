// TASK 1:
#include <iostream>
using namespace std;

#pragma once
#include <iostream>
using namespace std;

template <class T>
class Calculator
{
private:
	T num1, num2;
public:
	Calculator() : num1(1), num2(1) {}
	Calculator(T n1, T n2) : num1(n1), num2(n2) {}

	T add() { return num1 + num2; }
	T subtract() { return num1 - num2; }
	T multiply() { return num1 * num2; }
	T divide() {
		if (num2 == 0) cout << "Cannot divide by Zero.\n"; return 0;
		return num1 / num2;
	}

	void display() {
		cout << "\n\n===============================================\n";
		cout << "Num1: " << num1 << ", Num2: " << num2 << endl;
		cout << "Sum = " << add() << endl;
		cout << "Difference = " << subtract() << endl;
		cout << "Product = " << multiply() << endl;
		cout << "Division = " << divide() << endl;
		cout << "===============================================\n\n";
	}
};

int main() {

	cout << "---Integer Calculator---\n";
	int n1, n2;
	cout << "Enter an integer number 1: "; cin >> n1;
	cout << "Enter an integer number 2: "; cin >> n2;
	Calculator<int> c_int(n1, n2);
	c_int.display();
	

	cout << "---Double Calculator---\n";
	double num1 = 25.0, num2 = 12.5;
	Calculator<double> c_double(num1, num2);
	c_double.display();

	return 0;
}