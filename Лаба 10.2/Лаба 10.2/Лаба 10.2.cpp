#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

// Структура узла списка
struct Node {
    int data;
    struct Node* next;
};

struct Node* first = NULL;

// 1. Добавление в голову
void addToHead(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = first;
    first = newNode;
}

// 2. Печать списка
void printList() {
    struct Node* ptr = first;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// 3. Удаление из головы
int deleteFromHead() {
    if (first == NULL) {
        printf("Список пуст!\n");
        return -1;
    }
    struct Node* delNode = first;
    int value = delNode->data;
    first = first->next;
    free(delNode);
    return value;
}

// 4. Поиск по значению
int contains(int value) {
    struct Node* ptr = first;
    while (ptr != NULL) {
        if (ptr->data == value) return 1;
        ptr = ptr->next;
    }
    return 0;
}


}

// 6. Подсчёт суммы элементов
int sumList() {
    struct Node* ptr = first;
    int sum = 0;
    while (ptr != NULL) {
        sum += ptr->data;
        ptr = ptr->next;
    }
    return sum;
}

// 7. Подсчёт чётных элементов
int countEven() {
    struct Node* ptr = first;
    int count = 0;
    while (ptr != NULL) {
        if (ptr->data % 2 == 0) count++;
        ptr = ptr->next;
    }
    return count;
}

// 8. Увеличить все нечётные в 10 раз
void multiplyOddBy10() {
    struct Node* ptr = first;
    while (ptr != NULL) {
        if (ptr->data % 2 != 0) ptr->data *= 10;
        ptr = ptr->next;
    }
}

// 9. Увеличить i-ый элемент в 100 раз
void multiplyIthBy100(int i) {
    struct Node* ptr = first;
    int index = 0;
    while (ptr != NULL && index < i) {
        ptr = ptr->next;
        index++;
    }
    if (ptr != NULL) ptr->data *= 100;
    else printf("Элемента с индексом %d нет.\n", i);
}

// 10. Увеличить все элементы левее i-го в 10 раз
void multiplyLeftBy10(int i) {
    struct Node* ptr = first;
    int index = 0;
    while (ptr != NULL && index < i) {
        ptr->data *= 10;
        ptr = ptr->next;
        index++;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("=== Лабораторная работа 10.2 ===\n\n");

    // Демонстрация основных операций
    printf("Добавляем элементы 10, 20, 30 в голову:\n");
    addToHead(10);
    addToHead(20);
    addToHead(30);
    printList();

    printf("\nСумма элементов: %d\n", sumList());
    printf("Количество чётных элементов: %d\n", countEven());

    printf("\nУвеличиваем нечётные в 10 раз:\n");
    multiplyOddBy10();
    printList();

    printf("\nУвеличиваем 1-й элемент в 100 раз:\n");
    multiplyIthBy100(1);
    printList();

    printf("\nУвеличиваем элементы левее 2-го в 10 раз:\n");
    multiplyLeftBy10(2);
    printList();

    printf("\nПроверка наличия значения 200: %s\n", contains(200) ? "Да" : "Нет");
    printf("Проверка наличия значения 100: %s\n", contains(100) ? "Да" : "Нет");

    printf("\nУдаляем из головы: %d\n", deleteFromHead());
    printList();

    printf("\nОчищаем список.\n");
    clearList();
    printList();

    printf("Hello World")
    
    return 0;
}