// ExamenEstructuras2.cpp: define el punto de entrada de la aplicación de consola.
//
#include <tchar.h>
#include "PriorityQueue.h"
#include <ostream>


int _tmain(int argc, _TCHAR* argv[])
{
	PriorityQueue *p= new PriorityQueue();

	int cont = 0;
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 8; ++j)
			p->addItem(i*8+j, i);
	
	p->dump(std::cout);

	p->changePriority(6, 4);
	p->changePriority(40, 5);

	p->dump(std::cout);
	
	while (!p->empty())
		std::cout << p->removeItem() << std::endl;
	
	system("pause");
	
	
	return 0;
}

