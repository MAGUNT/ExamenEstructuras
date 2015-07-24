// ExamenEstructuras2.cpp: define el punto de entrada de la aplicación de consola.
//
#include <tchar.h>
#include "PriorityQueue.h"
#include "QueueDinamica.h"
#include "QueueEstatica.h"
#include "StackDinamico.h"
#include "StackEstatico.h"
#include "BiQueue.h"
#include <ostream>

void pruebaQueue(Queue* q)
{



	for (int i = 0; i < 20; i += 2)
		q->enqueue(i);

	//q->dump(std::cout) << std::endl;
	std::cout << "length" << q->length() << std::endl;
	for (int i = 0, size = q->length(); i < size; ++i)
	{

		std::cout << i << std::endl;
		std::cout << "first " << q->first();
		std::cout << " dequeue " << q->dequeue() << std::endl;
	}
	delete q;
	system("pause");



}
void pruebaStack(Stack* s)
{
	for (int i = 0; i < 20; ++i)
		s->push(i);


	std::cout << "length " << s->size() << std::endl;

	for (int i = 0, size = s->size(); i < size; ++i)
	{
		std::cout << "Top " << s->top();
		std::cout << "Pop " << s->pop() << std::endl;
	}
	delete s;
	system("pause");
}

void pruebaBiCola()
{
	
	BiQueue *q = new BiQueue();


	for (int i = 0; i < 10; ++i)
	{
		q->enqueueLeft(i);
	}

	for (int i = 0; i < 10; ++i)
	{
		q->enqueueRigth(i);
	}
	q->enqueueLeft(200);
	for (int i = 0, size = q->length(); i < size; ++i)
	{
		std::cout<<"Left "<<q->left();
		std::cout << "Dequueue " << q->denqueueLeft() << std::endl;
	}

	system("pause");
	delete q;
}

void pruebaPriorityQueue()
{

	PriorityQueue *p = new PriorityQueue();

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 8; ++j)
			p->addItem(i * 8 + j, i);

	p->dump(std::cout);

	p->changePriority(6, 4);
	p->changePriority(40, 5);
	p->changePriority(0, 9);

	p->dump(std::cout);

	while (!p->empty())
		std::cout << p->removeItem() << std::endl;

	delete p;
	system("pause");

}

int _tmain(int argc, _TCHAR* argv[])
{
	pruebaBiCola();
}

