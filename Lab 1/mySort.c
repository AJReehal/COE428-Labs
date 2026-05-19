#include "mySort.h"  

// This function will sort an array of numbers in lowest to greatest order
// d[] is the array of numbers
// n is how many numbers are in the array

void mySort(int d[], unsigned int n)
{
    int i, j;     // i is used to pick the number to insert, j is used to shift numbers
    int key;      // key is the number we are currently inserting

    // Start from the second number (because the first number is already "sorted")
    for (i = 1; i < n; i++) {
        key = d[i];    //  number  want to insert
        j = i - 1;     //  checking the numbers before key

        // Move numbers that are bigger than key one place to the right
        while (j >= 0 && d[j] > key) {
            d[j + 1] = d[j]; // Shift the bigger number to the right
            j = j - 1;       // Move left to check the next number
        }

        // Place the key number in the correct spot
        d[j + 1] = key;
    }
}

