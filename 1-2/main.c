
#include "list.h"

int main() {
    //creating empty list
    item *listItem = NULL;
    listItem = malloc(sizeof(item));
    listItem->pPrev = 0;
    listItem->pNext = 0;
    list *myList = NULL;
    myList = malloc(sizeof(list));
    myList->pHead = 0;
    myList->pTail = 0;
    int variant = 0;
    while (variant <= 8) {
        printMenu();
        scanf("%d", &variant);
        switch (variant) {
            case 0: { //Add item to tail
                listItem = malloc(sizeof(item));
                addListItem(myList, listItem);
                printf("\nItem was added successfully!\n");
                break;
            }
            case 1: {//Show list
                printList(myList);
                break;
            }
            case 2: {//Count items
                int amountOfItems = countListItems(myList);
                printf("\namountOfItems = %d\n", amountOfItems);
                break;
            }
            case 3: {//Insert item
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    int index = 0;
                    item *newItem = malloc(sizeof(item));
                    printf("\nEnter index of element: ");
                    scanf("%d", &index);
                    insertItem(myList, newItem, index);
                    printf("\nNew item was inserted successfully!\n");
                }
                break;
            }
            case 4: {//Get item by index
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    int index = 0;
                    printf("\nEnter index of element: ");
                    scanf("%d", &index);
                    item *element = getItem(myList, index);
                    if (element != 0) {
                        printf("#\tlistItem\tpPrev\t\tpNext\n");
                        printf("%d\t%p\t%p\t%p\n", index, element, element->pPrev, element->pNext);
                    }
                }
                break;
            }
            case 5: {//Get index of item
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    printf("\nEnter item address (8 bit 0-9 A-F): ");
                    scanf("%p", &listItem);
                    int index = getIndex(myList, listItem);
                    if (index > -1) {
                        printf("\nindex = %d\n", index);
                    } else {
                        printf("\nElement doesn't exist.\n");
                    }
                }
                break;
            }
            case 6: {//Remove item by index
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    int index = 0;
                    printf("\nEnter index of element: ");
                    scanf("%d", &index);
                    item *removedElement = removeItem(myList, index);
                    if (removedElement != 0) {
                        printf("\n#\tremovedItem\tpPrev\t\tpNext\n");
                        printf("%d\t%p\t%p\t%p\n", index, removedElement, removedElement->pPrev, removedElement->pNext);
                    }
                }
                break;
            }
            case 7: {//Delete item by index
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    int index = 0;
                    printf("\nEnter index of element: ");
                    scanf("%d", &index);
                    deleteItem(myList, index);
                }
                break;
            }
            case 8: {//Clear list
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    clearList(myList);
                }
                break;
            }
            case 9: {//Exit
                printf("Exit...");
                if (myList != NULL) {
                    clearList(myList);
                    free(myList);
                    myList = NULL;
                }
                if (listItem != NULL) {
                    free(listItem);
                    listItem = NULL;
                }
                break;
            }
            default:
                break;
        }
    }
    return 0;
}
