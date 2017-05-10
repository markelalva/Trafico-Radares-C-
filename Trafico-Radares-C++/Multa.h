/*
 * Multa.h
 *
 *  Created on: 10 may. 2017
 *      Author: Markel
 */

#ifndef MULTA_H_
#define MULTA_H_

namespace std {

class Multa {

char *matricula;
int importe;
int puntos;

public:
	Multa();
	Multa(Multa multa);
	virtual ~Multa();
};

} /* namespace std */

#endif /* MULTA_H_ */
