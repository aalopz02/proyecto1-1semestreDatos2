//
// Created by andres on 28/03/18.
//

#include "../headers/Grafo.h"

void Grafo::setNombreVariable(string nombre) {
    nombreVariable = nombre;
}

void Grafo::setContendido(string cont) {
    contenido = cont;
}

string Grafo::getTipoVariable() {
    return tipoVariable;
}

void Grafo::setTipoVariable(string tipo) {
    tipoVariable = tipo;
}

string Grafo::getContenido() {
    return contenido;
}

void Grafo::setScope(int n) {
    scope = n;
}

int Grafo::getScope() {
    return scope;
}

void Grafo::setTipoinstruccion(string tipo) {
    tipoInstruccion = tipo;
}

string Grafo::getTipoinstruccion() {
    return tipoInstruccion;
}

int Grafo::getNumeroLinea() {
    return numeroLinea;
}

void Grafo::setNumeroLinea(int numero) {
    numeroLinea = numero-6;
}

string Grafo::getNombreVariable() {
    return nombreVariable;
}

void Grafo::setPeticionServidor(QJsonObject msj) {
    peticionServidor = msj;
}

QJsonObject Grafo::getPeticionServidor() {
    return peticionServidor;
}
