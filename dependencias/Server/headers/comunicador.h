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
    /**
     * @brief : Constructor de la clase
     */
    comunicador();
    /**
     * @brief sendMsj : Función que envía un mensaje en formato Json a la clase uqe le correponde
     * @param mensaje : Mensaje a enviar
     */
    void sendMsj(QJsonObject mensaje);
    /**
     * @brief setListaInstrucciones : Setter lista instrucciones
     * @param entrada : Lista de instrucciones
     */
    void setListaInstrucciones(vector<Grafo> entrada);
    /**
     * @brief setCantidadRef : Setter cantidad referencias variables
     * @param ref : Lista con la cantidad de referencias
     */
    void setCantidadRef(vector<vector<string>> ref);

private:
    /**
     * @brief numeroReferencias : Lista con la cantidad de referencias
     */
    vector<vector<string>> numeroReferencias;
    /**
     * @brief instrucciones: Lista de instrucciones
     */
    vector<Grafo> instrucciones;
    /**
     * @brief servidor : Instancia del servidor
     */
    mServer *servidor = mServer::getMemServer();
    /**
     * @brief mensajeServidor : Función que maneja los mensajes dirijidos al servidor
     * @param msj : Mensaje recibido
     */
    void mensajeServidor(formuladorMensajes msj);
    /**
     * @brief mensajeWindow : Función que maneja los mensajes dirijidos a la ventana
     * @param msj : Mensaje recibido
     */
    void mensajeWindow(formuladorMensajes msj);
    /**
     * @brief getInstrucciones : getter lista instrucciones
     * @return lista instruccuines
     */
    vector<Grafo> getInstrucciones();
    /**
     * @brief getNumeroReferencias : Getter numero referencias
     * @return numero Referencias
     */
    vector<vector<string>> getNumeroReferencias();

};


#endif //Server_COMUNICADOR_H
