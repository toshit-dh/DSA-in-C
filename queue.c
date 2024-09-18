#include "queue.h"
#include <stdlib.h>
#include<stdbool.h>

QUEUE* createQueue(void) {
    QUEUE* queue;
    queue = (QUEUE*)malloc(sizeof(QUEUE));
    if (queue) {
        queue->front = NULL;
        queue->rear = NULL;
        queue->count = 0;
    }
    return queue;

}

bool enqueue(QUEUE* queue, void* itemPtr) {
    QUEUE_NODE* newPtr;
    if (!(newPtr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE)))) {
        return false;
    }
    newPtr->dataPtr = itemPtr;
    newPtr->next = NULL;
    if (queue->count == 0) {
        queue->front = newPtr;
    }
    else {
        queue->rear->next = newPtr;
    }
    (queue->count)++;
    queue->rear = newPtr;
    return true;
}

bool dequeue(QUEUE* queue, void** itemPtr) {
    QUEUE_NODE* deleteLoc;
    if (!queue->count) {
        return false;
    }
    *itemPtr = queue->front->dataPtr;
    deleteLoc = queue->front;
    if (queue->count == 1) {
        queue->rear = queue->front = NULL;
    }
    else {
        queue->front = queue->front->next;
    }
    (queue->count)--;
    free(deleteLoc);
}

bool queueFront(QUEUE* queue, void** itemPtr) {
    if (!queue->count) {
        return false;
    }
    else {
        *itemPtr = queue->front->dataPtr;
        return true;
    }
}

bool queueRear(QUEUE* queue, void** itemPtr) {
    if (!queue->count) {
        return false;
    }
    else {
        *itemPtr = queue->rear->dataPtr;
        return true;
    }
}

bool emptyQueue(QUEUE* queue) {
    return (queue->count == 0);
}

bool fullQueue(QUEUE* queue) {
    QUEUE_NODE* temp;
    temp = (QUEUE_NODE*)malloc(sizeof(*(queue->rear)));
    if (temp) {
        free(temp);
        return true;
    }
    return false;
}

int queueCount(QUEUE* queue) {
    return queue->count;
}

QUEUE* destroyQueue(QUEUE* queue) {
    QUEUE_NODE* deletePtr;
    if (queue) {
        while (queue->front != NULL) {
            free(queue->front->dataPtr);
            deletePtr = queue->front;
            queue->front = queue->front->next;
            free(deletePtr);
        }
        free(queue);
    }
    return NULL;
}
void copyQueue(QUEUE* source, QUEUE* destination) {
    QUEUE_NODE* ptr = source->front;

    while (ptr != NULL) {
        int* copiedValue = (int*)malloc(sizeof(int));
        *copiedValue = *((int*)(ptr->dataPtr));

        enqueue(destination, copiedValue);

        ptr = ptr->next;
    }
}

bool catQueue(QUEUE* queue1, QUEUE* queue2) {
    if (queue2->count == 0) return false;
    if (queue1->count == 0) {
        queue1->front = queue2->front;
        queue1->rear = queue2->rear;
    }
    else {
        queue1->rear->next = queue2->front;
        queue1->rear = queue2->rear;
    }
    queue1->count += queue2->count;
    return true;

}