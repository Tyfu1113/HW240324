#include <iostream>
#include <stdexcept>

using namespace std;

class PrimeNumber {
private:
    int prime;

    bool isPrime(int num) const {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }

    int getNextPrime(int num) const {
        int next = num + 1;
        while (!isPrime(next)) {
            ++next;
        }
        return next;
    }

    int getPreviousPrime(int num) const {
        int prev = num - 1;
        while (prev > 1 && !isPrime(prev)) {
            --prev;
        }
        if (prev <= 1) {
            throw std::out_of_range("No previous prime number exists");
        }
        return prev;
    }

public:
    // Default constructor
    PrimeNumber() : prime(1) {}

    // Constructor with an initial value
    PrimeNumber(int prime) {
        if (isPrime(prime) || prime == 1) {
            this->prime = prime;
        } else {
            throw std::invalid_argument("The number is not a prime number");
        }
    }

    // Getter function
    int getPrime() const {
        return prime;
    }

    // Prefix increment operator
    PrimeNumber& operator++() {
        prime = getNextPrime(prime);
        return *this;
    }

    // Postfix increment operator
    PrimeNumber operator++(int) {
        PrimeNumber temp(*this);
        prime = getNextPrime(prime);
        return temp;
    }

    // Prefix decrement operator
    PrimeNumber& operator--() {
        prime = getPreviousPrime(prime);
        return *this;
    }

    // Postfix decrement operator
    PrimeNumber operator--(int) {
        PrimeNumber temp(*this);
        prime = getPreviousPrime(prime);
        return temp;
    }
};

int main() {
    try {
        // testing default constructor
        PrimeNumber p1;
        cout << "Default prime number: " << p1.getPrime() << std::endl; // Should be 1
        // testing parameterized constructor
        PrimeNumber p2(13);
        cout << "Initialized prime number: " << p2.getPrime() << std::endl; // Should be 13
        // testing prefix increment
        ++p2;
        cout << "Next prime number (prefix ++): " << p2.getPrime() << std::endl; // Should be 17
        // testing postfix increment
        PrimeNumber p3 = p2++;
        cout << "Previous prime number (postfix ++): " << p3.getPrime() << std::endl; // Should be 17
        cout << "Current prime number: " << p2.getPrime() << std::endl; // Should be 19
        // testing prefix decrement
        --p2;
        cout << "Previous prime number (prefix --): " << p2.getPrime() << std::endl; // Should be 17
        // testing postfix decrement
        PrimeNumber p4 = p2--;
        cout << "Next prime number (postfix --): " << p4.getPrime() << std::endl; // Should be 17
        cout << "Current prime number: " << p2.getPrime() << std::endl; // Should be 13
        //smallest prime
        PrimeNumber p5(2);
        --p5;
        cout << "Previous prime number from 2: " << p5.getPrime() << std::endl; // Should throw exception

    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
