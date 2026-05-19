/**
 *  Integer Stack Module
 *
 *  Implements a stack of integers using a fixed-size array.
 *  Stack operations: push, pop, isEmpty.
 *
 *  Notes:
 *  - Maximum stack size: 100 elements.
 *  - Top of stack is tracked with the variable `top`.
 *  - `push` adds an element on top.
 *  - `pop` removes the element from the top.
 *  - `isEmpty` checks if the stack is empty.
 */

#include <stdio.h>
#include <stdbool.h>

// ---------- Global Variables ----------

// Index of the top of the stack (0 means empty)
int top = 0;

// Array to hold stack elements (maximum 100 integers)
int stack[100];

// ---------- Function Definitions ----------

/**
 * pop()
 * Removes and returns the top integer from the stack.
 * Returns -1 if the stack is empty (underflow).
 */
int pop() {
    if (top == 0) {  // Stack is empty
        printf("Stack is empty (Underflow Error)\n");
        return -1;
    } else {
        top = top - 1;       // Move top down to the previous element
        int temp = stack[top]; // Get the element to return
        return temp;           // Return popped value
    }
}

/**
 * push(item)
 * Adds an integer `item` to the top of the stack.
 * Prints an error if the stack is full (overflow).
 */
void push(int item) {
    if (top == 100) {  // Stack is full
        printf("Stack is full (Overflow Error)\n");
    } else {
        stack[top] = item;  // Place the item on top
        top = top + 1;      // Increment top
    }
}

/**
 * isEmpty()
 * Returns true if the stack is empty, false otherwise.
 */
bool isEmpty() {
    return (top == 0);
}
