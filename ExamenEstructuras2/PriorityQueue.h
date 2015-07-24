#pragma once
#include "Priority.h"
#include <iostream>
class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();

	void addItem(int item, int key);
	int removeItem();
	unsigned getSize();
	void changePriority(int item, int key);
	bool empty(){ return size == 0; };
	std::ostream&  dump(std::ostream&);
private:
	unsigned size;
	Priority* head;
	bool remove(int item);
	Priority* findElseCreatePriority(int);
	Priority * createBefore(Priority* priority, int key);
	Priority * createAfter(Priority* priority, int key);
	Priority * initPriority(int);
	
	
};

