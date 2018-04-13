//
// Created by andres on 11/03/18.
//

#ifndef TAREACORTA_MEMRESERVER_H
#define TAREACORTA_MEMRESERVER_H

#include <cstdlib>
#include <cstring>
#include <vector>
#include "Grafo.h"

using namespace std;

/**
 * @brief The memReserver class : Clase que se encarga de reservar un bloque de memoria inicial
 */
class memReserver {

private:
    /**
     * @brief memoria : Variable caracter que funciona como el bloque de memoria
     */
    char *memoria;
    /**
     * @brief tamanoMemoria : Entero que corresponde al tamaño de la memoria a reservar
     */
    int tamanoMemoria;

public:
    /**
     * @brief memReserver : Constructor de la clase que llama a reservar para inicializar la memoria
     * @param tamano : Tamaño de la memoria a reservar
     */
    memReserver(int tamano);
    /**
     * @brief reservar : Función que hace la reserva de la memoria y la inicializa
     */
    void reservar();
    /**
     * @brief leerVariablesGrafo : Función que dada una lista de instrucciones asigna los valores a
     * la memoria y crea el mapa de la misma
     * @param instrucciones : Lista de variables a escribir
     * @return : REtorna el mapa de memoria
     */
    std::vector<std::vector<string>> leerVariablesGrafo(vector<Grafo> instrucciones);
    /**
     * @brief escribirMemoria : Función auxiliar a leerVariablesGrafo que concatena los valores en la memoria
     * @param contenido : Valor a escribir en la memoria
     */
    void escribirMemoria(string contenido);
    /**
     * @brief obtenerMemoria : Función para obtener el bloque de memoria
     * @return : Retorna el puntero al bloque de memoria
     */
    char* obtenerMemoria();

};

#endif //TAREACORTA_MEMRESERVER_H
