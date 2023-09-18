//
// Created by Nico Ruiz on 9/14/2023.
//

#ifndef PRACTICA_1_POO_NRUIZU_NODO_H
#define PRACTICA_1_POO_NRUIZU_NODO_H
#include <iostream>
using namespace std;

class Nodo {
protected:
    int dato;
    string cientific;
    string evento;
    Nodo *enlaceNext;
    Nodo *enlacePrev;
public:
    Nodo(int t);

    Nodo(int p, Nodo *n, string event, string cientifico);

    int  getDataNodo() const;

    Nodo *getEnlaceNodoNext() const;

    Nodo *getEnlaceNodoPrev();

    string getEvento();

    string getCientific();

    void setEnlaceNext(Nodo *stge);

    void setEnlacePrev(Nodo *prev);

    void setEvento(string event);

    void setCientifico(string cient);
};


#endif //PRACTICA_1_POO_NRUIZU_NODO_H
