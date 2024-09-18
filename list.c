#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"list.h"

LIST* createList(int (*compare)(void* argu1, void* argu2)) {
    LIST* list;
    list = (LIST*)malloc(sizeof(LIST));
    if (list) {
        list->head = NULL;
        list->pos = NULL;
        list->rear = NULL;
        list->count = 0;
        list->compare = compare;
    }
    return list;
}
LIST* destroyList(LIST* plist) {
    NODE* deletePtr;
    if (plist) {
        while (plist->count > 0) {
            free(plist->head->dataPtr);
            deletePtr = plist->head;
            plist->head = plist->head->link;
            plist->count--;
            free(deletePtr);
        }
        free(plist);
    }
    return NULL;

}
int addNode(LIST* pList, void* dataInPtr) {
    bool found;
    bool success;
    NODE* pPre;
    NODE* pLoc;
    found = _search(pList, &pPre, &pLoc, dataInPtr);
    if (found) {
        return (+1);
    }
    success = _insert(pList, pPre, dataInPtr);
    if (!success) {
        return (-1);
    }
    return (0);
}
bool removeNode(LIST* pList, void* keyPtr, void** dataOutPtr) {
    bool found;
    NODE* pPre;
    NODE* pLoc;
    found = _search(pList, &pPre, &pLoc, keyPtr);
    if (found) {
        _delete(pList, pPre, pLoc, dataOutPtr);
    }
    return false;
}
bool searchList(LIST* pList, void* pArgu, void** pDataOut) {
    bool found;
    NODE* pPre;
    NODE* pLoc;
    found = _search(pList, &pPre, &pLoc, pArgu);
    if (found) {
        *pDataOut = pLoc->dataPtr;
    }
    else
    {
        *pDataOut = NULL;;
    }
    return found;
}
bool retriveNode(LIST* pList, void* pArgu, void** dataOutPtr) {
    bool found;
    NODE* pPre;
    NODE* pLoc;
    found = _search(pList, &pPre, &pLoc, pArgu);
    if (found) {
        *dataOutPtr = pLoc->dataPtr;
        return true;
    }
    *dataOutPtr = NULL;
    return false;
}

bool traverse(LIST* pList, int fromWhere, void** dataPtrOut) {
    if (pList->count == 0) return false;
    if (fromWhere == 0) {
        // Start from first node
        pList->pos = pList->head;
        *dataPtrOut = pList->pos->dataPtr;
        return true;
    } // if fromwhere
    else
    {
        // Start from current position
        if (pList->pos->link == NULL)\
            return false;
        else {
            pList->pos = pList->pos->link;
            *dataPtrOut = pList->pos->dataPtr;
            return true;
        } // if else
    } // if fromwhere else
} // traverse

int listCount(LIST* pList) {
    return pList->count;
}
bool emptyList(LIST* pList) {
    return (pList->count == 0);
}
bool fullList(LIST* pList) {
    NODE* temp;
    if ((temp = (NODE*)malloc(sizeof(*(pList->head))))) {
        free(temp);
        return false;
    }
    return true;
}
static int _insert(LIST* pList, NODE* pPre, void* dataInPtr) {
    NODE* pNew;
    if (!(pNew = (NODE*)malloc(sizeof(NODE)))) {
        return false;
    }
    pNew->dataPtr = dataInPtr;
    pNew->link = NULL;
    if (pPre == NULL) {
        pNew->link = pList->head;
        pList->head = pNew;
        if (pList->count == 0) {
            pList->rear = pNew;
        }
    }
    else {
        pNew->link = pPre->link;
        pPre->link = pNew;
        if (pNew->link == NULL) {
            pList->rear = pNew;
        }
    }
    (pList->count)++;
    return true;
}
static void _delete(LIST* pList, NODE* pPre, NODE* pLoc, void** dataOutPtr) {
    *dataOutPtr = pLoc->dataPtr;
    if (pPre == NULL) {
        pList->head = pLoc->link;
    }
    else {
        pPre->link = pLoc->link;
    }
    if (pLoc->link == NULL) {
        pList->rear = pPre;
    }
    (pList->count)--;
    free(pLoc);
    return;
}
static bool _search(LIST* pList, NODE** pPre, NODE** pLoc, void* pArgu) {
#define COMPARE\
    (((*pList->compare)(pArgu,(*pLoc)->dataPtr)))
#define COMPARE_LAST\
    ((*pList->compare)(pArgu,pList->rear->dataPtr))
    int result;
    *pPre = NULL;
    *pLoc = pList->head;
    if (pList->count == 0) {
        return false;
    }
    if (COMPARE_LAST > 0) {
        *pPre = pList->rear;
        *pLoc = NULL;
        return false;
    }
    while ((result = COMPARE) > 0) {
        *pPre = *pLoc;
        *pLoc = (*pLoc)->link;
    }
    if (result == 0)
        return true;
    else
        return false;
}
bool addLists(LIST* list1, LIST* list2) {

    // Initialize pointers to the heads of list1 and list2
    NODE* currentNode1 = list1->head;
    NODE* currentNode2 = list2->head;

    list1->rear->link = list2->head;
    list1->rear = list2->rear;
    return true;
}


void printList(LIST* pList) {
    NODE* currentNode = pList->head;

    while (currentNode != NULL) {
        // Assuming your data is of type int, change this to match your actual data type
        int* data = (int*)currentNode->dataPtr;
        printf("%d ", *data);
        currentNode = currentNode->link;
    }

    printf("\n");
}
