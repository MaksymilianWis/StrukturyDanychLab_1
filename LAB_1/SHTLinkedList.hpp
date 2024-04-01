#pragma once
#include "LinkedList.hpp"

//struct node {
//	int data_;
//	node* next_;
//
//	node() : data_(0), next_(nullptr) {};
//	node(int data) : data_(data), next_(nullptr) {};
//};

class SHTLinkedList :public LinkedList {
private:
	node* tail_;
	unsigned size_;
public:
	SHTLinkedList();

	int getdata();// data of current
	unsigned getsize();

	void addfront(int data);
	void addat(unsigned place, int data);
	void addback(int data);

	void delfront();
	void delat(unsigned place);
	void delback();

	int search(int data);

	node* next();
	void back();// wraca current_ na poczatek

	void printAll();

};