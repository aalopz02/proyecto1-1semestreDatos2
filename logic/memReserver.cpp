//
// Created by andres on 11/03/18.
//

#include "../headers/memReserver.h"

 pair<pagina*,pagina*> memReserver::obtenerMemoria() {
    return mem;

}

void memReserver::reservar() {
    mem.first = new pagina;
    mem.second = new pagina;

}
