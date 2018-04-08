//
// Created by andres on 25/03/18.
//

#include "../headers/lectorTextEdit.h"

lectorTextEdit::lectorTextEdit(QString lecturaEditor) {
    lectura = lecturaEditor.toStdString();
    generarSalidaCodigo();
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
    dividirLectura();
}

void lectorTextEdit::ejecutarCodigo(QTextEdit *log,QLabel *salida) {
    log->setText(QString::fromStdString(GetStdoutFromCommand("c++ -g a.cpp",1)));
    salida->setText(QString::fromStdString(GetStdoutFromCommand("./a.out",2)));
}

void lectorTextEdit::generarSalidaCodigo() {
    string nombreArchivo = "a.cpp";
    std::ofstream file (nombreArchivo);
    file << "#include <iostream>\nusing namespace std;\nint main(){\n"+lectura+"\n"+"}//final";
    file.close();
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
                scope = scope + 1;
            }
            if (linea == "}") {
                scope = scope - 1;
            }
            if (linea.substr(0,6) == "struct") {

            }
            if (linea == "}//final") {
                break;
            }
            agregarInstruccion(linea,numLinea,scope);
            numLinea ++;
        }

    }
    file.close();
}

void lectorTextEdit::agregarCantidadTiposDatos(int dato) {
    switch (dato) {
        case 1:
            cantidadTiposDatos[0]++;
            break;
        case 2:
            cantidadTiposDatos[1]++;
            break;
        case 3:
            cantidadTiposDatos[2]++;
            break;
        case 4:
            cantidadTiposDatos[3]++;
            break;
        case 5:
            cantidadTiposDatos[4]++;
            break;
    }
}

void lectorTextEdit::definirOperacion(string linea, int numeroLinea, int scope, string def, string tipo, int indice) {
    if (def == "def") {
        estructurarDefinicion(linea,numeroLinea,scope,tipo,indice);
    }
}

void lectorTextEdit::agregarInstruccion(string linea, int numeroLinea, int scope) {
    linea.erase(std::remove(linea.begin(), linea.end(), ' '), linea.end());
    if (linea.substr(0,3) == "int") {
        definirOperacion(linea, numeroLinea, scope, "def", "int",3);
        agregarCantidadTiposDatos(1);
    }
    if (linea.substr(0,4) == "long") {
        definirOperacion(linea, numeroLinea, scope, "def", "long",4);
        agregarCantidadTiposDatos(2);
    }
    if (linea.substr(0,4) == "char") {
        definirOperacion(linea, numeroLinea, scope, "def", "char",4);
        agregarCantidadTiposDatos(3);
    }
    if (linea.substr(0,5) == "float") {
        definirOperacion(linea, numeroLinea, scope, "def", "float",5);
        agregarCantidadTiposDatos(4);
    }
    if (linea.substr(0,6) == "double") {
        definirOperacion(linea, numeroLinea, scope, "def", "double",6);
        agregarCantidadTiposDatos(5);
    }

}

vector<vector<string>> lectorTextEdit::ordenarOperaciones(vector<int> entrada, string linea, int inicio) {
    vector<vector<string>> variables = {{},{}};
    string valor = "";
    int indice = entrada[0];
    int indiceEntradas = 0;
    cout <<"linea evaluar: "<<linea <<endl;
    for (int i = 0; i < linea.size()-1; i++) {
        if (i == indice) {
            cout << "indice evaluar: " << indice << endl;
            variables[0].push_back(valor);
            cout << "valor a agregar: " << valor << endl;
            valor = linea[i];
            variables[1].push_back(valor);
            valor = "";
            if (indiceEntradas + 1 < entrada.size()) {
                indiceEntradas++;
                indice = entrada[indiceEntradas];
            }
        } else {
            cout << "char agregar: " << linea[i] <<endl;
            valor += linea[i];
        }
    }
    variables[0].push_back(valor);
    cout << "valor a agregar: " << valor << endl;
    return variables;
}

