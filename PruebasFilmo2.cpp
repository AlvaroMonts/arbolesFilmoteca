/*
 *  PruebasFilmo.cpp
 *  Created on: 2/3/2015
 *  Author: carolina
 */

#include "Filmoteca.h"
#include "Pelicula.h"
#include <iostream>

using namespace std;

void rellenarFilmoteca (Filmoteca &f);
void probarInsertar (Filmoteca &fi, Pelicula &p);
void probarBuscarPelicula (Filmoteca &f);
void probarIncorrectos (Filmoteca &f);

int main () {

	string separador = "----------------------\n";
	Filmoteca film ("MiFilmoteca");

	cout << "***********************************************" << endl;
	cout << "    PRUEBAS DE FILMOTECA" << endl;
	cout << "***********************************************" << endl;

	cout << "Prueba F1. Mostrar una filmoteca vacia" << endl;
	film.mostrarFilmoteca ();
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();

	cout << "Prueba F2. Insertar en condiciones normales y mostrar filmoteca: " << endl;
	rellenarFilmoteca (film);
	film.mostrarFilmoteca ();
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();

	cout << "Prueba F3. Insertar en condiciones excepcionales y mostrar filmoteca: " << endl;
	probarIncorrectos (film);
	film.mostrarFilmoteca ();
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();

	cout << "Prueba F4. BUSCAR PELICULA y mostrar filmoteca: " << endl;
	probarBuscarPelicula (film);
	cout << separador << endl;
	film.mostrarFilmoteca ();
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();
	cout << "------ FIN --------" << endl;
	return 0;
}

////////////////////////////////////////////////////



void probarInsertar (Filmoteca &fi, Pelicula &p) {
	bool resul = fi.insertarPelicula (p);
	if (resul)
		cout << " - " + p.getTitulo () + " (" + p.getDirector ()
				+ "): INSERTADO" << endl;
	else cout << " - " + p.getTitulo () + " (" + p.getDirector ()
			+ "): NO INSERTADO" << endl;
}

void probarBuscarPelicula (Filmoteca &f) {
	Pelicula p = f.buscarPelicula ("Zoiberg");
	cout << p.aCadena () << endl;
	Pelicula p2 = f.buscarPelicula ("Yoga");
	cout << p2.aCadena () << endl;
}

void rellenarFilmoteca (Filmoteca &f) {
	string ani = "animacion";
	string drama = "drama";
	string comedia = "comedia";
	string amor = "com. romantica";
	string docu = "documentales";
	Pelicula p1 ("Kunfu", "Bruce Lee", comedia, 1989);
	Pelicula p2 ("Cenicienta", "Almodovar", ani, 2015);
	Pelicula p3 ("Pinocho", "Bu�uel", drama, 1980);
	Pelicula p4 ("Yoga", "Emir", drama, 2010);
	Pelicula p5 ("Rambo", "Schwazzenegger", amor, 2001);
	Pelicula p6 ("Dormir es un deporte", "Indurain", docu, 1999);
	Pelicula p7 ("Azarosos", "Crowfunding", drama, 2006);
	Pelicula p8 ("Zoiberg el Robot", "C3PO", "sci fi", 2010);
	probarInsertar (f, p1);
	probarInsertar (f, p2);
	probarInsertar (f, p3);
	probarInsertar (f, p7);
	probarInsertar (f, p6);
	probarInsertar (f, p4);
	probarInsertar (f, p5);
	probarInsertar (f, p8);
}

void probarIncorrectos (Filmoteca &f) {
	// repetido
	Pelicula p1 ("Cenicienta", "Almodovar", "drama", 2015);
	probarInsertar (f, p1);
	// no valido
	Pelicula fantasma ("", "Almodovar", "drama", 1980);
	probarInsertar (f, fantasma);
}
