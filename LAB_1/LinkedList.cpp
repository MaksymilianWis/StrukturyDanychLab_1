#pragma once
#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList() : head_(nullptr), current_(nullptr) {};

LinkedList::~LinkedList() {
    node* temp;

    while (head_ != nullptr)
    {
        temp = head_;
        if (head_->next_ != nullptr) head_ = head_->next_;
        delete temp;
        temp = nullptr;
    }
}

bool LinkedList::isempty() {
	if (this->head_ == nullptr)
	{
		return 1;
	}
	return 0;
}

unsigned LinkedList::getsize() {
	std::cout << "List does not track its size\n";
	return 0;
}

void LinkedList::fillFromListCSV(const std::string& filename, int maxElements) {
    // Otwieramy plik CSV
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open the file: " << filename << std::endl;
        return;
    }

    std::string line;
    int elementsAdded = 0;
    while (std::getline(file, line) && elementsAdded < maxElements) {
        std::istringstream iss(line);
        std::string value;
        while (std::getline(iss, value, ',') && elementsAdded < maxElements) {
            int element;
            try {
                // Konwertujemy wartoœæ z ci¹gu znaków na liczbê ca³kowit¹
                element = std::stoi(value);
            }
            catch (const std::invalid_argument& e) {
                // Ignorujemy nieprawid³owe wartoœci
                continue;
            }
            // Dodajemy element do tablicy
            addfront(element);
            elementsAdded++;
        }
    }

    // Zamykamy plik
    file.close();
}