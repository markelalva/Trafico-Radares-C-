/*
 * Paso.h
 *
 *  Created on: 10 may. 2017
 *      Author: Markel
 */

#ifndef PASO_H_
#define PASO_H_
#include <sys/timeb.h>

namespace std {

class Paso {

int numeroPaso;
int numeroRadar;
char matricula[8];
int velocidadCoche;
struct timeb fecha;

public:
	Paso();
	virtual ~Paso();
};

} /* namespace std */

#endif /* PASO_H_ */
