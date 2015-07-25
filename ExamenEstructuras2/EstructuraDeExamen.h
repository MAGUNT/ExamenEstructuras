#pragma once
#include <iostream>
#include <string>

class EstructuraDeExamen
{

private: 
	void mensaje();
	
public:
	virtual ~EstructuraDeExamen(){}
	virtual bool empty() = 0;
	virtual unsigned length()=0;
	virtual std::ostream&  dump(std::ostream&) = 0;
	virtual std::string getNombre() = 0;
	virtual int pop();
	virtual int top();
	virtual void push(int);

	virtual int dequeue();
	virtual void enqueue(int);
	virtual int first();
	
	virtual void enqueueLeft(int);
	virtual void enqueueRigth(int);
	virtual int denqueueLeft();
	virtual int denqueueRigth();
	virtual int rigth();
	virtual int left();
	virtual void addItem(int item, int key);
	virtual int removeItem();
	virtual void changePriority(int item, int key);


};


