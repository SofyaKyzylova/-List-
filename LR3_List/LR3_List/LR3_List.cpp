// LR3_List.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include "Header.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Node* head = NULL;

    cout << " Добавление элементов в начало списка: " << endl;
    head = addHead(head, 2);
    head = addHead(head, 10);
    head = addHead(head, -3);
    outList(head);
     
    cout << " Добавление элементов в конец списка: " << endl;
    addTail(head, 1);
    addTail(head, 4);
    addTail(head, -6);
    outList(head);
    
    int pos;
    cout << endl << " Введите номер позиции для вставки элемента со значением '5' : ";
    cin >> pos;
    insert(head, pos, 5);
    outList(head);
    
    cout << " Удаление начала списка" << endl;
    head = removeHead(head);
    outList(head);
    
    cout << " Удаление конца списка" << endl;
    removeTail(head);
    outList(head);
    cout << endl;
    
    cout << " Удаление 3 позиции списка: " << endl;
    remove(head, 3);
    outList(head);
   
    findData(head, 10);
    cout << endl;
    findPos(head, 3);
    cout << " Значение узла 2 равно: ";
    retrieve(head, 2);
    cout << endl;

    //Задание 2. Вариант С
    cout << " Отсортированный список 1: " << endl;
    head = InsertionSort(head);
    outList(head);

    Node* head_ = NULL;

    head_ = addHead_(head_, 3);
    head_ = addHead_(head_, 7);
    head_ = addHead_(head_, -1);
    head_ = addHead_(head_, 2);
    head_ = addHead_(head_, 5);
    cout << " Список 2:" << endl;
    outList_(head_);

    cout << " Отсортированный список 2: " << endl;
    head_ = InsertionSort_(head_);
    outList_(head_);

    cout << " Объединение двух упорядоченных списков в один упорядоченный список: " << endl;
    merge(head, head_);
    head = InsertionSort(head);
    outList(head);

    removeAll(head);

    if (isEmpty(head))
        cout << " Список пуст " << isEmpty(head) << endl;
    else
        cout << " Список не пуст " << isEmpty(head) << endl;
}
