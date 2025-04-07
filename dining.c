#include <stdio.h>
#include <pthread.h>

pthread_mutex_t chopstick[5];

void* philosopher(void* n) {
    int i = *(int*)n;
    pthread_mutex_lock(&chopstick[i]);
    pthread_mutex_lock(&chopstick[(i+1)%5]);
    printf("Philosopher %d eating\n", i);
    pthread_mutex_unlock(&chopstick[i]);
    pthread_mutex_unlock(&chopstick[(i+1)%5]);
}

int main() {
    pthread_t t[5];
    int i, id[5];
    for (i = 0; i < 5; i++) {
        pthread_mutex_init(&chopstick[i], 0);
        id[i] = i;
    }
    for (i = 0; i < 5; i++)
        pthread_create(&t[i], 0, philosopher, &id[i]);
    for (i = 0; i < 5; i++)
        pthread_join(t[i], 0);
}
