#include <iostream>
#include "headers/mServer.h"

int main(int argc, char *argv[])
{
    mServer *mServer1 = mServer::getMemServer();
    mServer1->reservaInicialMemoria({1,1,1,0,0,0});
    vector<vector<string>> mapa = mServer1->obtenerMapaMemoria();
    for (int i = 0; i < mapa[0].size(); i++) {
        cout << "variable: " << mapa[0][i] << " es: ";
        for (int j = stoi(mapa[1][i]); j < stoi(mapa[2][i]); j++) {
            cout << mServer1->obtenerMemoria()[j];
        }
        cout << endl;
    }
}