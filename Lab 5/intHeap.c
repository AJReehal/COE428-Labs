#include <stdio.h>

// Global variables for the heap
int size = 0;        // Keeps track of how many elements are in the heap
int heap[100];       // Array to store heap elements, max 100 items

/**
 * printXML: Recursively prints the heap as an XML tree
 * @param i: index of the current node in the heap array
 */
void printXML(int i) {
    int left = 2 * i + 1;   // Index of left child in array
    int right = 2 * i + 2;  // Index of right child in array
    
    // Only print if current index is within the heap size
    if (i < size) { 
        printf("<node id=\"%d\">", heap[i]); // Print opening tag with node value
        printXML(left);  // Recursively print left subtree
        printXML(right); // Recursively print right subtree
        printf("</node>"); // Print closing tag
    }
}

/**
 * swap: Swaps the values of two integers
 * @param a: pointer to first integer
 * @param b: pointer to second integer
 */
void swap(int *a, int *b) { 
    int temp = *a; // Temporary variable to hold value
    *a = *b;       // Assign value of b to a
    *b = temp;     // Assign temp (original a) to b
}

/**
 * heapify: Ensures the subtree rooted at index i satisfies max-heap property
 * @param i: index of the current node to heapify
 */
void heapify(int i) {
    int largest = i;          // Assume current node is largest
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index
    
    // If left child exists and is greater than current largest
    if (left < size && heap[left] > heap[largest]) { 
        largest = left; 
    }
    
    // If right child exists and is greater than current largest
    if (right < size && heap[right] > heap[largest]) { 
        largest = right; 
    }
    
    // If largest is not current node, swap and continue heapifying
    if (largest != i) { 
        swap(&heap[i], &heap[largest]); 
        heapify(largest); // Recursively heapify affected subtree
    }
}

/**
 * buildHeap: Converts an unordered array into a max heap
 */
void buildHeap() {
    // Start from last non-leaf node and heapify each node up to root
    for (int i = (size / 2) - 1; i >= 0; i--) { 
        heapify(i); 
    }
} 

/**
 * heapDelete: Removes and returns the root (largest element) of the heap
 * @return root value if heap is not empty, -1 if heap is empty
 */
int heapDelete() {
    if (size == 0) { 
        return -1; // Heap is empty
    }
    
    int root = heap[0];          // Store root value to return
    heap[0] = heap[size - 1];    // Replace root with last element
    heap[size - 1] = 0;          // Optional: clear last element
    size = size - 1;             // Reduce heap size
    
    heapify(0);                  // Restore max-heap property starting from root
    return root;                 // Return removed root
}

/**
 * addHeap: Adds a new value to the heap array
 * @param value: integer to add
 */
void addHeap(int value) {
    heap[size] = value;  // Add new value at the end
    size = size + 1;     // Increase heap size
}

/**
 * heapSize: Returns the current number of elements in the heap
 * @return size: number of elements in the heap
 */
int heapSize() {
    return size; 
}
