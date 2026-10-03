#ifndef STACK_H
#define STACK_H

#include "vehicle.h"

#define STACK_SIZE 50

typedef struct {
    Vehicle vehicles[STACK_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack);
int isStackEmpty(Stack *stack);
int isStackFull(Stack *stack);
int push(Stack *stack, Vehicle vehicle);
Vehicle pop(Stack *stack);
void displayHistory(Stack *stack);

#endif