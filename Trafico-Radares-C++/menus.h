/*
 * menus.h
 *
 *  Created on: 8 may. 2017
 *      Author: Markel
 */

#ifndef MENUS_H_
#define MENUS_H_
#include "BaseDeDatos.h"
#include "funciones.h"


namespace std {

class menus {
public:
	menus();
	virtual ~menus();
	int MenuPrincipal();
	int MenuEstadisticas();
	int MenuGenerarMulta(int numeroPasos, int numeroRadares, BaseDeDatos*bd, funciones *fun);
	int ConsultarMultas();
	int verTotalMultas(int numeroMultas, funciones *f, BaseDeDatos *bd);
	int verTotalDinero();
	int verTotalPuntos();
};

} /* namespace std */

#endif /* MENUS_H_ */
