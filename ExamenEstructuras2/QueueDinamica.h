#pragma once
#include "Queue.h"
#include "NodoS.h"
#include <iostream>
#include "EstructuraDeExamen.h"
class QueueDinamica: public EstructuraDeExamen
{

	friend class PriorityQueue;


private:
	NodoS *head;
	NodoS *tail;
	int size;

	bool remove(int);
	void deleteNext(NodoS*);

public:
	QueueDinamica();
	~QueueDinamica() override;
	int dequeue() override;
	void enqueue(int) override;
	bool empty() override;
	int first() override;
	unsigned length() override;
	std::ostream& dump(std::ostream&) override;
	virtual std::string getNombre(){ return "Cola dinamica"; }



};

