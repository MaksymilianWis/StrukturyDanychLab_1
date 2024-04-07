#pragma once
#include "SHLinkedList.hpp"
#include "iostream"

int SHLinkedList::getdata() {
	return current_->data_;
}

void SHLinkedList::addfront(int data) {

	if (!head_) {
		head_ = new node();
		head_->data_ = data;
		return;
	}

	node* newnode;

	// nadpisywanie danych
	newnode = new node(data);

	newnode->next_ = head_;

	head_ = newnode;
}


void SHLinkedList::addat(unsigned place, int data) {
	node* temp = head_;
	node* temp2;
	node* new_node = new node;

	if (place == 0) {
		addfront(data);
		return;
	}
	
	// szukanie elementu przed elementem place
	for (unsigned i = 0; temp != nullptr; i++) {

		// jezeli temp == ostatni element to dodaj na koniec
		if (temp->next_ == nullptr) {
			addback(data);
			return;
		}

		// jezeli znaleziony element przed elementem place
		if (i+1 == place) {
			new_node->data_ = data;

			// wstawianie new_node
			temp2 = temp->next_;
			temp->next_ = new_node;
			new_node->next_ = temp2;
			return;
		}

		// przeskoczenie do nastepnego node
		temp = temp->next_;
	}

	std::cout << "ERROR Miejsce wstawienia elementu poza rozmiarem Listy\n";
}

void SHLinkedList::addback(int data) {

	// tworzenie tymczasowego node wskazuj¹cego najpierw na head_
	node* temp;

	if (!head_) head_ = new node();

	temp = head_;

	// nadpisywanie danych
	node* newnode = new node(data);

	// szukanie pustego next_
	while (temp->next_) temp = temp->next_;

	// dodawanie na koniec
	temp->next_ = newnode;
}

void SHLinkedList::delback() {
	if (head_ == nullptr) return;
	// tworzenie tymczasowego node wskazuj¹cego najpierw na head_
	node* temp;
	temp = head_;

	node* prevtemp;
	prevtemp = temp;

	// szukanie pustego next_
	while (temp->next_) {
		prevtemp = temp;
		temp = temp->next_;
	}

	// jezeli lista pusta zwroc 0
	if (!head_ || temp == head_) {
		delete head_;
		head_ = nullptr;
		return;
	}

	// odlaczanie wskaznikow i usuwanie
	prevtemp->next_ = nullptr;
	delete temp;

	return;
}

void SHLinkedList::delat(unsigned place) {
	node* temp = head_;
	node* temp2;

	if (place == 0) {
		delfront();
		return;
	}

	// szukanie elementu przed elementem place
	for (unsigned i = 0; temp != nullptr; i++) {

		// jezeli znaleziony element przed elementem place
		if (i+1 == place) {

			// exception jezeli temp == ostatniemu elementowi w tablicy a szukamy elementu jeden przed
			if (temp->next_ == nullptr) {
				break;
			}

			// jezeli next_.next_ nie isteniej znaczy ze poszukiwany element jest ostatni na liscie wiec dellback()
			if (temp->next_->next_ == nullptr) {
				delback();
				return;
			}

			// tymczasowy next_
			temp2 = temp->next_;

			// nadpisanie next_ jezeli jest czym
			temp->next_ = temp->next_->next_;

			delete temp2;
			temp2 = nullptr;
			return;
		}

		// przeskoczenie do nastepnego node
		temp = temp->next_;
	}
	std::cout << "ERROR nie znaleziono elementu od pozycji: " << place << std::endl;
	return;
}

void SHLinkedList::delfront() {
	node* temp;

	// jezeli lista pusta zwroc 0
	if (!head_ || !head_->next_) {
		delete head_;
		head_ = nullptr;
		return;
	}

	temp = head_;
	head_ = head_->next_;

	delete temp;
	temp = nullptr;

	return;
}

int SHLinkedList::search(int data) {
	node* temp = head_;

	// sprawdzanie czy nie pusta
	if (temp == nullptr){
		std::cout << "ERROR nie odnaleziono danej, tablica pusta\n";
		return NULL;
	}

	// przeszukiwanie
	while (temp->data_ != data) {
		if (temp->next_ == nullptr) {
			return NULL;
		}
		temp = temp->next_;
	}
	return temp->data_;
}

node* SHLinkedList::next() {
	// jezeli lista pusta zwroc 0
	if (!current_) return 0;

	current_ = current_->next_;
	return current_;
}

void SHLinkedList::back() {
	current_ = head_;
}

void SHLinkedList::printAll() {
	node* temp = head_;
	unsigned i = 0;

	for (i; temp != nullptr; i++) {
		printf("Elemend %d to: %d\n", i, temp->data_);
		temp = temp->next_;
	}
}