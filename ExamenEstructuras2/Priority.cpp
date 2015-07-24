#include "Priority.h"
#include "QueueDinamica.h"


Priority::Priority(int pkey) : key(pkey), queue(new QueueDinamica()), next(nullptr), prev(nullptr)
{

}
Priority::Priority() : Priority(0)
{

}
Priority::~Priority()
{
	delete queue;
}
