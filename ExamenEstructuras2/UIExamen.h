/*
 * UIExamen.h
 *
 *  Created on: Jun 21, 2015
 *      Author: daniel
 */

#ifndef UI_UIExamen_H_
#define UI_UIExamen_H_
#include "EstructuraDeExamen.h"
#include "BiQueue.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "QueueDinamica.h"
#include "QueueEstatica.h"
#include "StackDinamico.h"
#include "StackEstatico.h"


class UIExamen {
private:
	EstructuraDeExamen *estructura;

	int capturarEntero();
	void setEstructura(int pestructura);

public:
	UIExamen();
	virtual ~UIExamen();
	void init();
	void indicarEstructura();
	void mostrarMenu();
	bool ejecutarOpcion(int opcion);
};

#endif /* UI_UIExamen_H_ */
