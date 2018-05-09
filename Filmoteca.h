/*
 * Filmoteca.h
 *
 * Created by Carolina Gallardo.
 * Copyright (c) 2016. All rights reserved.
 */

#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Pelicula.h"

#ifndef NODOF_H_
#define NODOF_H_

class NodoF {

public:
	Pelicula info;
	NodoF *iz, *de;

	NodoF (Pelicula peli) {
		info = peli;
		iz = de = NULL;
	}
};

#endif /* NODOF_H_ */


#ifndef FILMOTECA_H_
#define FILMOTECA_H_


typedef NodoF *pNodo;

class Filmoteca {

public:
	Filmoteca (string prop);
	~Filmoteca ();

	string getPropietario ();
	void setPropietario (string prop);

	bool estaVacia ();
	bool insertarPelicula (Pelicula l);
	bool eliminarPelicula (string titulo);
	Pelicula buscarPelicula (string titulo);
	bool elimina(pNodo &nodo, string t);
	void quitarSucesor(pNodo nodoQuitar, pNodo &sucesor);
	void mostrarFilmoteca ();

private:
	string propietario;
	pNodo raiz;
	void destruir (pNodo &nodo);

};

#endif /* FILMOTECA_H_ */
