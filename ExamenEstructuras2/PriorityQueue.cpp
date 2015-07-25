#include "PriorityQueue.h"
#include <stdexcept>

PriorityQueue::PriorityQueue() :head(nullptr), size(0)
{
}


PriorityQueue::~PriorityQueue()
{
	
	if (head != nullptr)
	{
		Priority *p = head;
		do
		{
			Priority *borrar = p;
			p = p->next;
			delete borrar;

		} while (head != p);
	}
}
void PriorityQueue::addItem(int item, int key)
{
	
	Priority* p = findElseCreatePriority(key);
	p->queue->enqueue(item);
	++size;
	
}
int PriorityQueue::removeItem()
{
	if (empty())
		throw std::underflow_error("underflow");

	Priority *p = head;

	while (p->next != head && p->queue->empty())
		p = p->next;
	
	--size;
	return p->queue->dequeue();
}
unsigned PriorityQueue::length()
{
	return size;
}
void PriorityQueue::changePriority(int item, int key)
{
	if (remove(item)) 
		addItem(item, key);
}
bool PriorityQueue::remove(int item)
{
	Priority *p = head;
	do
	{
		if (p->queue->remove(item))
			return --size, true;
		
		p = p->next;
	} while (head != p);

	return false;
}
Priority* PriorityQueue::findElseCreatePriority(int key)
{
	
	if (head == nullptr) 
		return initPriority(key);

	Priority *p = head;
	do
	{
		if (key == p->key) return p;
		if (key < p->key) return createBefore(p, key);	
		p = p->next;

	} while (p != head);
	
	return createAfter(p->prev, key);
}

Priority*  PriorityQueue::createBefore(Priority* p, int key)
{
	
	Priority* nuevo = new Priority(key);
	nuevo->next = p;
	nuevo->prev = p->prev;
	p->prev->next = nuevo;
	p->prev = nuevo;

	if (p == head) head = nuevo;

	return nuevo;
}

Priority*  PriorityQueue::createAfter(Priority* p, int key)
{

	Priority* nuevo = new Priority(key);
	nuevo->prev = p;
	nuevo->next = p->next;
	p->next->prev = nuevo;
	p->next = nuevo;


	return nuevo;
}
std::ostream& PriorityQueue::dump(std::ostream& os)
{
	if (empty()) return os;

	Priority *p = head;
	do
	{
		os << "Prioridad # " << p->key<<" "; 
		p->queue->dump(os)<<std::endl;
		p = p->next;

	} while (head != p);

	return os;
}
Priority * PriorityQueue::initPriority(int key)
{
	head = new Priority(key);
	head->next = head;
	head->prev = head;

	return head;
}
std::string PriorityQueue::getNombre()
{

	return "Cola de prioridades";
}