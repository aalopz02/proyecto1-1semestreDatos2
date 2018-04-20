//
// Created by andres on 11/03/18.
//

#ifndef Server_MSERVER_H
#define Server_MSERVER_H

#include <iostream>
#include "../../Server/headers/memReserver.h"

using  namespace std;
/**
 * @brief The mServer class : Clase del servidor para el manejo de la memoria y llama a las clases necesarias
 */
class mServer {

private:
    /**
     * @brief numReferenciasVariables : Arreglo que contiene la cantidad de referencias por cada variable
     */
    vector<vector<string>> numReferenciaVariables;
    /**
     * @brief mServer : Constructor de la clase privado para que no se pueda instanciar por fuera de la clase
     */
    mServer();
    /**
     * @brief instance : Variable que contiene la unica instancia de la clase
     */
    static mServer* instance;
    /**
     * @brief mapaMemoria : Variable que maneja el mapa de memoria por nombre, indice de iicio y indice final
     */
     vector<vector<string>> mapaMemoria;
     /**
      * @brief instrucciones : Lista de las variables a manejar
      */
     vector<Grafo> instrucciones;
     string contenidoCuadroRam;

public:
    string leerValor();
    int getCantidadReferencias(string nombre);
    void setContenidoCuadroRam();
    /**
     * @brief memReserver1 : Instancia de la clase para reserva de memoria
     */
    memReserver *memReserver1;
    /**
     * @brief getMemServer : Función que evalua si ya se creo una instancia o la crea y retorna esta instancia
     * @return : Retorna la instancia de la clase
     */
    static mServer* getMemServer();
    /**
     * @brief reservaInicialMemoria : Función que llama a memReserver para reservar e inicializar la memoria
     * @param tamano : Tamaño de la memoria a reservar contenido en un arreglo, por referencias a cada tipo de variable
     */
    void reservaInicialMemoria(vector<int> tamano);
    /**
     * @brief obtenerMemoria : Función que obtiene la memoria de memReserver
     * @return : Puntero a la memoria
     */
    char* obtenerMemoria();
    /**
     * @brief obtenerMapaMemoria : Función para obtener el mapa con los índices a la memoria por cada variable
     * @return : Mapa de la memoria
     */
    vector<vector<string>> obtenerMapaMemoria();
    void limpiarMemoria();
    void setLibrememoria(string nombre);
    void setInstrucciones(vector<Grafo> entrada);
    void setNumeroReferenciasVariables(vector<vector<string>> numeroReferencias);

};

#endif //Server_MSERVER_H