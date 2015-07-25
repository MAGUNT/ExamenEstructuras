#pragma once
#include "Stack.h"
#include "NodoS.h"
#include "EstructuraDeExamen.h"


class StackDinamico final : public EstructuraDeExamen
{
private:
	NodoS* topNodo;
	unsigned tamano;
	void check();

public:
	StackDinamico();
	~StackDinamico() override;
	
	int pop() override;
	int top() override;
	void push(int) override;
	bool empty() override;
	unsigned length() override;
	std::ostream&  dump(std::ostream&) override;
	std::string getNombre()override{ return "Stack dinamico"; }

};

