#include <iostream>
#include <cmath> // Use <cmath> instead of <math.h> for C++ compatibility
using namespace std;

// Area Calculator 
// Triangle: (base * height) / 2
// Rectangle: (length * width)
// Circle: π * r^2
class AreaCalculator {
public:
    double areaOfTriangle(double base, double height) {
        double area = (base * height) / 2; 
        return area;
    }

    double areaOfRectangle(double length, double width) {
        return length * width;
    }

    double areaOfCircle(int radius) {
        return 3.14159 * pow(radius, 2); 
    }
};

int main() {
    AreaCalculator area;

    cout << "Area of Triangle: " << area.areaOfTriangle(10, 2) << endl;
    cout << "Area of Rectangle: " << area.areaOfRectangle(10, 2) << endl;
    cout << "Area of Circle: " << area.areaOfCircle(10) << endl;

    return 0;
}
