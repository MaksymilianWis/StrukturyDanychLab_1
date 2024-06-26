#ifndef TABLICA_DYNAMICZNA_DYNAMICARRAY_H
#define TABLICA_DYNAMICZNA_DYNAMICARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <fstream>
#include <sstream>

using namespace std;

class dynamicArray {
private:
    int dynamicArrayCapacity = 0; //zmienna rozmiaru tablicy
    int dynamicArraySize = 0; //ilość elementów w tablicy
    int* dynamicArrayPtr = NULL; //wskaźnik na tablice

    void increaseCapacity();
    void decreaseCapacity();
public:
    dynamicArray(); //konstruktor
    dynamicArray(int capacity); //konstruktor z argumentem
    ~dynamicArray(); //destruktor

    int getDynamicArraySize() const;
    bool isDynamicArrayEmpty();
    int getDynamicArrayElementAt(int index);
    int findElement(int element);

    void displayDynamicArray();
    void displayDynamicArrayWCapacity();
    void add(int index, int element);
    void addBack(int element);
    void addFront(int item);
    void remove(int index);
    void removeBack();
    void removeFront();

    void fillFromArrayCSV(const string& filename, int maxElements);
};


#endif //TABLICA_DYNAMICZNA_DYNAMICARRAY_H