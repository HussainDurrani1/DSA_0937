#include <iostream>
using namespace std;
#include "Employee.h"

template <typename T>
class Stack {
    T* arr;
    int size;
    int top;

public:

    Stack(int ssize) {
        size = ssize;
        arr = new T[size];
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == size - 1);
    }

    void push(T value) {
        if (!isFull()) arr[++top] = value;
        else cout << "Stack is Full";
    }

    T pop() {
        return arr[top--];
    }

    T peek() {
        return arr[top];
    }

    void getTopValue() {
        if (!this->isEmpty()) cout << "Value at the top now: " << this->peek() << endl;
    }

    void popAndPrint() {
        cout << "Popped value is : " << this->pop() << endl;
    }

    ~Stack() {
        delete[] arr;    // Necessary to delete the Dynamically Allocated Memory
    }

};

int main() {
    cout << "=====Integers=====\n";
    Stack<int> s(3);
    s.push(3);
    s.push(7);
    s.push(20);

    if (s.isEmpty()) cout << "Your stack is empty" << endl;
    else {
        s.popAndPrint();
        s.popAndPrint();
    }
    s.getTopValue();

    cout << "\n=====Float=====\n";
    Stack<double> s1(3);
    s1.push(8.9);
    s1.push(9.1);
    s1.push(18.67);

    if (s1.isEmpty()) cout << "Your stack is empty" << endl;
    else {
        s1.popAndPrint();
        s1.popAndPrint();
    }
    s1.getTopValue();

    cout << "\n=====Char=====\n";
    Stack<char> s2(3);
    s2.push('A');
    s2.push('C');
    s2.push('F');

    if (s2.isEmpty()) cout << "Your stack is empty" << endl;
    else {
        s2.popAndPrint();
        s2.popAndPrint();
    }
    s2.getTopValue();


    cout << "\n=====String=====\n";
    Stack<string> s3(3);
    s3.push("Hello");
    s3.push("Durrani");
    s3.push("Hussain");

    if (s3.isEmpty()) cout << "Your stack is empty" << endl;
    else {
        s3.popAndPrint();
        s3.popAndPrint();
    }
    s3.getTopValue();

    
    Employee emp1("Hussain Durrani", 119990, 20, "FOIT");
    Employee emp2("Ali Hamza", 119000, 21, "Aitikaf Wala");
    Employee emp3("Talha Khurram", 100990, 19, "FOIT");
    cout << "\n=====Employee=====\n";
    Stack<Employee> s4(3);
    s4.push(emp3);
    s4.push(emp2);
    s4.push(emp1);

    if (s4.isEmpty()) cout << "Your stack is empty" << endl;
    else {
        s4.popAndPrint();
        s4.popAndPrint();
    }
    s4.getTopValue();

    return 0;
}
