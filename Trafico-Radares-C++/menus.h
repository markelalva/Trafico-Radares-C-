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
	void verTotalMultas(int numeroMultas, funciones *f, BaseDeDatos *bd);
	void verTotalDinero(BaseDeDatos *bd, int numeroMultas);
	void verTotalPuntos(BaseDeDatos *bd, int numeroMultas);
	void verMultasUsuario(BaseDeDatos *bd, int numeroMultas);
	void verPromedioMultas(BaseDeDatos *bd, int numeroRadares);
	void verRadarMasTransitado(int numeroRadares, int numeroPasos, BaseDeDatos *bd, funciones *f);
	void verRadarMenosTransitado(int numeroRadares, int numeroPasos, BaseDeDatos *bd, funciones *f);
	void verRadarMasMultas(int numeroRadares, int numeroMultas, BaseDeDatos *bd);
	void  verRadarMenosMultas(int numeroRadares, int numeroMultas, BaseDeDatos *bd);
};

} /* namespace std */

#endif /* MENUS_H_ */
