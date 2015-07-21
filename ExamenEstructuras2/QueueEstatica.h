#pragma once
#include "Queue.h"

class QueueEstatica : public Queue
{
private:
	int* arreglo;
	unsigned maxsize;
	unsigned size;
	int head;
	int tail;

	bool estaLleno();
public:
	QueueEstatica();
	QueueEstatica(unsigned);
	~QueueEstatica() override;
	int dequeue() override;
	void enqueue(int) override;
	bool empty() override;
	int first() override;
	unsigned length() override;

};

