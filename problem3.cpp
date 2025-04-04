#include <iostream>

// completed in class following along with lecture
void test();

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    std::string toString() {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    // operator overload
    bool operator == (Fraction &other) {
        return this->numerator == other.numerator &&
               this->denominator == other.denominator;
    }
};

Fraction reduce(Fraction input) {
    int divider = 2;
    while (divider <= input.numerator && divider <= input.denominator) {
        if (input.numerator % divider == 0 &&
            input.denominator % divider == 0) {
            input.numerator /= divider;
            input.denominator /= divider;
            continue;
            }
        divider++;
    }
    return input;
}

int main() {
    test();
}

void test() {
    // given an input, the actual output should match the expected output
    Fraction inputs[4] = { Fraction(1,2),
                        Fraction{2, 4},
                        Fraction{4, 2},
                        Fraction{6, 8}
    };

    Fraction outputs[4] = {Fraction(1,2),
                          Fraction{1, 2},
                          Fraction{2, 1},
                          Fraction{3, 4}
    };

    // calls the function
    for (int i = 0; i < 4; ++i) {
        Fraction input = inputs[i];
        Fraction expect = outputs[i];

        Fraction actual = reduce(input);

        // compare expected vs actual
        if (expect == actual) {
            std::cout << "PASS!" << std::endl;
        } else {
            std::cout << "FAIL! the case is: " << input.toString()  << std::endl;
        }
    }

}