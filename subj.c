#include <string.h>
#include "subj.h"

Car *createNewCar() {
    printf("\nChoose car type: "); //тип авто
    printf("\n1. PassengerCar");   //легковушка
    printf("\n2. MicroBus");       //микроавтобус
    printf("\n3. Bus");            //автобус
    printf("\n4. Truck");          //грузовой
    printf("\n5. Special\n");      //специальный
    int choice;
    scanf("%d", &choice);
    Car *pCreatedCar = NULL;
    switch (choice) {
        case 1: {
            pCreatedCar = create(itPassengerCar);
            break;
        }
        case 2: {
            pCreatedCar = create(itMicroBus);
            break;
        }
        case 3: {
            pCreatedCar = create(itBus);
            break;
        }
        case 4: {
            pCreatedCar = create(itTruck);
            break;
        }
        case 5: {
            pCreatedCar = create(itSpecial);
            break;
        }
        default:
            break;
    }
    return pCreatedCar;
}

Car *create(CarType type) {//создаем элемент с определенным типом
    Car *pCreatedCar = NULL;
    switch (type) {
        case itPassengerCar: {
            pCreatedCar = malloc(sizeof(PassengerCar));
            break;
        }
        case itMicroBus: {
            pCreatedCar = malloc(sizeof(MicroBus));
            break;
        }
        case itBus: {
            pCreatedCar = malloc(sizeof(Bus));
            break;
        }
        case itTruck: {
            pCreatedCar = malloc(sizeof(Truck));
            break;
        }
        case itSpecial: {
            pCreatedCar = malloc(sizeof(Special));
            break;
        }
        default: {
            printf("\nUndefined object.\n");
            break;
        }
    }
    if (pCreatedCar) {
        pCreatedCar->pNext = 0;//обнуляем указатели
        pCreatedCar->pPrev = 0;
        pCreatedCar->type = type;//созданному обьекту присваиваем его тип
    }
    return pCreatedCar;
}

/*
 * реализовать объявленные ранее (в subj.h) функции операций
   над объектами (т.е. функции диспетчеризации, которые
   вызывают специфические функции в зависимости от
   фактического типа структуры);
 */
void inputItem(Car *pCreatedCar) {
    if (pCreatedCar) {
        switch (pCreatedCar->type) {// в зависимости от типа структуры вызывается соответствующая ф-я
            case itPassengerCar: {
                inputPassengerCar((PassengerCar *) pCreatedCar);
                break;
            }
            case itMicroBus: {
                inputMicroBus((MicroBus *) pCreatedCar);
                break;
            }
            case itBus: {
                inputBus((Bus *) pCreatedCar);
                break;
            }
            case itTruck: {
                inputTruck((Truck *) pCreatedCar);
                break;
            }
            case itSpecial: {
                inputSpecial((Special *) pCreatedCar);
                break;
            }
            default: {
                printf("\nUndefined object.\n");
                break;
            }
        }
    } else {
        printf("\nUndefined pCreatedCar (func: void inputItem(Car *pCreatedCar)).\n");
    }
}

void inputCar(Car *pCar) {
    printf("\nEnter state number (max 9 symbols): ");//гос. номер
    scanf("%9s", pCar->number);
    printf("\nEnter owner (max 29 symbols): ");//собственник
    scanf("%29s", pCar->owner);
    printf("\nEnter brand (max 19 symbols): ");//бренд
    scanf("%19s", pCar->brand);
    printf("\nEnter model (max 19 symbols): ");//модель
    scanf("%19s", pCar->model);
    printf("\nEnter color (max 19 symbols): ");//цвет
    scanf("%19s", pCar->color);
}

void inputPassengerCar(PassengerCar *pCar) {
    inputCar((Car *) pCar);//сначала заполняем поля базового класса
    int choice;
    printf("\nChoose engine type: ");   //тип двигателя
    printf("\n1. Gasoline");            //бензин
    printf("\n2. Diesel\n");            //дизель
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            pCar->engine = Gasoline;
            break;
        }
        case 2: {
            pCar->engine = Diesel;
            break;
        }
        default:
            break;
    }
    printf("\nChoose car body type: "); //тип кузова
    printf("\n1. Sedan");               //седан
    printf("\n2. Coup");                //купе
    printf("\n3. Universal\n");         //универсал
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            pCar->body = Sedan;
            break;
        }
        case 2: {
            pCar->body = Coup;
            break;
        }
        case 3: {
            pCar->body = Universal;
            break;
        }
        default:
            break;
    }
    printf("\nChoose drive type: ");    //тип привода
    printf("\n1. Front");               //передний
    printf("\n2. Back");                //задний
    printf("\n3. Full\n");              //полный
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            pCar->drive = Front;
            break;
        }
        case 2: {
            pCar->drive = Back;
            break;
        }
        case 3: {
            pCar->drive = Full;
            break;
        }
        default:
            break;
    }
}

