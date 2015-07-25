#pragma once

#include "Stack.h"
#include "EstructuraDeExamen.h"

class StackEstatico final : public EstructuraDeExamen
	
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
	unsigned length() override;
	std::ostream&  dump(std::ostream&) override;
	std::string getNombre()override{ return "Stack estatico"; }

private:

	unsigned tamano;
	unsigned tamanoMax;

	int * arreglo;

	
};

