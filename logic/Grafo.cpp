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

string Grafo::getNombreVariable() {
    return nombreVariable;
}

Grafo * Grafo::getSiguiente() {
    return Siguiente;
}

Grafo * Grafo::getAnterior() {
    return Anterior;
}

void Grafo::setSiguiente(Grafo siguiente) {
    *Siguiente = siguiente;
}

void Grafo::setAnterior(Grafo anterior) {
    *Anterior = anterior;
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
    numeroLinea = numero;
}
