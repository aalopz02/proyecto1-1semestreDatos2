//
// Created by andres on 11/03/18.
//

#include "../headers/mServer.h"

mServer* mServer::instance = 0;

mServer::mServer() {
    memReserver1->reservar();

}

mServer* mServer::getMemServer() {
    if (instance == 0) {
        instance = new mServer();
    }
    return instance;

}

pair<int,int> mServer::obtenerPaginasUso() {
    return paginasUsando;

}

int mServer::obtenerCantidadPag() {
    return paginasTotales + 1;

}

void mServer::agregarPagina(string tipoInstruccion, string contenido, int numeroLinea) {
    if (pagLlena == 2) {
        paginasTotales ++;
        pagLlena = 0;
    }
    pagLlena ++;
    guardarPagina1.generarPagina(paginasTotales,tipoInstruccion, contenido, numeroLinea);
    guardarPagina1.guardarPaginaDisco();
    guardarPagina1.escribirPagina(memReserver1->obtenerMemoria(),paginasTotales);
    paginasUsando.first = memReserver1->obtenerMemoria().first->obtenerNumero();
    paginasUsando.second = memReserver1->obtenerMemoria().second->obtenerNumero();

}

void mServer::agregarPaginaCompleta(pagina pagina1) {
    guardarPagina1.setpaginas(pagina1);
    guardarPagina1.escribirPagina(memReserver1->obtenerMemoria(),paginasTotales);
    paginasUsando.first = memReserver1->obtenerMemoria().first->obtenerNumero();
    paginasUsando.second = memReserver1->obtenerMemoria().second->obtenerNumero();

}
