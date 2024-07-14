#include <stdio.h>

void sjf(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    int temp, total_wt = 0, total_tat = 0;

    // Sort the processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap processes
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    wt[0] = 0;
    tat[0] = bt[0];
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
        tat[i] = bt[i] + wt[i];
    }

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    // Print results
    printf("Process  Burst \t \t Wait \t Turnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %d\t \t%d \t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    int processes[] = {1, 2, 3, 5};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {10, 5, 8, 10};

    sjf(processes, n, burst_time);

    return 0;
}
