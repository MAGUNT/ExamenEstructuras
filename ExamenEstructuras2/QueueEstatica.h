#pragma once
#include "Queue.h"
#include "EstructuraDeExamen.h"

class QueueEstatica : public EstructuraDeExamen
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
	std::ostream&  dump(std::ostream&) override;
	std::string getNombre()override{ return "Cola estatica circular"; };

};

