//
// Created by andres on 11/03/18.
//

#ifndef TAREACORTA_MEMRESERVER_H
#define TAREACORTA_MEMRESERVER_H

#include <cstdlib>
#include <cstring>
#include "pagina.h"

/**
 * @brief The memReserver class : Clase que se encarga de reservar un bloque de memoria inicial
 */
class memReserver {

private:
    /**
     * @brief pair mem : Par de páginas que corresponden a las cargadas en memoria
     */
    std::pair<pagina *, pagina *>mem;

public:
    /**
     * @brief reservar : Función que hace la reserva de la memoria y la inicializa
     */
    void reservar();
    /**
     * @brief obtenerMemoria : Función para obtener la memoria actual
     * @return : Par de páginas mem
     */
    pair<pagina*,pagina*> obtenerMemoria();

};


#endif //TAREACORTA_MEMRESERVER_H
