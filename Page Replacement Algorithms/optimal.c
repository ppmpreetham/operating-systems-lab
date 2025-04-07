#include <stdio.h>
int main() {
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5}, f[3] = {-1,-1,-1};
    for (int i = 0; i < 12; i++) {
        int found = 0;
        for (int j = 0; j < 3; j++) if (f[j] == pages[i]) found = 1;
        if (!found) {
            int far[3] = {0}, idx = -1;
            for (int j = 0; j < 3; j++) {
                int k;
                for (k = i+1; k < 12; k++) if (f[j] == pages[k]) break;
                far[j] = (k == 12) ? 999 : k;
                if (idx == -1 || far[j] > far[idx]) idx = j;
            }
            f[idx] = pages[i];
        }
        for (int j = 0; j < 3; j++) printf("%d ", f[j]);
        printf("\n");
    }
}
