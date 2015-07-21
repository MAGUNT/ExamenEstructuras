#pragma once
#include "Stack.h"
#include "NodoS.h"


class StackDinamico: public Stack
{
private:
	NodoS* topNodo;
	unsigned tamano;
	void check();

public:
	StackDinamico();
	~StackDinamico();
	
	int pop() override;
	int top() override;
	void push(int) override;
	bool empty() override;
	unsigned size() override;

};

