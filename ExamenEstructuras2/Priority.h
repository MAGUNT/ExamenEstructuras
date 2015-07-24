#pragma once
#include "QueueDinamica.h"

class Priority
{
	friend class PriorityQueue;
private:
	Priority(int);
	Priority();
	~Priority();
	int key;
	QueueDinamica* queue;
	Priority *next;
	Priority *prev;
};

