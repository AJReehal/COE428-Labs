#include "mySort.h"

/*
 * Insertion Sort with metrics
 * Uses only:
 *   - myCompare()
 *   - myCopy()
 */
 
 // I make

// This function sorts part of an array using Insertion Sort.
// It sorts from index "first" to index "last".

void mySort(int array[], unsigned int first, unsigned int last)
{
    // Create a variable i that we will use to move through the array
    unsigned int i;

    // Start from the second element (first + 1)
    // and move forward until we reach the last element
    
    for (i = first + 1; i <= last; i++)
    {
        // Create a temporary variable called "key"
        // This will store the value we want to insert
        
        int key;

        // Copy the current element (array[i]) into key
        // We use myCopy so the metrics counter increases
        
        myCopy(&array[i], &key);

        // Create a variable j that starts just before i
        // This will move backwards through the sorted portion
        
        int j = i - 1;

        // While:
        // 1) We have NOT gone past the beginning of the array
        // 2) The element at position j is bigger than key
        
        while (j >= (int)first && myCompare(array[j], key) > 0) 
        {
            // Move the larger element one position to the right
            // This creates space for the key
            
            myCopy(&array[j], &array[j+1]);

            // Move j one step to the left
            // so we continue checking earlier elements
            
            j--;
        }

        // When the correct position is found,
        // insert the key into its correct spot
        
        myCopy(&key, &array[j+1]);
    }
}
