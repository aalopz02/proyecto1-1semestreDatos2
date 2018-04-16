//
// Created by andres on 13/04/18.
//

#ifndef PROYECTO1_COMUNICADOR_H
#define PROYECTO1_COMUNICADOR_H

#include <QtCore/QJsonObject>

class comunicador {
public:
    comunicador();
    void sendMsj(QJsonObject mensaje);
};


#endif //PROYECTO1_COMUNICADOR_H
