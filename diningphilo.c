#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define N 5

sem_t mutex;
sem_t chopstick[N];

void *philosopher(void *arg) {
    int id = *(int *)arg;
    while (1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);

        sem_wait(&mutex);
        sem_wait(&chopstick[id]);
        sem_wait(&chopstick[(id + 1) % N]);
        sem_post(&mutex);

        printf("Philosopher %d is eating.\n", id);
        sleep(2);

        sem_post(&chopstick[id]);
        sem_post(&chopstick[(id + 1) % N]);

        printf("Philosopher %d finished eating.\n", id);
    }
}

int main() {
    pthread_t philosophers[N];
    int ids[N];

    sem_init(&mutex, 0, 1);
    for (int i = 0; i < N; i++) {
        sem_init(&chopstick[i], 0, 1);
        ids[i] = i;
    }

    for (int i = 0; i < N; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }

    sem_destroy(&mutex);
    for (int i = 0; i < N; i++) {
        sem_destroy(&chopstick[i]);
    }

    return 0;
}
