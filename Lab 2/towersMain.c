#include <stdio.h>    
#include <stdlib.h>   
#include "towers.h"   

int main(int argc, char *argv[])
{
    int n;    // number of disks
    int start;    // source tower
    int dest;     // destination tower

    // Case 1: No command-line arguments

    if (argc == 1) {
        n = 3;
        start = 1;
        dest = 2;
    }

    // Case 2: One argument is given by the user which is the #ofdisks.
    
    else if (argc == 2) {
        n = atoi(argv[1]);  // convert string to integer
        start = 1;
        dest = 2;
    }

    // Case 3: Three arguments user inputs # of disks, from, dest
    
    else if (argc == 4) {
		
        n  = atoi(argv[1]);     
        start = atoi(argv[2]);  
        dest = atoi(argv[3]);  

        // Check that tower numbers are valid and different
        if (start < 1 || start > 3 || dest < 1 || dest > 3 || start == dest) {
            fprintf(stderr, "Error: Tower numbers must be 1, 2, or 3 and must be different.\n");
            exit(1);  
        }
    }

    // Any other number of arguments is invalid
    else {
        fprintf(stderr, "Error: Invalid number of arguments.\n");
        exit(1);  
    }

    // Check that number of disks is not negative
    if (n < 0) {
        fprintf(stderr, "Error: Number of disks must be non-negative.\n");
        exit(1);  
    }

    // Call the recursive Towers function
    towers(n, start, dest);

    return 0; 
}

