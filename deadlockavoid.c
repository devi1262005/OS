#include <stdio.h>

int is_safe_state(int processes[], int n, int max_matrix[][4], int allocation_matrix[][4], int available[]) {
    int need_matrix[5][3];

    // Calculate the Need matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            need_matrix[i][j] = max_matrix[i][j] - allocation_matrix[i][j];
        }
    }

    int finish[5] = {0};
    int safe_sequence[5];
    int work[3];

    for (int i = 0; i < 3; i++) {
        work[i] = available[i];
    }

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < 3; j++) {
                    if (need_matrix[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == 3) {
                    // Process i can finish
                    for (int k = 0; k < 3; k++) {
                        work[k] += allocation_matrix[i][k];
                    }

                    safe_sequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            // No process found, not in safe state
            printf("System is not in a safe state.\n");
            return 0;
        }
    }

    // If the loop completes, the system is in a safe state
    printf("System is in a safe state. Safe sequence: ");
    for (int i = 0; i < n - 1; i++) {
        printf("%d -> ", safe_sequence[i]);
    }
    printf("%d\n", safe_sequence[n - 1]);

    return 1;
}

int main() {
    int processes[] = {0, 1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);

    int max_matrix[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int allocation_matrix[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int available[] = {3, 3, 3};

    is_safe_state(processes, n, max_matrix, allocation_matrix, available);

    return 0;
}
