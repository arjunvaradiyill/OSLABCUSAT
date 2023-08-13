#include <stdio.h>

int main() {
    int i, j, n, bt[20], at[20], wt[20], tat[20], p[20], pos, temp, total = 0;
    float avwt, avtat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time and arrival time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d] Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        printf("P[%d] Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        p[i] = i + 1;
    }

    // Sorting the processes based on arrival time using Selection Sort
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (at[j] < at[pos]) {
                pos = j;
            }
        }
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = at[i];
        at[i] = at[pos];
        at[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        total += wt[i];
    }

    avwt = (float)total / n;
    total = 0;

    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], at[i], wt[i], tat[i]);
    }

    avtat = (float)total / n;
    printf("\nAverage Waiting Time = %f\n", avwt);
    printf("Average Turnaround Time = %f\n", avtat);

    return 0;
}
