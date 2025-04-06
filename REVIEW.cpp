#include <iostream>
using namespace std;

class Cars {
private:
    string color;
    string brand;
    int year;
    bool fullyPaid;

public:
    // Constructor
    Cars(string c, string b, int y, bool fp) : color(c), brand(b), year(y), fullyPaid(fp) {}

    // Method to display car details
    void displayDetails() {
        cout << "Color: " << color << endl;
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
        cout << "Fully Paid: " << (fullyPaid ? "Yes" : "No") << endl;
    }
};

int main() {
    // Create an instance of Cars with the specified details
    Cars myCar("red", "Mercedes", 2005, true);

    // Display the car details
    myCar.displayDetails();

    return 0;
}