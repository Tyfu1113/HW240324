#include <iostream>

using namespace std;

int myStrlen(const char str[]) {
    // Precondition: str contains a string value terminated with '\0'.
    // Returns the number of characters in the string str (not counting '\0').
    int index = 0;
    while (str[index] != '\0') {
        index++;
    }
    return index;
}

int main() {
    // Test the myStrlen function
    const char testStr1[] = "Hello, World!";
    const char testStr2[] = "AbsoluteC++";
    const char testStr3[] = "";
    const char testStr4[] = "9-4";

    cout << "Length of \"" << testStr1 << "\" is " << myStrlen(testStr1) << endl;
    cout << "Length of \"" << testStr2 << "\" is " << myStrlen(testStr2) << endl;
    cout << "Length of \"" << testStr3 << "\" is " << myStrlen(testStr3) << endl;
    cout << "Length of \"" << testStr4 << "\" is " << myStrlen(testStr4) << endl;

    return 0;
}
