#include <stdio.h>
#include <stdlib.h>


int main(void) {
    // use the 123 input value -> 321
    int input;
    int reverse = 0; // init to 0 and store reversed num
    int remainder; // mod 10
    printf("int input: ");
    scanf("%d", &input); // get input and store in the reference/address for input
    while (input != 0) {
        // get the last digit, mod 10, in general using input greater than 2 digits
        remainder = input % 10; //1: 123 % 10 = 3 ;2: 12 % 10 = 2 ;3: 1 % 10 = 1
        // add remainder to reverse, multiply by 10 to shift left
        reverse = ++reverse * 10 + remainder; //1: 0 * 10 + 3 = 3 ;2: 3 * 10 + 2 = 32 ;3: 32 * 10 + 1 = 321
        // remove last digit from input
        input /= 10; //1: 123 / 10 = 12 ;2: 12 / 10 = 1 ; 3: 1 / 10 = 0 (end of loop)
    }
    printf("reversed: %d\n", reverse);
}


