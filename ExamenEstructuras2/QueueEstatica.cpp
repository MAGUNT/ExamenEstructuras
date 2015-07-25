#include "QueueEstatica.h"
#include <stdexcept>

QueueEstatica::QueueEstatica() :QueueEstatica(20){}
QueueEstatica::QueueEstatica(unsigned pmaxSize) 
	: size(0), tail(0), head(0), maxsize(pmaxSize+1), arreglo(new int[pmaxSize]){}

QueueEstatica::~QueueEstatica()
{
	delete[] arreglo;
}

bool QueueEstatica::estaLleno()
{
	return head == (tail + 1) % maxsize;
}
int QueueEstatica::dequeue()
{
	if (empty()) 
		throw new std::underflow_error("La cola esta vacia");

	int ele = arreglo[head];
	(++head) %= maxsize;
	--size;

	return ele;
}
void QueueEstatica::enqueue(int numero)
{
	if (estaLleno())
		throw new std::overflow_error("La cola esta llena");

	arreglo[tail] = numero;
	(++tail) %= maxsize;
	++size;
}
bool QueueEstatica::empty()
{
	return tail == head;
}
int QueueEstatica::first()
{
	if (empty())
		throw new std::underflow_error("La cola esta vacia");

	return arreglo[head];
}

unsigned QueueEstatica::length()
{
	return size;
}
std::ostream&  QueueEstatica::dump(std::ostream& os)
{

	for (int i = head; i != tail; (++i) %= maxsize)
		os << arreglo[i] <<", ";

	return os<<std::endl;
}