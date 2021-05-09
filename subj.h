#ifndef INC_3_SUBJ_H
#define INC_3_SUBJ_H

#include "list.h"

typedef enum {
    Gasoline,
    Diesel
} Engine;

typedef enum {
    Sedan,
    Coup,
    Universal
} CarBody;

typedef enum {
    Front,
    Back,
    Full
} Drive;

typedef enum {//перечисление, значения которого соответствуют типам объектов
    itPassengerCar,
    itMicroBus,
    itBus,
    itTruck,
    itSpecial
} CarType;

/*
   стуктура (элемент списка) базового уровня, содержащая
   поля, "унаследованные" от структуры Item, и поля, общие
   для объектов всех типов (структур-"потомков");
 */
typedef struct {
    struct Item *pPrev;// наследование от Item
    struct Item *pNext;

    CarType type;

    char number[10];
    char owner[30];
    char brand[20];
    char model[20];
    char color[20];
} Car;

typedef struct {
    struct Item *pPrev;// наследование от Item
    struct Item *pNext;

    CarType type;

    char number[10];// наследование от Car
    char owner[30];
    char brand[20];
    char model[20];
    char color[20];

    Engine engine;
    CarBody body;
    Drive drive;
} PassengerCar;

typedef struct {
    struct Item *pPrev;// наследование от Item
    struct Item *pNext;

    CarType type;

    char number[10];// наследование от Car
    char owner[30];
    char brand[20];
    char model[20];
    char color[20];

    Engine engine;
    int placeCount;
} MicroBus;

typedef struct {
    struct Item *pPrev;// наследование от Item
    struct Item *pNext;

    CarType type;

    char number[10];// наследование от Car
    char owner[30];
    char brand[20];
    char model[20];
    char color[20];

    Engine engine;
    int placeCount;
    int capacity;
} Bus;

typedef struct {
    struct Item *pPrev;// наследование от Item
    struct Item *pNext;

    CarType type;

    char number[10];// наследование от Car
    char owner[30];
    char brand[20];
    char model[20];
    char color[20];

    Engine engine;
    int capacity;
} Truck;

typedef struct {
    struct Item *pPrev;// наследование от Item
    struct Item *pNext;

    CarType type;

    char number[10];// наследование от Car
    char owner[30];
    char brand[20];
    char model[20];
    char color[20];

    char description[100];
} Special;

/*
 * прототип функции, например Create, выполняющей создание
   объекта требуемого типа (тип задается соответствующим
   значением перечисления в качестве параметра, функция
   возвращает указатель базового типа на созданный объект).
 */
Car *createNewCar();

Car *create(CarType type);

void inputItem(Car *pCreatedCar);

void inputCar(Car *pCar);

void inputPassengerCar(PassengerCar *pCar);

void inputMicroBus(MicroBus *pCar);

void inputBus(Bus *pCar);

void inputTruck(Truck *pCar);

void inputSpecial(Special *pCar);

void printItem(Car *pCar);

void printCar(Car *pCar);

void printPassengerCar(PassengerCar *pCar);

void printMicroBus(MicroBus *pCar);

void printBus(Bus *pCar);

void printTruck(Truck *pCar);

void printSpecial(Special *pCar);

void printNewList(list *pList);

void placeSort(list *pList);//сортировка автомобилей по количеству мест

void swipe(list *pList, int i);//меняем местами указатели элемента i и того который справа. Это надо для сортировки

//поиск по номеру, владельцу и цвету
void search(list *pList);

void fillListTest(list *pList);//заполнение тестовыми данными

#endif //INC_3_SUBJ_H