void inputMicroBus(MicroBus *pCar) {
    inputCar((Car *) pCar);//сначала заполняем поля базового класса
    printf("\nChoose engine type: ");   //тип двигателя
    printf("\n1. Gasoline");            //бензин
    printf("\n2. Diesel\n");            //дизель
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            pCar->engine = Gasoline;
            break;
        }
        case 2: {
            pCar->engine = Diesel;
            break;
        }
        default:
            break;
    }
    printf("\nEnter number of seats: ");   //количество мест
    scanf("%d", &(pCar->placeCount));
}

void inputBus(Bus *pCar) {
    inputCar((Car *) pCar);//сначала заполняем поля базового класса
    printf("\nChoose engine type: ");   //тип двигателя
    printf("\n1. Gasoline");            //бензин
    printf("\n2. Diesel\n");            //дизель
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            pCar->engine = Gasoline;
            break;
        }
        case 2: {
            pCar->engine = Diesel;
            break;
        }
        default:
            break;
    }
    printf("\nEnter number of seats: ");   //количество мест
    scanf("%d", &(pCar->placeCount));
    printf("\nEnter lifting capacity: ");   //грузоподъемность
    scanf("%d", &(pCar->capacity));
}

void inputTruck(Truck *pCar) {
    inputCar((Car *) pCar);//сначала заполняем поля базового класса
    printf("\nChoose engine type: ");   //тип двигателя
    printf("\n1. Gasoline");            //бензин
    printf("\n2. Diesel\n");            //дизель
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            pCar->engine = Gasoline;
            break;
        }
        case 2: {
            pCar->engine = Diesel;
            break;
        }
        default:
            break;
    }
    printf("\nEnter lifting capacity: ");   //грузоподъемность
    scanf("%d", &(pCar->capacity));
}

void inputSpecial(Special *pCar) {
    inputCar((Car *) pCar);//сначала заполняем поля базового класса
    printf("\nEnter description (max 99 symbols): ");   //описание
    scanf("%99s", pCar->description);
}

void printItem(Car *pCar) {
    if (pCar) {
        switch (pCar->type) {
            case itPassengerCar: {
                printPassengerCar((PassengerCar *) pCar);
                break;
            }
            case itMicroBus: {
                printMicroBus((MicroBus *) pCar);
                break;
            }
            case itBus: {
                printBus((Bus *) pCar);
                break;
            }
            case itTruck: {
                printTruck((Truck *) pCar);
                break;
            }
            case itSpecial: {
                printSpecial((Special *) pCar);
                break;
            }
            default: {
                printf("\nUndefined object.\n");
                break;
            }
        }
    } else {
        printf("\nUndefined pCar (func: void printItem(Car *pCar)).\n");
    }
}

void printCar(Car *pCar) {
    printf("Pointer: %p prev: %p next: %p\n", pCar, pCar->pPrev, pCar->pNext);
    printf("State number: %s\n", pCar->number);
    printf("Owner: %s\n", pCar->owner);
    printf("Brand: %s\n", pCar->brand);
    printf("Model: %s\n", pCar->model);
    printf("Color: %s\n", pCar->color);
}

void printPassengerCar(PassengerCar *pCar) {
    printf("Type: Passenger Car\n");
    printCar((Car *) pCar);//сначала выводим поля базового класса
    printf("Engine type: ");
    switch (pCar->engine) {
        case Gasoline: {
            printf("Gasoline\n");
            break;
        }
        case Diesel: {
            printf("Diesel\n");
            break;
        }
        default:
            break;
    }
    printf("Car body type: ");
    switch (pCar->body) {
        case Sedan: {
            printf("Sedan\n");
            break;
        }
        case Coup: {
            printf("Coup\n");
            break;
        }
        case Universal: {
            printf("Universal\n");

            break;
        }
        default:
            break;
    }
    printf("Drive type: ");
    switch (pCar->drive) {
        case Front: {
            printf("Front\n");
            break;
        }
        case Back: {
            printf("Back\n");
            break;
        }
        case Full: {
            printf("Full\n");
            break;
        }
        default:
            break;
    }
}

