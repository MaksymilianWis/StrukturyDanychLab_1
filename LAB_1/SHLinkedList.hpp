#pragma once
#include "LinkedList.hpp"

//struct node {
//	int data_;
//	node* next_;
//
//	node() : data_(0), next_(nullptr) {};
//	node(int data) : data_(data), next_(nullptr) {};
//};

class SHLinkedList :public LinkedList {
private:
	// zmienne w rodzicu
public:

	int getdata();// data of current

	void addfront(int data);
	void addat(unsigned place, int data);
	void addback(int data);

	void delfront();
	void delat(unsigned place);//licz¹c od 0
	void delback();

	int search(int data);

	node* next();
	void back();//wraca current na poczatek

	void printAll();

};