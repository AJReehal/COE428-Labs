/* Reads integers from the terminal
Stores them in a heap
Builds a max heap
Prints the heap as an XML tree
Deletes elements from the heap (largest ? smallest)
Pushes deleted elements onto a stack
Pops the stack and prints them (smallest ? largest)
* 
* */


#include <stdio.h>
#include <stdbool.h>

// Stack functions (implemented in another file)
extern void push(int item);
extern int pop();
extern bool isEmpty();

// Heap functions from intHeap.c
extern void addHeap(int value);
extern void buildHeap();
extern void printXML(int i);
extern int heapSize();
extern int heapDelete();

int main() {
    int value;         // Stores numbers read from input
    int deletedVal;    // Stores values removed from heap
    
    // Read integers from input until EOF (Ctrl+D on Mac/Linux, Ctrl+Z on Windows)
    while (scanf("%d", &value) == 1) { 
        addHeap(value);      // Add each number to heap array
    }

    // Convert array into a proper max heap
    buildHeap();

    // Print the heap in XML tree format
    printXML(0); 
    printf("\n"); 

    // Remove elements from heap one by one
    // This will remove largest element first (max heap)
    while (heapSize() > 0) { 
        deletedVal = heapDelete();   // Delete root (largest value)
        printf("%d\n", deletedVal);  // Print deleted value
        push(deletedVal);            // Push deleted value onto stack
    }

    // Now pop all values from stack and print them
    // This reverses the order of the deleted values
    while (!isEmpty()) { 
        deletedVal = pop();          // Pop value from stack
        printf("%d\n", deletedVal);  // Print popped value
    }

    return 0; 
}
