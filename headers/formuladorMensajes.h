//
// Created by andres on 13/04/18.
//

#ifndef PROYECTO1_FORMULADORMENSAJES_H
#define PROYECTO1_FORMULADORMENSAJES_H

#include <QtCore/QJsonObject>

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

};


#endif //PROYECTO1_FORMULADORMENSAJES_H
