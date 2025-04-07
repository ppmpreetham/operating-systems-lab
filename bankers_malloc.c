#include <stdio.h>
#include <stdlib.h>

void bankers(int p, int r, int *avail, int **allocation, int **max, int **need) {
    int idx = 0;
    int *finish = (int *)malloc(p * sizeof(int));
    int *seq = (int *)malloc(p * sizeof(int));

    for (int i = 0; i < p; i++) 
        finish[i] = 0;

    for (int process = 0; process < p; process++) {
        for (int i = 0; i < p; i++) {
            if (!finish[i]) {
                int flag = 1;
                for (int j = 0; j < r; j++) if (avail[j] < need[i][j]) flag = 0;

                if (flag) {
                    for (int j = 0; j < r; j++) avail[j] += allocation[i][j];
                    seq[idx++] = i;
                    finish[i] = 1;
                }
            }
        } 
    }

    printf("Safe sequence is: ");
    for (int i = 0; i < p; i++) 
        printf("%d ", seq[i]);
    printf("\n");
    
    free(finish);
    free(seq);
}

int main() {
    int p, r;
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the number of resources: ");
    scanf("%d", &r);
    
    int **allocation = (int **)malloc(p * sizeof(int *));
    int **max = (int **)malloc(p * sizeof(int *));
    int **need = (int **)malloc(p * sizeof(int *));
    int *avail = (int *)malloc(r * sizeof(int));
    
    for (int i = 0; i < p; i++) {
        allocation[i] = (int *)malloc(r * sizeof(int));
        max[i] = (int *)malloc(r * sizeof(int));
        need[i] = (int *)malloc(r * sizeof(int));
    }
    
    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the Max Matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available memory:\n");
    for (int i = 0; i < r; i++) 
        scanf("%d", &avail[i]);

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    bankers(p, r, avail, allocation, max, need);
    
    for (int i = 0; i < p; i++) {
        free(allocation[i]);
        free(max[i]);
        free(need[i]);
    }
    free(allocation);
    free(max);
    free(need);
    free(avail);
    
    return 0;
}