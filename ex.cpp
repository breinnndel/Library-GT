#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // Constructor to initialize values
    Student(string n, int a) {
        name = n;
        age = a;
    }

    // Default constructor
    Student() {
        name = "";
        age = 0;
    }

    // Setter method (optional, since we have a constructor)
    void setDetails(string n, int a) {
        name = n;
        age = a;
    }

    // Display method
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Using the parameterized constructor
    Student s1("Alice", 20);
    Student s2 = s1;  // Shallow copy
    s2.setDetails("Bob", 22); // Modifies only s2

    s1.display(); // Output: Name: Alice, Age: 20
    s2.display(); // Output: Name: Bob, Age: 22

    return 0;
}