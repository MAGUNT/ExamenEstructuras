#pragma once
#include "NodoD.h"

class BiQueue
{

private:
	NodoD *head;
	NodoD *tail;
	unsigned size;
	void check();

public:
	BiQueue();
	~BiQueue();

	bool empty();
	void enqueueLeft(int);
	void enqueueRigth(int);
	int denqueueLeft();
	int denqueueRigth();
	int left();
	int rigth();
	unsigned length();

};

