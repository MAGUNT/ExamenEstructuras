#pragma once
#include "Priority.h"
#include <iostream>
#include "EstructuraDeExamen.h"

class PriorityQueue: public EstructuraDeExamen
{
public:
	PriorityQueue();
	~PriorityQueue() override;

	void addItem(int item, int key)override;
	int removeItem() override;
	unsigned length() override;
	void changePriority(int item, int key) override;
	bool empty()override{ return size == 0; };
	std::ostream&  dump(std::ostream&) override;

	std::string getNombre()override;

private:
	unsigned size;
	Priority* head;
	bool remove(int item);
	Priority* findElseCreatePriority(int);
	Priority * createBefore(Priority* priority, int key);
	Priority * createAfter(Priority* priority, int key);
	Priority * initPriority(int);
	
	
};

