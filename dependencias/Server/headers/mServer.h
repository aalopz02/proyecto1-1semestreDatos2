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
     /**
      * @brief contenidoCuadroRam : String que contiene los datos para el cuadro que muestra la ram en la ventana
      */
     string contenidoCuadroRam;

public:
    /**
     * @brief leerValor: Función que busca el valor de una variable
     * @param nombre : Nombre de la variablea buscar
     * @return Valor de la variable
     */
    string leerValor(string nombre);
    /**
     * @brief getCantidadReferencias : Función para obtener la cantidad de referencias a una variable
     * @param nombre : Nombre de la variable a buscar
     * @return Entero con la cantidad
     */
    int getCantidadReferencias(string nombre);
    /**
     * @brief setContenidoCuadroRam : Función que crea el string con el contenido del cuadro ram
     */
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
    /**
     * @brief limpiarMemoria : Lee las referencias a las variables y si llega a -1 pone ceros en los espacios
     */
    void limpiarMemoria();
    /**
     * @brief setLibreMemoria : Elimina del mapa de memoria los valores guardados para un nombre
     * @param nombre : Nombre a eliminar
     */
    void setLibrememoria(string nombre);
    /**
     * @brief setInstrucciones : Setter de la lista de instrucciones
     * @param entrada : Lista instrucciones
     */
    void setInstrucciones(vector<Grafo> entrada);
    /**
     * @brief setNumeroReferenciasVariables : Setter del número de referencias a variables
     * @param numeroReferencias : Lista con los números de referencias
     */
    void setNumeroReferenciasVariables(vector<vector<string>> numeroReferencias);

};

#endif //Server_MSERVER_H