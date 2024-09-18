#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include<stdbool.h>

typedef struct node {
    void* dataPtr;
    struct node* next;
}QUEUE_NODE;

typedef struct {
    QUEUE_NODE* front;
    QUEUE_NODE* rear;
    int count;
}QUEUE;

QUEUE* createQueue(void);
QUEUE* destroyQueue(QUEUE* queue);
bool dequeue(QUEUE* queue, void** itemPtr);
bool enqueue(QUEUE* queue, void* itemPtr);
bool queueFront(QUEUE* queue, void** itemPtr);
bool queueRear(QUEUE* queue, void** itemPtr);
int queueCount(QUEUE* queue);
bool emptyQueue(QUEUE* queue);
bool fullQueue(QUEUE* queue);
void copyQueue(QUEUE* source, QUEUE* destination);

bool catQueue(QUEUE* queue1, QUEUE* queue2);

#endif