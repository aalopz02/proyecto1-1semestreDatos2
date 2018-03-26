//
// Created by andres on 11/03/18.
//

#ifndef TAREACORTA_MSERVER_H
#define TAREACORTA_MSERVER_H

#include <iostream>
#include <array>
#include "memReserver.h"
#include "../headers/guardarPagina.h"

using  namespace std;
/**
 * @brief The mServer class : Clase del servidor para el manejo de la memoria y llama a las clases necesarias
 */
class mServer {

private:
    /**
     * @brief mServer : Constructor de la clase privado para que no se pueda instanciar por fuera de la clase
     */
    mServer();
    /**
     * @brief instance : Variable que contiene la unica instancia de la clase
     */
    static mServer* instance;
    /**
     * @brief paginasTotales : Variable que maneja el número de páginas creadas
     */
    int paginasTotales = 0;
    /**
     * @brief paginasUsando : Maneja las paginas cargadas en memoria
     */
    pair<int,int> paginasUsando;
    /**
     * @brief pagLlena : Variable que cuenta las instrucciones agregadas a las paginas para manejar un máximo de dos instrucciones por página
     */
    int pagLlena = 0;
    /**
     * @brief guardarPagina1 : instancia de la clase guardarPagina para manejar las páginas
     */
    guardarPagina guardarPagina1 = guardarPagina();


public:
    /**
     * @brief memReserver1 : Instancia de la clase para reserva de memoria
     */
    memReserver *memReserver1 = (memReserver*) malloc(sizeof(memReserver));
    /**
     * @brief getMemServer : Función que evalua si ya se creo una instancia o la crea y retorna esta instancia
     * @return : Retorna la instancia de la clase
     */
    static mServer* getMemServer();
    /**
     * @brief obtenerCantidadPag : Función que retorna el total de paginas creado
     * @return : paginasTotales
     */
    int obtenerCantidadPag();
    /**
     * @brief obtenerPaginasUso : Función que devuelve las paginas en memoria
     * @return : paginasUsando
     */
    pair<int,int> obtenerPaginasUso();
    /**
     * @brief agregarPagina : Función que agrega llama a la clase guardarPagina
     * @param tipoInstruccion : Texto que indica el tipo de instrucción a guardar
     * @param contenido : Texto que indica los parametros de esa instrucción
     * @param numeroLinea : Entero que corresponde al número de línea de la instrucción
     */
    void agregarPagina(string tipoInstruccion, string contenido, int numeroLinea);
    /**
     * @brief agregarPaginaCompleta : Función que agrega un página entera después de leerla desde el disco
     * @param pagina1 : Página leída
     */
    void agregarPaginaCompleta(pagina pagina1);

};


#endif //TAREACORTA_MSERVER_H