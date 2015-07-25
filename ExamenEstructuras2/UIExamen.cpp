/*
 * UIExamen.cpp
 *
 *  Created on: Jun 21, 2015
 *      Author: daniel
 */
#include "UIExamen.h"
#include <iostream>
#include <sstream>

UIExamen::UIExamen() {

}

UIExamen::~UIExamen() {
}

int main() {
	UIExamen ui = new UIExamen();
	ui.init();
	return 0;
}

void UIExamen::init() {
	bool continuar = true;

	do {
		this->indicarEstructura();
		this->mostrarMenu();
		int opcion = this->capturarEntero();
		continuar = this->ejecutarOpcion(opcion);
	} while (continuar);
}

bool UIExamen::ejecutarOpcion(int opcion) {
	int carnetExistente;
	int indice;
	tEstudiante* estudiante;
	bool continuar = true;

	switch (opcion){
		case 1:	// inserta inicio
			crearEstudiante(estudiante);
			listaDoble->insertarInicio(estudiante);
			break;

		case 2:	// inserta final
			crearEstudiante(estudiante);
			listaDoble->insertar(estudiante);
			break;

		case 3:	// inserta antes de
			crearEstudiante(estudiante);
			std::cout << "Insertar nuevo estudiante antes del estudiante con carnet: " << std::endl;
			carnetExistente = capturarEntero();
			listaDoble->insertarAntesDe(estudiante, carnetExistente);
			break;

		case 4:	// inserta despues de
			crearEstudiante(estudiante);
			std::cout << "Insertar nuevo estudiante despues del estudiante con carnet: " << std::endl;
			carnetExistente = capturarEntero();
			listaDoble->insertarDespuesDe(estudiante, carnetExistente);
			break;

		case 5:	// inserta ascendente
			crearEstudiante(estudiante);
			listaDoble->insertarInicio(estudiante);
			break;

		case 6:	// inserta descendente
			crearEstudiante(estudiante);
			listaDoble->insertar(estudiante);
			break;

		case 7:	// inserta index of
			crearEstudiante(estudiante);
			std::cout <<
					"Digite la posicion del estudiante donde se va a insertar un estudiante nuevo"
					<< std::endl;
			indice = capturarEntero();
			listaDoble->insertarIndex(estudiante, indice);
			break;

		case 8:	// elimina
			std::cout << "Digite el carnet del estudiante que se va a eliminar" << std::endl;
			carnetExistente = capturarEntero();
			listaDoble->eliminar(carnetExistente);
			break;

		case 9:	// elimina index
			std::cout << "Digite el posicion del estudiante que se va a eliminar" << std::endl;
			indice = capturarEntero();
			listaDoble->eliminarIndex(indice);
			break;

		case 10: // vaciar
			listaDoble->vaciarLista();
			break;

		case 11: // esta vacia?
			std::cout << "Vacia: " << (listaDoble->vacia() == true? "Si":"No");
			break;

		case 12: // obtener dato
			std::cout << "Digite el carnet del estudiante" << std::endl;
			carnetExistente = capturarEntero();
			estudiante = listaDoble->obtenerDato(carnetExistente);
			if (estudiante != 0) {
				std::cout << estudiante->getDatos() << std::endl;
			} else {
				std::cout << "No se encontro un estudiante con ese carnet" << std::endl;
			}
			break;

		case 13: // obtener dato index
			std::cout << "Digite el indice" << std::endl;
			indice = capturarEntero();
			estudiante = listaDoble->obtenerDatoIndex(indice);
			if (estudiante != 0) {
				std::cout << estudiante->getDatos() << std::endl;
			} else {
				std::cout << "No se encontro un estudiante en ese indice" << std::endl;
			}
			break;

		case 14: // modificar dato
			crearEstudiante(estudiante);
			std::cout << "Ingrese el carnet del estudiante existente" << std::endl;
			carnetExistente = capturarEntero();
			listaDoble->modificarDato(carnetExistente, estudiante);
			break;

		case 15: // modificar dato indice
			crearEstudiante(estudiante);
			std::cout << "Digite indice del estudiante en la lista" << std::endl;
			indice = capturarEntero();
			listaDoble->modificarDatoIndex(indice, estudiante);
			break;

		case 16: // mostrar lista
			listaDoble->mostrarLista();
			break;

		case 17: // Tama�o de la lista
			std::cout << "El largo es de: " << listaDoble->getLargo();
			break;

		case 18: //	Salir del programa
			continuar = false;
			break;

		default:
			continuar = false;
	}
	return continuar;
}

void UIExamen::indicarEstructura() {
	int numEstructra = 0;

	std::cout << "" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "" << std::endl;

	std::cout << "Seleccione una estructura a utilizar:" << std::endl;
	std::cout << "1.  Cola estatica" << std::endl;
	std::cout << "2.  Cola dinamica" << std::endl;
	std::cout << "3.  Pila estatica" << std::endl;
	std::cout << "4.  Pila dinamica" << std::endl;
	std::cout << "5.  Bicola" << std::endl;
	std::cout << "6.  Cola prioridades" << std::endl;

	numEstructra = this->capturarEntero();
	setEstructura(numEstructra);
}

void UIExamen::mostrarMenu() {
	std::cout << "" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "" << std::endl;

	std::cout << "Seleccione una opcion:" << std::endl;
	std::cout << "1.  Indicar estructura" << std::endl;
	std::cout << "2.  Insertar numero al final" << std::endl;
	std::cout << "3.  Inserta numero a la derecha " << std::endl;
	std::cout << "4.  Inserta numero a la izquierda " << std::endl;
	std::cout << "5.  Remover numero" << std::endl;
	std::cout << "6.  Remover numero a la derecha" << std::endl;
	std::cout << "7.  Remover numero a la izquierda" << std::endl;
	std::cout << "8. Vaciar lista" << std::endl;
	std::cout << "9. Esta vacia?" << std::endl;
	std::cout << "10. Obtener numero" << std::endl;
	std::cout << "11. Mostrar numeros en la lista" << std::endl;
	std::cout << "12. Salir de la aplicacion" << std::endl;
}

void UIExamen::setEstructura(int pestructura) {
	switch (pestructura){
		case 1:	
			estructura = new QueueEstatica();
			break;

		case 2:	
			estructura = new QueueDinamica();
			break;

		case 3:
			estructura = new StackEstatico();
			break;

		case 4:
			estructura = new StackDinamico();
			break;

		case 5:
			estructura = new BiQueue();
			break;

		case 6:	// inserta descendente
			estructura = new PriorityQueue();
			break;

		default:
			estructura = null;
	}
}

int UIExamen::capturarEntero() {
	std::string linea;
	int opcion;

	while(std::getline(std::cin, linea)
		&& !(std::istringstream{linea} >> opcion)) {

		std::cerr << "Caracter invalido, trate de nuevo" << std::endl;
	}

	return opcion;
}


