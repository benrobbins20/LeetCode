#include <iostream>

int main() {
    int input;
    bool isPrime = true; // prime default unless factor is found
    int max = 0; // floor(sqrt(input))
    std::cout << "input: ";
    std::cin >> input;
    if (input < 2) {
        return 0; // just return, no need to set bool flag
    }
    else {
        max = (int) sqrt(input);
        for (int i = 2; i <= max;i++) {
            if (input % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    if (isPrime) {
        std::cout << input << " is prime" << std::endl;
    }
    else {
        std::cout << input << " is not prime" << std::endl;
    }
    return 0;
}