//
// Created by andres on 11/03/18.
//

#include <sstream>
#include "../headers/mServer.h"

mServer* mServer::instance = 0;

mServer::mServer() {

}

mServer* mServer::getMemServer() {
    if (instance == 0) {
        instance = new mServer();
    }
    return instance;

}

void mServer::reservaInicialMemoria(vector<int> tamano) {
    int memoriaTotal = 0;
    vector<int> tamanosBytes = {4,8,1,4,8,4};
    for (int i = 0; i < tamano.size(); i++) {
        memoriaTotal += tamano[i]*tamanosBytes[i];
    }
    memReserver1 = new memReserver(memoriaTotal);
    mapaMemoria = memReserver1->leerVariablesGrafo(instrucciones);
}

char* mServer::obtenerMemoria() {
    return memReserver1->obtenerMemoria();
}

vector<vector<string>> mServer::obtenerMapaMemoria() {
    return mapaMemoria;
}

void mServer::limpiarMemoria() {
    vector<string> variablesLibres = {};
    for (int i = 0; i < mapaMemoria[0].size(); i++) {
        if (stoi(numReferenciaVariables[1][i]) == 0) {
            variablesLibres.push_back(numReferenciaVariables[0][i]);
        }
    }
    for (int i = 0; i < variablesLibres.size(); i++) {
        setLibrememoria(variablesLibres[i]);
        mapaMemoria[0].erase(mapaMemoria[0].begin() + i);
        mapaMemoria[1].erase(mapaMemoria[1].begin() + i);
        mapaMemoria[2].erase(mapaMemoria[2].begin() + i);
    }
}

void mServer::setLibrememoria(string nombre) {
    for (int i = 0; i < mapaMemoria[0].size(); i++) {
        if (mapaMemoria[0][i] == nombre) {
            for (int j = stoi(mapaMemoria[1][i]); j < stoi(mapaMemoria[2][i]); i++) {
                obtenerMemoria()[i] = 0;
            }
        }
    }
}

void mServer::setInstrucciones(vector<Grafo> entrada){
    instrucciones = entrada;
}

void mServer::setContenidoCuadroRam() {
    string contenidoCuadro;
    int indice = 0;
    const char* inicio = &(obtenerMemoria()[0]);
    const void* dir = inicio;
    for (int i = 0; i < obtenerMapaMemoria()[0].size();i++) {
        indice = stoi(obtenerMapaMemoria()[1][i]);
        std::ostringstream s2;
        s2 << dir + indice;
        contenidoCuadro += s2.str();
        contenidoCuadro += "\n";
        contenidoCuadro += leerValor();
        contenidoCuadro += "\n";
        contenidoCuadro += obtenerMapaMemoria()[0][i];
        contenidoCuadro += "\n";
        contenidoCuadro += to_string(getCantidadReferencias(obtenerMapaMemoria()[0][i]));
        contenidoCuadro += "\n";
    }
    contenidoCuadroRam = contenidoCuadro;
    cout << contenidoCuadroRam << endl;
}

string mServer::leerValor() {
    return "valor";
}

int mServer::getCantidadReferencias(string nombre) {
    int numero = 0;
    for (int i = 0;i < numReferenciaVariables[0].size(); i++) {
        if (numReferenciaVariables[0][i] == nombre) {
            numero = stoi(numReferenciaVariables[1][i]);
        }
    }
    return numero;
}

void mServer::setNumeroReferenciasVariables(vector<vector<string>> numeroReferencias) {
    numReferenciaVariables = numeroReferencias;
}
