#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STATES 8

// ------------------ DATA STRUCTURES ------------------

// FSM state table
// Each row represents a state
// [0] = State name
// [1] = Next state when input = 0
// [2] = Next state when input = 1
char states[MAX_STATES][3];

// Array to store garbage (unreachable) states
char isGarb[MAX_STATES];

// Number of active states
int numStates = MAX_STATES;

// Current FSM state
char currentState;


// ------------------ FUNCTION DECLARATIONS ------------------

void findUnreachableStates();           // Step 4
void deleteStates();                    // Step 5a
void deletestate(char target);          // Step 5b

char nextState(char states[MAX_STATES][3], char curr, int input);  // Step 2

void changeState(char command[]);       // Step 3
void printS();                          // Step 1

int validInput(char *input);            // Step 0


// ------------------ MAIN PROGRAM ------------------

int main() {

    char strInput[10];     // buffer for user command
    int intInput;          // store numeric input (0 or 1)

    // Initial FSM configuration
    char initialStates[MAX_STATES][3] = {
        {'A','G','B'},
        {'B','D','H'},
        {'C','B','A'},
        {'D','E','C'},
        {'E','H','G'},
        {'F','C','D'},
        {'G','F','G'},
        {'H','A','E'}
    };

    // Copy initial FSM into working FSM
    for(int i=0;i<MAX_STATES;i++)
        for(int j=0;j<3;j++)
            states[i][j] = initialStates[i][j];

    // Initial state of FSM
    currentState = 'B';

    printf("%c\n", currentState);

    // ------------------ MAIN INPUT LOOP ------------------

    while(1) {

        intInput = 5; // reset

        printf("Enter a command: ");

        // read command from user
        if(scanf("%s", strInput) != 1)
            break;

        // validate command
        if(validInput(strInput)) {

            // ------------------ Step 2: FSM input ------------------

            if(strcmp(strInput,"0")==0 || strcmp(strInput,"1")==0) {

                intInput = strInput[0]-'0';

                currentState = nextState(states,currentState,intInput);

                printf("%c\n", currentState);
            }

            // ------------------ Step 3: Change transition ------------------

            else if(strInput[0]=='c') {

                changeState(strInput);
            }

            // ------------------ Step 1: Print FSM ------------------

            else if(strInput[0]=='p') {

                printS();
            }

            // ------------------ Step 4: Find garbage states ------------------

            else if(strInput[0]=='g') {

                findUnreachableStates();
            }

            // ------------------ Step 5: Delete states ------------------

            else if(strInput[0]=='d') {

                // delete all garbage states
                if(strlen(strInput)==1)
                    deleteStates();

                // delete specific state
                else if(strlen(strInput)==2)
                    deletestate(strInput[1]);

                else
                    printf("Invalid delete command\n");
            }

            // ------------------ Step 7: Exit ------------------

            else if(strInput[0]=='e') {

                exit(0);
            }
        }

        else {

            printf("Invalid input, try again.\n");
        }
    }

    return 0;
}



// ------------------ Step 4: Garbage Detection ------------------

void findUnreachableStates() {

    int count = 0;
    int g = 0;

    // clear garbage array
    for(int i=0;i<MAX_STATES;i++)
        isGarb[i]='\0';

    // check each state
    for(int i=0;i<MAX_STATES;i++) {

        if(states[i][0]=='-')
            continue;

        int refcount = 0;

        // check if any state transitions TO this state
        for(int j=0;j<MAX_STATES;j++) {

            if(states[j][0]=='-')
                continue;

            if(states[i][0]==states[j][1] || states[i][0]==states[j][2])
                refcount++;
        }

        // if never referenced -> garbage
        if(refcount==0 && states[i][0]!=currentState) {

            // check for duplicates
            int exists = 0;

            for(int k=0;k<g;k++)
                if(isGarb[k]==states[i][0])
                    exists = 1;

            if(!exists) {
                isGarb[g++] = states[i][0];
                count++;
            }
        }
    }

    // print result
    if(count==0)
        printf("No garbage\n");

    else {

        printf("Garbage:");

        for(int i=0;i<g;i++)
            printf(" %c",isGarb[i]);

        printf("\n");
    }
}



// ------------------ Step 5a: Delete All Garbage States ------------------

void deleteStates() {

    int count = 0;

    for(int i=0;i<MAX_STATES;i++) {

        for(int j=0;j<MAX_STATES;j++) {

            if(isGarb[i]==states[j][0]) {

                printf("Deleted: %c\n",states[j][0]);

                // mark state as deleted
                states[j][0]='-';
                states[j][1]='-';
                states[j][2]='-';

                count++;
            }
        }
    }

    numStates -= count;

    if(count==0)
        printf("No states deleted.\n");
}



// ------------------ Step 5b: Delete Specific State ------------------

void deletestate(char target) {

    int count = 0;

    for(int i=0;i<MAX_STATES;i++) {

        if(states[i][0]==target) {

            states[i][0]='-';
            states[i][1]='-';
            states[i][2]='-';

            printf("Deleted: %c\n",target);

            count++;
        }
    }

    numStates -= count;

    if(count==0)
        printf("State Not Deleted.\n");
}



// ------------------ Step 2: Compute Next State ------------------

char nextState(char states[MAX_STATES][3], char curr, int input) {

    // invalid input protection
    if(input!=0 && input!=1) {

        printf("Invalid input\n");

        return curr;
    }

    // search for current state
    for(int i=0;i<MAX_STATES;i++) {

        if(states[i][0]==curr) {

            if(input==0)
                return states[i][1];

            else
                return states[i][2];
        }
    }

    printf("Error: current state not found\n");

    return curr;
}



// ------------------ Step 3: Change FSM Transition ------------------

void changeState(char command[]) {

    // expected format: c0A or c1B
    char bit = command[2];
    char newState = command[4];

    for(int i=0;i<MAX_STATES;i++) {

        if(states[i][0]==currentState && states[i][0]!='-') {

            if(bit=='0')
                states[i][1] = newState;

            else if(bit=='1')
                states[i][2] = newState;

            printf("Transition updated\n");

            break;
        }
    }
}



// ------------------ Step 1: Print FSM ------------------

void printS() {

    printf("FSM States:\n");

    for(int i=0;i<MAX_STATES;i++) {

        if(states[i][0]!='-')


            printf("%c %c %c\n",states[i][0],states[i][1],states[i][2]);
    }
}



// ------------------ Step 0: Validate Input ------------------

int validInput(char *input) {

    // single commands
    if(strlen(input)==1) {

        if(input[0]=='0'||input[0]=='1'||input[0]=='p'||input[0]=='g'||input[0]=='d'||input[0]=='e')

            return 1;
    }

    // change command format: c 0 A
    else if(strlen(input)==5 && input[0]=='c') {

        if((input[2]=='0'||input[2]=='1') && input[4]>='A' && input[4]<='H')

            return 1;
    }

    // delete specific: dA
    else if(strlen(input)==2 && input[0]=='d' && input[1]>='A' && input[1]<='H') {

        return 1;
    }

    return 0;
}
