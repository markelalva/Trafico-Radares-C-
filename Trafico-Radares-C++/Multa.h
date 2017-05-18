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
	int numeroRadar;

public:

Multa();
Multa(int numeroMulta,int velocidadCoche, int velocidadRadar,char *matricula, int numeroRadar);
Multa(const Multa &multa);
virtual ~Multa();
void visualizarMulta();
int getnumeroMulta();
int getPuntos();
int getImporte();
int getVelocidadCoche();
int getvelocidadRadar();
int getnumeroRadar();
char * getMatricula();
void setnumeroMulta(int numeroMulta);
void setPuntos(int puntos);
void setImporte(int importe);
void setMatricula(char *matricula);
void setVelocidadCoche(int velocidadCoche);
void setVelocidadRadar(int velocidadRadar);
void setnumeroRadar(int numeroRadar);

};

} /* namespace std */

#endif /* MULTA_H_ */
