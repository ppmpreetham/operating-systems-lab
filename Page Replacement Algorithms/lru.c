#include <stdio.h>
int main() {
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5}, f[3] = {-1,-1,-1}, used[3] = {0}, t = 0;
    for (int i = 0; i < 12; i++, t++) {
        int found = 0;
        for (int j = 0; j < 3; j++)
            if (f[j] == pages[i]) { used[j] = t; found = 1; }
        if (!found) {
            int lru = 0;
            for (int j = 1; j < 3; j++)
                if (used[j] < used[lru]) lru = j;
            f[lru] = pages[i]; used[lru] = t;
        }
        for (int j = 0; j < 3; j++) printf("%d ", f[j]);
        printf("\n");
    }
}
