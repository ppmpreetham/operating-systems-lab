#include <stdio.h>
int max(int a, int b) { return a > b ? a : b; }

void priority(int n, int at[], int bt[], int pr[], int ct[], int tat[], int wt[]) {
    int done[n], time = 0;
    for(int i=0;i<n;i++) done[i]=0;

    for(int completed = 0; completed < n; completed++) {
        int idx = -1, best = 1e9;
        for(int i=0; i<n; i++)
            if(!done[i] && at[i] <= time && pr[i] < best) {
                best = pr[i];
                idx = i;
            }

        if(idx == -1) { time++; completed--; continue; }

        time = max(time, at[idx]) + bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        done[idx] = 1;
    }
}
