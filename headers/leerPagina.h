//
// Created by andres on 18/03/18.
//

#ifndef TAREACORTA_LEERPAGINA_H
#define TAREACORTA_LEERPAGINA_H

#include "../headers/mServer.h"
#include <sstream>
#include <vector>
#include <fstream>
#include "pagina.h"
/**
 * @brief The leerPagina class : Clase que busca en las páginas escritas en el disco, un número de línea
 */
class leerPagina {
private:
    /**
     * @brief pagina1 : Página en donde se va a cargar la página a leer en disco
     */
    pagina pagina1;
    /**
     * @brief numeroLineaBuscar : En donde se almacena el número de línea a buscar
     */
    int numeroLineaBuscar;

public:
    /**
     * @brief leerPagina : Constructor de la clase leerPagina
     * @param numeroLinea : Número de línea a buscar
     */
    leerPagina(int numeroLinea);
    /**
     * @brief buscarArchivo : Función que carga el contenido del archivo en donde se encontró la línea
     */
    void buscarArchivo();
    /**
     * @brief buscarLinea : Función que determina el rango de páginas en donde buscar basado en si es mayor o menor que las instrucciones guardadas en en archivo mitad del total de páginas
     * @return nombreArchivo : Nombre en donde se encontró la instrucción
     */
    string buscarLinea();
    /**
     * @brief buscarLineaAux : Función que busca en un rango de páginas guardado en memoria
     * @param inicio : Inicio de la búsqueda
     * @param final : Final de la búsqueda
     * @return nombreArchivo : Nombre en donde se encontró la instrucción
     */
    string buscarLineaAux(int inicio, int final);
    /**
     * @brief obtenerPagina : Devuelve la página encontrada
     * @return pagina1 : Página en donde se encontró la instrucción
     */
    pagina obtenepagina();

};


#endif //TAREACORTA_LEERPAGINA_H
