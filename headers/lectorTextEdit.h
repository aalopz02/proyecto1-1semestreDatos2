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
    lectorTextEdit(QString lecturaEditor);
    void generarSalidaCodigo();
    void debugCodigo(QTextEdit *log,QTextEdit *salida);
    void ejecutarCodigo(QTextEdit *log, QTextEdit *salida);

private:
    string enStruct = "def";
    string nombreStructAux;
    string lectura;
    std::vector<string> nombreEstructuras;
    std::vector<vector<string>> miembrosEstructuras = {{},{}};
    std::vector<Grafo> listaInstrucciones;
    std::vector<int> cantidadTiposDatos = {0,0,0,0,0};
    void dividirLectura();
    void agregarCantidadTiposDatos(int dato);
    void agregarInstruccion(string linea, int numerolinea,int scope);
    void estructurarDefinicion(string linea, int numeroLinea, int scope, string tipo, int indice);
    string realizarOperacion(vector<vector<string>> operaciones, string tipo, int scope, string expresion);
    void imprimir();
    void definirOperacion(string linea, int numeroLinea, int scope, string def, string tipo, int indice);
    vector<string> buscarValor(string nombre, string tipo, int scope);
    vector<vector<string>> ordenarOperaciones(vector<int> entrada, string linea);
    void agregarMachoteEstructura(string linea);
    void agregarMiembroEstructura(string linea, string tipo);
    string buscarNombreVariable(string nombre);
    void definirOperacionSobreVariable(string linea, string nombre, int scope, string tipo, int numeroLinea);
    string analizarLinea(int scope, int numeroLinea, string nombre, string tipo, string linea, int valorAsignado);

};


#endif //PROYECTO1_LECTORTEXTEDIT_H