/*
 * menus.h
 *
 *  Created on: 8 may. 2017
 *      Author: Markel
 */

#ifndef MENUS_H_
#define MENUS_H_

namespace std {

class menus {
public:
	menus();
	virtual ~menus();
	int MenuPrincipal();
	int MenuEstadisticas();
	int MenuGenerarMulta();
	int ConsultarMultas();
};

} /* namespace std */

#endif /* MENUS_H_ */
