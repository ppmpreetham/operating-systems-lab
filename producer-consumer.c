#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int buffer = 0;
sem_t empty, full;
pthread_mutex_t mutex;

void* producer() {
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    buffer = 1;
    printf("Produced\n");
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

void* consumer() {
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    buffer = 0;
    printf("Consumed\n");
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

int main() {
    pthread_t p, c;
    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, 0);
    pthread_create(&p, 0, producer, 0);
    pthread_create(&c, 0, consumer, 0);
    pthread_join(p, 0);
    pthread_join(c, 0);
    return 0;
}
