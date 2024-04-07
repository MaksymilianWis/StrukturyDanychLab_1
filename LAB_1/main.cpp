#include "SDHTLinkedList.hpp"
#include "SHLinkedList.hpp"
#include "SHTLinkedList.hpp"
#include "LinkedList.hpp"

#include <iostream>
#include <time.h>
#include "random"

#include "dynamicArray.h"
#include "test.h"
#include "cstdlib"
#include <ctime>
#include "Zapis.h"
#include <chrono>

using namespace std;

void runDynamicArray() {
}

void testingDynamicArray(const unsigned numOfArrays, int size, int iteration) {
    Zapis plik_addFront("ArrayList_addFront.csv");
    Zapis plik_addBack("ArrayList_addBack.csv");
    Zapis plik_add("ArrayList_add.csv");
    Zapis plik_removeFront("ArrayList_removeFront.csv");
    Zapis plik_removeBack("ArrayList_removeBack.csv");
    Zapis plik_remove("ArrayList_remove.csv");
    Zapis plik_find("ArrayList_find.csv");

    dynamicArray dynamicArray2(4);
    dynamicArray2.fillFromArrayCSV("random_numbersi.csv", 50000);

    cout << "Please wait..." << endl;
    dynamicArray** arrays = new dynamicArray * [numOfArrays];
    dynamicArray** backupArrays = new dynamicArray * [numOfArrays];

    // Tworzymy numOfArrays tablic o pojemnoœci 4
    for (int i = 0; i < numOfArrays; ++i) {
        arrays[i] = new dynamicArray(4);
        backupArrays[i] = new dynamicArray(4);
    }
    for (int i = 0; i < numOfArrays; i++) {
        arrays[i]->fillFromArrayCSV("random_numbers.csv", size);
        backupArrays[i]->fillFromArrayCSV("random_numbers.csv", size);
    }

    //cout << arrays[1]->getDynamicArraySize() << endl;

    //addFront
    auto begin = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->addFront(5);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //double durationInNanoSeconds = double(duration) / CLOCKS_PER_SEC;
    plik_addFront.shot(iteration, elapsed.count(), size);
    //addBack
    auto begin2 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->addBack(5);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    plik_addBack.shot(iteration, elapsed2.count(), size);

    //add
    int index = dynamicArray2.getDynamicArrayElementAt(0);
    auto begin3 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->add(index, 5);
    }
    auto end3 = std::chrono::high_resolution_clock::now();
    auto elapsed3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - begin3);
    plik_add.shot(iteration, elapsed3.count(), size);

    //removeFront
    auto begin4 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->removeFront();
    }
    auto end4 = std::chrono::high_resolution_clock::now();
    auto elapsed4 = std::chrono::duration_cast<std::chrono::nanoseconds>(end4 - begin4);
    plik_removeFront.shot(iteration, elapsed4.count(), size);

    //removeBack
    auto begin5 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->removeBack();
    }
    auto end5 = std::chrono::high_resolution_clock::now();
    auto elapsed5 = std::chrono::duration_cast<std::chrono::nanoseconds>(end5 - begin5);
    plik_removeBack.shot(iteration, elapsed5.count(), size);

    //remove
    index = dynamicArray2.getDynamicArrayElementAt(0);
    auto begin6 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->remove(index);
    }
    auto end6 = std::chrono::high_resolution_clock::now();
    auto elapsed6 = std::chrono::duration_cast<std::chrono::nanoseconds>(end6 - begin6);
    plik_remove.shot(iteration, elapsed6.count(), size);

    //find
    auto begin7 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        int number = dynamicArray2.getDynamicArrayElementAt(i);
        arrays[i]->findElement(number);
    }
    auto end7 = std::chrono::high_resolution_clock::now();
    auto elapsed7 = std::chrono::duration_cast<std::chrono::nanoseconds>(end7 - begin7);
    plik_find.shot(iteration, elapsed7.count(), size);


    for (int i = 0; i < numOfArrays; ++i) {
        delete arrays[i];
        delete backupArrays[i];
    }
}
void runTestsDynamicArray(const unsigned numOfArrays) {

    test::generateRandomNumbers(80000, 0, 100000, "random_numbers.csv", 5);
    test::generateRandomNumbers(80000, 0, 60000, "random_numbersi.csv", 3);

    char choice3;
    do {
        cout << "1. array_10" << endl;
        cout << "2. array_100" << endl;
        cout << "3. array_1k" << endl;
        cout << "4. array_2k" << endl;
        cout << "5. array_4k" << endl;
        cout << "6. array_8k" << endl;
        cout << "7. array_16k" << endl;
        cout << "8. array_32k" << endl;
        cout << "9. array_64k" << endl;
        cout << "X. array_128k" << endl;
        cout << "A. Test all" << endl;
        cout << "0. Exit" << endl;



        cin >> choice3;
        switch (choice3) {
        case '0':
            cout << "Exiting..." << endl;
            break;
        case '1':
        {
            testingDynamicArray(numOfArrays, 10, 1);
            break;
        }
        case '2':
        {
            testingDynamicArray(numOfArrays, 100, 2);
            break;
        }
        case '3':
        {
            testingDynamicArray(numOfArrays, 1000, 3);
            break;
        }
        case '4':
        {
            testingDynamicArray(numOfArrays, 2000, 4);
            break;
        }
        case '5':
        {
            testingDynamicArray(numOfArrays, 4000, 5);
            break;
        }
        case '6':
        {
            testingDynamicArray(numOfArrays, 8000, 6);
            break;
        }
        case '7':
        {
            testingDynamicArray(numOfArrays, 16000, 7);
            break;
        }
        case '8':
        {
            testingDynamicArray(numOfArrays, 32000, 8);
            break;
        }
        case '9':
        {
            testingDynamicArray(numOfArrays, 64000, 9);
            break;
        }
        case 'X':
        {
            testingDynamicArray(numOfArrays, 128000, 10);
            break;
        }
        case 'A':
        {
            testingDynamicArray(numOfArrays, 10, 1);
            testingDynamicArray(numOfArrays, 100, 2);
            testingDynamicArray(numOfArrays, 1000, 3);
            testingDynamicArray(numOfArrays, 2000, 4);
            testingDynamicArray(numOfArrays, 4000, 5);
            testingDynamicArray(numOfArrays, 8000, 6);
            testingDynamicArray(numOfArrays, 16000, 7);
            testingDynamicArray(numOfArrays, 32000, 8);
            testingDynamicArray(numOfArrays, 64000, 9);
            testingDynamicArray(numOfArrays, 128000, 10);
            break;
        }

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice3 != '0');
}


int main() {
    char choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Your dynamicArray" << endl;
        cout << "2. Tests" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
        case '1':
            runDynamicArray();
            break;
        case '2':
            cout << "Running tests..." << endl;
            cout << "Please choose the number of arrays, " << endl;
            int numOfArrays;
            cin >> numOfArrays;
            cout << "Please wait..." << endl;
            runTestsDynamicArray(numOfArrays);
            break;
        case '3':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != '3');

    return 0;
}