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

void pruebaQueue(EstructuraDeExamen* q)
{



	for (int i = 0; i < 20; i += 2)
		q->enqueue(i);

	q->dump(std::cout) << std::endl;
	std::cout << "length" << q->length() << std::endl;
	for (int i = 0, size = q->length(); i < size; ++i)
	{

		std::cout << i << std::endl;
		std::cout << "first " << q->first();
		std::cout << " dequeue " << q->dequeue() << std::endl;
	}
	system("pause");



}
void pruebaStack(EstructuraDeExamen* s)
{
	for (int i = 0; i < 20; ++i)
		s->push(i);


	std::cout << "length " << s->length() << std::endl;
	s->dump(std::cout);

	for (int i = 0, size = s->length(); i < size; ++i)
	{
		std::cout << "Top " << s->top();
		std::cout << "Pop " << s->pop() << std::endl;
	}

	system("pause");
}

void pruebaBiCola(EstructuraDeExamen* q)
{
	
	


	for (int i = 0; i < 10; ++i)
	{
		q->enqueueLeft(i);
	}

	for (int i = 0; i < 10; ++i)
	{
		q->enqueueRigth(i);
	}
	q->enqueueLeft(200);

	q->dump(std::cout);

	for (int i = 0, size = q->length(); i < size; ++i)
	{
		std::cout<<"Left "<<q->left();
		std::cout << "Dequueue " << q->denqueueLeft() << std::endl;
	}

	system("pause");
	delete q;
}

void pruebaPriorityQueue(EstructuraDeExamen* p)
{

	

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 8; ++j)
			p->addItem(i * 8 + j, i);
	
	p->addItem(20000, -1);
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
void poli(EstructuraDeExamen* es)
{
	es->push(10);
	es->dump(std::cout);

	system("pause");
}


int _tmain(int argc, _TCHAR* argv[])
{
	
	pruebaPriorityQueue(new PriorityQueue());
	

}

