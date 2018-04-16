//
// Created by andres on 25/03/18.
//

#ifndef PROYECTO1_LECTORTEXTEDIT_H
#define PROYECTO1_LECTORTEXTEDIT_H

#include "Grafo.h"
#include <thread>
#include <fstream>
#include <QtCore/QString>
#include <iostream>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLabel>

using namespace std;

class lectorTextEdit {

public:
    /**
     * @brief lectorTextEdit : Constructor de la clase
     * @param lecturaEditor : Texto a leer
     */
    lectorTextEdit(QString lecturaEditor);

    /**
     * @brief generarSalidaCodigo : Función que crea el archivo completo con la lectura y demás necesario
     * para que pueda ser compliado
     */
    void generarSalidaCodigo();

    /**
     * @brief debugCodigo : Función que compila el archivo creado y llama a la función para dividir la lectura
     * @param log : QTextEdit que corresponde al log del IDE en donde copia errores de compilación
     * @param salida : QTextEdit que corresponde a la salida de texto del IDE
     */
    void debugCodigo(QTextEdit *log, QTextEdit *salida);

    /**
     * @brief ejecutarCodigo : Función que ejecuta el código compilado
     * @param log : QTextEdit que corresponde al log del IDE en donde copia errores de compilación
     * @param salida : QTextEdit que corresponde a la salida de texto del IDE
     */
    void ejecutarCodigo(QTextEdit *log, QTextEdit *salida);
    std::vector<Grafo> getListaInstrucciones();
private:
    vector<vector<string>> numReferenciaVariables;
    /**
     * @brief output : puntero a la salida stdout del IDE
     */
    QTextEdit *output;
    /**
     * @brief enStruct : Texto en donde se almacena el tipo de instrucción a evaluar
     */
    string enStruct = "def";
    /**
     * @brief nombreStructAux : Texto en donde se almacena el nombre de una estructura en caso de que se encuentre
     * alguna
     */
    string nombreStructAux;
    /**
     * @brief lectura : Texto contenido en el editor de texto del IDE
     */
    string lectura;
    /**
     * @brief nombreEstructuras : Vector en donde se guardan los nombres de las estructuras para buscar si se hace referencia a alguna
     */
    std::vector<string> nombreEstructuras;
    /**
     * @brief miembrosEstructuras : Vector que contiene las variables y el tipo que conponen a una estructura
     */
    std::vector<vector<string>> miembrosEstructuras = {{}, {}};
    /**
     * @brief listaInstrucciones : Lista con las instrucciones encontradas
     */
    std::vector<Grafo> listaInstrucciones;
    /**
     * @brief cantidadTipoDatos : Vector que almacena las referencias a cada tipo para enviarlo  al servidor de memoria
     */
    std::vector<int> cantidadTiposDatos = {0, 0, 0, 0, 0};
    /**
     * @brief dividirLectura : Lee linea por línea y envía lo leído a agregarinstruccion() además de definir el scope de una línea
     */
    void dividirLectura();

