#include <stdio.h>

void fcfs(int n, int arrival[], int burst[], int complete[], int tat[], int w[]){
    complete[0] = arrival[0] + burst[0];
    
    for (size_t i = 1; i < n; i++){
        complete[i] = complete[i-1] + burst[i];
    }

    for (size_t i = 0; i < n; i++){
        tat[i] = complete[i] - arrival[i];
        w[i] = tat[i] - burst[i];
    }
}

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