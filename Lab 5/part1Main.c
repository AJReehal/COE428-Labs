#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Stack functions from stringStack.c
extern void push(char *item);    // Push a string onto the stack
extern char *pop();              // Pop a string from the stack
extern int isEmpty();            // Check if stack is empty

#define MAX_TAG_LEN 100

int main() {
    int ch;                       // Current character read
    char tag[MAX_TAG_LEN];        // Buffer to store a tag name
    int i;                        // Index for building tag

    // Read input character by character until EOF
    while ((ch = getchar()) != EOF) {
        if (ch == '<') {          // Start of a tag
            ch = getchar();       // Read next character

            // ---------- Opening tag ----------
            if (isalpha(ch)) {   // Start tag like <a> or <tag>
                i = 0;
                tag[i++] = ch;

                // Read rest of tag name until '>'
                while ((ch = getchar()) != '>' && ch != EOF) {
                    // -------- Invalid Case: Tag too long --------
                    if (i >= MAX_TAG_LEN - 1) {
                        fprintf(stderr, "Invalid XML: tag too long\n");
                        exit(1);   // Program stops on invalid input
                    }

                    // -------- Invalid Case: Non-letter character in tag --------
                    if (!isalpha(ch)) {
                        fprintf(stderr, "Invalid XML: invalid character in tag\n");
                        exit(1);   // Program stops on invalid input
                    }

                    tag[i++] = ch;
                }
                tag[i] = '\0';      // Null-terminate string

                // -------- Invalid Case: Empty tag <> --------
                if (strlen(tag) == 0) {
                    fprintf(stderr, "Invalid XML: empty tag not allowed\n");
                    exit(1);
                }

                push(strdup(tag));    // **Push** start tag onto stack
            }

            // ---------- Closing tag ----------
            else if (ch == '/') {    // End tag like </a> or </tag>
                i = 0;

                // Read tag name until '>'
                while ((ch = getchar()) != '>' && ch != EOF) {
                    // -------- Invalid Case: Tag too long --------
                    if (i >= MAX_TAG_LEN - 1) {
                        fprintf(stderr, "Invalid XML: tag too long\n");
                        exit(1);
                    }

                    // -------- Invalid Case: Non-letter character in closing tag --------
                    if (!isalpha(ch)) {
                        fprintf(stderr, "Invalid XML: invalid character in closing tag\n");
                        exit(1);
                    }

                    tag[i++] = ch;
                }
                tag[i] = '\0';        // Null-terminate string

                // -------- Invalid Case: Closing tag with no matching open tag --------
                if (isEmpty()) {
                    fprintf(stderr, "Invalid XML: stack is empty, unmatched closing tag\n");
                    exit(1);
                }

                char *openTag = pop(); // **Pop** last start tag

                // -------- Invalid Case: Closing tag does not match opening tag --------
                if (strcmp(openTag, tag) != 0) {
                    fprintf(stderr, "Invalid XML: tags do not match <%s></%s>\n", openTag, tag);
                    free(openTag);
                    exit(1);
                }

                free(openTag);         // Free memory after successful match
            }
        }
    }

    // -------- Invalid Case: Unclosed tags remain after reading input --------
    if (isEmpty()) {
        printf("Valid XML\n");
    } else {
        fprintf(stderr, "Invalid XML: unclosed tags remain\n");
    }

    return 0;
}
