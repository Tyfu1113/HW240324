#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int numClasses;
    string* classList;

public:
    // Default constructor
    Student() : name(""), numClasses(0), classList(nullptr) {}

    // Parameterized constructor
    Student(const string& name, int numClasses) : name(name), numClasses(numClasses) {
        classList = new string[numClasses];
    }

    // Destructor
    ~Student() {
        delete[] classList;
    }

    // Copy constructor
    Student(const Student& other) : name(other.name), numClasses(other.numClasses) {
        classList = new string[numClasses];
        for (int i = 0; i < numClasses; ++i) {
            classList[i] = other.classList[i];
        }
    }

    //Overloading operator =
    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] classList;
            name = other.name;
            numClasses = other.numClasses;
            classList = new string[numClasses];
            for (int i = 0; i < numClasses; ++i) {
                classList[i] = other.classList[i];
            }
        }
        return *this;
    }

    // Mutator function to input student information
    void input() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter number of classes: ";
        cin >> numClasses;
        classList = new string[numClasses];
        cout << "Enter class names:\n";
        for (int i = 0; i < numClasses; ++i) {
            cout << "Class " << i + 1 << ": ";
            cin >> classList[i];
        }
    }

    // Accessor function to output student information
    void output() const {
        cout << "Name: " << name << endl;
        cout << "Number of classes: " << numClasses << endl;
        cout << "Class list:\n";
        for (int i = 0; i < numClasses; ++i) {
            cout << classList[i] << endl;
        }
    }

    // Function to reset class information
    void resetClasses() {
        delete[] classList;
        numClasses = 0;
        classList = nullptr;
    }
};

int main() {
    // testinging the Student class
    Student student1;
    student1.input();
    student1.output();

    // testing copy constructor and assignment operator
    Student student2 = student1;
    student2.output();

    // testing resetClasses function
    student1.resetClasses();
    student1.output(); //should be zero

    return 0;
}
