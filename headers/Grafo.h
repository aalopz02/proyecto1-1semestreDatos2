//
// Created by andres on 28/03/18.
//

#ifndef TAREACORTA_GRAFO_H
#define TAREACORTA_GRAFO_H

#include <iostream>

using namespace std;
class Grafo {

private:
    Grafo *Anterior;
    Grafo *Siguiente;
    string tipoVariable;
    string nombreVariable;
    string contenido;
    string tipoInstruccion;
    int scope;
    int numeroLinea;

public:

    void setAnterior(Grafo anterior);
    void setSiguiente(Grafo siguiente);

    Grafo * getAnterior();
    Grafo * getSiguiente();

    void setTipoinstruccion(string tipo);
    void setNombreVariable(string nombre);
    void setContendido(string cont);
    void setTipoVariable(string tipo);
    void setScope(int n);
    void setNumeroLinea(int numero);

    int getNumeroLinea();
    string getTipoinstruccion();
    string getNombreVariable();
    string getContenido();
    string getTipoVariable();
    int getScope();

};


#endif //TAREACORTA_GRAFO_H
