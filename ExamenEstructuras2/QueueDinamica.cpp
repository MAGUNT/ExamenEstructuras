#include "QueueDinamica.h"
#include <stdexcept>

QueueDinamica::QueueDinamica() :
size(0), head(nullptr), tail(nullptr)
{
}


QueueDinamica::~QueueDinamica()
{
	while (head != nullptr)
	{
		NodoS *borrar = head;
		head = head->next;
		delete borrar;
	}

}

int QueueDinamica::dequeue()
{
	if (empty()) 
		throw new std::underflow_error("Cola esta vacia");

	NodoS* nodoViejo = head;
	int valorViejo = head->dato;
	
	if (head == tail) tail = nullptr;// para evitar el dangling pointer
	
	head = head->next;
	delete nodoViejo;
	--size;

	return valorViejo;
}
void QueueDinamica::enqueue(int numero)
{
	NodoS *nuevo = new NodoS(numero);

	if (empty()) 
		head = nuevo;
	else 
		tail->next= nuevo;

	tail = nuevo;
	++size;

}
bool QueueDinamica::empty()
{
	return size == 0;
}
int QueueDinamica::first()
{
	return head->dato;
}
unsigned QueueDinamica::length()
{
	return size;
}