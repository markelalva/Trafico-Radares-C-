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
	cout <<"Informacion del paso: Numero "<< paso.numeroPaso << " el radar : " << paso.numeroRadar<< " y la matricula del coche es " << paso.matricula << endl;

}

int funciones::comprobarPaso(int numeroPasos, int numeroRadares, BaseDeDatos *bd){

Paso *listaPasos = bd->selectArrayPasos(numeroPasos);
Multa **listaMultas =(Multa**) malloc(sizeof(Multa*) * numeroPasos);
int contadorMultas =0;

for(int i =0; i<numeroPasos; i++){
Radar *e = bd->selectRadar(listaPasos[i].numeroRadar);
//cout << e->numeroRadar << " Tiene una velocidad de: " << e->velocidad << " y un margen " << e->margen << endl;
if(listaPasos[i].velocidadCoche > e->margen){
	//Generamos una multa
	Multa *mult = new Multa(contadorMultas,listaPasos[i].velocidadCoche, e->velocidad, listaPasos[i].matricula);
	listaMultas[contadorMultas] = mult;
	contadorMultas++;
}



}

//Una vez hayamos encontrado todas las multas, las cargamos en la BD

for(int i =0; i<contadorMultas; i++){
//cout << listaMultas[i]->getMatricula() << endl;
//listaMultas[i]->visualizarMulta();
bd->insertMulta(listaMultas[i]->getnumeroMulta(), listaMultas[i]->getMatricula(), listaMultas[i]->getImporte(), listaMultas[i]->getPuntos());

}
return contadorMultas++;
}

void funciones::mostrarMultas(int numeroMultas, BaseDeDatos *bd){
	cout <<"Que pasa toreteg" << endl;
	for(int i =0; i<=numeroMultas; i++){
	Multa *e = bd->selectMulta(i);
	e->visualizarMulta();

}
}
}
