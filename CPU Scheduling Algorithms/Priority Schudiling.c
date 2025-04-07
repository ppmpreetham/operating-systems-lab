#include <stdio.h>
int main() {
    int n;
    printf("Processes: ");
    scanf("%d", &n);
    int bt[n], p[n], pid[n], wt[n], tat[n];
    printf("Burst times: ");
    for(int i = 0; i < n; i++) {
        pid[i] = i+1;
        scanf("%d", &bt[i]);
    }
    printf("Priorities (lower = higher priority): ");
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);

    // Sort by priority
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(p[i] > p[j]) {
                int t = p[i]; p[i] = p[j]; p[j] = t;
                t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = pid[i]; pid[i] = pid[j]; pid[j] = t;
            }

    wt[0] = 0;
    for(int i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("P\tBT\tPty\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], bt[i], p[i], wt[i], tat[i]);
}