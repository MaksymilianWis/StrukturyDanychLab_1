#pragma once
#include "SHTLinkedList.hpp"
#include "iostream"

SHTLinkedList::SHTLinkedList() :size_(0), tail_(nullptr){
	//head_ = new node();
	//tail_ = head_;
	//if (!head_) {
	//	printf("ERROR could not create head_");
	//	return;
	//}
	//if (!tail_) {
	//	printf("ERROR could not create tail_");
	//	return;
	//}
	//current_ = head_;
}

int SHTLinkedList::getdata() {
	return current_->data_;
}

void SHTLinkedList::addfront(int data) {
	if (!head_) head_ = new node();

	if (!head_->data_) {
		head_->data_ = data;
		return;
	}

	node* newnode;

	//nadpisywanie danych
	newnode = new node(data);

	newnode->next_ = head_;

	head_ = newnode;
	size_++;
}

void SHTLinkedList::addat(unsigned place, int data) {
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
			size_++;
			return;
		}

		// jezeli znaleziony element przed elementem place
		if (i + 1 == place) {
			new_node->data_ = data;

			// wstawianie new_node
			temp2 = temp->next_;
			temp->next_ = new_node;
			new_node->next_ = temp2;
			size_++;
			return;
		}

		// przeskoczenie do nastepnego node
		temp = temp->next_;
	}

	std::cout << "ERROR Miejsce wstawienia elementu poza rozmiarem Listy\n";
}

void SHTLinkedList::addback(int data) {
	if (!tail_) tail_ = new node();

	//nadpisywanie danych
	node* newnode = new node(data);

	//dodawanie na koniec
	tail_->next_ = newnode;

	tail_ = newnode;
	size_++;
}

void SHTLinkedList::delback() {
	if (head_ == nullptr) return;
	//tworzenie tymczasowego node wskazuj¹cego najpierw na head_
	node* temp;
	temp = head_;

	node* prevtemp;
	prevtemp = temp;

	//szukanie pustego next_
	while (temp->next_) {
		prevtemp = temp;
		temp = temp->next_;
	}

	//jezeli lista pusta
	if (!head_ || temp == head_) {
		delete head_;
		head_ = nullptr;
		size_--;
		return;
	}

	//odlaczanie wskaznikow i usuwanie
	prevtemp->next_ = nullptr;
	delete temp;

	tail_ = prevtemp;

	size_--;
	return;
}

void SHTLinkedList::delat(unsigned place) {
	node* temp = head_;
	node* temp2;
	node* new_node = new node;

	if (place == 0) {
		delfront();
		size_--;
		return;
	}
	if (place == size_ - 1) {
		delback();
		size_--;
		return;
	}

	// szukanie elementu przed elementem place
	for (unsigned i = 0; temp != nullptr; i++) {

		// jezeli znaleziony element przed elementem place
		if (i + 1 == place) {

			// tymczasowy next_
			temp2 = temp->next_;

			// nadpisanie next_ jezeli jest czym
			temp->next_ = temp->next_->next_;

			delete temp2;
			temp2 = nullptr;
			size_--;
			return;
		}

		// przeskoczenie do nastepnego node
		temp = temp->next_;
	}

	std::cout << "ERROR Miejsce wstawienia elementu poza rozmiarem Listy\n";
}

void SHTLinkedList::delfront() {
	node* temp;

	//jezeli lista pusta zwroc 0
	if (!head_ || !head_->next_) {
		delete head_;
		head_ = nullptr;
		size_--;
		return;
	}

	temp = head_;
	head_ = head_->next_;

	delete temp;
	temp = nullptr;

	size_++;
	return;
}

int SHTLinkedList::search(int data) {
	node* temp = head_;

	// sprawdzanie czy nie pusta
	if (temp == nullptr) {
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

node* SHTLinkedList::next() {
	//jezeli lista pusta zwroc 0
	if (!current_) return 0;

	current_ = current_->next_;
	return current_;
}

void SHTLinkedList::back() {
	current_ = head_;
}

void SHTLinkedList::printAll() {
	node* temp = head_;
	unsigned i = 0;

	for (i; temp != nullptr; i++) {
		printf("Elemend %d to: %d\n", i, temp->data_);
		temp = temp->next_;
	}
}

unsigned SHTLinkedList::getsize() {
	return size_;
}