#pragma once

#include "Stack.h"

class StackEstatico final: 
	public Stack
{
public:
	StackEstatico();
	StackEstatico(int);
	~StackEstatico() override;
	int pop() override;
	int top() override;
	void push(int) override;
	bool empty() override;
	bool full();
	unsigned size() override;

private:

	unsigned tamano;
	unsigned tamanoMax;

	int * arreglo;

	
};

