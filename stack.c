#include <stdio.h>
#include "stack.h"

void initializeStack(Stack *stack) {
    stack->top = -1;
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

int isStackFull(Stack *stack) {
    return stack->top == STACK_SIZE - 1;
}

int push(Stack *stack, Vehicle vehicle) {
    if (isStackFull(stack)) {
        return 0;
    }

    stack->top++;
    stack->vehicles[stack->top] = vehicle;

    return 1;
}

Vehicle pop(Stack *stack) {
    Vehicle vehicle;

    vehicle.slotNumber = -1;

    if (isStackEmpty(stack)) {
        return vehicle;
    }

    vehicle = stack->vehicles[stack->top];
    stack->top--;

    return vehicle;
}

void displayHistory(Stack *stack) {
    printf("\n========== PARKING HISTORY ==========\n");

    if (isStackEmpty(stack)) {
        printf("No parking history.\n");
        printf("=====================================\n");
        return;
    }

    for (int i = stack->top; i >= 0; i--) {
        printf("\nVehicle Number : %s",
               stack->vehicles[i].vehicleNumber);
        printf("\nOwner Name     : %s",
               stack->vehicles[i].ownerName);
        printf("\nVehicle Type   : %s",
               stack->vehicles[i].vehicleType);
        printf("\nSlot Number    : %d\n",
               stack->vehicles[i].slotNumber);
    }

    printf("=====================================\n");
}