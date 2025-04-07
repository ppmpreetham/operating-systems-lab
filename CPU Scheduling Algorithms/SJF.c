#include <stdio.h>
void sort(int bt[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(bt[i] > bt[j]) {
                int t = bt[i]; bt[i] = bt[j]; bt[j] = t;
            }
}
int main() {
    int n;
    printf("Processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n];
    printf("Burst times: ");
    for(int i = 0; i < n; i++) scanf("%d", &bt[i]);

    sort(bt, n);
    wt[0] = 0;
    for(int i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("P\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
}
