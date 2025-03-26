#include <stdio.h>
#include <stdlib.h>

// rotate array k moves
// [1,2,3,4,5,6,7] k=3 => [5,6,7,1,2,3,4]
// to keep index in bounds of array, (i+k) % n (size of array)
// index 0 = (0+3) % 7 = 3
// index 6 = (6+3) % 7 = 2


void rotate_with_temp(int *nums, int numsSize, int k) {

    // handle k > numsSize
    k = k % numsSize;

    // store nums in a temporary dynamic array
    // malloc(size) is type casted to int*, meaning its treated as an array (int* nums)
    int *temp = (int *) malloc(numsSize * sizeof(int));

    // copy nums to temp
    for (int i = 0;i < numsSize;i++) {
        temp[i] = nums[i];
    }

    // rotate nums (i+k) % n
    // using temp to store the normal order, update the nums array accessable by main
    for (int i = 0;i < numsSize;i++) {
        nums[(i+k) % numsSize] = temp[i];
    }
}

// rotate in place performs 3 reverses
// reverse the entire array
// reverse the first 0 to k-1 elements -- the chunk prepended to list from overflow
// reverse the k to n-1 elements -- the chunk that shifted forward
void rotate_in_place(int *nums, int numsSize, int k) {

    // handle k > numsSize
    k = k % numsSize;

    // reverse the entire array
    // for loop method, can be half the array size and pivot arround middle (numsSize/2)
    // for evens
    //      nums[0] <-> nums[5]
    //      nums[1] <-> nums[4]
    //      nums[2] <-> nums[3]
    // for odds
    //      nums[0] <-> nums[4]
    //      nums[1] <-> nums[3]
    //      nums[2] <-> nums[2] -- not swapped
    for (int i = 0;i < numsSize/2;i++) {
        int temp = nums[i];
        nums[i] = nums[numsSize-1-i]; // must also subtract i to keep shifting backwards from last element
        nums[numsSize-1-i] = temp;
    }

    // reverse the first 0 to k-1 elements
    for (int i = 0;i < k/2;i++) {
        int temp = nums[i];
        nums[i] = nums[k-1-i];
        nums[k-1-i] = temp;
    }

    // reverse the last k to n-1 elements
    for (int i = 0;i < (numsSize-k)/2;i++) {
        int temp = nums[k+i];
        nums[k+i] = nums[numsSize-1-i];
        nums[numsSize-1-i] = temp;
    }
    for (int i = 0;i < numsSize;i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    // rot 2
    int k = 2;

    // do an odd array and even array to verify index swaps work
    int oddNums[] = {1,2,3,4,5};
    int oddNumsSize = 5;

    int evenNums[] = {1,2,3,4,5,6};
    int evenNumsSize = 6;
    rotate_in_place(oddNums, oddNumsSize, k);
    rotate_in_place(evenNums, evenNumsSize, k);
    return 0;
}
