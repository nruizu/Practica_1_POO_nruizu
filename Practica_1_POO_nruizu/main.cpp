#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
    Lista *l = new Lista();
    l->crearLista();
    l->visualizarRev();
    cout << "\n-------------------------\n" << endl;
    l->visualizarEventoA();
    l->visualizarEventoB();

    if(l->buscarListaEvento("EventoC")){
        l->visualizarSecuencia();
    }
    else{
        cout << "\nNo se dio ningun evento C" << endl;
    }

    return 0;
}
