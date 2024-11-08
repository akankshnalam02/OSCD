#include <stdio.h>

struct Process {
    int bt, prio, wt, tat;
};

int main() {
    int n, total_wt = 0, total_tat = 0;
    struct Process p[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time and Priority for P[%d]: ", i + 1);
        scanf("%d %d", &p[i].bt, &p[i].prio);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].prio > p[j].prio) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nExecution Breakdown:\n");
    for (int i = 0; i < n; i++) {
        p[i].wt = (i == 0) ? 0 : p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].bt + p[i].wt;
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("P[%d] executed for %d units of time\n", i + 1, p[i].bt);
        printf("P[%d] TAT=%d WT=%d\n", i + 1, p[i].tat, p[i].wt);
    }

    printf("\nAvg WT=%.2f Avg TAT=%.2f\n", (float)total_wt / n, (float)total_tat / n);
    return 0;
}

