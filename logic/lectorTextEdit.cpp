//
// Created by andres on 25/03/18.
//

#include "../headers/lectorTextEdit.h"

lectorTextEdit::lectorTextEdit(QString lecturaEditor) {
    lectura = lecturaEditor.toStdString();
}

string GetStdoutFromCommand(string cmd, char modo) {

    string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
        pclose(stream);
    }
    if (data.empty()) {
        if (modo == 1) {
            return "Programa compilado correctamente\n\n\n\n";
        }
        else {
            return ">>";
        }
    }
    return data;
}

void lectorTextEdit::debugCodigo(QTextEdit *log,QLabel *salida) {
    log->setText(QString::fromStdString(GetStdoutFromCommand("c++ -g a.cpp",1)));
    salida->setText(QString::fromStdString(GetStdoutFromCommand("gdb a ",2)));
}

void lectorTextEdit::ejecutarCodigo(QTextEdit *log,QLabel *salida) {
    log->setText(QString::fromStdString(GetStdoutFromCommand("c++ -g a.cpp",1)));
    salida->setText(QString::fromStdString(GetStdoutFromCommand("./a.out",2)));
}

void lectorTextEdit::generarSalidaCodigo(QTextEdit *log,QLabel *salida) {
    string nombreArchivo = "a.cpp";
    std::ofstream file (nombreArchivo);
    file << "#include <iostream>\nusing namespace std;\nint main(){\n"+lectura+"\n"+"}";
    file.close();
    ejecutarCodigo(log,salida);
}

void lectorTextEdit::dividirLectura() {
    int scope = 0;
    int numLinea = 0;
    string linea;
    ifstream file ("a.cpp");
    while (getline(file,linea)) {
        if (numLinea == 0 || numLinea ==1 || numLinea == 2) {
            numLinea++;
        } else {
            if (linea == "{") {
                scope++;
            }
            if (linea == "}") {
                scope--;
            }
            if (linea.substr(0,6) == "struct") {

            }
            agregarInstruccion(linea,numLinea,scope);
            numLinea ++;
        }

    }
    file.close();
}

void lectorTextEdit::agregarCantidadTiposDatos(string dato) {

}

void lectorTextEdit::agregarInstruccion(string linea, int numeroLinea, int scope) {
    if (linea.substr(0,3) == "int") {
        agregarCantidadTiposDatos("i");
    }
    if (linea.substr(0,4) == "long") {
        agregarCantidadTiposDatos("l");
    }
    if (linea.substr(0,4) == "char") {
        agregarCantidadTiposDatos("c");
    }
    if (linea.substr(0,5) == "float") {
        agregarCantidadTiposDatos("f");
    }
    if (linea.substr(0,6) == "double") {
        agregarCantidadTiposDatos("d");
    }
    if (linea.substr(0,6) == "struct") {cout << "esstruct"<<endl;}
    if (linea.substr(0,9) == "reference") {cout << "esreference"<<endl;}
    if (linea.substr(0,9) == "getAddre") {cout << "esgetAddre"<<endl;}
    if (linea.substr(0,8) == "getValue") {cout << "esgetValue"<<endl;}

}
//string tipoVariable;
//string nombreVariable;
//string contenido;
//int scope
