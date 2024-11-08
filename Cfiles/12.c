#include<stdio.h>
int main() {
    int n, bt[10], wt[10] = {0}, tat[10], total_wt = 0, total_tat = 0;
    int process[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        process[i] = i + 1;
    }

    // Sorting processes by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                int temp_bt = bt[i], temp_process = process[i];
                bt[i] = bt[j];
                process[i] = process[j];
                bt[j] = temp_bt;
                process[j] = temp_process;
            }
        }
    }

    printf("\nExecution Breakdown:\n");
    // Calculating WT and TAT based on SJF
    for (int i = 0; i < n; i++) {
        printf("P[%d] executed for %d units of time\n", process[i], bt[i]);
        tat[i] = bt[i] + (i > 0 ? tat[i - 1] : 0);
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P[%d] TAT=%d WT=%d\n", process[i], tat[i], wt[i]);
    }

    printf("\nAvg WT=%.2f Avg TAT=%.2f\n", (float)total_wt / n, (float)total_tat / n);
    return 0;
}
