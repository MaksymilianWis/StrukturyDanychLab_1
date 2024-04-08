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
    dynamicArray dynamicArray1(4);
    int element, index;
    char choice2;
    do {
        cout << "1. addFront" << endl;
        cout << "2. addBack" << endl;
        cout << "3. add" << endl;
        cout << "4. removeFront" << endl;
        cout << "5. removeBack" << endl;
        cout << "6. remove" << endl;
        cout << "7. display" << endl;
        cout << "8. display with capacity" << endl;
        cout << "9. isDynamicArrayEmpty" << endl;
        cout << "10. getDynamicArrayElementAt" << endl;
        cout << "11. getDynamicArraySize" << endl;
        cout << "12. fillFromArrayCSV" << endl;
        cout << "13. Exit" << endl;

        cin >> choice2;
        switch (choice2) {
        case '1':
            cout << "Enter the element you want to add: ";
            cin >> element;
            dynamicArray1.addFront(element);
            break;
        case '2':
            cout << "Enter the element you want to add (back): ";
            cin >> element;
            dynamicArray1.addBack(element);
            break;
        case '3':
            cout << "Enter the index and the element you want to add: ";
            cin >> index >> element;
            dynamicArray1.add(index, element);
            break;
        case '4':
            cout << "Removing the first element..." << endl;
            dynamicArray1.removeFront();
            break;
        case '5':
            cout << "Removing the last element..." << endl;
            dynamicArray1.removeBack();
            break;
        case '6':
            cout << "Enter the index you want to remove: ";
            cin >> index;
            dynamicArray1.remove(index);
            break;
        case '7':
            dynamicArray1.displayDynamicArray();
            break;
        case '8':
            dynamicArray1.displayDynamicArrayWCapacity();
            break;
        case '9':
            if (dynamicArray1.isDynamicArrayEmpty()) {
                cout << "The dynamicArray is empty." << endl;
            }
            else {
                cout << "The dynamicArray is not empty." << endl;
            }
            break;
        case '10':
            cout << "Enter the index of the element you want to get: ";
            cin >> index;
            cout << "The element at index " << index << " is: " << dynamicArray1.getDynamicArrayElementAt(index)
                << endl;
            break;
        case '11':
            cout << "The size of the dynamicArray is: " << dynamicArray1.getDynamicArraySize() << endl;
            break;
        case '12':
            cout << "Filling the dynamicArray from a CSV file: random_numbers.csv ..." << endl;
            dynamicArray1.fillFromArrayCSV("random_numbers.csv", 50000);
            break;
        case '13':
            cout << "Exiting..." << endl;
            break;

        }
    } while (choice2 != '13');
}
void runLinkedList(string type_of_list) {
    LinkedList* list;
    if (type_of_list == "H") list = new SHLinkedList;
    else if (type_of_list == "HT")list = new SHTLinkedList;
    else if (type_of_list == "DHT")list = new SDHTLinkedList;
    else list = new SDHTLinkedList;

    int element, index;
    char choice2;
    do {
        cout << "a. addfront" << endl;
        cout << "b. addback" << endl;
        cout << "c. addat" << endl;
        cout << "d. delfront" << endl;
        cout << "e. delback" << endl;
        cout << "f. delat" << endl;
        cout << "g. display" << endl;
        cout << "h. isLinkedListEmpty" << endl;
        cout << "i. search for" << endl;
        cout << "j. getLinkedListSize" << endl;
        cout << "k. Exit" << endl;

        cin >> choice2;
        switch (choice2) {
        case 'a':
            cout << "Enter the element you want to add: ";
            cin >> element;
            list->addfront(element);
            break;
        case 'b':
            cout << "Enter the element you want to add (back): ";
            cin >> element;
            list->addback(element);
            break;
        case 'c':
            cout << "Enter the index and the element you want to add: ";
            cin >> index >> element;
            list->addat(index, element);
            break;
        case 'd':
            cout << "Removing the first element..." << endl;
            list->delfront();
            break;
        case 'e':
            cout << "Removing the last element..." << endl;
            list->delback();
            break;
        case 'f':
            cout << "Enter the index you want to remove: ";
            cin >> index;
            list->delat(index);
            break;
        case 'g':
            list->printAll();
            break;
        case 'h':
            if (list->isempty()) {
                cout << "The LinkedList is empty." << endl;
            }
            else {
                cout << "The LinkedList is not empty." << endl;
            }
            break;
        case 'i':
            cout << "Enter the element you want to get: ";
            cin >> element;
            cout << "The element " << element << " is: " << list->search(element)
                << endl;
            break;
        case 'j':
            cout << "The size of the dynamicArray is: " << list->getsize() << "\n";
            break;
        case 'k':
            cout << "Exiting..." << endl;
            break;

        }
    } while (choice2 != 'k');
}

