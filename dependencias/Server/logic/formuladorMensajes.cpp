//
// Created by andres on 13/04/18.
//

#include "../headers/formuladorMensajes.h"
#include "../headers/comunicador.h"

formuladorMensajes::formuladorMensajes(int id, string contenido) {
    QJsonObject nuevo = QJsonObject();
    nuevo.insert("id",QString::fromStdString(std::to_string(id)));
    nuevo.insert("contenido",QString::fromStdString(contenido));
    mensaje = nuevo;
}

string formuladorMensajes::getIdPeticion() {
    return mensaje.value("id").toString().toStdString();
}

formuladorMensajes::formuladorMensajes(QJsonObject msj) {
    mensaje = msj;
}

string formuladorMensajes::getTipoRequest() {
    string request;
    int codigo = stoi(mensaje.value("id").toString().toStdString());
    switch (codigo) {
        case 11:
            request = "Prueba conexión";
            break;
        case 12:
            request = "Window: Actualizar información cuadro Ram";
            break;
        case 13:
            request = "Window: Obtener dirección variable";
            break;
        case 14:
            request = "Window: Obtener valor variable";
            break;
        case 15:
            request = "Window: Definir puntero";
            break;
        case 26:
            request = "LectorTextEdit: Inicializar bloque memoria";
            break;
        case 28:
            request = "LectorTextEdit: Envío información sobre varibles";
            break;
        case 96:
            request = "Server: Respuesta a petición de inicializar memoria";
            break;
        case 95:
            request = "Server: Dirección de memoria para definir puntero";
            break;
        case 94:
            request = "Server: Devolver valor variable";
            break;
        case 93:
            request = "Server: Devolver dirección memoria de una variable";
            break;
        case 92:
            request = "Server: Datos para actualizar cuadro Ram";
            break;
        default:
            request = "ERROR_CODIGO_MAL_DEFINIDO";
            break;
    }
    return request;
}

string formuladorMensajes::getContenido() {
    return mensaje.value("contenido").toString().toStdString();
}

QJsonObject formuladorMensajes::getMensaje() {
    return mensaje;
}

formuladorMensajes::formuladorMensajes(int id, vector<int> numReferenciasTipos) {
    QJsonObject nuevo = QJsonObject();
    nuevo.insert("id",QString::fromStdString(std::to_string(id)));
    string res;
    for (int i = 0; i < numReferenciasTipos.size(); i++) {
        res+= "-";
        res += to_string(numReferenciasTipos[i]);
    }
    nuevo.insert("contenido",QString::fromStdString(res));
    mensaje = nuevo;
}

formuladorMensajes::formuladorMensajes(int id, vector<vector<string>> refenciasVariables) {
    QJsonObject nuevo = QJsonObject();
    nuevo.insert("id",QString::fromStdString(std::to_string(id)));
    string res;
    if (refenciasVariables[0].empty()) {
        return;
    }
    for (int i = 0; i < refenciasVariables[0].size()-1; i++) {
        res+= "-";
        res += refenciasVariables[0][i];
        res += "-";
        res += refenciasVariables[1][i];
    }
    nuevo.insert("contenido",QString::fromStdString(res));
    mensaje = nuevo;
}

formuladorMensajes::formuladorMensajes(int id) {
    QJsonObject nuevo = QJsonObject();
    nuevo.insert("id",QString::fromStdString(std::to_string(id)));
    mensaje = nuevo;
}

