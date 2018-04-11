//
// Created by andres on 28/03/18.
//

#ifndef PROYECTO1_GRAFO_H
#define PROYECTO1_GRAFO_H

#include <iostream>

using namespace std;
/**
 * @brief The Grafo class : Clase que define a una variable
 */
class Grafo {

private:
    /**
     * @brief tipoVariable : Contiene el tipo de variable
     */
    string tipoVariable;
    /**
     * @brief nombreVariable : Nombre de la variable
     */
    string nombreVariable;
    /**
     * @brief contenido : Valor de la variable
     */
    string contenido;
    /**
     * @brief tipoInstruccion : Contiene si es una definición o operación
     */
    string tipoInstruccion;
    /**
     * @brief scope : Entero para manejar el scope
     */
    int scope;
    /**
     * @brief numeroLinea : Número de línea de la instrucción
     */
    int numeroLinea;

public:
    /**
     * @brief setTipoinstruccion : Setter tipoInstruccion
     * @param tipo : Tipo instrucción
     */
    void setTipoinstruccion(string tipo);
    /**
     * @brief setNombreVariable : Setter nombreVariable
     * @param nombre : Nombre de la variable
     */
    void setNombreVariable(string nombre);
    /**
     * @brief setContenido : Setter contenido
     * @param cont : Contenido de la variable
     */
    void setContendido(string cont);
    /**
     * @brief setTipoVariable : Setter tipoVariable
     * @param tipo : Tipo de variable
     */
    void setTipoVariable(string tipo);
    /**
     * @brief setScope : Setter scope
     * @param n : Entero scope
     */
    void setScope(int n);
    /**
     * @brief setNumerolinea : Setter numeroLinea
     * @param numero : Numero de línea
     */
    void setNumeroLinea(int numero);
    /**
     * @brief getNumeroLinea : Getter numeroLinea
     * @return : numeroLinea
     */
    int getNumeroLinea();
    /**
     * @brief getTipoinstruccion : Getter tipoInstruccion
     * @return : tipoinstruccion
     */
    string getTipoinstruccion();
    /**
     * @brief getNombreVariable : Getter nombreVartiable
     * @return : nombreVariable
     */
    string getNombreVariable();
    /**
     * @brief getContenido : Getter contenido
     * @return : contenido
     */
    string getContenido();
    /**
     * @brief getTipoVariable : Getter tipoVariable
     * @return : tipoVariable
     */
    string getTipoVariable();
    /**
     * @brief getScope : Getter scope
     * @return : scope
     */
    int getScope();

};

#endif //PROYECTO1_GRAFO_H
