#include <iostream>
using namespace std;

void display(string name, int age, bool isMarried) {
    cout << "Hello " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Is Married? " << (isMarried ? "Yes" : "No") << endl;
}

// Value-returning functions

string fullName(string firstName, string lastName) {
    return firstName + " " + lastName;
}

// Calculate the area of a triangle where a = (base * height) / 2
double calculateAreaOfTriangle(double base, double height) {
    return (base * height) / 2;
}

int main() {
    cout << fullName("John", "Doe") << endl;

    double area = calculateAreaOfTriangle(10, 2);
    cout << "Triangle Area: " << area << endl;

    display("Alice", 25, true);

    return 0;
}
