#include <stdio.h>

void bankers(int p, int r, int avail[], int allocation[][r], int max[][r], int need[][r]){
    int idx = 0;
    int finish[p];
    int seq[p];

    for (int i = 0; i < p; i++) finish[i] = 0;

    for (int process = 0; process < p; process++){
        for (int i = 0; i < p; i++){
            if(!finish[i]){
                int flag = 1;
                for (int j = 0; j < r; j++) if(avail[j] < need[i][j]) flag = 0;

                if(flag){
                    for (int j = 0; j < r; j++) avail[j] += allocation[i][j];
                    seq[idx++] = i;
                    finish[i] = 1;
                }
            }
        } 
    }

    printf("Safe sequence is: ");
    for (int i = 0; i < p; i++) printf("%d ", seq[i]);
    printf("\n");
}

void main(){
    int p, r;
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the number of resources: ");
    scanf("%d", &r);
    
    int allocation[p][r], max[p][r], need[p][r];
    int avail[r];
    
    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < p; i++){
        for (int j = 0; j < r; j++){
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the Max Matrix:\n");
    for (int i = 0; i < p; i++){
        for (int j = 0; j < r; j++){
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available memory:\n");
    for(int i = 0; i < r; i++) scanf("%d", &avail[i]);

    for (int i = 0; i < p; i++){
        for (int j = 0; j < r; j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    bankers(p, r, avail, allocation, max, need);
}