/*
 * UIListas.h
 *
 *  Created on: Jun 21, 2015
 *      Author: daniel
 */

#ifndef UI_UILISTAS_H_
#define UI_UILISTAS_H_


class UIListas {
private:
	int capturarEntero();

public:
	UIListas();
	virtual ~UIListas();
	void init();
	void mostrarMenu();
	bool ejecutarOpcion(int opcion);
};

#endif /* UI_UILISTAS_H_ */
