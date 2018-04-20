//
// Created by andres on 13/04/18.
//

#ifndef Server_FORMULADORMENSAJES_H
#define Server_FORMULADORMENSAJES_H

#include <QtCore/QJsonObject>
#include "Grafo.h"

using namespace std;

class formuladorMensajes {

public:
    formuladorMensajes(int id);
    formuladorMensajes(int id, string contenido);
    formuladorMensajes(QJsonObject msj);
    formuladorMensajes(int id, vector<int> numReferenciasTipos);
    formuladorMensajes(int id, vector<vector<string>> refenciasVariables);
    QJsonObject getMensaje();
    string getTipoRequest();
    string getIdPeticion();
    string getContenido();

private:
    QJsonObject mensaje;
    vector<Grafo> instrucciones;

};


#endif //Server_FORMULADORMENSAJES_H
