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

int menus::MenuPrincipal(){
	//Menu principal
	int opcion =0;
	cout << "Bienvenido al menu principal" << endl;
	cout << "Elija una opci�n" << endl;
	cout << "1- Consultar estad�sticas" << endl;
	cout << "2- Generar multas" << endl;
	cout << "3- Consultar multas" << endl;
	cout << "4- Salir" << endl;
	cin >> opcion;
	while (opcion <1 || opcion >4){
		cout << "Introduce un valor valido" << endl;
		cin >> opcion;

	}

	return opcion;

}

int menus::MenuEstadisticas(){
	int opcion =0;
	cout << "Estas en el menu de estadisticas" << endl;
	cout << "1- Consultar el radar mas transitado" << endl;
	cout << "2- Consultar el radar menos transitado" << endl;
	cout << "3- Consultar el radar con mas multas" << endl;
	cout << "4- Consultar el radar con menos multas" << endl;
	cout << "5- Consultar el usuario con mas multas" << endl;
	cout << "6- Consultar el usuario con menos multas" << endl;
	cout << "7- Consultar la mayor multa" << endl;
	cout << "8- Consultar el promedio de multas por radar" << endl;
	cout << "9- Salir" << endl;
	cin >> opcion;
	while (opcion <1 || opcion >9){
		cout << "Introduce un valor valido" << endl;
		cin >> opcion;

	}

	return opcion;

}

void menus::MenuGenerarMulta(){
	int opcion;
	cout << "Esta en el menu de Generar Multas" << endl;
	//AQUI VA LA FUNCIONALIDAD (PENDIENTE)



	cout << "Todas las multas han sido generadas y almacenadas en la BD" << endl;
	cout << "Presione 0 para volver al menu principal" << endl;
	cin >> opcion;

	while (opcion !=0){
	cout << "ERROR! Presione 0 para volver al menu principal" << endl;
	cin >> opcion;
	}


}

int menus::ConsultarMultas(){
	int opcion =0;
	cout << "Estas en el menu de consulta de multas" << endl;
	cout << "1- Ver el total de multas" << endl;
	cout << "2- Consultar las multas de un usuario" << endl;
	cout << "3- Consultar el total del dinero obtenido mediante multas" << endl;
	cout << "4- Consultar el total de puntos detraidos mediante multas" << endl;
	cout << "5- Salir" << endl;
	cin >> opcion;
	while (opcion <1 || opcion >5){
		cout << "Introduce un valor valido" << endl;
		cin >> opcion;

	}

	return opcion;
}



} /* namespace std */
