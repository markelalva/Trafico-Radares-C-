/*
 * main.cpp
 *
 *  Created on: 7 may. 2017
 *      Author: Markel
 */
#include <iostream>
#include "menus.h"
#include "BaseDeDatos.h"
using namespace std;

int main(){
menus *m = new menus();
//Cargamos la BD


BaseDeDatos *bd = new BaseDeDatos("Base de Datos");
bd->abrirBD(); //Probar
bd->cerrarBD(); //Probar

int opcion = m->MenuPrincipal();

do{
switch (opcion){
int opcion1;
int opcion2;
case 1:
opcion1 = m->MenuEstadisticas();
switch (opcion1){

case 1:
	break;
case 2:
	break;
case 3:
	break;
case 4:
	break;
case 5:
	break;
case 6:
	break;
case 7:
	break;
case 8:
	break;
case 9:
	opcion = 0; //Para volver al menu principal
	break;
}
break;

case 2:
m->MenuGenerarMulta();
break;

case 3:
opcion2 = m->ConsultarMultas();
switch(opcion2){
case 1:
	break;
case 2:
	break;
case 3:
	break;
case 4:
	break;
case 5:
	opcion =0;
	break;
}
break;



}
} while (opcion !=4);

cout <<"Gracias por usar el programa, esperemos le haya sido util" << endl;

return 0;
}

 /* namespace std */
