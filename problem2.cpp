#include <iostream>

// Checks prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


void testIsPrime() {
    // test inputs
    int inputs[] = {2, 3, 4, 5, 11, 15, 17};

    // test outputs
    bool outputs[] = {true, true, false, true, true, false, true, false, false, false};

    int size = 7;

    for (int i = 0; i < size; i++) {
        int input = inputs[i];
        bool expected = outputs[i];
        bool actual = isPrime(input);

        if (actual == expected) {
            std::cout << "PASS! " << std::endl;
        }
        if (actual != expected) {
            std::cout << "FAIL!" << std::endl;
        }
    }
}

int main() {
    testIsPrime();
}

