//
// Created by andres on 17/03/18.
//

#ifndef TAREACORTA_PAGINA_H
#define TAREACORTA_PAGINA_H
#include <iostream>

using namespace std;
/**
 * @brief The class pagina : Clase que define los atributos y métodos que corresponden a una  página
 */
class pagina {
private:
    /**
     * @brief numeroPagina: Número de página que se escribe
     */
    int numeroPagina = 0;
    /**
     * @brief siguiente : Entero que cambia a 1 si la página le sigue otra o se mantiene en 0 si es la última
     */
    int siguiente = 0;
    /**
     * @brief instrucción1 : String que contiene la estructura de una instrucción, tipo de instrucción, contenido y número de línea
     */
    string instruccion1;
    /**
     * @brief instrucción2 : String que contiene la estructura de una instrucción, tipo de instrucción, contenido y número de línea
     */
    string instruccion2;

public:
    /**
     * @brief pagina : Constructor de la clase
     * @param numero : Número de página
     */
    explicit pagina(int numero);
    pagina();
    /**
     * @brief crearNueva : Cambia el valor de la variable siguiente por 1 para indicar que hay una página después de la actual
     */
    void crearNueva();
    /**
     * @brief instrucción : Función que asigna un string que corresponde a una instrucción
     * @param instruccion : String que corresponde a una instrucción con la estructura definida anteriormente
     */
    void instruccion(string instruccion);
    /**
     * @brief obtenerContenido : Función para obtener los valores de la página como un solo String
     * @return instrucción : Retorna la concatenación de los valores definidos para el objeto pagina actual
     */
    string obtenerContenido();
    /**
     * @brief obtenerNunmero : Función para obtener el número actual de página
     * @return numeroPagina : Número de página actual
     */
    int obtenerNumero();

};

#endif //TAREACORTA_PAGINA_H