#include <stdio.h>
int main() {
    int mem[] = {100, 500, 200, 300, 600}, p[] = {212, 417, 112, 426};
    for (int i = 0; i < 4; i++) {
        int best = -1;
        for (int j = 0; j < 5; j++)
            if (mem[j] >= p[i] && (best == -1 || mem[j] < mem[best]))
                best = j;
        if (best != -1) {
            printf("P%d -> Block %d\n", i+1, best+1);
            mem[best] -= p[i];
        }
    }
}
