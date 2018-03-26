//
// Created by andres on 25/03/18.
//

#ifndef TAREACORTA_LECTORTEXTEDIT_H
#define TAREACORTA_LECTORTEXTEDIT_H


#include <QtCore/QString>
#include <iostream>

using namespace std;

class lectorTextEdit {
public:
    lectorTextEdit(QString lecturaEditor);

private:
    string lectura;
    void ejecutarCodigo();
    void generarSalidaCodigo();
};


#endif //TAREACORTA_LECTORTEXTEDIT_H
