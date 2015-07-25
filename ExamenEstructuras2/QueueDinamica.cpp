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
bool QueueDinamica::remove(int item)
{
	if (empty()) return false;

	NodoS *nodo = head;

	if (head->dato == item)
	{
		NodoS *borrar = head;
		head = head->next;
		delete borrar;
		--size;
		return true;
	}

	while (nodo->next != nullptr && item != nodo->next->dato)
		nodo = nodo->next;
	
	bool exist = nodo->next != nullptr;
	if (exist) deleteNext(nodo);
	
	return exist;

}
void QueueDinamica::deleteNext(NodoS* nodo)
{
	NodoS *borrar = nodo->next;
	nodo->next = nodo->next->next;
	delete borrar;
	--size;
}
std::ostream&  QueueDinamica::dump(std::ostream& os)
{
	if (empty()) return os;
	NodoS *nodo = head;

	while (nodo->next != nullptr)
	{
		os << nodo->dato << ", ";
		nodo = nodo->next;
	}
	return os << nodo->dato;
}