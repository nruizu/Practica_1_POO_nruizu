//
// Created by Nico Ruiz on 9/14/2023.
//

#ifndef PRACTICA_1_POO_NRUIZU_LISTA_H
#define PRACTICA_1_POO_NRUIZU_LISTA_H

#include <cstddef>
#include "Nodo.h"

class Lista {
protected:
    Nodo *primero; //Es un puntero de tipo nodo
public:

    Lista();    //Constructor de la lista. Al crearse la lista se debe inicializar el puntero *primero (head)  de modo que apunte a NULL

    void crearLista();

    void crearListaSimple(Nodo *n);

    void insertarCabezaLista(int entrada);

    void insertarUltimo(int entrada);

    void insertarLista(int entrada);

    void insertarLista(Nodo *anterior, int entrada);

    Nodo *buscarListaDato(int destino);

    Nodo *buscarListaEvento(string destino);

    Nodo *buscarListaPrev(int destino);

    void eliminar(int entrada);

    Nodo *getUltimo();

    void visualizar();

    void visualizarRev();

    void visualizarEventoA();

    void visualizarEventoB();

    void visualizarSecuencia();

    bool esPrimo(int num);

    bool esCoprimo(int numA, int numC);

    string randomCientifico();
};


#endif //PRACTICA_1_POO_NRUIZU_LISTA_H
