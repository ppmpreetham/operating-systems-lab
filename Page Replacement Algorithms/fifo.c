#include <stdio.h>
int main() {
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5}, f[3] = {-1,-1,-1}, i, counter = 0;
    for (i = 0; i < 12; i++) {
        int found = 0;
        for (int j = 0; j < 3; j++) if (f[j] == pages[i]) found = 1;
        if (!found) f[counter++ % 3] = pages[i];
        for (int j = 0; j < 3; j++) printf("%d ", f[j]);
        printf("\n");
    }
}
