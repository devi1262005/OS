#include <stdio.h>

void round_robin(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n], remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = bt[i];
        wt[i] = 0;
    }

    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    wt[i] = time - bt[i];
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {10, 5, 8};
    int quantum = 2;

    round_robin(processes, n, burst_time, quantum);

    return 0;
}
