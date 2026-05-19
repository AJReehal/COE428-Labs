#include <stdio.h>     
#include <stdlib.h>
#include "mySort.h"   

int main(int argc, char * argv[])
{
    int data[100000];   // Big array to hold numbers to sort
    int nDataItems;    // Number of numbers we are actually sorting
    int i;              // Loop counter

    // Check if the user typed any numbers after the program name
    if (argc == 1) {
        // No numbers were typed, so use some default numbers
        nDataItems = 4;   // We have 4 numbers
        data[0] = 10;
        data[1] = 20;
        data[2] = 30;
        data[3] = 40;
    } else {
        // User typed numbers, so we convert them from text to integers
        nDataItems = 0;
        for (i = 1; i < argc; i++) {
            data[nDataItems] = atoi(argv[i]);  // Convert text to number
            nDataItems++;                     // Count how many numbers we have
        }
    }

    // Call our sorting function to sort the numbers
    mySort(data, nDataItems);

    // Check if the numbers are sorted correctly
    for (i = 0; i < nDataItems - 1; i++) {
        if (data[i] > data[i + 1]) {  
			fprintf(stderr, "Sort error: array is not sorted correctly.\n");
            exit(1);  
        }
    }

    // Print all the sorted numbers
    for (i = 0; i < nDataItems; i++) {
        printf("%d\n", data[i]);
    }

    return 0;  
}

