// swap 2 numbers without using a temporary variable

#include <stdio.h>

/*
(a+b) - b = a -> assign to b
(a+b) - a = b -> assign to a
-------
swap() takes the pointers to the variables and dereferences modify the values.
Sum the values and then take the difference effectively swapping 
their value. Lower space complexity at the cost of a few more operations.
-------
*/
void swap(int* a, int* b) {
    *a = *a + *b; // combine the variables
    *b = *a - *b; // subtract the sum from the other variable
    *a = *a - *b; // last variable equals the sum minus the second variable
}


int main() {
    // swap a=5 and b=10
    int a = 5;
    int b = 10;
    swap(&a, &b); // pass the memory addresses of variables to the function
    printf("a: %d, b: %d\n", a, b);

    //swap c=453 and d=949
    int c = 453;
    int d = 949;
    swap(&c, &d);
    printf("c: %d, d: %d\n", c, d);
}
