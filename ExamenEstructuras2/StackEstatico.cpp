#include "StackEstatico.h"
#include <stdexcept>

StackEstatico::StackEstatico() :StackEstatico(20){}

StackEstatico::StackEstatico(int ptamano) 
	: tamanoMax(ptamano), tamano(0), arreglo(new int[ptamano]){}

StackEstatico::~StackEstatico()
{
	delete[] arreglo;
}

int StackEstatico::pop()
{
	if (empty())
		throw new std::underflow_error("El stack esta vacio");

	return arreglo[--tamano];
}
int StackEstatico::top()
{
	return arreglo[tamano - 1];
}
void StackEstatico::push(int elemento)
{
	if (full())
		throw new std::overflow_error("El stack esta lleno");

	arreglo[tamano++] = elemento;

}
bool StackEstatico::empty()
{
	return tamano == 0;
}

bool StackEstatico::full()
{
	return tamano == tamanoMax;
}
unsigned StackEstatico::length()
{
	return tamano;
}
std::ostream&  StackEstatico::dump(std::ostream& os)
{
	for (unsigned i = 0; i < tamano; ++i)
	{
		os << arreglo[i] << ", ";
	}

	return os<<std::endl;
}