#include <stdio.h>

#define MAX_PROCESSES 10


void roundRobinScheduling(int n, int arrival_time[], int burst_time[],int QT) {
    int TIME_QUANTUM=QT;
    int remaining_time[MAX_PROCESSES];
    int completed = 0;
    int time = 0;
    int wt=0,tat=0;
    int i;
    for (i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
    }

    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                if (arrival_time[i] <= time) {
                    int execution_time = (remaining_time[i] < TIME_QUANTUM) ? remaining_time[i] : TIME_QUANTUM;
                    remaining_time[i] -= execution_time;
                    time += execution_time;

                    if (remaining_time[i] == 0) {
                        completed++;
                        tat=time-arrival_time[i];
                        wt=tat-burst_time[i];
                        printf("\nProcess %d completed at time %d\t tat:%d\twt:%d", i, time,tat,wt);
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    int QT;
    int arrival_time[MAX_PROCESSES];
    int burst_time[MAX_PROCESSES];
    int i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    printf("\n enter quantum time ");
    scanf("%d",&QT);

    roundRobinScheduling(n, arrival_time, burst_time,QT);

    return 0;
}
