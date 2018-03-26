//
// Created by andres on 17/03/18.
//

#include "../headers/pagina.h"

pagina::pagina(int numero) {
    numeroPagina = numero;
}

string pagina::obtenerContenido() {
    return std::to_string(numeroPagina)+"\n"+instruccion1+instruccion2+std::to_string(siguiente)+"\n";
}

void pagina::crearNueva() {
    siguiente = 1;
}

void pagina::instruccion(string instruccion) {
    if (instruccion1.empty()) {
        instruccion1 = instruccion;

    }
    else {
        instruccion2 = instruccion;
    }

}

int pagina::obtenerNumero() {
    return numeroPagina;
}

pagina::pagina() {}
