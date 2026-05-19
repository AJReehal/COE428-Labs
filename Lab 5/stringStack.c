#include <stdio.h>
#include <stdlib.h>

/**
 * The functions in this module implement a Stack data structure
 * of char pointers (aka "strings").
 *
 * NOTE: the stack is implemented as a fixed size array (size = 100).
 * Consequently, no more than 100 strings can be pushed onto
 * the Stack at any given time.
 */

// RECOMMENDATION:
// Uncomment the following 2 lines and use these static globals!
static int top = 0;
static char * stack[100];

/**
 * pop() removes the top string on the stack and returns it.
 *
 * If pop() is attempted on an empty stack, an error message
 * is printed to stderr and the value NULL ((char *) 0) is returned.
 */
char * pop()
{
    // Check for underflow 
    if (top == 0) {
        fprintf(stderr, "Error: Stack is empty (Underflow)\n");
        return (char *) 0;  // Return NULL as requested
    }
    
    // Decrement top to point to the actual item, then return it 
    top = top - 1;
    return stack[top];
}

/**
 * push(thing2push) adds the "thing2push" to the top of the stack.
 *
 * If there is no more space available on the Stack, an error
 * message is printed to stderr.
 */
void push(char * item)
{
    if (top >= 100) {
        fprintf(stderr, "Error: Stack is full (Overflow)\n");
    } else {
        stack[top] = item;
        top = top + 1;
    }
}

/**
 * isEmpty() returns a non-zero integer (not necessarily 1) if the
 * stack is empty; otherwise, it returns 0 (zero).
 *
 */
int isEmpty()
{
    return (top == 0); 
}
