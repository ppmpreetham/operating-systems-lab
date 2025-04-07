#include <stdio.h>
int main() {
    int mem[] = {100, 500, 200, 300, 600}, p[] = {212, 417, 112, 426};
    for (int i = 0; i < 4; i++) {
        int worst = -1;
        for (int j = 0; j < 5; j++)
            if (mem[j] >= p[i] && (worst == -1 || mem[j] > mem[worst]))
                worst = j;
        if (worst != -1) {
            printf("P%d -> Block %d\n", i+1, worst+1);
            mem[worst] -= p[i];
        }
    }
}
