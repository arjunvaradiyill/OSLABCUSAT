#include <stdio.h>

int main() {
    int n, i, j, temp, bt[20], at[20], wt[20], tat[20], p[20];
    float avwt = 0, avtat = 0;

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
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int currentTime = 0;
    for (i = 0; i < n; i++) {
        int shortest = i;
        for (j = i + 1; j < n; j++) {
            if (at[j] <= currentTime && bt[j] < bt[shortest]) {
                shortest = j;
            }
        }

        temp = bt[i];
        bt[i] = bt[shortest];
        bt[shortest] = temp;

        temp = at[i];
        at[i] = at[shortest];
        at[shortest] = temp;

        temp = p[i];
        p[i] = p[shortest];
        p[shortest] = temp;

        wt[i] = currentTime - at[i];
        if (wt[i] < 0) {
            currentTime = at[i];
            wt[i] = 0;
        }

        currentTime += bt[i];
        tat[i] = bt[i] + wt[i];

        avwt += wt[i];
        avtat += tat[i];
    }

    avwt /= n;
    avtat /= n;

    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], at[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %f\n", avwt);
    printf("Average Turnaround Time: %f\n", avtat);

    return 0;
}
