#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <fstream>
#include <sstream>

struct node {
	int data_;
	node* next_;
	node* prev_;

	node() : data_(0), next_(nullptr), prev_(nullptr) {};
	node(int data) : data_(data), next_(nullptr), prev_(nullptr) {};
};

class LinkedList {
protected:
	node* head_;
	node* current_;
public:
	LinkedList();
	~LinkedList();

	virtual int getdata() = 0;// data of current
	virtual unsigned getsize();

	virtual void addfront(int data) = 0;
	virtual void addat(unsigned place, int data) = 0;
	virtual void addback(int data) = 0;

	virtual void delfront() = 0;
	virtual void delat(unsigned place) = 0;
	virtual void delback() = 0;

	virtual int search(int data) = 0;

	//virtual node* next() = 0;
	virtual void back() = 0;// wraca current_ na poczatek
	bool isempty();// zwraca 1 jezeli pusta

	virtual void printAll() = 0;
	void fillFromListCSV(const std::string& filename, int maxElements);

};