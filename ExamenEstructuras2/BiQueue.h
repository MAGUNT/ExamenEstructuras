#pragma once
#include "NodoD.h"
#include "EstructuraDeExamen.h"

class BiQueue : public EstructuraDeExamen
{

private:
	NodoD *head;
	NodoD *tail;
	unsigned size;
	void check();

public:
	BiQueue();
	~BiQueue();

	bool empty() override;
	void enqueueLeft(int) override;
	void enqueueRigth(int) override;
	int denqueueLeft() override;
	int denqueueRigth() override;
	int left() override;
	int rigth() override;
	unsigned length() override;
	std::ostream&  dump(std::ostream&)override;
	virtual std::string getNombre()override;


};

