#include <stdio.h>

int main(void) {
    int count;
    int fib1 = 0;
    int fib2 = 1;
    int next_fib = fib1 + fib2;
    int internal_count = 0; // debug for verifying count - 2 iterations
    // baseline starts with 0,1, collect n fib numbers and generate list
    printf("fib count: ");
    scanf("%d", &count); // address of count gets derefed by scanf
    printf("fib series: %d, %d", fib1, fib2);
    // from 2 to < count, will be count - 2 iterations
    for (int i = 2;i < count;i++) {
        printf(", %d", next_fib); // next_fib already equals 1 on first iteration
        // shift fib1->fib2, fib2->current (next_fib), calculate next_fib = fib1 + fib2
        fib1 = fib2;
        fib2 = next_fib;
        next_fib = fib1 + fib2;
        internal_count++;
    }
    printf("\n");
}