// testy
void testingDynamicArray(const unsigned numOfArrays, int size, int iteration, bool overwrite) {
    Zapis plik_addFront("ArrayList_addFront.csv", overwrite);
    Zapis plik_addBack("ArrayList_addBack.csv", overwrite);
    Zapis plik_add("ArrayList_add.csv", overwrite);
    Zapis plik_removeFront("ArrayList_removeFront.csv", overwrite);
    Zapis plik_removeBack("ArrayList_removeBack.csv", overwrite);
    Zapis plik_remove("ArrayList_remove.csv", overwrite);
    Zapis plik_find("ArrayList_find.csv", overwrite);

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

    // wracanie do oryginalnego rozmiaru
    arrays = backupArrays;

    //addBack
    auto begin2 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->addBack(5);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    plik_addBack.shot(iteration, elapsed2.count(), size);

    // wracanie do oryginalnego rozmiaru
    arrays = backupArrays;

    //add
    int index = dynamicArray2.getDynamicArrayElementAt(0);
    auto begin3 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->add(index, 5);
    }
    auto end3 = std::chrono::high_resolution_clock::now();
    auto elapsed3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - begin3);
    plik_add.shot(iteration, elapsed3.count(), size);

    // wracanie do oryginalnego rozmiaru
    arrays = backupArrays;

    //removeFront
    auto begin4 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->removeFront();
    }
    auto end4 = std::chrono::high_resolution_clock::now();
    auto elapsed4 = std::chrono::duration_cast<std::chrono::nanoseconds>(end4 - begin4);
    plik_removeFront.shot(iteration, elapsed4.count(), size);

    // wracanie do oryginalnego rozmiaru
    arrays = backupArrays;

    //removeBack
    auto begin5 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->removeBack();
    }
    auto end5 = std::chrono::high_resolution_clock::now();
    auto elapsed5 = std::chrono::duration_cast<std::chrono::nanoseconds>(end5 - begin5);
    plik_removeBack.shot(iteration, elapsed5.count(), size);

    // wracanie do oryginalnego rozmiaru
    arrays = backupArrays;

    //remove
    index = dynamicArray2.getDynamicArrayElementAt(0);
    auto begin6 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->remove(index);
    }
    auto end6 = std::chrono::high_resolution_clock::now();
    auto elapsed6 = std::chrono::duration_cast<std::chrono::nanoseconds>(end6 - begin6);
    plik_remove.shot(iteration, elapsed6.count(), size);

    // wracanie do oryginalnego rozmiaru
    arrays = backupArrays;

    //find
    auto begin7 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        int number = dynamicArray2.getDynamicArrayElementAt(i);
        arrays[i]->findElement(number);
    }
    auto end7 = std::chrono::high_resolution_clock::now();
    auto elapsed7 = std::chrono::duration_cast<std::chrono::nanoseconds>(end7 - begin7);
    plik_find.shot(iteration, elapsed7.count(), size);
}

