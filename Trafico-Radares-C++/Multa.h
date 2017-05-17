/*
 * Multa.h
 *
 *  Created on: 10 may. 2017
 *      Author: Markel
 */

#ifndef MULTA_H_
#define MULTA_H_
#include <string.h>
#include <iostream>

namespace std {

class Multa {
private:
	int numeroMulta;
	int velocidadCoche;
	int velocidadRadar;
	char *matricula;
	int importe;
	int puntos;

public:

Multa();
Multa(int numeroMulta,int velocidadCoche, int velocidadRadar,char *matricula);
Multa(const Multa &multa);
virtual ~Multa();
void visualizarMulta();
int getnumeroMulta();
int getPuntos();
int getImporte();
int getVelocidadCoche();
int getvelocidadRadar();
char * getMatricula();
void setnumeroMulta(int numeroMulta);
void setPuntos(int puntos);
void setImporte(int importe);
void setMatricula(char *matricula);
void setVelocidadCoche(int velocidadCoche);
void setVelocidadRadar(int velocidadRadar);


};

} /* namespace std */

#endif /* MULTA_H_ */
