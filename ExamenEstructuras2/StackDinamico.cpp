#include "StackDinamico.h"
#include <stdexcept>

StackDinamico::StackDinamico() :tamano(0), topNodo(nullptr)
{

}
StackDinamico::~StackDinamico()
{
	while (topNodo != nullptr)
	{
		NodoS *borrar = topNodo;
		topNodo = topNodo->next;
		delete borrar;
	}
}

void  StackDinamico::check()
{
	if (empty())
		throw new std::underflow_error("el stack esta vacio");
}

int StackDinamico::pop()
{
	check();

	int datoViejo = topNodo->dato;
	NodoS *nodoViejo = topNodo;
	topNodo = topNodo->next;

	delete nodoViejo;
	--tamano;

	return datoViejo;
}
int StackDinamico::top()
{
	check();
	return topNodo->dato;
}
void StackDinamico::push(int elemento)
{
	topNodo = new NodoS(elemento, topNodo);
	++tamano;
}
bool StackDinamico::empty()
{
	return topNodo == nullptr;
}

unsigned StackDinamico::length()
{
	return tamano;
}

std::ostream&  StackDinamico::dump(std::ostream& os)
{
	NodoS *nodo = topNodo;
	while (nodo->next != nullptr)
	{
		os << nodo->dato <<", ";
	}
	return os << nodo->dato << std::endl;
}