#include <stdio.h>
#include <stdbool.h>
#include <math.h> 

int main(void) {
    int input;
    bool isPrime = true;
    int max = 0; // only need to check up to the square root (floor) of the input to find a factor
    printf("input: ");
    scanf("%d", &input); // scanf has an abstraction that dereferences the pointer, just need to pass address
    if (input < 2) {
        isPrime = false; // primes start at 2
    }
    else {
        max = (int) floor(sqrt(input)); // sqrt is double, cast to int
        for (int i = 2; i <= max;i++) {
            if (input % i == 0) {
                isPrime = false; // a factor is found, so input is not prime
                break;
            }
        }
    }
    if (isPrime) {
        printf("%d is prime\n", input);
    }
    else {
        printf("%d is not prime\n", input);
    }
    return 0;
}
