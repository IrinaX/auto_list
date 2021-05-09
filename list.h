#ifndef INC_3_LIST_H
#define INC_3_LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    struct Item *pPrev;
    struct Item *pNext;
} item;

typedef struct List {
    struct Item *pTail;
    struct Item *pHead;
} list;

void addListItem(list *myList, item *listItem);

void printList(list *myList);

int countListItems(list *myList);

void printMenu();

item *getItem(list *myList, int index);

item *removeItem(list *myList, int index);

void deleteItem(list *myList, int index);

void clearList(list *myList);

void insertItem(list *myList, item *newItem, int index);

int getIndex(list *myList, item *listItem);
#endif //INC_3_LIST_H
