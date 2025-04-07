#include <stdio.h>
int main() {
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5}, f[3] = {-1,-1,-1}, i, j = 0;
    for (i = 0; i < 12; i++) {
        int found = 0;
        for (int k = 0; k < 3; k++) if (f[k] == pages[i]) found = 1;
        if (!found) f[j++ % 3] = pages[i];
        for (int k = 0; k < 3; k++) printf("%d ", f[k]);
        printf("\n");
    }
}
