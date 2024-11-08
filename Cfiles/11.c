#include <stdio.h>

int main() {
    int n, q, at[10], bt[10], temp[10], remain, time = 0;
    int total_wt = 0, total_tat = 0;

    printf("Enter number of processes and time quantum: ");
    scanf("%d %d", &n, &q);
    remain = n;

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival and Burst Time for P[%d]: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        temp[i] = bt[i];
    }

    printf("\nExecution Breakdown:\n");
    for (int i = 0; remain; i = (i + 1) % n) {
        if (temp[i] > 0) {
            int time_used = (temp[i] < q) ? temp[i] : q;
            time += time_used;
            temp[i] -= time_used;
            printf("P[%d] executed for %d units of time at time %d\n", i + 1, time_used, time);

            if (temp[i] == 0) {
                remain--;
                int tat = time - at[i];
                int wt = tat - bt[i];
                total_tat += tat;
                total_wt += wt;
                printf("P[%d] TAT=%d WT=%d\n", i + 1, tat, wt);
            }
        }
    }

    printf("\nAvg WT=%.2f Avg TAT=%.2f\n", (float)total_wt / n, (float)total_tat / n);
    return 0;
}
