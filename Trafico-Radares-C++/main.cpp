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
FILE *usuarios;

Paso *listaPasos;
Usuario *listaUsuarios;
funciones *f;
int numeroRadares;
int numeroPasos;
int numeroMultas;
int numeroUsuarios;
int main(){

//Cargamos la BD
BaseDeDatos *bd = new BaseDeDatos("Base de Datos");

//Cargamos los radares en un array desde el fichero
f = new funciones();

bd->abrirBD(); //Abrimos la BD
//Borramos las Tablas anteriores
bd->borrarTablaPasos();
bd->borrarTablaRadares();
bd->borrarTablaMultas();
bd->borrarTablaUsuarios();

//Creamos las tablas
bd->crearTablaPasos();
bd->crearTablaRadares();
bd->crearTablaMultas();
bd->crearTablaUsuarios();

//Cargamos los radares y los pasos en la BD
	//Radares

numeroRadares = f->cargarRadares(bd, radares);
	//Pasos
numeroPasos = f->cargarPasos(bd,pasos);
//Usuarios
numeroUsuarios = f->cargarUsuarios(bd, usuarios);

numeroMultas =0;

int opcion1 =0;
int opcion2 =0;
//Mostramos
menus *m = new menus();
int opcion;
do{
opcion = m->MenuPrincipal();


switch (opcion){

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
numeroMultas = m->MenuGenerarMulta(numeroPasos, numeroRadares, bd,f);
break;

case 3:
do{
opcion2 = m->ConsultarMultas();
switch (opcion2){
case 1:
	m->verTotalMultas(numeroMultas, f, bd);
	break;
case 2:
	m->verMultasUsuario(bd, numeroMultas);
	break;
case 3:
	m->verTotalDinero(bd, numeroMultas);
	break;
case 4:
	m->verTotalPuntos(bd, numeroMultas);
	break;
case 5:
	opcion =0;
	break;
}
} while(opcion2!=5);
break;




}
} while (opcion !=4);

cout <<"Gracias por usar el programa, esperemos le haya sido util" << endl;

return 0;
}

 /* namespace std */
