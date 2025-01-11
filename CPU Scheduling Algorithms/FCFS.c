#include <stdio.h>

int max(int a, int b){ return a>b?a:b;}

void fcfs(int n, int arrival[], int burst[], int completed[], int tat[], int waiting[]){
    completed[0] = arrival[0] + burst[0];
    
    for (int i = 1; i < n; i++){
        completed[i] = max(completed[i-1],arrival[i]) + burst[i];
    }

    for (int i = 0; i < n; i++){
        tat[i] = completed[i] - arrival[i];
        waiting[i] = tat[i] - burst[i];
    }
}

// Driver Code
void main(){
    int n;
    printf("Enter the number of inputs\n");
    scanf("%d",&n);

    int arrival[n], burst[n], complete[n], tat[n], w[n];

    printf("Enter your times in the order of\nArrival, Burst\n");
    for (size_t i = 0; i < n; i++){
        scanf("%d %d", &arrival[i], &burst[i]);
    }
    
    fcfs(n, arrival, burst, complete, tat, w);

    printf("Arrival Burst Completion TAT Waiting\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", arrival[i], burst[i], complete[i],tat[i],w[i]);
    }
}

