#pragma once
class NodoD
{
	friend class BiQueue;


private:
	int dato;
	NodoD *next;
	NodoD *prev;

	NodoD();
	NodoD(int);
	NodoD(int, NodoD*prev, NodoD*next);
};

