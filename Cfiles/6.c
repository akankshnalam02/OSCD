#include <stdio.h>
#include <stdlib.h>

void main() {
    int table[2][2] = {{1, -1}, {1, 0}}; // DFA transition table
    int status = 0;
    char input[100];

    printf("Enter Input String: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != 'a' && input[i] != 'b') {
            printf("Invalid character entered.\n");
            exit(0);
        }

        // Transition based on current character
        if (input[i] == 'a') {
            status = table[status][0];
        } else {
            status = table[status][1];
        }

        if (status == -1) {
            printf("String not Accepted.\n");
            return;
        }
    }

    printf("String Accepted.\n");
}
