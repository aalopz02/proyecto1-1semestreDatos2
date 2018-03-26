//
// Created by andres on 11/03/18.
//

#include "../headers/guardarPagina.h"

guardarPagina::guardarPagina() {
    pagina1 = new pagina;
    pagina2 = new pagina;
    paginaNueva = 0;
    actual = pagina1;

}

void guardarPagina::generarPagina(int numeroPagina, string tipoInstruccion, string contenido, int numeroLinea) {
    if (paginaNueva == 4) {
        actual->crearNueva();
        guardarPaginaDisco();
        pagina1 = new pagina(numeroPagina);
        actual = pagina1;
        paginaNueva = 0;
    }
    if (paginaNueva == 2) {
        actual->crearNueva();
        guardarPaginaDisco();
        pagina2 = new pagina(numeroPagina);
        actual = pagina2;
    }
    actual->instruccion(tipoInstruccion+"\n"+contenido+"\n"+std::to_string(numeroLinea)+"\n");
    paginaNueva ++;

}

void guardarPagina::escribirPagina(pair<pagina*,pagina*>mem, int paginasTotales) {
    *mem.first = *pagina1;
    *mem.second = *pagina2;

}

void guardarPagina::guardarPaginaDisco() {
    string nombreArchivo = std::to_string(actual->obtenerNumero())+".dat";
    std::ofstream file (nombreArchivo);
    file << actual->obtenerContenido();
    file.close();

}

void guardarPagina::setpaginas(pagina pagina3) {
    if (posicionMem == 0) {
        posicionMem = 1;
        *pagina1 = pagina3;
        return;
    }
    posicionMem = 0;
    *pagina2 = pagina3;

}
