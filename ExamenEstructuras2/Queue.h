#pragma once
class Queue
{
public:
	virtual ~Queue(){}
	virtual int dequeue()=0;
	virtual void enqueue(int)=0;
	virtual bool empty()=0;
	virtual int first()=0;
	virtual unsigned length()=0;

};

