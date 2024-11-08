#include <stdio.h>
#include <string.h>

char prod[7][10] = {"S->A", "A->Bb", "A->Cd", "B->aB", "B->@", "C->Cc", "C->@"};
char first[7][10] = {"abcd", "ab", "cd", "a@", "@", "c@", "@"};
char follow[7][10] = {"$", "$", "$", "a$", "b$", "c$", "d$"};
char table[5][6][10];

int numr(char c) {
    if (c == 'S') { return 0; }
    if (c == 'A') { return 1; }
    if (c == 'B') { return 2; }
    if (c == 'C') { return 3; }
    if (c == 'a') { return 0; }
    if (c == 'b') { return 1; }
    if (c == 'c') { return 2; }
    if (c == 'd') { return 3; }
    if (c == '$') { return 4; }
    return -1;
}

void fillTable() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; first[i][j]; j++) {
            if (first[i][j] != '@') {
                strcpy(table[numr(prod[i][0]) + 1][numr(first[i][j]) + 1], prod[i]);
            }
        }
        if (first[i][0] == '@') {
            for (int j = 0; follow[i][j]; j++) {
                strcpy(table[numr(prod[i][0]) + 1][numr(follow[i][j]) + 1], prod[i]);
            }
        }
    }
}

void setupHeaders() {
    char headers[] = "abcd$";
    for (int i = 0; i < 5; i++) {
        table[0][i + 1][0] = headers[i];
    }
    strcpy(table[1][0], "S");
    strcpy(table[2][0], "A");
    strcpy(table[3][0], "B");
    strcpy(table[4][0], "C");
}

void printTable() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%-10s", table[i][j]);
        }
        printf("\n");
    }
}

int main() {
    memset(table, 0, sizeof(table));
    fillTable();
    setupHeaders();
    printTable();
    return 0;
}
