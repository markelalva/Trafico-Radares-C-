/*
 * main.cpp
 *
 *  Created on: 7 may. 2017
 *      Author: Markel
 */
#include <iostream>
#include "menus.h"
using namespace std;

int main(){
menus *m = new menus();

int opcion = m->MenuPrincipal();

do{
switch (opcion){
int opcion1;
int opcion2;
int opcion3;
case 1:
opcion1 = m->MenuEstadisticas();
break;

case 2:
//opcion 2 = m->MenuGenerarMulta();
break;

case 3:
opcion3 = m->ConsultarMultas();
break;



}
} while (opcion !=4);

cout <<"Gracias por usar el programa, esperemos le haya sido util" << endl;

return 0;
}

 /* namespace std */
