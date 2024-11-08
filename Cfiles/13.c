#include <stdio.h>

int main() {
    int n, at[10], bt[10], wt[10] = {0}, tat[10], total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival and Burst Time for P[%d]: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    printf("\nExecution Breakdown:\n");
    // Calculating WT and TAT based on FCFS
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            wt[i] = (wt[i - 1] + bt[i - 1]) - at[i] + at[i - 1];
        }
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P[%d] executed for %d units of time\n", i + 1, bt[i]);
        printf("P[%d] TAT=%d WT=%d\n", i + 1, tat[i], wt[i]);
    }

    printf("\nAvg WT=%.2f Avg TAT=%.2f\n", (float)total_wt / n, (float)total_tat / n);
    return 0;
}
