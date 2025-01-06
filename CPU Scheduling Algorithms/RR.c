#include <stdio.h>
#include <stdbool.h>

void round_robin(int n, int arrival[], int burst[], int quantum, int complete[], int tat[], int w[]) {
    int remaining_burst[n];
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = burst[i];
    }

    int time = 0;
    bool done;

    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                done = false;
                if (remaining_burst[i] > quantum) {
                    time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    time += remaining_burst[i];
                    complete[i] = time;
                    remaining_burst[i] = 0;
                }
            }
        }
    } while (!done);

    for (int i = 0; i < n; i++) {
        tat[i] = complete[i] - arrival[i];
        w[i] = tat[i] - burst[i];
    }
}

void main() {
    int n, quantum;
    printf("Enter the number of inputs\n");
    scanf("%d", &n);

    int arrival[n], burst[n], complete[n], tat[n], w[n];

    printf("Enter your times in the order of\nArrival, Burst\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    printf("Enter the time quantum\n");
    scanf("%d", &quantum);

    round_robin(n, arrival, burst, quantum, complete, tat, w);

    printf("Arrival Burst Completion TAT Waiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", arrival[i], burst[i], complete[i], tat[i], w[i]);
    }
}