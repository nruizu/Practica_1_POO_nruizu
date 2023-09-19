//
// Created by Nico Ruiz on 9/14/2023.
//

#include "Lista.h"
#include <stdlib.h>
#include <time.h>
#include "Nodo.h"
#include <iostream>

using namespace std;

void Lista::crearLista(){
    srand(time(NULL));
    int x;
    int contador = 1;
    Nodo *n = primero;
    while (contador < 23){
        bool seguido;
        bool seguidoB;
        x = rand() % 100+1;
        bool primo = this->esPrimo(x);
        Nodo *temp = this->buscarListaEvento("EventoA");
        if(primo){
            if (seguido){
                if (temp==NULL){
                    primero = new Nodo(x, n,"EventoA", "Einstein");
                }
                else{
                    if (seguidoB){
                        Nodo *temp2 = this->buscarListaEvento("EventoB");
                        if (temp2==NULL){
                            primero = new Nodo(x, n, "EventoB", this->randomCientifico());
                        }
                        else{
                            if (esCoprimo(temp->getDataNodo(),x)){
                                primero = new Nodo(x, n, "EventoC", this->randomCientifico());
                                if (esPrimo(x)){
                                    if((temp2->getCientific()=="Rosen") && (primero->getCientific()=="Rosen")){
                                        cout << "\nEl cientifico Rosen ha podido viajar al pasado pero no ha podido pasar informacion ya que Rosen no se puede pasar informacion a si mismo, por lo que se ha creado una maquina del tiempo sin ayuda del cientifico del futuro\n\n";
                                    }
                                    else if(primero->getCientific()=="Rosen"){
                                        cout << "\nEl cientifico Rosen ha podido viajar al pasado para observar y ademas ha pasado informacion a Einstein, por lo que se ha creado una maquina del tiempo con ayuda del cientifico del futuro\n\n";
                                    }
                                    else{
                                        cout << "\nEl cientifico Einstein ha podido viajar al pasado para observar y ademas ha pasado informacion, por lo que  se ha creado una maquina del tiempo con ayuda del cientifico del futuro\n\n";
                                    }
                                    n->setEnlacePrev(primero);
                                    break;
                                }
                                else{
                                    if (primero->getCientific()=="Rosen"){
                                        cout << "\nEl cientifico Rosen ha viajado al pasado pero solo ha podido observar, por lo que se ha creado una maquina del tiempo sin ayuda del cientifico del futuro\n\n";
                                    }else{
                                        cout << "\nEl cientifico Einstein ha viajado al pasado pero solo ha podido observar, por lo que se ha creado una maquina del tiempo sin ayuda del cientifico del futuro\n\n";
                                    }
                                    n->setEnlacePrev(primero);
                                    break;
                                }
                            }
                        }
                    }
                    else{
                        primero = new Nodo(x, n, "EventoB", this->randomCientifico());
                        seguidoB = true;
                    }
                }
            }
            else{
                primero = new Nodo(x, n,"EventoA", "Einstein");
                seguido = true;
            }
        }else{
            primero = new Nodo(x, n, "EventoNormal", this->randomCientifico());
            seguido = false;
            seguidoB = false;
        }
        if (n!=NULL){
            n->setEnlacePrev(primero);
        }
        n=primero;
        contador++;
    }

}

Lista::Lista() { primero = NULL; }//inicializamos el puntero primero con NULL al momento de crear la lista, es decir este es el puntero head cuando se crea la lista}

Nodo *Lista::getUltimo(){
    Nodo *n = primero;
    if (n == NULL)throw "Error, la lista esta vacia";
    while (n->getEnlaceNodoNext() != NULL) n = n->getEnlaceNodoNext();
    return n;
}

Nodo *Lista::buscarListaDato(int destino){
    Nodo *temp;
    for(temp = primero; temp != NULL; temp = temp->getEnlaceNodoNext()){
        if(destino == temp->getDataNodo())
            return temp;
    }
    return NULL;
}

Nodo *Lista::buscarListaEvento(string destino){
    Nodo *temp;
    for(temp = primero; temp != NULL; temp = temp->getEnlaceNodoNext()){
        if(destino == temp->getEvento())
            return temp;
    }
    return NULL;
}

void Lista::visualizarRev(){
    Nodo *n;
    n = getUltimo();
    while(n != NULL){
        cout << "|" << n->getDataNodo() << "|" << n->getCientific() << "|" << n->getEvento() << "|" << " --> " ;
        n = n->getEnlaceNodoPrev();
    }
    cout << "NULL";
}

void Lista::visualizarEventoA(){
    Nodo *n;
    int c=0;
    n = primero;
    while(n != NULL){
        if (n->getEvento()=="EventoA"){
            cout << "|" << n->getDataNodo() << "|" << n->getCientific() << "|" << n->getEvento() << "|" << " -- " ;
            c++;
        }
        n = n->getEnlaceNodoNext();
    }
    cout << "\nSe dieron " << c << " evento(s) A\n\n";
}

void Lista::visualizarEventoB(){
    Nodo *n;
    int c=0;
    n = primero;
    while(n != NULL){
        if (n->getEvento()=="EventoB"){
            cout << "|" << n->getDataNodo() << "|" << n->getCientific() << "|" << n->getEvento() << "|" << " -- " ;
            c++;
        }
        n = n->getEnlaceNodoNext();
    }
    cout << "\nSe dieron " << c << " evento(s) B\n\n";
}

void Lista::visualizarSecuencia() {
    Nodo *n;
    int k=0;
    n =primero;
    while(k<3){
        k++;
        cout << "|" << n->getDataNodo() << "|" << n->getCientific() << "|" << n->getEvento() << "|" << " -- " ;
        n = n->getEnlaceNodoNext();
    }
}

bool Lista::esPrimo(int num){
    int i = 1;
    int contador = 0;
    while (i<num){
        if (num%i == 0){
            contador++;
        }
        i++;
    }
    if (contador == 1) {
        return true;
    }
    return false;
}

bool Lista::esCoprimo(int numA, int numC){
    int menor;
    if (numA<numC){
        menor = numA;
    }
    else{
        menor = numC;
    }
    for (int i=2; i<menor; i++){
        if ((numA%i==0) && (numC%i==0)){
            return false;
        }
    }
    return true;
}

string Lista::randomCientifico(){
    int random = rand() % 2;
    if (random == 0){
        return "Einstein";
    }
    else{
        return "Rosen";
    }
}
