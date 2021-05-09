#include "list.h"
#include "subj.h"

/*
14. Элементы списка описывают следующие автомобили: легковой (тип кузова, тип двигателя, тип привода),
микроавтобус (тип двигателя, количество мест), автобус (тип двигателя, количество мест, грузоподъемность),
грузовой (тип двигателя, грузоподъемность), специальный (текстовое описание). Для автомобилей всех типов
также указывается: гос. номер, владелец, марка, модель, цвет. Необходимо реализовать сортировку автомобилей
по количеству мест и поиск по номеру, владельцу и цвету.
*/
int main() {
    //creating empty list
    Car *listItem = NULL;
    listItem = malloc(sizeof(item));
    listItem->pPrev = 0;
    listItem->pNext = 0;
    list *myList = NULL;
    myList = malloc(sizeof(list));
    myList->pHead = 0;
    myList->pTail = 0;
    int variant = 0;
    while (variant <= 14) {
        printMenu();
        scanf("%d", &variant);
        switch (variant) {
            case 0: {
                fillListTest(myList);
                break;
            }
            case 1: { //добавление элемента в хвост
                listItem = createNewCar();
                inputItem(listItem);
                addListItem(myList, (item *) listItem);
                printf("\nItem was added successfully!\n");
                break;
            }
            case 2: {// показать список
                printNewList(myList);
                break;
            }
            case 3: {// посчитать элементы
                int amountOfItems = countListItems(myList);
                printf("\namountOfItems = %d\n", amountOfItems);
                break;
            }
            case 4: {// вставить элемент
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    int index;
                    Car *newCar = createNewCar();
                    inputItem(newCar);
                    printf("\nEnter index of element:");
                    scanf("%d", &index);
                    insertItem(myList, (item *) newCar, index);
                }
                break;
            }
            case 5: {// получить элемент по индексу
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    int index = 0;
                    printf("\nEnter index of element:");
                    scanf("%d", &index);
                    item *element = getItem(myList, index);
                    if (element != 0) {
                        printItem((Car *) element);
                    }
                }
                break;
            }
            case 6: {// получить индекс элемента по указателю
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    printf("\nEnter item address (8 bit 0-9 A-F):");
                    scanf("%p", &listItem);
                    int index = getIndex(myList, (item *) listItem);
                    if (index > -1) {
                        printf("\nindex = %d\n", index);
                    } else {
                        printf("\nElement doesn't exist.\n");
                    }
                }
                break;
            }
            case 7: {// вырезать элемент из списка
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    int index = 0;
                    printf("\nEnter index of element:");
                    scanf("%d", &index);
                    item *removedElement = removeItem(myList, index);
                    if (removedElement != 0) {
                        printItem((Car *) removedElement);
                    }
                }
                break;
            }
            case 8: {// удалить элемент из списка
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    int index = 0;
                    printf("\nEnter index of element:");
                    scanf("%d", &index);
                    deleteItem(myList, index);
                }
                break;
            }
            case 9: {// очистить список
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    clearList(myList);
                }
                break;
            }
            case 10: {//сортировка автомобилей по количеству мест
                if (myList->pHead) {//если начальный эл-т отсутствует, то список пуст
                    placeSort(myList);
                    printf("\nList was sorted successfully.\n");
                } else {
                    printf("\nList is empty.\n");
                }
                break;
            }
            case 11: {//поиск по номеру, владельцу и цвету
                search(myList);
                break;
            }
            case 12: {//Exit
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
