//
// Created by andres on 10/04/18.
//

#ifndef SERVER_SERVIDOR_H
#define SERVER_SERVIDOR_H

#include <QtNetwork/QLocalServer>

class QLocalServer;

class Servidor {

public:
    Servidor();

private:
    QLocalServer *server;
    void respuesta();

};


#endif //SERVER_SERVIDOR_H
