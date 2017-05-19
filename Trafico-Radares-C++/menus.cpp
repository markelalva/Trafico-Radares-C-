/*
 * menus.cpp
 *
 *  Created on: 8 may. 2017
 *      Author: Markel
 */

#include "menus.h"
#include <iostream>

namespace std {

menus::menus() {
	// TODO Auto-generated constructor stub

	cout << "Se han generado los menus con exito" << endl;
}

menus::~menus() {
	// TODO Auto-generated destructor stub
}

int menus::MenuPrincipal() {
	//Menu principal
	int opcion = 0;
	cout << "Bienvenido al menu principal" << endl;
	cout << "Elija una opcion" << endl;
	cout << "1- Consultar estadisticas" << endl;
	cout << "2- Generar multas" << endl;
	cout << "3- Consultar multas" << endl;
	cout << "4- Imprimir multas" << endl;
	cout << "5- Salir" << endl;
	cin >> opcion;
	while (opcion < 1 || opcion > 5) {
		cout << "Introduce un valor valido" << endl;
		cin >> opcion;

	}

	return opcion;

}

int menus::MenuEstadisticas() {
	int opcion = 0;
	cout << "Estas en el menu de estadisticas" << endl;
	cout << "1- Consultar el radar mas transitado" << endl;
	cout << "2- Consultar el radar menos transitado" << endl;
	cout << "3- Consultar el radar con mas multas" << endl;
	cout << "4- Consultar el radar con menos multas" << endl;
	cout << "5- Consultar el usuario con mas multas" << endl;
	cout << "6- Consultar el usuario con menos multas" << endl;
	cout << "7- Consultar la mayor multa" << endl;
	cout << "8- Consultar el promedio de multas por radar" << endl;
	cout << "9- Salir" << endl;
	cin >> opcion;
	while (opcion < 1 || opcion > 9) {
		cout << "Introduce un valor valido" << endl;
		cin >> opcion;

	}

	return opcion;

}

int menus::MenuGenerarMulta(int numeroPasos, int numeroRadares, BaseDeDatos*bd,
		funciones *fun) {
	int opcion, numeroMultas;
	cout << "Esta en el menu de Generar Multas" << endl;
	numeroMultas = fun->comprobarPaso(numeroPasos, numeroRadares, bd);

	cout << "Todas las multas han sido generadas y almacenadas en la BD"
			<< endl;
	cout << "Presione 0 para volver al menu principal" << endl;
	cin >> opcion;

	while (opcion != 0) {
		cout << "ERROR! Presione 0 para volver al menu principal" << endl;
		cin >> opcion;
	}
	return numeroMultas;

}

int menus::ConsultarMultas() {
	int opcion = 0;
	cout << "Estas en el menu de consulta de multas" << endl;
	cout << "1- Ver el total de multas" << endl;
	cout << "2- Consultar las multas de un usuario" << endl;
	cout << "3- Consultar el total del dinero obtenido mediante multas" << endl;
	cout << "4- Consultar el total de puntos detraidos mediante multas" << endl;
	cout << "5- Salir" << endl;
	cin >> opcion;
	while (opcion < 1 || opcion > 5) {
		cout << "Introduce un valor valido" << endl;
		cin >> opcion;

	}

	return opcion;
}

void menus::verTotalMultas(int numeroMultas, funciones *f, BaseDeDatos *bd) {
	int opcion = 0;
	if (numeroMultas > 0) {
		cout << "Se muestran todas las multas que han sido puestas" << endl;
		//Llamamos a la funcion de mostrar todas las multas, pendiente de crear.

		f->mostrarMultas(numeroMultas, bd);

		cout << "Todas las multas han sido mostradas" << endl;
	} else {
		cout
				<< "No existe ninguna multa almacenada en la Base De Datos, generalas y vuelve a intentarlo"
				<< endl;
	}
	cout << "Presione 0 para volver al menu principal" << endl;
	cin >> opcion;

	while (opcion != 0) {
		cout << "ERROR! Presione 0 para volver al menu principal" << endl;
		cin >> opcion;
	}

}

void menus::verTotalDinero(BaseDeDatos *bd, int numeroMultas) {
	int opcion = 0;
	if (numeroMultas > 0) {
		int dinero = 0;

		dinero = bd->selectImporteTotal();

		cout << "Se han obtenido " << dinero << " euros. Mediante : "
				<< numeroMultas << " multas." << endl;
	} else {
		cout
				<< "No existe ninguna multa almacenada en la Base De Datos, generalas y vuelve a intentarlo"
				<< endl;
	}
	cout << "Presione 0 para volver al menu principal" << endl;
	cin >> opcion;

	while (opcion != 0) {
		cout << "ERROR! Presione 0 para volver al menu principal" << endl;
		cin >> opcion;
	}

}

void menus::verTotalPuntos(BaseDeDatos *bd, int numeroMultas) {
	int opcion = 0;
	if (numeroMultas > 0) {
		int puntos = 0;

		puntos = bd->selectPuntosTotal();

		cout << "Se han detraido " << puntos << " puntos. Mediante : "
				<< numeroMultas << " multas." << endl;
	} else {
		cout
				<< "No existe ninguna multa almacenada en la Base De Datos, generalas y vuelve a intentarlo"
				<< endl;
	}
	cout << "Presione 0 para volver al menu principal" << endl;
	cin >> opcion;

	while (opcion != 0) {
		cout << "ERROR! Presione 0 para volver al menu principal" << endl;
		cin >> opcion;
	}

}

void menus::verMultasUsuario(BaseDeDatos *bd, int numeroMultas) {
	int opcion = 0;
	if (numeroMultas > 0) {
		char *matricula = new char[8];
		cout << "Introduce la matricula a consultar" << endl;
		cin >> matricula;
		cout << matricula << endl;
		bd->verMultas(matricula);
	} else {
		cout
				<< "No existe ninguna multa almacenada en la Base De Datos, generalas y vuelve a intentarlo"
				<< endl;
	}
	cout << "Presione 0 para volver al menu principal" << endl;
	cin >> opcion;

	while (opcion != 0) {
		cout << "ERROR! Presione 0 para volver al menu principal" << endl;
		cin >> opcion;
	}

}
void menus::verPromedioMultas(BaseDeDatos *bd, int numeroRadares){
int numeroRadar =0;
int opcion;
cout <<"Introduce el numero de radar para obtener su promedio " << endl;
cin >> numeroRadar;

while(numeroRadar < 0 || numeroRadar >numeroRadares -1){
	cout << "No ha introducido un valor valido" << endl;
	cin >>numeroRadar;
}

int numeroMultas = bd->numeroMultas(numeroRadar);
int numeroPasos = bd->numeroPasos(numeroRadar);

double promedio = numeroPasos / numeroMultas;

cout << "El radar " << numeroRadar << " pone, de media, 1 multa cada " << promedio << " pasos." << endl;

cout << "Presione 0 para volver al menu principal" << endl;
cin >> opcion;

while (opcion != 0) {
	cout << "ERROR! Presione 0 para volver al menu principal" << endl;
	cin >> opcion;
}


}

void menus::verRadarMasTransitado(int numeroRadares,int  numeroPasos,BaseDeDatos *bd, funciones *f){
int opcion =0;
f->radarMasTransitado(numeroRadares, numeroPasos, bd);
cout << "Presione 0 para volver al menu principal" << endl;
cin >> opcion;

while (opcion != 0) {
	cout << "ERROR! Presione 0 para volver al menu principal" << endl;
	cin >> opcion;
}


}

void menus::verRadarMenosTransitado(int numeroRadares,int numeroPasos,BaseDeDatos *bd, funciones *f){
	int opcion =0;
	f->radarMenosTransitado(numeroRadares, numeroPasos, bd);
	cout << "Presione 0 para volver al menu principal" << endl;
	cin >> opcion;

	while (opcion != 0) {
		cout << "ERROR! Presione 0 para volver al menu principal" << endl;
		cin >> opcion;
	}

}

void menus::verRadarMasMultas(int numeroRadares, int numeroMultas, BaseDeDatos *bd, funciones *f){
	int opcion =0;
	f->radarMasMultas(numeroRadares, numeroMultas, bd);
	cout << "Presione 0 para volver al menu principal" << endl;
	cin >> opcion;

	while (opcion != 0) {
		cout << "ERROR! Presione 0 para volver al menu principal" << endl;
		cin >> opcion;
	}


}

void menus::verRadarMenosMultas(int numeroRadares,int numeroMultas,BaseDeDatos  *bd, funciones *f){
	int opcion =0;
	f->radarMenosMultas(numeroRadares, numeroMultas, bd);
	cout << "Presione 0 para volver al menu principal" << endl;
	cin >> opcion;

	while (opcion != 0) {
		cout << "ERROR! Presione 0 para volver al menu principal" << endl;
		cin >> opcion;
	}
}

void menus::verUsuarioMasMultas(int numeroUsuarios,  int numeroMultas,BaseDeDatos *bd, funciones *f){
	int opcion =0;
	f->usuarioMasMultas(numeroUsuarios, numeroMultas, bd);
	cout << "Presione 0 para volver al menu principal" << endl;
	cin >> opcion;

	while (opcion != 0) {
		cout << "ERROR! Presione 0 para volver al menu principal" << endl;
		cin >> opcion;
	}


}
void menus::verUsuarioMenosMultas(int numeroUsuarios,  int numeroMultas,BaseDeDatos *bd){


}

} /* namespace std */
