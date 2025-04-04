#include <iostream>

void test();

// recursive
bool isPowerOf2(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;
    if (n % 2 != 0) return false;

    return isPowerOf2(n / 2);
}

// loop
bool isPowerOf2Loop(int n) {
    if (n <= 0) return false;
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}

int main() {
    test();
}

void test() {
    // test inputs
    int inputs[4] = {1, 2, 3, 6};

    // test outputs
    bool outputs[4] = {true, true, false, false};


    std::cout << "Recursive method" << std::endl;
    for (int i = 0; i < 4; i++) {
        int input = inputs[i];
        bool output = outputs[i];
        bool actual = isPowerOf2(input);

        if (actual == output) {
            std::cout << "PASS! " << std::endl;
        }
        if (actual != output) {
            std::cout << "FAIL!" << std::endl;
        }
    }

    // Test loop-based method
    std::cout << "\nLoop method" << std::endl;
    for (int i = 0; i < 4; i++) {
        int input = inputs[i];
        bool output = outputs[i];
        bool actual = isPowerOf2Loop(input);

        if (actual == output) {
            std::cout << "PASS! " << std::endl;
        }
        if (actual != output) {
            std::cout << "FAIL!" << std::endl;
        }
    }
}