    /**
     * @brief agregarCantidadTiposDatos : Función que dependiendo del tipo de dato incrementa las referencias a un tipop de dato
     * @param dato : Tipo del dato encontrado
     */
    void agregarCantidadTiposDatos(int dato);
    /**
     * @brief agregarInstruccion : Función que identifica tipos y estructuras en cada línea
     * @param linea : Texto que corresponde a la línea en lectura
     * @param numerolinea :  Número de línea
     * @param scope : Scope de la línea, se define 0 si no es una operación
     */
    void agregarInstruccion(string linea, int numerolinea,int scope);
    /**
     * @brief estructurarDefinición : Lee una línea que corresponde a una declaración de variable y asigna los valores
     * que corresponde a un objeto Grafo que luego agrega a la lista de instrucciones
     * @param linea : Texto que corresponde a la línea en lectura
     * @param numeroLinea : Número de línea
     * @param scope : Scope de la línea
     * @param tipo : Tipo de la variable en definición
     * @param indice : Valor que corresponde al tamaño del string tipo para omitirlo de la lectura
    */
    void estructurarDefinicion(string linea, int numeroLinea, int scope, string tipo, int indice);
    /**
     * @brief realizarOperacion : Función que utiliza la biblioteca exprtk.hpp para calcular el resultado de una
     * operación matemática
     * @param operaciones : Lista que contiene los operadores y los valores leídos en la línea
     * @param tipo : Tipo de la variable a la que se realiza la igualdad
     * @param scope : Scope de la línea
     * @param expresion : Operación a resolver
     * @return : Texto que contiene el resultado de la operqación para poder asignarlo
     */
    string realizarOperacion(vector<vector<string>> operaciones, string tipo, int scope, string expresion);
    /**
     * @brief imprimir : Función que escribe en el stdout
     * @param texto : Texto a imprimir
     */
    void imprimir(string texto);
    /**
     * @brief definirOperacion : Función que dependiendo dela variable enStruct realiza distintas llamadas a funciones
     * @param linea : Texto que corresponde a la línea a leer
     * @param numeroLinea : Número de línea
     * @param scope : Scope de la línea
     * @param def : Tipo de instrucción a evaluar
     * @param tipo : Tipo del dato a leer
     * @param indice : Tamaño del string de tipo paraa omitirlo si es el caso
     */
    void definirOperacion(string linea, int numeroLinea, int scope, string def, string tipo, int indice);
    /**
     * @brief buscarValor : Busca un valor dado el nombre de una variable y evalúa si está definida o si el scope permite la operación
     * @param nombre : Nombre de la variable a buscar
     * @param tipo : Tipo de variable a la que se asignará el valor
     * @param scope : Scope de la variable a la que se asignar el valor
     * @return : Lista que contiene el valor encontrado
     */
    vector<string> buscarValor(string nombre, string tipo, int scope);
    /**
     * @brief ordenarOperaciones : Lee los nombres que están en una operación para luego buscar los valores correspondientes
     * @param entrada : Lista que contiene los índices en donde se encontró un operador
     * @param linea : Línea a leer
     * @return : Lista que contiene los nombres y los operadores por separado
     */
    vector<vector<string>> ordenarOperaciones(vector<int> entrada, string linea);
    /**
     * @brief agregarMachoteEstructura : Agrega el nombre de una estructura a nombresEstructura
     * @param linea : Línea a leer
     */
    void agregarMachoteEstructura(string linea);
    /**
     * @brief agregarMiembrosEstructura : Agrega las variables de una estructura a la lista miembrosEstructura
     * @param linea : Línea a leer
     * @param tipo : Tipo de dato a guardar
     */
    void agregarMiembroEstructura(string linea, string tipo);
    /**
     * @brief buscarNombreVariable : Función que busca si un string se encuentra definido como variable
     * @param nombre : Nombre a buscar
     * @return : El índice de la lista de instrucciones donde se encontró o error de búsqueda
     */
    string buscarNombreVariable(string nombre);
    /**
     * @brief definirOperacionSobreVariable : Agrega una nueva instrucción que corresponde una operación a la lista de instrucciones
     * @param linea : Línea a leer
     * @param nombre : Nombre de la variable
     * @param scope : Scope de la línea
     * @param tipo : Tipo de la variable a asignar
     * @param numeroLinea : Número de línea
     */
    void definirOperacionSobreVariable(string linea, string nombre, int scope, string tipo, int numeroLinea);
    /**
     * @brief analizarLinea : Función que lee una línea que corresponde a una definición de variable
     * @param scope : Scope de la línea
     * @param numeroLinea : Número de línea
     * @param nombre : Nombre de la variable a definir
     * @param tipo : Tipo de la variables a definir
     * @param linea : Texto que corresponde a la línea en lectura
     * @param valorAsignado : Valor que indica si hay una asignación
     * @return : Texto que corresponde al valor de la variable
     */
    string analizarLinea(int scope, int numeroLinea, string nombre, string tipo, string linea, int valorAsignado);

};

#endif //PROYECTO1_LECTORTEXTEDIT_H