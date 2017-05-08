/*
 * BaseDeDatos.h
 *
 *  Created on: 8 may. 2017
 *      Author: Markel
 */

#ifndef BASEDEDATOS_H_
#define BASEDEDATOS_H_

namespace std {

class BaseDeDatos {
private:
	char *nombreBD;
	sqlite3 *BaseDeDatos;
	sqlite3_stmt *stmt;
public:
	BaseDeDatos();
	virtual ~BaseDeDatos();
};

} /* namespace std */

#endif /* BASEDEDATOS_H_ */
