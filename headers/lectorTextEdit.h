//
// Created by andres on 25/03/18.
//

#ifndef TAREACORTA_LECTORTEXTEDIT_H
#define TAREACORTA_LECTORTEXTEDIT_H

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
    lectorTextEdit(QString lecturaEditor);
    void generarSalidaCodigo(QTextEdit *log, QLabel *salida);
    void debugCodigo(QTextEdit *log,QLabel *salida);

private:
    string lectura;
    std::vector<Grafo> listaInstrucciones;
    std::vector<int> cantidadTiposDatos;
    void ejecutarCodigo(QTextEdit *log, QLabel *salida);
    void dividirLectura();
    void agregarCantidadTiposDatos(string dato);
    void agregarInstruccion(string linea, int numerolinea,int scope);

};


#endif //TAREACORTA_LECTORTEXTEDIT_H