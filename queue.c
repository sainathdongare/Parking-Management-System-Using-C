#include <stdio.h>
#include "queue.h"

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueEmpty(Queue *queue) {
    return queue->front == -1;
}

int isQueueFull(Queue *queue) {
    return queue->rear == QUEUE_SIZE - 1;
}

int enqueue(Queue *queue, Vehicle vehicle) {
    if (isQueueFull(queue)) {
        return 0;
    }

    if (isQueueEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear++;
    queue->vehicles[queue->rear] = vehicle;

    return 1;
}

Vehicle dequeue(Queue *queue) {
    Vehicle vehicle;

    vehicle.slotNumber = -1;

    if (isQueueEmpty(queue)) {
        return vehicle;
    }

    vehicle = queue->vehicles[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }

    return vehicle;
}

void displayQueue(Queue *queue) {
    printf("\n========== WAITING QUEUE ==========\n");

    if (isQueueEmpty(queue)) {
        printf("No vehicles waiting.\n");
        printf("===================================\n");
        return;
    }

    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d. %s | %s | %s\n",
               i - queue->front + 1,
               queue->vehicles[i].vehicleNumber,
               queue->vehicles[i].ownerName,
               queue->vehicles[i].vehicleType);
    }

    printf("===================================\n");
}