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
    void generarSalidaCodigo();
    void debugCodigo(QTextEdit *log,QLabel *salida);
    void ejecutarCodigo(QTextEdit *log, QLabel *salida);

private:
    string lectura;
    std::vector<Grafo> listaInstrucciones;
    std::vector<int> cantidadTiposDatos = {0,0,0,0,0};
    void dividirLectura();
    void agregarCantidadTiposDatos(int dato);
    void agregarInstruccion(string linea, int numerolinea,int scope);
    void estructurarDefinicion(string linea, int numeroLinea, int scope, string tipo, int indice);
    string realizarOperacion(vector<vector<string>> operaciones);
    void imprimir();
    void definirOperacion(string linea, int numeroLinea, int scope, string def, string, int indice);
    vector<string> buscarValor(string nombre, string tipo, int scope);
    vector<vector<string>> ordenarOperaciones(vector<int> entrada, string linea,int inicio);

};


#endif //TAREACORTA_LECTORTEXTEDIT_H