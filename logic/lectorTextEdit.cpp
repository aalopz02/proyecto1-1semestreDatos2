//
// Created by andres on 25/03/18.
//

#include <thread>
#include <fstream>
#include "../headers/lectorTextEdit.h"

lectorTextEdit::lectorTextEdit(QString lecturaEditor) {
    lectura = lecturaEditor.toStdString();
    generarSalidaCodigo();
}

void lectorTextEdit::ejecutarCodigo() {
    //system("c++ a.cpp"); // compila simple
    system("c++ -g a.cpp -o a"); //compila para el debuger
    //cout<< system("./a.out"); //ejecuta simple
    system("gdb a"); // debuger

}

void lectorTextEdit::generarSalidaCodigo() {
    string nombreArchivo = "a.cpp";
    std::ofstream file (nombreArchivo);
    file << lectura;
    file.close();
    ejecutarCodigo();
}

