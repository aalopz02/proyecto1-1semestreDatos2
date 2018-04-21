//
// Created by andres on 16/03/18.
//

#ifndef WINDOW_H
#define WINDOW_H

#include <QKeyEvent>
#include <QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtCore/QCoreApplication>
#include <QtGui/QTextBlock>
#include "headers/lectorTextEdit.h"

using namespace std;
/**
 * @brief The Window class : Clase que corresponde a la ventana principal
 */
class Window : public QWidget {
Q_OBJECT
public:
    /**
     * @brief Window : Constructor de la ventana principal
     * @param parent : Define que el padre de la ventana principal es nulo
     */
    explicit Window(QWidget *parent = 0);
    /**
     * @brief obtenerLecturaEditor : Función que retorna el contenido del editor de texto
     * @return : Contenido del editor de texto
     */
    QString obtenerLecturaEditor();
    /**
     * @brief actualizarCuadroRam : Función que llama a formuladorMensajes y al servidor para actualizar el
     * el cuadro de vista Ram
     */
    void actualizarCuadroRam();
private slots:

    /**
     * @brief quitMyApp : Función que elimina los archivos creados en el disco cuando se termina la aplicación
     */
    void quitMyApp();

    /**
     * @brief BotonClearLog : Listener de botón clearLog
     */
    void BotonClearLog();

    /**
     * @brief BotonEjecutarCodigo : Listener de botón ejecutar
     */
    void BotonEjecutarCodigo();

    /**
     * @brief BotonDetenerEjecucionCodigo : Listener botón stop
     */
    void BotonDetenerEjecucionCodigo();

    /**
     * @brief BotonDebugCodigo : Listener botón debug
     */
    void BotonDebugCodigo();

    /**
     * @brief BotonAvanzarDebug : Listener botón siguienteDebug
     */
    void BotonAvanzarDebug();

private:
    /**
     * @brief mostrarLinea : Agrega un  efecto sobre el text edit para mostrar el recorrido del debug
     */
    void mostrarLinea();
    /**
     * @brief instrucciones : Vector de Grafo para contener lasa instrucciones leídas
     */
    vector<Grafo> instrucciones;
    /**
     * @brief lineaActual : Entero que contiene la línea por donde va la ejecución
     */
    int lineaActual = 0;
    /**
     * @brief indiceInstrucciones : Indice para moverse en la lista de instrucciones
     */
    int indiceInstrucciones = 0;
    /**
     * @brief agregarLineas : Función que agrega números de líneas
     * @return : String con los números de línea
     */
    string agregarLineas();
    /**
     * @brief lectura : Variable para llamar al lector de texto del editor
     */
    lectorTextEdit lectura = lectorTextEdit("");
    /**
     * @brief numeroMaxLinea : Número máximo de líneas para agregar a la lista de números de línea
     */
    int numeroMaxLinea = 35;
    /**
     * @brief etiqueta_Ram : Etiqueta del texto de las columnas del cuadro de Ram
     */
    QLabel *etiqueta_Ram;
    /**
     * @brief ejecutar : Botón para ejecutar el código normalmente
     */
    QToolButton *ejecutar;
    /**
     * @brief stop : Botón para detener el debug
     */
    QToolButton *stop;
    /**
     * @brief debug : Botón para iniciar el debug
     */
    QToolButton *debug;
    /**
     * @brief salida : Visor de resultados stdout
     */
    QTextEdit *salida;
    /**
     * @brief siguienteDebug : Botón para continuar con el debug
     */
    QToolButton *siguienteDebug;
    /**
     * @brief log : Cuadro que muestra los resultados de compilación y muestra si se dan comunicaciones con el servidor de memoria
     */
    QTextEdit *log;
    /**
     * @brief clearLog : Botón que limpia el cuadro de log
     */
    QToolButton *clearLog;
    /**
     * @brief contenedor_Botones : Contenedor para los botones
     */
    QLabel *contenedor_Botones;
    /**
     * @brief contenedor_Nombres : Cuadro para mostrar el nombre de las variables
     */
    QTextEdit *contenedor_Nombres;
    /**
     * @brief contenedor_Dir : Cuadro para mostrar las direcciones de las variables
     */
    QTextEdit *contenedor_Dir;
    /**
     * @brief contenedor_Ref : Cuadro para contener la cantidad de referencias a una variable
     */
    QTextEdit *contenedor_Ref;
    /**
     * @brief contenedor_Valor : Cuadro para mostrar loos valores de las variables
     */
    QTextEdit *contenedor_Valor;
    /**
     * @brief editor : Editor donde se escribirá el código en el IDE
     */
    QTextEdit *editor;
    /**
     * @brief numLineas : Etiqueta para mostrar los números de línea del editor del IDE
     */
    QLabel *numLineas;

};

#endif // WINDOW_H