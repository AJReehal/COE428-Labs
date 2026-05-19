#include "mySort.h"

/*
 * MergeSort with metrics
 * This algorithm sorts an array by:
 * 1. Dividing it into two halves
 * 2. Recursively sorting each half
 * 3. Merging the two sorted halves
 */


/* ---------- MERGE FUNCTION ---------- */
/*
   This function merges two already-sorted halves
   back into one sorted section.
*/
void merge(int array[], unsigned int first, unsigned int mid, unsigned int last)
{
    // Temporary array to store merged result
    int temp[MAX_SIZE_N_TO_SORT];

    // i moves through left half
    unsigned int i = first;

    // j moves through right half
    unsigned int j = mid + 1;

    // k moves through temp array
    unsigned int k = first;

    /*
      While BOTH halves still have elements:
      Compare left and right values,
      and copy the smaller one into temp.
    */
    while (i <= mid && j <= last)
    {
        if (myCompare(array[i], array[j]) <= 0)
        {
            // Left element is smaller ? copy it
            myCopy(&array[i], &temp[k]);
            i++;
        }
        else
        {
            // Right element is smaller ? copy it
            myCopy(&array[j], &temp[k]);
            j++;
        }
        k++;
    }

    /*
      If left half still has elements left,
      copy them into temp
    */
    while (i <= mid)
    {
        myCopy(&array[i], &temp[k]);
        i++;
        k++;
    }

    /*
      If right half still has elements left,
      copy them into temp
    */
    while (j <= last)
    {
        myCopy(&array[j], &temp[k]);
        j++;
        k++;
    }

    /*
      Now copy everything from temp
      back into the original array
    */
    for (i = first; i <= last; i++)
    {
        myCopy(&temp[i], &array[i]);
    }
}


/* ---------- MERGESORT FUNCTION ---------- */
/*
   This function divides the array
   until each piece has only one element.
*/
void mySort(int array[], unsigned int first, unsigned int last)
{
    // BASE CASE:
    // If there is 0 or 1 element, it is already sorted.
    if (first >= last)
        return;

    /*
       DIVIDE STEP:
       Find the middle index.
       This splits the array into two halves.
    */
    unsigned int mid = first + (last - first) / 2;

    /*
       RECURSIVE CALLS:
       Sort left half
    */
    mySort(array, first, mid);

    /*
       Sort right half
    */
    mySort(array, mid + 1, last);

    /*
       MERGE STEP:
       Combine the two sorted halves
    */
    merge(array, first, mid, last);
}
