/*
 * Multa.cpp
 *
 *  Created on: 10 may. 2017
 *      Author: Markel
 */

#include "Multa.h"

namespace std {

Multa::Multa() {
	// TODO Auto-generated constructor stub
	this->importe =0;
	this->puntos = 0;
	this->matricula = new char [1];

}

Multa::~Multa() {
	// TODO Auto-generated destructor stub
	delete [] matricula;
}

Multa::Multa(Multa &multa){
	this->importe = multa.importe;
	this->puntos = multa.puntos;
	this->matricula = new char [strlen(multa.matricula) +1];
	strcpy(this->matricula, multa.matricula);

}

void Multa::visualizarMulta(){
	cout << "Se ha puesto una multa a " << this->matricula << " con un importe de :" << this->importe << " y un total de puntos de: " << this->puntos << endl;

}

} /* namespace std */
