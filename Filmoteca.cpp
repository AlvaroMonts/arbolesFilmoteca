/*
 * Filmoteca.cpp
 *
 */

#include "Filmoteca.h"

Filmoteca::Filmoteca(string prop) {
	propietario = prop;
	raiz = NULL;
}
void Filmoteca::destruir(pNodo &nodo) {
	if (nodo != NULL) {
		destruir(nodo->iz);
		destruir(nodo->de);
		delete nodo;
		nodo = NULL;
	}
}
Filmoteca::~Filmoteca() {
	destruir(raiz);
}

bool Filmoteca::estaVacia() {
	return raiz == NULL;
}

string Filmoteca::getPropietario() {
	return propietario;
}

void Filmoteca::setPropietario(string p) {
	propietario = p;
}

bool Filmoteca::insertarPelicula(Pelicula peli) {
	bool resul = false;
	//COMPLETAR
	resul = insertarPeliculaAux(raiz, peli);
	return resul;
}

bool insertarPeliculaAux(pNodo &aux, Pelicula peli) {
	bool resul = false;
	cout << "INSERTANDO::" << peli.getTitulo() << endl;
	if (aux == NULL) {
		aux = new pNodo(peli.getTitulo());
		resul = true;
	} else if (peli.getTitulo() != aux->info.getTitulo()) {
		if (peli.getTitulo() < aux->info.getTitulo())
			insertarPeliculaAux(aux->iz, peli);
		else
			insertarPeliculaAux(aux->de, peli);
		resul = true;
	} else {
		cout << "Error, la peli ya existe" << endl;
	}

return resul:
}

void Filmoteca::quitarSucesor(pNodo nodoQuitar, pNodo &sucesor) {
pNodo hijo;

if (sucesor->de == NULL) {
	hijo = sucesor->iz;
	nodoQuitar->info = sucesor->info;
	delete sucesor;
	sucesor = hijo;
} else
	quitarSucesor(nodoQuitar, sucesor->de);
}

bool Filmoteca::elimina(pNodo &nodo, string t) {
pNodo hijo;
bool resul = false;

if (nodo != NULL) {
	if (t == nodo->info.getTitulo()) {
		if ((nodo->iz == NULL) || (nodo->de == NULL)) {
			if (nodo->iz == NULL)
				hijo = nodo->de;
			else
				hijo = nodo->iz;
			delete nodo;
			nodo = hijo;
		} else
			quitarSucesor(nodo, nodo->iz);
		resul = true;
	} else if (t < nodo->info.getTitulo())
		resul = elimina(nodo->iz, t);
	else
		resul = elimina(nodo->de, t);
}
return resul;
}

bool Filmoteca::eliminarPelicula(string titulo) {
return elimina(raiz, titulo);
}

Pelicula Filmoteca::buscarPelicula(string t) {
Pelicula p;
//COMPLETAR
return p;
}

void Filmoteca::mostrarFilmoteca() {
//COMPLETAR
pNodo hijo;
pNodo aux = raiz;
string sol = "HOLAAAAAAAAAAA";
if (aux != NULL) {
	if ((aux->iz == NULL) || (aux->de == NULL)) {
		if (aux->iz == NULL)
			hijo = aux->de;
		else
			hijo = aux->iz;
		delete aux;
		aux = hijo;
	} else
		quitarSucesor(aux, aux->iz);
	sol += aux->info.getTitulo() + ",";
}
cout << sol << endl;
}

