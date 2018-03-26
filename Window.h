//
// Created by andres on 16/03/18.
//

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtCore/QCoreApplication>
#include "headers/mServer.h"
#include "headers/leerPagina.h"
#include "headers/lectorTextEdit.h"

using namespace std;
/**
 * @brief The Window class : Clase que corresponde a la ventana principal
 */
class Window : public QWidget
{
Q_OBJECT
public:
    /**
     * @brief Window : Constructor de la ventana principal
     * @param parent : Define que el padre de la ventana principal es nulo
     */
    explicit Window(QWidget *parent = 0);
    QString obtenerLecturaEditor();

private slots:
    /**
     * @brief quitMyApp : Función que elimina las p{aginas guardadas en eldisco cuando se termina la aplicación
     */
    void quitMyApp();
    void BotonClearLog();
    void BotonEjecutarCodigo();
    void BotonDetenerEjecucionCodigo();
    void BotonDebugCodigo();

private:
    QToolButton *ejecutar;
    QToolButton *stop;
    QToolButton *debug;
    QLabel *salida;
    QLabel *log;
    QToolButton *clearLog;
    QLabel *contenedor_Botones;
    QLabel *contenedor_Ram;
    QTextEdit *editor;
    QLabel *numLineas;
};

#endif // WINDOW_H