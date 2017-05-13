/*
 * funciones.cpp
 *
 *  Created on: 13 may. 2017
 *      Author: Markel
 */

#include "funciones.h"

namespace std {

funciones::funciones() {
	// TODO Auto-generated constructor stub

}

funciones::~funciones() {
	// TODO Auto-generated destructor stub
}





void funciones::mostrarRadar(Radar &radar){
	cout << radar.numeroRadar << endl;

}

void funciones::mostrarPaso(Paso &paso){
	cout <<paso.numeroPaso << endl;

}

Multa funciones::comprobarPaso(Paso &paso){


	//Comprobamos que la velocidad del coche sea mayor que el margen del radar

	//Sacamos de la BD la velocidad del radar
/*
	int velocidadRadar;
	int velocidadMargen;

	if(paso.velocidadCoche > velocidadMargen){
		Multa e = new Multa(paso.velocidadCoche, velocidadRadar, paso.matricula);
		return e;
	}
	else{
		Multa e = new Multa();
		return e;
	}
	*/

}
}