void testingLinkedList(const unsigned numOfLists, int size, int iteration,bool overwrite, string type_of_list) {
    // deklaracja odpowiedniej listy
    LinkedList** list = new LinkedList * [numOfLists];
    LinkedList** backuplist = new LinkedList * [numOfLists];
    // wybor typu listy
    if (type_of_list == "H") {
        //list = new SHLinkedList[numOfLists];
        //backuplist = new SHLinkedList[numOfLists];
        for (unsigned i = 0; i < numOfLists; ++i) {
            list[i] = new SHLinkedList;
            backuplist[i] = new SHLinkedList;
        }
    }
    else if (type_of_list == "HT") {
        //list = new SHTLinkedList[numOfLists];
        //backuplist = new SHTLinkedList[numOfLists];
        for (unsigned i = 0; i < numOfLists; ++i) {
            list[i] = new SHTLinkedList;
            backuplist[i] = new SHTLinkedList;
        }
    }
    else if (type_of_list == "DHT") {
        //list = new SDHTLinkedList[numOfLists];
        //backuplist = new SDHTLinkedList[numOfLists];
        for (unsigned i = 0; i < numOfLists; ++i) {
            list[i] = new SDHTLinkedList;
            backuplist[i] = new SDHTLinkedList;
        }
    }
    else {
        //list = new SDHTLinkedList[numOfLists];
        //backuplist = new SDHTLinkedList[numOfLists];
        for (unsigned i = 0; i < numOfLists; ++i) {
            list[i] = new SDHTLinkedList;
            backuplist[i] = new SDHTLinkedList;
        }
    }

    // deklaracja zmiennych czsu oraz potencjalnych plikow do zapisu testow
    clock_t start, duration;
    Zapis plik_addFront(type_of_list + "LinkedList_addFront.csv", overwrite);
    Zapis plik_addBack(type_of_list + "LinkedList_addBack.csv", overwrite);
    Zapis plik_add(type_of_list + "LinkedList_addat.csv", overwrite);
    Zapis plik_removeFront(type_of_list + "LinkedList_delFront.csv", overwrite);
    Zapis plik_removeBack(type_of_list + "LinkedList_dellBack.csv", overwrite);
    Zapis plik_remove(type_of_list + "LinkedList_dellat.csv", overwrite);
    Zapis plik_find(type_of_list + "LinkedList_search.csv", overwrite);

    dynamicArray dynamicArray2(4);
    dynamicArray2.fillFromArrayCSV("random_numbersi.csv", 50000);

    cout << "Please wait..." << endl;

    for (int i = 0; i < numOfLists; i++) {
        list[i]->fillFromListCSV("random_numbers.csv", size);
        backuplist[i]->fillFromListCSV("random_numbers.csv", size);
    }

    //addFront
    auto begin = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfLists; i++) {
        list[i]->addfront(5);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //double durationInNanoSeconds = double(duration) / CLOCKS_PER_SEC;
    plik_addFront.shot(iteration, elapsed.count(), size);

    // wracanie do oryginalnego rozmiaru
    list = backuplist;

    //addBack
    auto begin2 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfLists; i++) {
        list[i]->addback(5);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    plik_addBack.shot(iteration, elapsed2.count(), size);

    // wracanie do oryginalnego rozmiaru
    list = backuplist;

    //add
    int index = dynamicArray2.getDynamicArrayElementAt(0);
    auto begin3 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfLists; i++) {
        list[i]->addat(index, 5);
    }
    auto end3 = std::chrono::high_resolution_clock::now();
    auto elapsed3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - begin3);
    plik_add.shot(iteration, elapsed3.count(), size);

    // wracanie do oryginalnego rozmiaru
    list = backuplist;

    //removeFront
    auto begin4 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfLists; i++) {
        list[i]->delfront();
    }
    auto end4 = std::chrono::high_resolution_clock::now();
    auto elapsed4 = std::chrono::duration_cast<std::chrono::nanoseconds>(end4 - begin4);
    plik_removeFront.shot(iteration, elapsed4.count(), size);

    // wracanie do oryginalnego rozmiaru
    list = backuplist;

    //removeBack
    auto begin5 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfLists; i++) {
        list[i]->delback();
    }
    auto end5 = std::chrono::high_resolution_clock::now();
    auto elapsed5 = std::chrono::duration_cast<std::chrono::nanoseconds>(end5 - begin5);
    plik_removeBack.shot(iteration, elapsed5.count(), size);

    // wracanie do oryginalnego rozmiaru
    list = backuplist;

    //remove
    index = dynamicArray2.getDynamicArrayElementAt(0);
    auto begin6 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfLists; i++) {
        list[i]->delat(index);
    }
    auto end6 = std::chrono::high_resolution_clock::now();
    auto elapsed6 = std::chrono::duration_cast<std::chrono::nanoseconds>(end6 - begin6);
    plik_remove.shot(iteration, elapsed6.count(), size);

    // wracanie do oryginalnego rozmiaru
    list = backuplist;

    //find
    auto begin7 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfLists; i++) {
        int number = dynamicArray2.getDynamicArrayElementAt(i);
        list[i]->search(number);
    }
    auto end7 = std::chrono::high_resolution_clock::now();
    auto elapsed7 = std::chrono::duration_cast<std::chrono::nanoseconds>(end7 - begin7);
    plik_find.shot(iteration, elapsed7.count(), size);
}
// podmenu
void runTestsDynamicArray(const unsigned numOfArrays) {

    test::generateRandomNumbers(80000, 0, 100000, "random_numbers.csv", 5);
    test::generateRandomNumbers(80000, 0, 60000, "random_numbersi.csv", 3);

    char choice3;
    do {
        cout << "1. array_2k" << endl;
        cout << "2. array_4k" << endl;
        cout << "3. array_6k" << endl;
        cout << "4. array_8k" << endl;
        cout << "5. array_10k" << endl;
        cout << "6. array_12k" << endl;
        cout << "7. array_14k" << endl;
        cout << "8. array_16k" << endl;
        cout << "9. array_18k" << endl;
        cout << "X. array_20k" << endl;
        cout << "A. Test all" << endl;
        cout << "0. Exit" << endl;



        cin >> choice3;
        switch (choice3) {
        case '0':
            cout << "Exiting..." << endl;
            break;
        case '1':
        {
            testingDynamicArray(numOfArrays, 2000, 1, 1);
            break;
        }
        case '2':
        {
            testingDynamicArray(numOfArrays, 4000, 2, 1);
            break;
        }
        case '3':
        {
            testingDynamicArray(numOfArrays, 6000, 3, 1);
            break;
        }
        case '4':
        {
            testingDynamicArray(numOfArrays, 8000, 4, 1);
            break;
        }
        case '5':
        {
            testingDynamicArray(numOfArrays, 10000, 5, 1);
            break;
        }
        case '6':
        {
            testingDynamicArray(numOfArrays, 12000, 6, 1);
            break;
        }
        case '7':
        {
            testingDynamicArray(numOfArrays, 14000, 7, 1);
            break;
        }
        case '8':
        {
            testingDynamicArray(numOfArrays, 16000, 8, 1);
            break;
        }
        case '9':
        {
            testingDynamicArray(numOfArrays, 18000, 9, 1);
            break;
        }
        case 'X':
        {
            testingDynamicArray(numOfArrays, 20000, 10, 1);
            break;
        }
        case 'A':
        {
            testingDynamicArray(numOfArrays, 2000, 1, 0);
            testingDynamicArray(numOfArrays, 4000, 2, 0);
            testingDynamicArray(numOfArrays, 6000, 3, 0);
            testingDynamicArray(numOfArrays, 8000, 4, 0);
            testingDynamicArray(numOfArrays, 10000, 5, 0);
            testingDynamicArray(numOfArrays, 12000, 6, 0);
            testingDynamicArray(numOfArrays, 14000, 7, 0);
            testingDynamicArray(numOfArrays, 16000, 8, 0);
            testingDynamicArray(numOfArrays, 18000, 9, 0);
            testingDynamicArray(numOfArrays, 20000, 10, 0);
            break;
        }

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice3 != '0');
}
void runTestsLinkedList(const unsigned numOfLists, string type_of_list) {

    test::generateRandomNumbers(80000, 0, 100000, "random_numbers.csv", 5);
    test::generateRandomNumbers(80000, 0, 60000, "random_numbersi.csv", 3);

    char choice3;
    do {
        cout << "1. list_2k" << endl;
        cout << "2. list_4k" << endl;
        cout << "3. list_6k" << endl;
        cout << "4. list_8k" << endl;
        cout << "5. list_10k" << endl;
        cout << "6. list_12k" << endl;
        cout << "7. list_14k" << endl;
        cout << "8. list_16k" << endl;
        cout << "9. list_18k" << endl;
        cout << "X. list_20k" << endl;
        cout << "A. Test all" << endl;
        cout << "0. Exit" << endl;



        cin >> choice3;
        switch (choice3) {
        case '0':
            cout << "Exiting..." << endl;
            break;
        case '1':
        {
            testingLinkedList(numOfLists, 2000, 1, 1, type_of_list);
            break;
        }
        case '2':
        {
            testingLinkedList(numOfLists, 4000, 2, 1, type_of_list);
            break;
        }
        case '3':
        {
            testingLinkedList(numOfLists, 6000, 3, 1, type_of_list);
            break;
        }
        case '4':
        {
            testingLinkedList(numOfLists, 8000, 4, 1, type_of_list);
            break;
        }
        case '5':
        {
            testingLinkedList(numOfLists, 10000, 5, 1, type_of_list);
            break;
        }
        case '6':
        {
            testingLinkedList(numOfLists, 12000, 6, 1, type_of_list);
            break;
        }
        case '7':
        {
            testingLinkedList(numOfLists, 14000, 7, 1, type_of_list);
            break;
        }
        case '8':
        {
            testingLinkedList(numOfLists, 16000, 8, 1, type_of_list);
            break;
        }
        case '9':
        {
            testingLinkedList(numOfLists, 18000, 9, 1, type_of_list);
            break;
        }
        case 'X':
        {
            testingLinkedList(numOfLists, 20000, 10, 1, type_of_list);
            break;
        }
        case 'A':
        {
            testingLinkedList(numOfLists, 2000, 1, 0, type_of_list);
            testingLinkedList(numOfLists, 4000, 2, 0, type_of_list);
            testingLinkedList(numOfLists, 6000, 3, 0, type_of_list);
            testingLinkedList(numOfLists, 8000, 4, 0, type_of_list);
            testingLinkedList(numOfLists, 10000, 5, 0, type_of_list);
            testingLinkedList(numOfLists, 12000, 6, 0, type_of_list);
            testingLinkedList(numOfLists, 14000, 7, 0, type_of_list);
            testingLinkedList(numOfLists, 16000, 8, 0, type_of_list);
            testingLinkedList(numOfLists, 18000, 9, 0, type_of_list);
            testingLinkedList(numOfLists, 20000, 10, 0, type_of_list);
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
        cout << "2. Your linkedList" << endl;
        cout << "3. Tests of dynamicArray" << endl;
        cout << "4. Tests of linkedList" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
        case '1':
            runDynamicArray();
            break;
        case '2':
            char sub_choice;
            do {
                cout << "Please choose type of an list:\n";
                cout << "1.Head\n";
                cout << "2.Head and Tail\n";
                cout << "3.Two way Head, Tail\n";
                cout << "0.Exit" << endl;
                cin >> sub_choice;
                switch (sub_choice) {
                case '1':
                    runLinkedList("H");
                    break;
                case '2':
                    runLinkedList("HT");
                    break;
                case '3':
                    runLinkedList("DHT");
                    break;
                case '0':
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            } while (sub_choice != '0');
            break;
        case '3':
            cout << "Running tests..." << endl;
            cout << "Please choose the number of arrays, " << endl;
            int numOfArrays;
            cin >> numOfArrays;
            cout << "Please wait..." << endl;
            runTestsDynamicArray(numOfArrays);
            break;
        case '4':
            cout << "Running tests..." << endl;
            cout << "Please choose the number of lists, " << endl;
            int numOfLists;
            cin >> numOfLists;
            char sub_choice2;
            do {
                cout << "Please choose type of an list:\n";
                cout << "1.Head\n";
                cout << "2.Head and Tail\n";
                cout << "3.Two way Head, Tail\n";
                cout << "0.Exit" << endl;
                cin >> sub_choice2;
                cout << "Please wait..." << endl;
                switch (sub_choice2) {
                case '1':
                    runTestsLinkedList(numOfLists, "H");
                    break;
                case '2':
                    runTestsLinkedList(numOfLists, "HT");
                    break;
                case '3':
                    runTestsLinkedList(numOfLists, "DHT");
                    break;
                case '0':
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            } while (sub_choice2 != '0');
            break;
        case '0':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != '0');

    return 0;
}