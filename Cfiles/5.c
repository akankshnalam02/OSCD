#include <stdio.h>

int main() {
    int alloc[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int max[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int avail[3] = {3, 3, 2}, f[5] = {0}, ans[5], need[5][3], i, j, k, ind = 0;

    // Calculate Need matrix
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Banker's Algorithm
    for (k = 0; k < 5; k++) {
        for (i = 0; i < 5; i++) {
            if (!f[i]) {
                int flag = 0;
                for (j = 0; j < 3; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    ans[ind++] = i;
                    for (j = 0; j < 3; j++) {
                        avail[j] += alloc[i][j];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    // Check if safe and print sequence
    for (i = 0; i < 5; i++) {
        if (!f[i]) {
            printf("The system is not safe.\n");
            return 0;
        }
    }
    printf("Safe Sequence: ");
    for (i = 0; i < 4; i++) {
        printf("P%d -> ", ans[i]);
    }
    printf("P%d\n", ans[4]);

    return 0;
}
