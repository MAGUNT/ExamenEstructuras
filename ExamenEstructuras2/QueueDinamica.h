#pragma once
#include "Queue.h"
#include "NodoS.h"
class QueueDinamica: public Queue
{
private:
	NodoS *head;
	NodoS *tail;
	int size;

public:
	QueueDinamica();
	~QueueDinamica() override;
	int dequeue() override;
	void enqueue(int) override;
	bool empty() override;
	int first() override;
	unsigned length() override;

};

