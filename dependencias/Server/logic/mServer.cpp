//
// Created by andres on 11/03/18.
//

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

    //mapaMemoria = memReserver1->leerVariablesGrafo(instrucciones);

}

char* mServer::obtenerMemoria() {
    return memReserver1->obtenerMemoria();
}

vector<vector<string>> mServer::obtenerMapaMemoria() {
    return mapaMemoria;
}
