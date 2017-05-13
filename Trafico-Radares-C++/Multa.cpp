/*
 * Multa.cpp
 *
 *  Created on: 10 may. 2017
 *      Author: Markel
 */

#include "Multa.h"

namespace std {

Multa::Multa(int velocidadcoche, int velocidadradar,char *matricula) {
    // TODO Auto-generated constructor stub
    this->importe =0;
    this->puntos = 0;
    this->matricula = new char [8];
    strcpy(this->matricula, matricula);
    switch(velocidadradar){
    case 80:
        if(velocidadcoche >= 81 && velocidadcoche <= 110){
        	this->importe = 100;
        	this->puntos =0;
        }
        if(velocidadcoche >= 111 && velocidadcoche <= 130){
        	this->importe = 300;
        	this->puntos =2;
        }
        if(velocidadcoche >= 131 && velocidadcoche <= 140){
        	this->importe = 400;
        	this->puntos =4;
        }
        if(velocidadcoche >= 141 && velocidadcoche <= 150){
        	this->importe = 500;
        	this->puntos =6;
        }
        if(velocidadcoche >= 151){
        	this->importe = 600;
        	this->puntos =6;

        }
        break;
    case 100:
        if(velocidadcoche >= 101 && velocidadcoche <= 130){
        	this->importe = 100;
        	this->puntos =0;
        }
        if(velocidadcoche >= 131 && velocidadcoche <= 150){
        	this->importe = 300;
        	this->puntos =2;
        }
        if(velocidadcoche >= 151 && velocidadcoche <= 160){
        	this->importe = 400;
        	this->puntos =4;
        }
        if(velocidadcoche >= 161 && velocidadcoche <= 170){
        	this->importe = 500;
        	this->puntos =6;
        }
        if(velocidadcoche >= 171){
        	this->importe = 600;
        	this->puntos =6;
        }
        break;
    case 120:
        if(velocidadcoche >= 121 && velocidadcoche <= 150){
        	this->importe = 100;
        	this->puntos =0;
        }
        if(velocidadcoche >= 151 && velocidadcoche <= 170){
        	this->importe = 300;
        	this->puntos =2;
        }
        if(velocidadcoche >= 171 && velocidadcoche <= 180){
        	this->importe = 400;
        	this->puntos =4;
        }
        if(velocidadcoche >= 181 && velocidadcoche <= 190){
        	this->importe = 500;
        	this->puntos =6;
        }
        if(velocidadcoche >= 191){
        	this->importe = 600;
        	this->puntos =6;
        }
        break;
    }

}

Multa::~Multa() {
	// TODO Auto-generated destructor stub
	delete [] matricula;
}

Multa::Multa( const Multa &multa){
	this->importe = multa.importe;
	this->puntos = multa.puntos;
	this->matricula = new char [strlen(multa.matricula) +1];
	strcpy(this->matricula, multa.matricula);

}

void Multa::visualizarMulta(){
	cout << "Se ha puesto una multa a " << this->matricula << " con un importe de :" << this->importe << " y un total de puntos de: " << this->puntos << endl;

}

} /* namespace std */
