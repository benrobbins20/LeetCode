#include <iostream>

int main() {
    int input;
    int reverse = 0; // default to z because its needed for the first step (multiply and shift left)
    int remainder; // mod 10
    std::cout << "input: ";
    std::cin >> input;
    while (input != 0) {
        // mod 10: last digit, div 10 everything but last digit
        remainder = input % 10;
        reverse = reverse * 10 + remainder; // shift left and then add the remainder
        input /= 10; // decrement input by the last digit
    }
    std::cout << "reversed: " << reverse << std::endl;
} 

