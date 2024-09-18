#include<stdio.h>
#include<stdlib.h>
#include "list.h"

int compare(void* arg1, void* arg2) {
    return 1;
}

int main() {
    LIST* list;
    list = createList(compare);

    int* p;
    p = (int*)malloc(sizeof(int));
    int* s;
    *p = 8;

    addNode(list, p);

    int* arr;
    arr = (int*)malloc(15 * sizeof(int));
    for (int i = 0; i < 15; i++) {
        arr[i] = 9 + i * 7 + 32 / (i + 1);
    }

    addNode(list, arr);

    traverse(list, 0, (void*)&s);
    printf("%d\n", *(int*)s);

    traverse(list, 1, (void*)&s);
    for (int i = 0; i < 15; i++) {
        printf("%d\t", s[i]);
    }
}