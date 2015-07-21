#pragma once
class Stack
{
public:
	virtual ~Stack(){};

	virtual int pop()=0;
	virtual int top() = 0;
	virtual void push(int) = 0;
	virtual bool empty() = 0;
	virtual unsigned size() = 0;
};

