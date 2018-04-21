//
// Created by andres on 13/04/18.
//

#include <fstream>
#include "../headers/comunicador.h"

comunicador::comunicador() {

}

void comunicador::sendMsj(QJsonObject mensaje) {
    formuladorMensajes msj = formuladorMensajes(mensaje);
    if (stoi(msj.getIdPeticion()) == 11) {
        mensajeServidor(msj);
        mensajeWindow(msj);
        return;
    }
    if (stoi(msj.getIdPeticion()) < 16 && stoi(msj.getIdPeticion()) > 11) {
        mensajeServidor(msj);
        return;
    }
    if (stoi(msj.getIdPeticion()) == 26) {
        mensajeServidor(msj);
        return;
    }
    if (stoi(msj.getIdPeticion()) == 28) {
        mensajeServidor(msj);
        return;
    }
    if (stoi(msj.getIdPeticion()) < 96 && stoi(msj.getIdPeticion()) > 91) {
        mensajeWindow(msj);
        return;
    }
}

void comunicador::mensajeWindow(formuladorMensajes msj) {
    switch (stoi(msj.getIdPeticion())) {
        case 92:
            std::ofstream file ("ContRam.txt");
            file << msj.getTipoRequest() + "\n" + msj.getContenido();
            file.close();
            break;
    }
}

void comunicador::setListaInstrucciones(vector<Grafo> entrada) {
    instrucciones = entrada;
}

vector<Grafo> comunicador::getInstrucciones() {
    return instrucciones;
}

void comunicador::setCantidadRef(vector<vector<string>> ref) {
    numeroReferencias = ref;
}

vector<vector<string>> comunicador::getNumeroReferencias() {
    return numeroReferencias;
}

void comunicador::mensajeServidor(formuladorMensajes msj) {
    string res;
    vector<int> cantidadDatos;
    vector<vector<string>> referenciasVariables = {{},{}};
    int indice = 0;
    switch (stoi(msj.getIdPeticion())) {
        case 26:
            res = "";
            for (int i = 0; i < msj.getContenido().size(); i++) {
                if (msj.getContenido()[i] == '-') {
                    try {
                        cantidadDatos.push_back(stoi(res));
                    } catch (std::invalid_argument& e) {
                        res = "";
                    }
                    res = "";
                } else {
                    res += msj.getContenido()[i];
                }
            }
            cantidadDatos.push_back(stoi(res));
            servidor->setInstrucciones(getInstrucciones());
            servidor->reservaInicialMemoria(cantidadDatos);
            break;
        case 28:
            servidor->setNumeroReferenciasVariables(getNumeroReferencias());
            break;
        case 12:
            servidor->setContenidoCuadroRam();
            break;
        default:break;
    }
}