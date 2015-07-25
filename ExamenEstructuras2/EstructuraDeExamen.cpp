#include "EstructuraDeExamen.h"

void EstructuraDeExamen::mensaje(){
	std::cout << "La estructura: " << getNombre() << " no puede ejecutar esta operacion" << std::endl;
}
int EstructuraDeExamen::pop(){ mensaje(); return 0; }
int EstructuraDeExamen::top(){ mensaje(); return 0; }
 void EstructuraDeExamen::push(int){mensaje();}
 int EstructuraDeExamen::dequeue(){ mensaje(); return 0; }
 void EstructuraDeExamen::enqueue(int){mensaje();}
 int EstructuraDeExamen::first(){ mensaje(); return 0; }
 void EstructuraDeExamen::enqueueLeft(int){mensaje();}
 void EstructuraDeExamen::enqueueRigth(int){mensaje();}
 int EstructuraDeExamen::denqueueLeft(){ mensaje(); return 0; }
 int EstructuraDeExamen::denqueueRigth(){ mensaje(); return 0; }
 int EstructuraDeExamen::left(){ mensaje(); return 0; }
 int EstructuraDeExamen::rigth(){ mensaje(); return 0; }
 
 void EstructuraDeExamen::addItem(int item, int key){mensaje();}
 int EstructuraDeExamen::removeItem(){ mensaje(); return 0; }
 void EstructuraDeExamen::changePriority(int item, int key){mensaje();}

