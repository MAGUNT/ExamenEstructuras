#pragma once


class NodoS
{
	friend class StackDinamico;
	friend class QueueDinamica;

private:
	int dato;
	NodoS *next;

	NodoS();
	NodoS(int);
	NodoS(int , NodoS*);
};