void printMicroBus(MicroBus *pCar) {
    printf("Type: Micro Bus\n");
    printCar((Car *) pCar);//сначала выводим поля базового класса
    printf("Engine type: ");
    switch (pCar->engine) {
        case Gasoline: {
            printf("Gasoline\n");
            break;
        }
        case Diesel: {
            printf("Diesel\n");
            break;
        }
        default:
            break;
    }
    printf("Number of seats: %d\n", pCar->placeCount);
}

void printBus(Bus *pCar) {
    printf("Type: Bus\n");
    printCar((Car *) pCar);//сначала выводим поля базового класса
    printf("Engine type: ");
    switch (pCar->engine) {
        case Gasoline: {
            printf("Gasoline\n");
            break;
        }
        case Diesel: {
            printf("Diesel\n");
            break;
        }
        default:
            break;
    }
    printf("Number of seats: %d\n", pCar->placeCount);
    printf("Lifting capacity: %d\n", pCar->capacity);
}

void printTruck(Truck *pCar) {
    printf("Type: Truck\n");
    printCar((Car *) pCar);//сначала выводим поля базового класса
    printf("Engine type: ");
    switch (pCar->engine) {
        case Gasoline: {
            printf("Gasoline\n");
            break;
        }
        case Diesel: {
            printf("Diesel\n");
            break;
        }
        default:
            break;
    }
    printf("Lifting capacity: %d\n", pCar->capacity);
}

void printSpecial(Special *pCar) {
    printf("Type: Special\n");
    printCar((Car *) pCar);//сначала выводим поля базового класса
    printf("Description: %s\n", pCar->description);
}

void printNewList(list *pList) {
    int i = 0;
    if (pList) {
        if (pList->pHead) {
            for (item *pItem = pList->pHead; pItem != NULL; pItem = pItem->pNext) {
                printf("\nIndex: %d\n", i);
                printItem((Car *) pItem);
                ++i;
            }
        } else {
            printf("\nList is empty.\n");
        }
    } else {
        printf("\nUndefined pList. Func: void printNewList(list *pList)\n");
    }
}

void placeSort(list *pList) {//сортировка по кол-ву мест в авто
    int amount = countListItems(pList);
    if (amount == 0 || amount == 1)//если список пустой или в нем один элемент, не сортируем
    {
        printf("\nList is empty or have only one object.\n");
        return;
    }
    for (int i = 0; i < amount; ++i) {//сортируем методом пузырьковой сортировки
        for (int j = 0; j < amount - i - 1; ++j) {
            Car *pCurrCarItem = (Car *) getItem(pList, j);
            Car *pNextCarItem = (Car *) getItem(pList, j + 1);
            MicroBus *pCurrMicroBus = (MicroBus *) pCurrCarItem;//MicroBus так как Bus наследуется от MicroBus
            MicroBus *pNextMicroBus = (MicroBus *) pNextCarItem;//MicroBus так как Bus наследуется от MicroBus
            if (pCurrMicroBus->placeCount > pNextMicroBus->placeCount)//если у текущего микроавтобуса мест больше
            {
                swipe(pList, j);//меняем их местами
            }
        }
    }
}

void swipe(list *pList, int i) {//меняем местами указатели элемента i и того который справа. Это надо для сортировки
    item *first = getItem(pList, i);
    item *second = first->pNext;
    item *temp_prev = first->pPrev;

    if (first == pList->pHead)
        pList->pHead = second;

    if (second == pList->pTail)
        pList->pTail = first;

    if (first->pPrev != NULL)
        first->pPrev->pNext = second;

    if (second->pNext != NULL)
        second->pNext->pPrev = first;

    first->pNext = second->pNext;
    first->pPrev = second;

    second->pNext = first;
    second->pPrev = temp_prev;
}

