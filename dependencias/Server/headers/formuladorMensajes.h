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
    //Constructores diferentes para cada tipo de mensaje a envia y destinatario
    formuladorMensajes(int id);
    formuladorMensajes(int id, string contenido);
    formuladorMensajes(QJsonObject msj);
    formuladorMensajes(int id, vector<int> numReferenciasTipos);
    formuladorMensajes(int id, vector<vector<string>> refenciasVariables);
    /**
     * @brief getMensaje: Funcion para obtener el objeto Json
     * @return Objeto Json
     */
    QJsonObject getMensaje();
    /**
     * @brief getTipoRequest : Función para obtener el tipo de peticón basado en el id
     * @return
     */
    string getTipoRequest();
    /**
     * getIdPeticion : Getter id
     * @return id
     */
    string getIdPeticion();
    /**
     * @brief getContenido : Devuelve el contenido del mensaje
     * @return Contenido Mensaje
     */
    string getContenido();

private:
    QJsonObject mensaje;
    vector<Grafo> instrucciones;

};


#endif //Server_FORMULADORMENSAJES_H
