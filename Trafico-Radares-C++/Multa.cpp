/*
 * Multa.cpp
 *
 *  Created on: 10 may. 2017
 *      Author: Markel
 */

#include "Multa.h"

namespace std {
Multa::Multa() {
	this->numeroMulta = 0;
	this->importe = 0;
	this->matricula = new char[1];
	this->puntos = 0;
	this->velocidadCoche = 0;
	this->velocidadRadar = 0;
	this->numeroRadar =0;

}

Multa::Multa(int numeroMulta, int velocidadCoche, int velocidadRadar,
		char *matricula, int numeroRadar) {
	// TODO Auto-generated constructor stub
	this->numeroMulta = numeroMulta;
	this->matricula = new char[8];
	strcpy(this->matricula, matricula);
	this->velocidadCoche = velocidadCoche;
	this->velocidadRadar = velocidadRadar;
	this->numeroRadar = numeroRadar;
	switch (velocidadRadar) {
	case 80:
		if (velocidadCoche >= 81 && velocidadCoche <= 110) {
			this->importe = 100;
			this->puntos = 0;

		}
		if (velocidadCoche >= 111 && velocidadCoche <= 130) {
			this->importe = 300;
			this->puntos = 2;
		}
		if (velocidadCoche >= 131 && velocidadCoche <= 140) {
			this->importe = 400;
			this->puntos = 4;
		}
		if (velocidadCoche >= 141 && velocidadCoche <= 150) {
			this->importe = 500;
			this->puntos = 6;
		}
		if (velocidadCoche >= 151) {
			this->importe = 600;
			this->puntos = 6;

		}
		break;
	case 100:
		if (velocidadCoche >= 101 && velocidadCoche <= 130) {
			this->importe = 100;
			this->puntos = 0;
		}
		if (velocidadCoche >= 131 && velocidadCoche <= 150) {
			this->importe = 300;
			this->puntos = 2;
		}
		if (velocidadCoche >= 151 && velocidadCoche <= 160) {
			this->importe = 400;
			this->puntos = 4;
		}
		if (velocidadCoche >= 161 && velocidadCoche <= 170) {
			this->importe = 500;
			this->puntos = 6;
		}
		if (velocidadCoche >= 171) {
			this->importe = 600;
			this->puntos = 6;
		}
		break;
	case 120:
		if (velocidadCoche >= 121 && velocidadCoche <= 150) {
			this->importe = 100;
			this->puntos = 0;
		}
		if (velocidadCoche >= 151 && velocidadCoche <= 170) {
			this->importe = 300;
			this->puntos = 2;
		}
		if (velocidadCoche >= 171 && velocidadCoche <= 180) {
			this->importe = 400;
			this->puntos = 4;
		}
		if (velocidadCoche >= 181 && velocidadCoche <= 190) {
			this->importe = 500;
			this->puntos = 6;
		}
		if (velocidadCoche >= 191) {
			this->importe = 600;
			this->puntos = 6;
		}
		break;
	}

}

Multa::~Multa() {
	// TODO Auto-generated destructor stub
	delete[] matricula;
}

Multa::Multa(const Multa &multa) {
	this->numeroMulta = multa.numeroMulta;
	this->importe = multa.importe;
	this->puntos = multa.puntos;
	this->matricula = new char[strlen(multa.matricula) + 1];
	strcpy(this->matricula, multa.matricula);
	this->velocidadRadar = multa.velocidadRadar;
	this->velocidadCoche = multa.velocidadCoche;
	this->numeroRadar = multa.numeroRadar;

}

void Multa::visualizarMulta() {
	cout << "Multa numero: " << this->numeroMulta
			<< " Se ha puesto una multa a " << this->matricula
			<< " con un importe de :" << this->importe
			<< " y un total de puntos de: " << this->puntos << " .Por circular a "
			<< this->velocidadCoche << " teniendo la velocidad limitada a "
			<< this->velocidadRadar << " por el radar: " << this->numeroRadar << endl;
	;

}

int Multa::getnumeroMulta() {
	return this->numeroMulta;
}
char* Multa::getMatricula() {
	return this->matricula;
}

int Multa::getPuntos() {
	return this->puntos;

}
int Multa::getImporte() {
	return this->importe;
}
int Multa::getVelocidadCoche(){
	return this->velocidadCoche;
}
int Multa::getvelocidadRadar(){
	return this->velocidadRadar;
}
int Multa::getnumeroRadar(){
	return this->numeroRadar;
}

void Multa::setImporte(int importe) {
	this->importe = importe;
}

void Multa::setPuntos(int puntos) {
	this->puntos = puntos;
}

void Multa::setnumeroMulta(int numeroMulta) {
	this->numeroMulta = numeroMulta;
}
void Multa::setMatricula(char *matricula) {
	this->matricula = new char[8];
	strcpy(this->matricula, matricula);
}

void Multa::setVelocidadCoche(int velocidadCoche) {
	this->velocidadCoche = velocidadCoche;
}

void Multa::setVelocidadRadar(int velocidadRadar) {
	this->velocidadRadar = velocidadRadar;
}

void Multa::setnumeroRadar(int numeroRadar){
	this->numeroRadar = numeroRadar;
}
}

/* namespace std */
