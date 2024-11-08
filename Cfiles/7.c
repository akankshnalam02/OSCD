#include <stdio.h>

void main() {
    char str[100];
    char state = 'P';  // Initial state is P
    int i = 0;

    printf("Enter input string: \n");
    scanf("%s", str);

    // Traverse through the input string
    while (str[i] != '\0') {
        if (state == 'P') {
            // From state P, we can go to state Q on 'a' or state R on 'b'
            if (str[i] == 'a') {
                state = 'Q';  // On 'a', go to state Q
            } else if (str[i] == 'b') {
                state = 'R';  // On 'b', go to state R
            } else {
                state = 'T';  // Invalid character, move to T (error state)
            }
        } 
        else if (state == 'Q') {
            // In state Q, we can stay in Q on 'a' or go to R on 'b'
            if (str[i] == 'a') {
                state = 'Q';  // On 'a', stay in state Q
            } else if (str[i] == 'b') {
                state = 'R';  // On 'b', go to state R
            } else {
                state = 'T';  // Invalid character, move to T (error state)
            }
        }
        else if (state == 'R') {
            // In state R, we can stay in R on 'b' or move to S (final state)
            if (str[i] == 'b') {
                state = 'R';  // On 'b', stay in state R
            } else {
                state = 'T';  // Invalid character, move to T (error state)
            }
        }
        else if (state == 'T') {
            // Once in state T, the string is rejected
            break;
        }
        i++;
    }

    // Accept the string if we end in state 'R' or 'S' (valid end states)
    if (state == 'R') {
        printf("String Accepted\n");
    } else {
        printf("String not Accepted\n");
    }
}

