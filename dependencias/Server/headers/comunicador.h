//
// Created by andres on 13/04/18.
//

#ifndef Server_COMUNICADOR_H
#define Server_COMUNICADOR_H

#include <QtCore/QJsonObject>
#include "mServer.h"
#include "formuladorMensajes.h"

class comunicador {
public:
    comunicador();
    void sendMsj(QJsonObject mensaje);
    void setListaInstrucciones(vector<Grafo> entrada);

private:
    vector<Grafo> instrucciones;
    mServer *servidor = mServer::getMemServer();
    void mensajeServidor(formuladorMensajes msj);
    void mensajeWindow(formuladorMensajes msj);
    void mensajeLector(formuladorMensajes msj);
    vector<Grafo> getInstrucciones();

};


#endif //Server_COMUNICADOR_H
