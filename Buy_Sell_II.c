#include <stdio.h>

// print a B where the stock is bought and S where the stock is sold
void printB(int index, int* prices, int pricesSize) {
    for (int i = 0;i < pricesSize;i++) {
        printf("%d ", prices[i]);
    }
    printf("\n");
    for (int i = 0;i < pricesSize;i++) {
        if (i == index) {
            printf("B ");
        }
        else {
            printf("  ");
        }
    }
    printf("\n");
}
void printS(int index, int* prices, int pricesSize) {
    for (int i = 0;i < pricesSize;i++) {
        printf("%d ", prices[i]);
    }
    printf("\n");
    for (int i = 0;i < pricesSize;i++) {
        if (i == index) {
            printf("S ");
        }
        else {
            printf("  ");
        }
    }
    printf("\n");
}

// move index through the array to find if current index is buy or sell point, index does not go backwards!
int maxProfit(int* prices, int pricesSize) {
    int profit = 0;

    // create a high and low variable, init to first index
    int low = prices[0];
    int high = prices[0];

    // index for a while loop that moves to 1 less of array size, (CANT BUY LAST PRICE)
    int i = 0;
    
    // loop through array, O(N) because i is never decremented
    while (i < pricesSize - 1) {

        // find a low point to buy, index must stay in bounds 
        while (i < pricesSize - 1 && prices[i] >= prices[i+1]) {
            // will continue comparing current index and next index until min is found
            i += 1;
        }
        low = prices[i];
        if (i != pricesSize - 1) {printB(i, prices, pricesSize);}
        

        // now switch the condition to increment through and find sell point
        while (i < pricesSize - 1 && prices[i] <= prices[i+1]) {
            i += 1;
        }
        high = prices[i];
        if (i != pricesSize - 1) {printS(i, prices, pricesSize);}
        profit += high - low;
    }
    return profit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = 6;
    int result = maxProfit(prices, pricesSize);
    /*
    Output with banner
    7 1 5 3 6 4 
      B         
    7 1 5 3 6 4 
        S       
    7 1 5 3 6 4 
          B     
    7 1 5 3 6 4 
            S   
    */
    printf("Max profit: %d\n", result);
    return 0;
}

