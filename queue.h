#ifndef QUEUE_H
#define QUEUE_H

#include "vehicle.h"

#define QUEUE_SIZE 20

typedef struct {
    Vehicle vehicles[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *queue);
int isQueueEmpty(Queue *queue);
int isQueueFull(Queue *queue);
int enqueue(Queue *queue, Vehicle vehicle);
Vehicle dequeue(Queue *queue);
void displayQueue(Queue *queue);

#endif