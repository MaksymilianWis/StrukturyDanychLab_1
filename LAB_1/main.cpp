#include "ArrayList.hpp"
#include "SDHTLinkedList.hpp"
#include "SHLinkedList.hpp"
#include "SHTLinkedList.hpp"
#include "Zapis.hpp"
#include "random"
#include "LinkedList.hpp"

#include <iostream>
#include <time.h>

#include "dynamicArray.h"
#include "test.h"
#include "cstdlib"
#include <ctime>

using namespace std;

void runDynamicArray() {
    dynamicArray dynamicArray1(4);
    int element, index;
    char choice2;
    do {
        cout << "a. addFront" << endl;
        cout << "b. addBack" << endl;
        cout << "c. add" << endl;
        cout << "d. removeFront" << endl;
        cout << "e. removeBack" << endl;
        cout << "f. remove" << endl;
        cout << "g. display" << endl;
        cout << "h. display with capacity" << endl;
        cout << "i. isDynamicArrayEmpty" << endl;
        cout << "j. getDynamicArrayElementAt" << endl;
        cout << "k. getDynamicArraySize" << endl;
        cout << "l. fillFromArrayCSV" << endl;
        cout << "m. Exit" << endl;

        cin >> choice2;
        switch (choice2) {
        case 'a':
            cout << "Enter the element you want to add: ";
            cin >> element;
            dynamicArray1.addFront(element);
            break;
        case 'b':
            cout << "Enter the element you want to add (back): ";
            cin >> element;
            dynamicArray1.addBack(element);
            break;
        case 'c':
            cout << "Enter the index and the element you want to add: ";
            cin >> index >> element;
            dynamicArray1.add(index, element);
            break;
        case 'd':
            cout << "Removing the first element..." << endl;
            dynamicArray1.removeFront();
            break;
        case 'e':
            cout << "Removing the last element..." << endl;
            dynamicArray1.removeBack();
            break;
        case 'f':
            cout << "Enter the index you want to remove: ";
            cin >> index;
            dynamicArray1.remove(index);
            break;
        case 'g':
            dynamicArray1.displayDynamicArray();
            break;
        case 'h':
            dynamicArray1.displayDynamicArrayWCapacity();
            break;
        case 'i':
            if (dynamicArray1.isDynamicArrayEmpty()) {
                cout << "The dynamicArray is empty." << endl;
            }
            else {
                cout << "The dynamicArray is not empty." << endl;
            }
            break;
        case 'j':
            cout << "Enter the index of the element you want to get: ";
            cin >> index;
            cout << "The element at index " << index << " is: " << dynamicArray1.getDynamicArrayElementAt(index)
                << endl;
            break;
        case 'k':
            cout << "The size of the dynamicArray is: " << dynamicArray1.getDynamicArraySize() << endl;
            break;
        case 'l':
            cout << "Filling the dynamicArray from a CSV file: random_numbers.csv ..." << endl;
            dynamicArray1.fillFromArrayCSV("random_numbers.csv");
            break;
        case 'm':
            cout << "Exiting..." << endl;
            break;

        }
    } while (choice2 != 'm');
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

void runTestDynamicArray(const unsigned numOfArrays, int j) {
    clock_t start, duration;
    Zapis plik_addFront("ArrayList_addFront.csv");
    Zapis plik_addBack("ArrayList_addBack.csv");
    Zapis plik_add("ArrayList_add.csv");
    Zapis plik_removeFront("ArrayList_removeFront.csv");
    Zapis plik_removeBack("ArrayList_removeBack.csv");
    Zapis plik_remove("ArrayList_remove.csv");
    Zapis plik_find("ArrayList_find.csv");

    test::generateRandomNumbers(100, 0, 525, "random_numbers.csv", 5);
    test::generateRandomNumbers(500, 0, 525, "random_numbersi.csv", 3);

    // Number of dynamicArray objects
    dynamicArray** arrays = new dynamicArray*[numOfArrays];
    dynamicArray** backupArrays = new dynamicArray*[numOfArrays];

    dynamicArray dynamicArray2(4);
    dynamicArray2.fillFromArrayCSV("random_numbersi.csv");

    // Tworzymy 10 000 tablic o pojemnoœci 4
    for (int i = 0; i < numOfArrays; ++i) {
        arrays[i] = new dynamicArray(4);
        backupArrays[i] = new dynamicArray(4);
    }

    for (int i = 0; i < numOfArrays; ++i) {
        arrays[i]->fillFromArrayCSV("random_numbers.csv");
        backupArrays[i]->fillFromArrayCSV("random_numbers.csv");
    }
    char choice1;
    do {
        cout << "a. addFront" << endl;
        cout << "b. addBack" << endl;
        cout << "c. add" << endl;
        cout << "d. removeFront" << endl;
        cout << "e. removeBack" << endl;
        cout << "f. remove" << endl;
        cout << "g. find number" << endl;
        cout << "h. Exit" << endl;

        cin >> choice1;
        switch (choice1) {
        case 'a':
            for (int k = 0; k < j; k++) {
                start = clock();
                for (unsigned i = 0; i < numOfArrays; i++) {
                    arrays[i]->addFront(5);
                }
                duration = clock() - start;
                double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                plik_addFront.shot(k, unsigned(duration), numOfArrays);
            }
            break;
        case 'b':
            for (int k = 0; k < j; k++) {
                start = clock();
                for (unsigned i = 0; i < numOfArrays; i++) {
                    arrays[i]->addBack(5);
                }
                duration = clock() - start;
                double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                plik_addBack.shot(k, unsigned(duration), numOfArrays);
            }
            break;
        case 'c':
            for (int k = 0; k < j; k++) {
                int index = dynamicArray2.getDynamicArrayElementAt(k);
                start = clock();
                for (unsigned i = 0; i < numOfArrays; i++) {
                    arrays[i]->add(index, 5);
                }
                duration = clock() - start;
                double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                plik_add.shot(k, unsigned(duration), numOfArrays);
            }
            break;
        case 'd':
            for (int k = 0; k < j; k++) {
                start = clock();
                for (unsigned i = 0; i < numOfArrays; i++) {
                    arrays[i]->removeFront();
                }
                duration = clock() - start;
                double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                plik_removeFront.shot(k, unsigned(duration), numOfArrays);
            }
            break;
        case 'e':
            for (int k = 0; k < j; k++) {
                start = clock();
                for (unsigned i = 0; i < numOfArrays; i++) {
                    arrays[i]->removeBack();
                }
                duration = clock() - start;
                double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                plik_removeBack.shot(k, unsigned(duration), numOfArrays);
            }
            break;
        case 'f':
            for (int k = 0; k < j; k++) {
                int index = dynamicArray2.getDynamicArrayElementAt(k);
                start = clock();

                for (unsigned i = 0; i < numOfArrays; i++) {
                    arrays[i]->remove(index);
                }
                duration = clock() - start;
                double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                plik_remove.shot(k, unsigned(duration), numOfArrays);
            }
            break;
        case 'g':
            for (unsigned i = 0; i < j; i++) {
                int number = dynamicArray2.getDynamicArrayElementAt(i);
                start = clock();
                for (int j = 0; j < numOfArrays; j++) {
                    if (arrays[i]->getDynamicArrayElementAt(j) == 9) {
                        break;
                    }
                }
                duration = clock() - start;
                plik_find.shot(i, unsigned(duration), numOfArrays);
            }
            break;
        case 'h':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        arrays[1]->displayDynamicArray();
        for (unsigned i = 0; i < numOfArrays; i++) {
            arrays[i] = backupArrays[i];
        }


    } while (choice1 != 'g');

    for (int i = 0; i < numOfArrays; ++i) {
        delete arrays[i];
    }
}

void runTestLinkedList(string type_of_list, const unsigned numOfLists, int j) {
    // deklaracja odpowiedniej listy
    LinkedList** list = new LinkedList*[numOfLists];
    LinkedList** backuplist = new LinkedList*[numOfLists];
    if (type_of_list == "H") {
        //list = new SHLinkedList[numOfLists];
        //backuplist = new SHLinkedList[numOfLists];
        for (unsigned i = 0; i < numOfLists; ++i) {
            list[i] = new SHLinkedList;
            backuplist[i] = new SHLinkedList;
        }
    }
    else if (type_of_list == "HT"){
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
    else{
        //list = new SDHTLinkedList[numOfLists];
        //backuplist = new SDHTLinkedList[numOfLists];
        for (unsigned i = 0; i < numOfLists; ++i) {
            list[i] = new SDHTLinkedList;
            backuplist[i] = new SDHTLinkedList;
        }
    }

    // deklaracja zmiennych czsu oraz potencjalnych plikow do zapisu testow
    clock_t start, duration;
    Zapis plik_addFront("LinkedList_addFront.csv");
    Zapis plik_addBack("LinkedList_addBack.csv");
    Zapis plik_add("LinkedList_add.csv");
    Zapis plik_removeFront("LinkedList_removeFront.csv");
    Zapis plik_removeBack("LinkedList_removeBack.csv");
    Zapis plik_remove("LinkedList_remove.csv");

    test::generateRandomNumbers(100, 0, 525, "random_numbers.csv", 5);

    //// Tworzymy numOfLists list
    //for (int i = 0; i < numOfLists; ++i) {
    //    list[i] = new dynamicArray(4);
    //    backuplist[i] = new 
    //}

    for (int i = 0; i < numOfLists; ++i) {
        list[i]->fillFromListCSV("random_numbers.csv");
        backuplist[i]->fillFromListCSV("random_numbers.csv");
    }
    char choice1;
    do {
        cout << "a. addFront" << endl;
        cout << "b. addBack" << endl;
        cout << "c. add" << endl;
        cout << "d. removeFront" << endl;
        cout << "e. removeBack" << endl;
        cout << "f. remove" << endl;
        cout << "g. Exit" << endl;

        cin >> choice1;
        switch (choice1) {
        case 'a':
            for (int k = 0; k < j; k++) {
                start = clock();
                for (unsigned i = 0; i < numOfLists; i++) {
                    list[i]->addfront(5);
                }
                duration = clock() - start;
                double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                plik_addFront.shot(k, unsigned(duration), numOfLists);
            }
            break;
        case 'b':
            for (int k = 0; k < j; k++) {
                start = clock();
                for (unsigned i = 0; i < numOfLists; i++) {
                    list[i]->addback(5);
                }
                duration = clock() - start;
                double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                plik_addBack.shot(k, unsigned(duration), numOfLists);
            }
            break;
        case 'c':
            for (int k = 0; k < j; k++) {
                start = clock();
                for (unsigned i = 0; i < numOfLists; i++) {
                    list[i]->addat(5, 5);
                }
                duration = clock() - start;
                double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                plik_add.shot(k, unsigned(duration), numOfLists);
            }
            break;
        case 'd':
            for (int k = 0; k < j; k++) {
                start = clock();
                for (unsigned i = 0; i < numOfLists; i++) {
                    list[i]->delfront();
                }
                duration = clock() - start;
                double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                plik_removeFront.shot(k, unsigned(duration), numOfLists);
            }
            break;
        case 'e':
            for (int k = 0; k < j; k++) {
                start = clock();
                for (unsigned i = 0; i < numOfLists; i++) {
                    list[i]->delback();
                }
                duration = clock() - start;
                double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                plik_removeBack.shot(k, unsigned(duration), numOfLists);
            }
            break;
        case 'f':
            for (int k = 0; k < j; k++) {
                start = clock();
                for (unsigned i = 0; i < numOfLists; i++) {
                    list[i]->delat(5);
                }
                duration = clock() - start;
                double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                plik_remove.shot(k, unsigned(duration), numOfLists);
            }
            break;
        case 'g':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        list[0]->printAll();
        for (unsigned i = 0; i < numOfLists; i++) {
            list[i] = backuplist[i];
        }


    } while (choice1 != 'g');
}

// przetestuj menu
int main() {
    char choice;
    do {
        cout << "Menu:" << endl;
        cout << "a. Your dynamicArray" << endl;
        cout << "b. DynamicArray tests" << endl;
        cout << "c. Your linkedList" << endl;
        cout << "d. LinkedList tests" << endl;
        cout << "e. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
        case 'a':
            runDynamicArray();
            break;
        case 'b':
            cout << "Running tests..." << endl;
            cout << "Please choose the number of arrays, "
                "than hit enter and choose the number of iteration: " << endl;
            int numOfArrays, j;
            cin >> numOfArrays >> j;
            cout << "Please wait..." << endl;
            runTestDynamicArray(numOfArrays, j);
            break;
        case 'c':
            char sub_choice;
            do{
                cout << "Please choose type of an list:\n";
                cout << "a.Head\nb.Head and Tail\nc.Two way Head, Tail\nd.Exit" << endl;
                cin >> sub_choice;
                switch (sub_choice) {
                case 'a':
                    runLinkedList("H");
                    break;
                case 'b':
                    runLinkedList("HT");
                    break;
                case 'c':
                    runLinkedList("DHT");
                    break;
                case 'd':
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            } while (sub_choice != 'd');

        case 'd':
        do {
            cout << "Please choose type of an list:\n";
            cout << "a.Head\nb.Head and Tail\nc.Two way Head, Tail\nd.Exit" << endl;
            cin >> sub_choice;

            if(sub_choice != 'd') {
                cout << "Running tests..." << endl;
                cout << "Please choose the number of arrays, "
                    "than hit enter and choose the number of iteration: " << endl;
                int numOfArrays, j;
                cin >> numOfArrays >> j;
            }

            switch (sub_choice) {
            case 'a':
                runTestLinkedList("H", numOfArrays, j);
                break;
            case 'b':
                runTestLinkedList("HT", numOfArrays, j);
                break;
            case 'c':
                runTestLinkedList("DHT", numOfArrays, j);
                break;
            case 'd':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
            // jezeli pomyslnie wybrana opcja to po jednym razie wyjdz z petli
            break;
        } while (sub_choice != 'd');
        case 'e':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 'e');

    return 0;
}