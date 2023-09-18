//
// Created by Nico Ruiz on 9/14/2023.
//

#include "Nodo.h"
#include <cstddef>


Nodo::Nodo(int t){
    dato = t;
    enlaceNext = 0; //Null en c++
    enlacePrev = 0;
}

Nodo::Nodo(int d, Nodo *n, string event, string cientifico){
    dato = d;
    cientific = cientifico;
    evento = event;
    enlaceNext = n;
    enlacePrev = NULL;
}

int Nodo::getDataNodo() const{
    return dato;
}

Nodo *Nodo::getEnlaceNodoNext() const{
    return enlaceNext;
}

Nodo *Nodo::getEnlaceNodoPrev(){
    return enlacePrev;
}

string Nodo::getEvento(){
    return evento;
}

string Nodo::getCientific() {
    return cientific;
}

void Nodo::setCientifico(string cient){
    cientific = cient;
}

void Nodo::setEnlaceNext(Nodo* stge){
    enlaceNext = stge;
}

void Nodo::setEnlacePrev(Nodo* prev){
    enlacePrev = prev;
}

void Nodo::setEvento(string event){
    evento = event;
}
