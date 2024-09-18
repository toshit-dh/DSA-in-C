#pragma once
#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

// Define your own boolean type (e.g., boool)
//typedef boool;

// Structure to represent a stack node
typedef struct node {
    void* dataPtr;
    struct node* link;
} STACK_NODE;

// Structure to represent the stack itself
typedef struct {
    int count;
    STACK_NODE* top;
} STACK;

// Function prototypes
STACK* createStack(void);
bool pushStack(STACK* stack, void* dataInPtr);
void* popStack(STACK* stack);
bool fullStack(STACK* stack);
bool emptyStack(STACK* stack);
void* stackTop(STACK* stack);
void* stackMin(STACK* stack);
void* stackMax(STACK* stack);
int stackCount(STACK* stack);
STACK* destroyStack(STACK* stack);
void copyStack(STACK* source, STACK* destination);
#endif // STACK_H