vector<string> lectorTextEdit::buscarValor(string nombre, string tipo, int scope) {
    Grafo aux;
    vector<string> result = {"",""};
    for (int i = 0; i < listaInstrucciones.size(); i++) {
        aux = listaInstrucciones[i];
        if (nombre == aux.getNombreVariable()) {
            if (aux.getScope() <= scope) {
                if (tipo == "int") {
                    if (aux.getTipoVariable() == "int") {
                        result[0] = aux.getContenido();
                        result[1] = aux.getTipoVariable();
                        return result;
                    }
                    if (aux.getTipoVariable() == "float" || aux.getTipoVariable() == "double" || aux.getTipoVariable() == "long") {
                        result[0] = std::to_string(stoi(aux.getContenido()));
                        result[1] = aux.getTipoVariable();
                        return result;
                    }
                    if (aux.getTipoVariable() == "char") {
                        result[0] = std::to_string(aux.getContenido()[1] - 0);
                        result[1] = aux.getTipoVariable();
                        return result;
                    }
                }
                if (tipo == "float" || tipo == "double" || tipo == "long") {
                    if (aux.getTipoVariable() == "float" || aux.getTipoVariable() == "double" || aux.getTipoVariable() == "int" || aux.getTipoVariable() == "long") {
                        result[0] = aux.getContenido();
                        result[1] = aux.getTipoVariable();
                        return result;
                    }
                    if (aux.getTipoVariable() == "char") {
                        result[0] = std::to_string(aux.getContenido()[1] - 0);
                        result[1] = aux.getTipoVariable();
                        return result;
                    }
                }
            } else {
                result[0] = "ERROR_VARIABLE_FUERA_SCOPE";
                return result;
            }
        }
    }
    if (tipo == "char") {
        result[0] = nombre;
        return result;
    }
    result[0] = "ERROR_VARIABLE_NO_DEFINIDA";
    return result;
}

void lectorTextEdit::estructurarDefinicion(string linea, int numeroLinea, int scope, string tipo, int indice) {
    Grafo instruccion = Grafo();

    instruccion.setTipoVariable(tipo);
    instruccion.setScope(scope);
    instruccion.setNumeroLinea(numeroLinea);

    int valorAsignado = 0;
    string nombre;
    for (int i = indice; i < linea.size(); i++) {
        if (linea[i] == '=') {
            valorAsignado = i;
            break;
        }
        if (linea[i] == ';') {
            break;
        }
        nombre += linea[i];
    }
    instruccion.setNombreVariable(nombre);

    vector<int> operaciones;
    vector<char> operadores = {'/','*','%','+','-',};

    string valor;
    string valorAux;
    if (valorAsignado != 0) {
        for (int i = valorAsignado + 1; i < linea.size(); i++) {
            for (int j = 0; j < operadores.size(); j++) {
                if (operadores[j] == linea[i]) {
                    operaciones.push_back(i-(valorAsignado + 1));
                }
            }
        valor += linea[i];
        }
        if (operaciones.empty()) {
            try {
                stoi(valor);
            } catch(std::invalid_argument& e) {
                vector<string> busqueda = buscarValor(valor,tipo,scope);
                valor = busqueda[0];
                if (valor == "ERROR_VARIABLE_NO_DEFINIDA") {
                    valor = valor + " no está definida ";
                }
                if (valor == "ERROR_VARIABLE_FUERA_SCOPE") {
                    valor = valor + " no está dentro del scope de: " + nombre;
                }
            }
        } else {
            vector<vector<string>> res = ordenarOperaciones(operaciones,valor,valorAsignado);
            cout << res[0][0]<<endl;
            for (int i = 0; i < res.size(); i++) {
                cout << res[1][i] <<endl;
                cout << res[0][i+1] <<endl;
            }
        }
    }
    else {
        valor = "NO_VALOR_ASIGNADO";
    }
    instruccion.setContendido(valor);
    listaInstrucciones.push_back(instruccion);

}

string lectorTextEdit::realizarOperacion(vector<vector<string>> operaciones) {
    string resultado;
    string nombre;

    for (int i = 0; i < operaciones.size(); i++) {

    }
    return resultado;
}
//if (linea.substr(0,6) == "struct") {cout << "esstruct"<<endl;}
//if (linea.substr(0,9) == "reference") {cout << "esreference"<<endl;}
//if (linea.substr(0,9) == "getAddre") {cout << "esgetAddre"<<endl;}
//if (linea.substr(0,8) == "getValue") {cout << "esgetValue"<<endl;}