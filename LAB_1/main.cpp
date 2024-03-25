#include "dynamicArray.h"
#include "Zapis.h"
#include "test.h"
#include "cstdlib"
#include <ctime>

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
                } else {
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
                dynamicArray1.fillFromArrayCSV("random_numbers.csv");
                break;
            case '13':
                cout << "Exiting..." << endl;
                break;

        }
    } while (choice2 != '13');
}

void runTests(const unsigned numOfArrays, int j){
    clock_t start, duration;
    Zapis plik_addFront("ArrayList_addFront.csv");
    Zapis plik_addBack("ArrayList_addBack.csv");
    Zapis plik_add("ArrayList_add.csv");
    Zapis plik_removeFront("ArrayList_removeFront.csv");
    Zapis plik_removeBack("ArrayList_removeBack.csv");
    Zapis plik_remove("ArrayList_remove.csv");

    test::generateRandomNumbers(100, 0, 525, "random_numbers.csv", 5);

     // Number of dynamicArray objects
    dynamicArray* arrays[numOfArrays];
    dynamicArray* backupArrays[numOfArrays];

    // Tworzymy 10 000 tablic o pojemności 4
    for (int i = 0; i < numOfArrays; ++i) {
        arrays[i] = new dynamicArray(4);
        backupArrays[i] = new dynamicArray(4);
    }

    for (int i = 0; i < numOfArrays; ++i) {
        arrays[i]->fillFromArrayCSV("random_numbers.csv");
        backupArrays[i] -> fillFromArrayCSV("random_numbers.csv");
    }
    char choice1;
    do {
        cout << "1. addFront" << endl;
        cout << "2. addBack" << endl;
        cout << "3. add" << endl;
        cout << "4. removeFront" << endl;
        cout << "5. removeBack" << endl;
        cout << "6. remove" << endl;
        cout << "7. Exit" << endl;

        cin >> choice1;
        switch (choice1) {
            case '1':
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
            case '2':
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
            case '3':
                for (int k = 0; k < j; k++) {
                    start = clock();
                    for (unsigned i = 0; i < numOfArrays; i++) {
                        arrays[i]->add(5, 5);
                    }
                    duration = clock() - start;
                    double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                    plik_add.shot(k, unsigned(duration), numOfArrays);
                }
                break;
            case '4':
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
            case '5':
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
            case '6':
                for (int k = 0; k < j; k++) {
                    start = clock();
                    for (unsigned i = 0; i < numOfArrays; i++) {
                        arrays[i]->remove(5);
                    }
                    duration = clock() - start;
                    double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
                    plik_remove.shot(k, unsigned(duration), numOfArrays);
                }
                break;
            case '7':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        arrays[1]->displayDynamicArray();
        for (unsigned i = 0; i < numOfArrays; i++) {
            arrays[i] = backupArrays[i];
        }


    } while (choice1 != '7');

    for (int i = 0; i < numOfArrays; ++i) {
        delete arrays[i];
    }
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

        switch(choice) {
            case '1':
                runDynamicArray();
                break;
            case '2':
                cout << "Running tests..." << endl;
                cout << "Please choose the number of arrays, "
                        "than hit enter and choose the number of iteration: " << endl;
                int numOfArrays, j;
                cin >> numOfArrays >> j;
                cout << "Please wait..." << endl;
                runTests(numOfArrays, j);
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
