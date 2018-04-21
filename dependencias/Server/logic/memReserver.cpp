//
// Created by andres on 11/03/18.
//

#include "../headers/memReserver.h"

void memReserver::reservar() {
    memoria = (char*) malloc(tamanoMemoria);
    for (int i = 0; i < tamanoMemoria; i++){
        memset(memoria, 0, tamanoMemoria);
    }
}

memReserver::memReserver(int tamano) {
    tamanoMemoria = tamano;
    reservar();
}

std::vector<std::vector<string>> memReserver::leerVariablesGrafo(vector<Grafo> instrucciones) {
    int indiceActual = 0;
    Grafo aux;
    string contenido;
    std::vector<std::vector<string>> mapaAux = {{},{},{}};
    for (int i = 0; i < instrucciones.size(); i++) {
        aux = instrucciones[i];
        if (aux.getNombreVariable() == "ERROR") {
            break;
        }
        if (aux.getNombreVariable() != "Cout") {
            if (aux.getTipoVariable() == "int") {
                mapaAux[0].push_back(aux.getNombreVariable());
                mapaAux[1].push_back(std::to_string(indiceActual));
                escribirMemoria(aux.getContenido());
                indiceActual += aux.getContenido().size();
                mapaAux[2].push_back(std::to_string(indiceActual));
            }
            if (aux.getTipoVariable() == "char") {
                mapaAux[0].push_back(aux.getNombreVariable());
                mapaAux[1].push_back(std::to_string(indiceActual));
                escribirMemoria(aux.getContenido());
                indiceActual += aux.getContenido().size();
                mapaAux[2].push_back(std::to_string(indiceActual));
            }
            if (aux.getTipoVariable() == "long") {
                mapaAux[0].push_back(aux.getNombreVariable());
                mapaAux[1].push_back(std::to_string(indiceActual));
                escribirMemoria(aux.getContenido());
                indiceActual += aux.getContenido().size();
                mapaAux[2].push_back(std::to_string(indiceActual));
            }
            if (aux.getTipoVariable() == "double") {
                mapaAux[0].push_back(aux.getNombreVariable());
                mapaAux[1].push_back(std::to_string(indiceActual));
                escribirMemoria(aux.getContenido());
                indiceActual += aux.getContenido().size();
                mapaAux[2].push_back(std::to_string(indiceActual));
            }
            if (aux.getTipoVariable() == "float") {
                mapaAux[0].push_back(aux.getNombreVariable());
                mapaAux[1].push_back(std::to_string(indiceActual));
                escribirMemoria(aux.getContenido());
                indiceActual += aux.getContenido().size();
                mapaAux[2].push_back(std::to_string(indiceActual));
            }
            if (aux.getTipoVariable() == "reference") {
                mapaAux[0].push_back(aux.getNombreVariable());
                mapaAux[1].push_back(std::to_string(indiceActual));
                escribirMemoria(aux.getContenido());
                indiceActual += aux.getContenido().size();
                mapaAux[2].push_back(std::to_string(indiceActual));
            }
        }
    }
    return mapaAux;
}

void memReserver::escribirMemoria(string contenido) {
    strcat(memoria,contenido.c_str());
}

char* memReserver::obtenerMemoria() {
    return memoria;
}