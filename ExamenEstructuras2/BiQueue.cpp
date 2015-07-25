#include "BiQueue.h"
#include <stdexcept>

//nota podria cambiarlo a circular

BiQueue::BiQueue() :size(0), head(nullptr), tail(nullptr){}
BiQueue::~BiQueue()
{
	while (head != nullptr)
	{
		NodoD *borrar = head;
		head = head->next;
		delete borrar;
	}
}
void BiQueue::check()
{
	if (empty())
		throw new std::underflow_error("Cola esta vacia");
}
bool BiQueue::empty(){ return size == 0; }
void BiQueue::enqueueLeft(int numero)
{
	head = new NodoD(numero, nullptr,head);
	if (empty())
		tail = head;
	else
		head->next->prev = head;
	++size;
}
void BiQueue::enqueueRigth(int numero)
{
	tail = new NodoD(numero, tail, nullptr);
	if (empty())
		head = tail;
	else
		tail->prev->next = tail;
	++size;
}
int BiQueue::denqueueLeft()
{
	check();
	NodoD* borrar = head;
	int valor = head->dato;
	
	if (head == tail)
		tail = nullptr; 
	else
		head->next->prev = nullptr;
	
	head = head->next;
	delete borrar;
	--size;

	return valor;
}
int BiQueue::denqueueRigth()
{
	check();
	NodoD *borrar = tail;
	int valor = tail->dato;

	if (head == tail)
		head = nullptr;
	else
		tail->prev->next = nullptr;

	tail = tail->prev;
	delete borrar;
	--size;

	return valor;
}
int BiQueue::left()
{
	check();
	return head->dato;
}
int BiQueue::rigth()
{
	check();
	return tail->dato;
}
unsigned BiQueue::length()
{ 
	return size;
}
std::ostream&   BiQueue::dump(std::ostream& os)
{
	NodoD *nodo = head;
	while (nodo->next != nullptr)
	{
		os << nodo->dato << ", ";
	}
	return os << nodo->dato<<std::endl;
}
 std::string  BiQueue::getNombre()
{
	return "BiCola";
}