void search(list *pList) {//поиск по номеру, владельцу и цвету
    if (pList)
        if (pList->pHead) {
            int choice;
            printf("\nChoose search type: "); //Выберите тип поиска
            printf("\n1. State number");      //гос. номер
            printf("\n2. Owner");             //собственник
            printf("\n3. Color\n");           //цвет
            scanf("%d", &choice);
            char keyWord[30];
            int result = 0;
            switch (choice) {
                case 1: {
                    printf("\nEnter state number (max 9 symbols):");
                    scanf("%s", keyWord);
                    printf("\n");
                    for (item *pItem = pList->pHead; pItem != NULL; pItem = pItem->pNext) {
                        //если гос. номер совпадает с введенным, то выводим на экран
                        if (strcmp(((Car *) pItem)->number, keyWord) == 0) {
                            printItem((Car *) pItem);
                            result = 1;
                        }
                    }
                    break;
                }
                case 2: {
                    printf("\nEnter owner (max 29 symbols):");
                    scanf("%s", keyWord);
                    printf("\n");
                    for (item *pItem = pList->pHead; pItem != NULL; pItem = pItem->pNext) {
                        //если собственник совпадает с введенным, то выводим на экран
                        if (strcmp(((Car *) pItem)->owner, keyWord) == 0) {
                            printItem((Car *) pItem);
                            result = 1;
                        }
                    }
                    break;
                }
                case 3: {
                    printf("\nEnter color (max 19 symbols):");
                    scanf("%s", keyWord);
                    printf("\n");
                    for (item *pItem = pList->pHead; pItem != NULL; pItem = pItem->pNext) {
                        //если цвет совпадает с введенным, то выводим на экран
                        if (strcmp(((Car *) pItem)->color, keyWord) == 0) {
                            printItem((Car *) pItem);
                            result = 1;
                        }
                    }
                    break;
                }
                default:
                    break;
            }
            if (result == 0) {
                printf("No info found.\n");
            }
        } else
            printf("\nList is empty.\n");
    else
        printf("\nUndefined pList. Func: void numberSearch(list *pList, char *number)\n");
}


void fillListTest(list *pList) {//заполнение тестовыми данными
    Car *pCar = create(itPassengerCar);
    sscanf("AM749A", "%s", pCar->number);
    sscanf("Irina", "%s", pCar->owner);
    sscanf("KIA", "%s", pCar->brand);
    sscanf("RIO", "%s", pCar->model);
    sscanf("white", "%s", pCar->color);
    ((PassengerCar *) pCar)->engine = Gasoline;
    ((PassengerCar *) pCar)->body = Sedan;
    ((PassengerCar *) pCar)->drive = Front;
    addListItem(pList, (item *) pCar);
    printf("\nPassengerCar was added successfully!\n");

    pCar = create(itMicroBus);
    sscanf("QW720A", "%s", pCar->number);
    sscanf("Vitek", "%s", pCar->owner);
    sscanf("Mers", "%s", pCar->brand);
    sscanf("Benz", "%s", pCar->model);
    sscanf("blue", "%s", pCar->color);
    ((MicroBus *) pCar)->engine = Gasoline;
    (*(MicroBus *) pCar).placeCount = 10;
    addListItem(pList, (item *) pCar);
    printf("\nMicroBus was added successfully!\n");

    pCar = create(itBus);
    sscanf("fg620m", "%s", pCar->number);
    sscanf("Sasha", "%s", pCar->owner);
    sscanf("BMW", "%s", pCar->brand);
    sscanf("Bus", "%s", pCar->model);
    sscanf("red", "%s", pCar->color);
    ((Bus *) pCar)->engine = Gasoline;
    (*(Bus *) pCar).placeCount = 5;
    (*(Bus *) pCar).capacity = 3500;
    addListItem(pList, (item *) pCar);
    printf("\nBus was added successfully!\n");

    pCar = create(itTruck);
    sscanf("NM940S", "%s", pCar->number);
    sscanf("Petya", "%s", pCar->owner);
    sscanf("Ford", "%s", pCar->brand);
    sscanf("T", "%s", pCar->model);
    sscanf("black", "%s", pCar->color);
    ((Truck *) pCar)->engine = Diesel;
    (*(Truck *) pCar).capacity = 10500;
    addListItem(pList, (item *) pCar);
    printf("\nTruck was added successfully!\n");

    pCar = create(itBus);
    sscanf("QQ625D", "%s", pCar->number);
    sscanf("Misha", "%s", pCar->owner);
    sscanf("Wolkswagen", "%s", pCar->brand);
    sscanf("PoloBig", "%s", pCar->model);
    sscanf("grey", "%s", pCar->color);
    ((Bus *) pCar)->engine = Gasoline;
    (*(Bus *) pCar).placeCount = 6;
    (*(Bus *) pCar).capacity = 1200;
    addListItem(pList, (item *) pCar);
    printf("\nBus was added successfully!\n");
}



