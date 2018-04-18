//
// Created by andres on 13/04/18.
//

#ifndef Server_COMUNICADOR_H
#define Server_COMUNICADOR_H

#include <QtCore/QJsonObject>

class comunicador {
public:
    comunicador();
    void sendMsj(QJsonObject mensaje);
};


#endif //Server_COMUNICADOR_H
