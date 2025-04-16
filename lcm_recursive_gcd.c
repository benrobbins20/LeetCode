#include <stdio.h>

// max num macro
#define min(a, b) ((a) < (b) ? (a) : (b))

int gcd(int a, int b) {
    // iterative, while loop
    while (b != 0) {
        // store b->temp
        // take remainder of a/b = b
        // assign a to temp
        /*
        gcd(12,18)
        12 % 18 = 12 = b
        a = 18
        this swaps the values of a and b if a < b
        gcd(18,12)
        temp = 12
        18 % 12 = 6 = b
        a = 12
        gcd(12,6)
        12 % 6 = 0 = b
        a = 6
        gcd(6,0)
        return 6
        */
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm_gcd(int a, int b) {
    // gcd(18,12) == 6
    // least common multiple is product divided by gcd
    return (a*b) / gcd(a,b);
}

int lcm_recursive(int a, int b, int k) {
    /*  base cases  */

    // if one of the numbers is 1, then the lcm is simply the other number
    if (a == 1 || b == 1) {
        return a * b;
    }

    // if both are equal return either, num1/a 
    if (a == b) {
        return a;
    }

    // k must be smaller than both nums to proceed with recursion
    if (k < min(a,b)) {
        // if both are divisible by k, then perform recursive calls of k * a/k, b/k
        if (a % k == 0 && b % k == 0) {
            // continue getting product of k 
            return k * lcm_recursive(a/k, b/k, k);
        }
        // or increment k
        else {
            return lcm_recursive(a,b,k+1);
        }
    }
    
    // base case, a number is not divisible by k if k is greater than one of the numbers, 
    // return the lcm which is just product of both
    else {
        return a * b;
    }
}


int main(void) {
    // lcm using gcd and recrusion

    int recursive_lcm = lcm_recursive(12,9,2);
    printf("lcm recursive(12,9): %d\n", recursive_lcm);

    int gcd_lcm = lcm_gcd(12,9);
    printf("lcm gcd(12,9): %d\n", gcd_lcm);
}