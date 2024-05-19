#include <iostream>
#include <cmath>

using namespace std;

class MyInteger {
private:
    int value;

public:
    // Default constructor
    MyInteger() : value(0) {}

    // Constructor with initial value
    MyInteger(int value) : value(value) {}

    // Getter function
    int getValue() const {
        return value;
    }

    // Setter function
    void setValue(int value) {
        this->value = value;
    }

    // Overload [] operator
    int operator[](size_t index) const {
        int temp = value;
        for (size_t i = 0; i < index; ++i) {
            if (temp == 0) return -1;
            temp /= 10;
        }
        return (temp == 0) ? -1 : temp % 10;
    }
};

int main() {
    MyInteger x(1024);
    cout << "x[0] = " << x[0] << endl; // Should print 4
    cout << "x[1] = " << x[1] << endl; // Should print 2
    cout << "x[2] = " << x[2] << endl; // Should print 0
    cout << "x[3] = " << x[3] << endl; // Should print 1
    cout << "x[4] = " << x[4] << endl; // Should pring -1

    return 0;
}
