/*
 * main.cpp
 *
 *  Created on: 7 may. 2017
 *      Author: Markel
 */
#include <iostream>
#include "menus.h"
#include "BaseDeDatos.h"
#include <stdlib.h>
#include <stdio.h>
#include "estructuras.h"
#include "funciones.h"
using namespace std;
FILE *radares;
FILE *pasos;
Radar *listaRadares;
Paso *listaPasos;
funciones *f;
int numeroRadares;
int numeroPasos;
int main(){

//Cargamos la BD
BaseDeDatos *bd = new BaseDeDatos("Base de Datos");

//Cargamos los radares en un array desde el fichero
f = new funciones();

radares = fopen("radares.dat", "rb");
numeroRadares = fgetc(radares);
listaRadares= new Radar[numeroRadares];

fread(listaRadares, sizeof(Radar), numeroRadares, radares);

//Cargamos los pasos

pasos = fopen("pasos.dat", "rb");
numeroPasos = fgetc(pasos);
listaPasos= new Paso[numeroPasos];

fread(listaPasos, sizeof(Paso), numeroPasos, pasos);


bd->abrirBD(); //Abrimos la BD
//Borramos las Tablas anteriores
bd->borrarTablaPasos();
bd->borrarTablaRadares();

//Creamos las tablas
bd->crearTablaPasos();
bd->crearTablaRadares();

//Cargamos los radares y los pasos en la BD
	//Radares
int i;
/*for( i=0; i<numeroRadares; i++){
bd->insertRadar(listaRadares[i].numeroRadar, listaRadares[i].velocidad, listaRadares[i].margen);
}
	//Pasos
for(i=0; i<numeroPasos; i++){
bd->insertPaso(listaPasos[i].numeroPaso, listaPasos[i].numeroRadar, listaPasos[i].matricula, listaPasos[i].velocidadCoche);
}
*/
char *matricula  = new char [8];
matricula= "99393FBF";
bd->insertPaso(10, 12, matricula, 140);
//Mostramos
menus *m = new menus();
int opcion;
do{
opcion = m->MenuPrincipal();


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
