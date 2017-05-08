/*
 * menus.cpp
 *
 *  Created on: 8 may. 2017
 *      Author: Markel
 */

#include "menus.h"
#include <iostream>

namespace std {

menus::menus() {
	// TODO Auto-generated constructor stub

	cout <<"Se han generado los menus con exito" << endl;
}

menus::~menus() {
	// TODO Auto-generated destructor stub
}

void menus::MenuPrincipal(){
	//Menu principal
	cout << "Bienvenido al menu principal" << endl;
	cout << "Elija una opción" << endl;
	cout << "1- Consultar estadísticas" << endl;
	cout << "2- Generar multas" << endl;
	cout << "3- Consultar multas" << endl;
}

void menus::MenuEstadisticas(){
	cout << "Estas en el menu de estadisticas" << endl;
	cout << "1- Consultar el radar mas transitado" << endl;
	cout << "2- Consultar el radar menos transitado" << endl;
	cout << "3- Consultar el radar con mas multas" << endl;
	cout << "4- Consultar el radar con menos multas" << endl;
	cout << "5- Consultar el usuario con mas multas" << endl;
	cout << "6- Consultar el usuario con menos multas" << endl;
	cout << "7- Consultar la mayor multa" << endl;
	cout << "8- Consultar el promedio de multas por radar" << endl;

}

void menus::ConsultarMultas(){
	cout << "Estas en el menu de consulta de multas" << endl;
	cout << "1- Ver el total de multas" << endl;
	cout << "2- Consultar las multas de un usuario" << endl;
	cout << "3- Consultar el total del dinero obtenido mediante multas" << endl;
	cout << "4- Consultar el total de puntos detraidos mediante multas" << endl;

}


} /* namespace std */
