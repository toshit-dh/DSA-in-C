#include "stack.h"
#include <stdlib.h>


// Function to create a new stack
STACK* createStack() {
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    if (stack) {
        stack->count = 0;
        stack->top = NULL;
    }
    return stack;
}

// Function to check if the stack is empty
bool emptyStack(STACK* stack) {
    return stack->count == 0;
}

// Function to check if the stack is full
bool fullStack(STACK* stack) {
    STACK_NODE* temp;
    if (temp = (STACK_NODE*)malloc(sizeof(*(stack->top)))) {
        free(temp);
        return false;
    }
    return true;
}

// Function to retrieve data from the top of the stack without popping
void* stackTop(STACK* stack) {
    if (stack->count == 0) {
        return NULL;
    }
    return stack->top->dataPtr;
}

// Function to get the number of elements in the stack
int stackCount(STACK* stack) {
    return stack->count;
}

// Function to delete all nodes in the stack and return NULL pointer
STACK* destroyStack(STACK* stack) {
    STACK_NODE* temp;
    if (stack) {
        while (stack->top != NULL) {
            free(stack->top->dataPtr);
            temp = stack->top;
            stack->top = stack->top->link;
            free(temp);
        }
        free(stack);
    }
    return NULL;
}
bool pushStack(STACK* stack, void* dataInPtr) {
    STACK_NODE* newPtr;
    newPtr = (STACK_NODE*)malloc(sizeof(STACK_NODE));
    if (!newPtr) {
        return false;
    }
    newPtr->dataPtr = dataInPtr;
    newPtr->link = stack->top;
    stack->top = newPtr;
    (stack->count)++;
    return true;
}
void* popStack(STACK* stack) {
    void* dataOutPtr;
    STACK_NODE* temp;
    if (stack->count == 0) {
        dataOutPtr = NULL;
    }
    else {
        temp = stack->top;
        dataOutPtr = stack->top->dataPtr;
        stack->top = stack->top->link;
        free(temp);
        (stack->count)--;
    }
    return dataOutPtr;
}
// Function to get the minimum element in the stack
void* stackMin(STACK* stack) {
    if (stack->count == 0) {
        return NULL;
    }

    // Initialize minElement with the value of the top element
    int* minElement = stack->top->dataPtr;// start ptr to start

    // Start from the second element in the stack
    STACK_NODE* currentNode = stack->top->link;

    // Iterate through the stack to find the minimum element
    while (currentNode != NULL) {
        // Compare the data of the current node with the minimum element
        // Assumes the data type is int; adjust for other data types
        if (*(int*)currentNode->dataPtr < *(int*)minElement) {
            // Update minElement if the current element is smaller
            minElement = currentNode->dataPtr;
        }
        // Move to the next node
        currentNode = currentNode->link;
    }

    // Return the minimum element found
    return minElement;
}
void* stackMax(STACK* stack) {
    if (stack->count == 0) {
        return NULL;
    }
    void* maxEle = stack->top->dataPtr;
    STACK_NODE* currentEle = stack->top->link;
    while (currentEle != NULL) {
        if (*(int*)currentEle->dataPtr > *(int*)maxEle) {
            maxEle = currentEle->dataPtr;
        }
        currentEle = currentEle->link;
    }
    return maxEle;
}
void copyStack(STACK* source, STACK* destination) {
    STACK_NODE* current = source->top;
    current = current->link;
    void* ele = source->top->dataPtr;
    pushStack(destination, ele);
    while (current != NULL) {
        pushStack(destination, current->dataPtr);
        current = current->link;
    }
}


