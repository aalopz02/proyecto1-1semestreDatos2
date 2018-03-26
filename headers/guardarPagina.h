//
// Created by andres on 11/03/18.
//

#ifndef TAREACORTA_GUARDARPAGINA_H
#define TAREACORTA_GUARDARPAGINA_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include "pagina.h"

using namespace std;
/**
 * @brief The guardarPagina class : Clase que se encarga de crear las páginas y las guarda en disco en el bloque me memoria ram reservado
 */
class guardarPagina {

private:
    /**
     * @brief pagina1 : Primera página para asignación
     */
    pagina * pagina1;
    /**
     * @brief pagina2 : Segunda página para asignación
     */
    pagina * pagina2;
    /**
     * @brief actual : Página auxiliar para realizar asignaciones
     */
    pagina * actual;
    /**
     * @brief paginaNueva : Entero que cuenta la cantidad de veces que se define una instrucción para ver cuando se llena una página
     */
    int paginaNueva = 4;
    /**
     * @brief posicionMem : Cambia entre 1 y 0 para intercalar las páginas en memoria
     */
    int posicionMem = 0;

public:
    /**
     * @brief guardarPagina : Constructor de la clase guardarPagina
     */
    guardarPagina();
    /**
     * @brief generarDirecciones : Clase que genera un string con las características de una intrucción y las concatena a la página
     * @param tipoInstruccion : Corresponde al tipo de instrucción
     * @param contenido : Corresponde a la línea de contenido que copntiene la instrucción
     * @param numeroLinea : Es el número de línea en donde se encuentra el inicio de la instrucción
     */
    void generarPagina(int numeroPagina, string tipoInstruccion, string contenido, int numeroLinea);
    /**
     * @brief : Función que recibe un número y se lo asigna a la página como identificador
     * @param mem : Par de páginas que corresponden a las cargadas en memoria
     * @param paginasTotales : Número entero que corresponde al número de página
     */
    void escribirPagina(pair<pagina*,pagina*>mem, int paginasTotales);
    /**
     * @brief : Guarda la página en el disco cuando se necesite y utiliza el número de página como identificador
     */
    void guardarPaginaDisco();
    /**
     * @brief setPaginas : Recibe una página para cargarlaen memoria
     * @param pagina3 : Página a cargar
     */
    void setpaginas(pagina pagina3);

};

#endif //TAREACORTA_GUARDARPAGINA_H