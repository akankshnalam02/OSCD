#include <stdio.h>

char *ip;
char string[50];

// Function Declarations
int E();
int Edash();
int T();
int Tdash();
int F();

int E() {
    printf("%s\tE->TE' \n", ip);
    return T() && Edash();
}

int Edash() {
    if (*ip == '+') {
        printf("%s\tE'->+TE' \n", ip);
        ip++;
        return T() && Edash();
    } else {
        printf("%s\tE'->^ \n", ip);
        return 1;
    }
}

int T() {
    printf("%s\tT->FT' \n", ip);
    return F() && Tdash();
}

int Tdash() {
    if (*ip == '*') {
        printf("%s\tT'->*FT' \n", ip);
        ip++;
        return F() && Tdash();
    } else {
        printf("%s\tT'->^ \n", ip);
        return 1;
    }
}

int F() {
    if (*ip == '(') {
        printf("%s\tF->(E) \n", ip);
        ip++;
        if (E()) {
            if (*ip == ')') {
                ip++;
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if (*ip == 'i') {  // Assuming 'i' represents an identifier
        printf("%s\tF->id \n", ip);
        ip++;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    printf("Enter the string\n");
    scanf("%s", string);
    ip = string;
    printf("\n\nInput\tAction\n--------------------------------\n");
    if (E() && *ip == '\0') {
        printf("\n--------------------------------\nString is successfully parsed\n");
    } else {
        printf("\n--------------------------------\nError in parsing String\n");
    }
    return 0;
}

