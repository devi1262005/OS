#include <stdio.h>
#include <stdlib.h>

void priority_scheduling(int process_ids[], int burst_times[], int priorities[], int n) {
    // Sort the processes based on priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priorities[j] > priorities[j + 1]) {
                // Swap burst time
                int temp = burst_times[j];
                burst_times[j] = burst_times[j + 1];
                burst_times[j + 1] = temp;

                // Swap process id
                temp = process_ids[j];
                process_ids[j] = process_ids[j + 1];
                process_ids[j + 1] = temp;

                // Swap priority
                temp = priorities[j];
                priorities[j] = priorities[j + 1];
                priorities[j + 1] = temp;
            }
        }
    }

    int wt[n], tat[n];
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = burst_times[i - 1] + wt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = burst_times[i] + wt[i];
    }

    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    // Print results
    printf("Process\tBurst \tPriority \tWait \tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n", process_ids[i], burst_times[i], priorities[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    int process_ids[] = {1, 2, 3, 5};
    int burst_times[] = {10, 5, 8, 10};
    int priorities[] = {2, 1, 3, 4};
    int n = sizeof(process_ids) / sizeof(process_ids[0]);

    priority_scheduling(process_ids, burst_times, priorities, n);

    return 0;
}
