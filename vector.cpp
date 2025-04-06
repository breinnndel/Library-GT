#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    Student(string& name, int age, string& section) 
        : name(name), age(age), section(section) {}

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    string getSection() {
        return section;
    }

private:
    string name;
    int age;
    string section;
};

class StudentManager {
public:
    void addStudent(string name, int age, string section) {
        students.push_back(Student(name, age, section));
    }

    void displayStudents() {
        for (size_t i = 0; i < students.size(); ++i) {
            cout << "Name: " << students[i].getName() 
                 << ", Age: " << students[i].getAge() 
                 << ", Section: " << students[i].getSection() 
                 << endl;
        }
    }

public:
    void removeStudent(string name) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getName() == name) {
                students.erase(it);
                break;
            }
        }
    }

private:
    vector<Student> students;
};

int main() {
    StudentManager manager;
    string name;
    int age;
    string section;

    while (true) {
        cout << "Enter student name (or 'exit' to finish): ";
        cin >> name;
        if (name == "exit") break;

        cout << "Enter student age: ";
        cin >> age;

        cout << "Enter student section: ";
        cin >> section;

        manager.addStudent(name, age, section);
    }
    cout << "Enter the name of the student to remove: ";
    cin >> name;
    manager.removeStudent(name);
    cout << "List of students:" << endl;
    manager.displayStudents();
    cout << "Enter the name of the student to remove: ";
    cin >> name;
    manager.removeStudent(name);

    cout << "List of students after removal:" << endl;
    manager.displayStudents();
    return 0;
}
