#include "list.h"

/* голова - <0===> - хвост */
void addListItem(list *myList, item *listItem) {
    if (myList->pHead == NULL) {//если нет элементов в списке
        listItem->pPrev = NULL;//добавленный элемент ни на что не указывает
        listItem->pNext = NULL;
        myList->pHead = listItem;//голова и хвост в списке это добавленный элемент
        myList->pTail = listItem;
    } else {
        myList->pTail->pNext = listItem;//обновляем указатель на след. эл-т у текущего "хвоста"
        listItem->pPrev = myList->pTail; //у нового эл-та определяем указатель на пред. эл-т(т.е. прошлый хвост)
        listItem->pNext = NULL;//следущего эл-та нет, поэтому указатель на след эл-т null
        myList->pTail = listItem; //обновляем хвост списка
    }
}

void printList(list *myList) {
    printf("\nList: %p\t\tHead: %p\tTail: %p\n", myList, myList->pHead, myList->pTail);
    printf("#\tlistItem\tpPrev\t\tpNext\n");
    int i = 0;
    for (item *element = myList->pHead; element != NULL; element = element->pNext) {
        printf("%d\t%p\t%p\t%p\n", i, element, element->pPrev, element->pNext);
        ++i;
    }
}

int countListItems(list *myList) {
    int i = 0;
    for (item *element = myList->pHead; element != NULL; element = element->pNext) {
        ++i;
    }
    return i;
}

void printMenu() {
    printf("\nWhat do you want to do?\n");
    printf("0. Fill list with test data\n");
    printf("1. Add item to tail\n");
    printf("2. Show list\n");
    printf("3. Count items\n");
    printf("4. Insert item\n");
    printf("5. Get item by index\n");
    printf("6. Get index of item\n");
    printf("7. Remove item by index\n");
    printf("8. Delete item by index\n");
    printf("9. Clear list\n");
    printf("10. Sort list by place count\n");
    printf("11. Search by state number, owner, color\n");
    printf("12. Exit\n");
    printf(">");
}

item *getItem(list *myList, int index) {
    if (myList->pHead == NULL) {//если начальный эл-т в списке отсутствует, возвращяем 0
        printf("\nList is empty.\n");
        return NULL;
    }
    item *element = myList->pHead;//присваиваем начальный элемент списка
    for (int i = 0; i < index; ++i) {
        if (element->pNext == NULL) {//если указатель на след. эл-т отсутствует, значит текущий эл-т последний
            printf("\nElement doesn't exist.\n");
            return NULL;
        } else {
            element = element->pNext;//присваиваем следующий элемент
        }
    }
    return element;
}

item *removeItem(list *myList, int index) {
    item *element = getItem(myList, index);
    if (element == NULL) {
        return NULL;
    }
    if (myList->pTail == myList->pHead) {//если в списке остался один элемент
        myList->pTail = NULL;//хвост обнуляем
        myList->pHead = NULL;//голову тоже
        return element;
    }
    if (element->pPrev == NULL) {//если удалить надо начальный элемент(голову) (индекс 0)
        element->pNext->pPrev = NULL;//обнуляем указатель на голову
        myList->pHead = element->pNext;//новая голова это эл-т с индексом 1
    } else {
        if (element->pNext == NULL) {//если удалить надо конечный элемент(хвост) (индекс n)
            element->pPrev->pNext = NULL;//обнуляем указатель на хвост
            myList->pTail = element->pPrev;//новый хвост это эл-т с индексом n-1
        } else {//если элемент находится посередине
            element->pPrev->pNext = element->pNext;//обновляем указатель на след элемент у пред элемента
            element->pNext->pPrev = element->pPrev;//обновляем указатель на пред элемент у след элемента
        }
    }
    return element;
}

void deleteItem(list *myList, int index) {
    item *removedItem = removeItem(myList, index);
    free(removedItem);
    removedItem = NULL;
    printf("\nItem was successfully deleted!\n");
}

void clearList(list *myList) {
    item *element = myList->pHead;//определяем начальный элемент списка для цикла
    while (element != NULL) {
        item *nextItem = element->pNext;//сохраняем указатель на следующий элемент
        free(element);//освобождаем память
        element = nextItem;//присваиваем текущему указателю сохраненный
    }
    myList->pHead = NULL;
    myList->pTail = NULL;
    printf("\nList was cleared successfully!\n");
}

void insertItem(list *myList, item *newItem, int index) {
    item *element = getItem(myList, index);
    if (element != NULL) {
        if (element == myList->pHead) {     // если выбран 0-ой эл-т
            newItem->pPrev = NULL;          // у нового элемента обнуляем указатель на предыдущий элемент
            newItem->pNext = element;       // у newItem присваиваем указателю на след элемент адрес текущей головы
            element->pPrev = newItem;       // у текущей головы обновляем указатель на пред эл-т
            myList->pHead = newItem;        // обновляем указатель на голову
            return;
        }
        if (element == myList->pTail) {     // если выбран последнй эл-т
            newItem->pNext = NULL;          // у нового элемента обнуляем указатель на след элемент
            newItem->pPrev = element;       // у newItem присваиваем указателю на пред элемент адрес текущего хвоста
            element->pNext = newItem;       // у текущего хвоста обновляем указатель на след эл-т
            myList->pTail = newItem;        // обновляем указатель на хвост
        } else {
            element->pPrev->pNext = newItem;    // у элемента index-1 присваиваем указателю на след элемент адрес newItem
            newItem->pPrev = element->pPrev;    // у newItem присваиваем указателю на пред элемент адрес элемента index-1
            newItem->pNext = element;           // у newItem присваиваем указателю на след элемент адрес элемента index
            element->pPrev = newItem;           // у элемента index присваиваем указателю на пред элемент адрес элемента newItem
        }
        printf("\nNew item was inserted successfully!\n");
    }
}

int getIndex(list *myList, item *listItem) {
    int index = 0;
    for (item *element = myList->pHead;  element != NULL;
         element = element->pNext) {
        if (listItem == element) {//если указатель текущего элемента равен необходимому
            return index;
        }
        ++index;
    }
    return -1;//если адрес был не найден
}