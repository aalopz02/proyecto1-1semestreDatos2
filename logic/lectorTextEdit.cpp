//
// Created by andres on 25/03/18.
//

#include "../headers/lectorTextEdit.h"
#include "../dependencias/exprtk.hpp"
#include "../dependencias/Server/headers/comunicador.h"
#include "../dependencias/Server/headers/formuladorMensajes.h"

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
            return "Programa compilado correctamente";
        }
        else {
            return ">>";
        }
    }
    return data;
}

void lectorTextEdit::debugCodigo(QTextEdit *log,QTextEdit *salida) {
    output = salida;
    string texto = GetStdoutFromCommand("c++ -g a.cpp",1);
    if (texto == "Programa compilado correctamente") {
        log->append(QString::fromStdString(texto));
        dividirLectura(log);
    } else {
        log->append(QString::fromStdString(texto));
    }
}

void lectorTextEdit::ejecutarCodigo(QTextEdit *log,QTextEdit *salida) {
    string texto = GetStdoutFromCommand("c++ -g a.cpp",1);
    log->append(QString::fromStdString(texto));
    salida->setText(QString::fromStdString(GetStdoutFromCommand("./a.out",2)));
}

void lectorTextEdit::generarSalidaCodigo() {
    string nombreArchivo = "a.cpp";
    std::ofstream file (nombreArchivo);
    file << "#include <iostream>\n#define getAdrr &\n#define getValue *\n"
            "typedef int * reference_int;typedef long * reference_long;typedef float * reference_float;typedef double * reference_double;typedef char * reference_char;\n"
            "using namespace std;\nint main(){\n"+lectura+"\n"+"}//final";
    file.close();
}

void lectorTextEdit::dividirLectura(QTextEdit *log) {
    int scope = 0;
    int numLinea = 0;
    string linea;
    ifstream file ("a.cpp");
    while (getline(file,linea)) {
        if (numLinea < 6) {
            numLinea++;
        } else {
            if (linea == "{") {
                scope = scope + 1;
            }
            if (linea == "}") {
                scope = scope - 1;
            }
            if (linea == "}//final") {
                break;
            }
            if (!linea.empty()) {
                agregarInstruccion(linea,numLinea,scope);
            }
            numLinea ++;
        }
    }
    file.close();

    inicializarMemoria(log);

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
        case 0:
            break;
        default:break;
    }
}

void lectorTextEdit::agregarMachoteEstructura(string linea) {
    string nombre;
    for (int i = 6; i< linea.size()-1; i++) {
        nombre += linea[i];
    }
    nombreStructAux = nombre;
    nombreEstructuras.push_back(nombre);
}

void lectorTextEdit::agregarMiembroEstructura(string linea, string tipo) {
    string nombre;
    for (auto i = (int) tipo.size(); i < linea.size()-1; i++) {
        nombre += linea[i];
    }
    miembrosEstructuras[0].push_back(nombreStructAux+"."+nombre);
    miembrosEstructuras[1].push_back(tipo);
}

void lectorTextEdit::definirOperacion(string linea, int numeroLinea, int scope, string def, string tipo, int indice) {
    if (def == "def") {
        estructurarDefinicion(linea,numeroLinea,scope,tipo,indice);
    }
    if (def == "defstruct") {
        agregarMachoteEstructura(linea);
    }
    if (def == "miembroStruct") {
        agregarMiembroEstructura(linea,tipo);
    }
    if (def == "asignacionStruct") {
        crearVariablesStruct(scope, numeroLinea, linea);
    }
    if (def == "operacion") {
        string busqueda;
        int indiceCortar = 0;
        for (int i = 0; i < linea.size(); i++) {
            if (linea[i] == '=') {
                indiceCortar = i;
                busqueda = buscarNombreVariable(linea.substr(0,i));
                break;
            }
        }
        if (busqueda == "ERROR_VARIABLE_NO_DEFINIDA") {
            Grafo grafo1 = Grafo();
            grafo1.setContendido("La variable: "+linea.substr(0,indiceCortar)+" no está definida");
            grafo1.setNumeroLinea(numeroLinea);
            grafo1.setNombreVariable("ERROR");
            listaInstrucciones.push_back(grafo1);
        } else {
            definirOperacionSobreVariable(linea,linea.substr(0,indiceCortar),scope,tipo,numeroLinea);
        }
    }
    if (def == "getValue") {

    }
    if (def == "getAdrr") {

    }
    if (def == "reference") {

    }
}

void lectorTextEdit::agregarInstruccion(string linea, int numeroLinea, int scope) {
    Grafo aux;
    linea.erase(std::remove(linea.begin(), linea.end(), ' '), linea.end());
    if (linea.substr(0,3) == "int") {
        definirOperacion(linea, numeroLinea, scope, enStruct, "int",3);
        if (enStruct != "miembroStruct") {
            agregarCantidadTiposDatos(1);
        }
        return;
    }
    if (linea.substr(0,4) == "long") {
        definirOperacion(linea, numeroLinea, scope, enStruct, "long",4);
        if (enStruct != "miembroStruct") {
            agregarCantidadTiposDatos(2);
        }
        return;
    }
    if (linea.substr(0,4) == "char") {
        definirOperacion(linea, numeroLinea, scope, enStruct, "char",4);
        if (enStruct != "miembroStruct") {
            agregarCantidadTiposDatos(3);
        }
        return;
    }
    if (linea.substr(0,5) == "float") {
        definirOperacion(linea, numeroLinea, scope, enStruct, "float",5);
        if (enStruct != "miembroStruct") {
            agregarCantidadTiposDatos(4);
        }
        return;
    }
    if (linea.substr(0,6) == "double") {
        definirOperacion(linea, numeroLinea, scope, enStruct, "double",6);
        if (enStruct != "miembroStruct") {
            agregarCantidadTiposDatos(5);
        }
        return;
    }
    if (linea.substr(0,2) == "};") {
        enStruct = "def";
        return;
    }
    if (linea.substr(0,9) == "reference_") {
        enStruct = "ref";
        definirOperacion(linea, numeroLinea, scope, enStruct, linea.substr(9,linea.size()-1),0);
        enStruct = "def";
        return;
    }
    if (linea.substr(0,7) == "getValue"){
        enStruct = "getValue";
        definirOperacion(linea, numeroLinea, 0, enStruct,"",0);
        enStruct = "def";
        return;
    }
    if (linea.substr(0,6) == "getAdrr") {
        enStruct = "getAdrr";
        definirOperacion(linea, numeroLinea, 0, enStruct,"",0);
        enStruct = "def";
        return;
    }
    if (linea.substr(0,6) == "struct" && linea[linea.size()-1] == ';') {
        enStruct = "asignacionStruct";
        definirOperacion(linea, numeroLinea, scope, enStruct,"",0);
        enStruct = "def";
        return;
    }
    if (linea.substr(0,6) == "struct" && linea[linea.size()-1] == '{') {
        enStruct = "defstruct";
        definirOperacion(linea, numeroLinea, 0, enStruct, "",0);
        enStruct = "miembroStruct";
        return;
    }
    if (linea.substr(0,4) == "cout") {
        imprimir(linea.substr(6, linea.size() - 2), numeroLinea);
        return;
    }
    string nombre;
    for (int i = 0; i < linea.size(); i++) {
        if (linea[i] == '='){
            break;
        }
        nombre += linea[i];
    }
    int indice;
    try {
        indice = stoi(buscarNombreVariable(nombre));
        definirOperacionSobreVariable(linea,nombre,scope,listaInstrucciones[indice].getTipoVariable(),numeroLinea);
    } catch (std::invalid_argument& e) {
        definirOperacionSobreVariable(linea,nombre,0,"ND",numeroLinea);
    }

}

vector<vector<string>> lectorTextEdit::ordenarOperaciones(vector<int> entrada, string linea) {
    vector<vector<string>> variables = {{},{}};
    string valor;
    int indice = entrada[0];
    int indiceEntradas = 0;
    for (int i = 0; i < linea.size()-1; i++) {
        if (i == indice) {
            variables[0].push_back(valor);
            valor = linea[i];
            variables[1].push_back(valor);
            valor = "";
            if (indiceEntradas + 1 < entrada.size()) {
                indiceEntradas++;
                indice = entrada[indiceEntradas];
            }
        } else {
            if (linea[i] == '(' || linea[i] == ')') {
                valor += "";
            }
            else {
                valor += linea[i];
            }
        }
    }
    variables[0].push_back(valor);
    return variables;
}

string lectorTextEdit::buscarValor(string nombre, string tipo, int scope) {
    Grafo aux;
    string result;
    for (int i = 0; i < listaInstrucciones.size(); i++) {
        aux = listaInstrucciones[i];
        if (nombre == aux.getNombreVariable() && buscarNombreVariable(nombre) != "ERROR_VARIABLE_NO_DEFINIDA") {
            if (aux.getScope() <= scope) {
                if (tipo == "int") {
                    if (aux.getTipoVariable() == "int") {
                        aumentarReferenciaVariable(aux.getNombreVariable());
                        result = aux.getContenido();
                        return result;
                    }
                    if (aux.getTipoVariable() == "float" || aux.getTipoVariable() == "double" || aux.getTipoVariable() == "long") {
                        result = std::to_string(stoi(aux.getContenido()));
                        aumentarReferenciaVariable(aux.getNombreVariable());
                        return result;
                    }
                    if (aux.getTipoVariable() == "char") {
                        result = std::to_string(aux.getContenido()[1] - 0);
                        aumentarReferenciaVariable(aux.getNombreVariable());
                        return result;
                    }
                }
                if (tipo == "float" || tipo == "double" || tipo == "long") {
                    if (aux.getTipoVariable() == "float" || aux.getTipoVariable() == "double" || aux.getTipoVariable() == "int" || aux.getTipoVariable() == "long") {
                        result = aux.getContenido();
                        aumentarReferenciaVariable(aux.getNombreVariable());
                        return result;
                    }
                    if (aux.getTipoVariable() == "char") {
                        result = std::to_string(aux.getContenido()[1] - 0);
                        aumentarReferenciaVariable(aux.getNombreVariable());
                        return result;
                    }
                }
            } else {
                result = "ERROR_VARIABLE_FUERA_SCOPE";
                return result;
            }
        }
    }
    if (tipo == "char") {
        result = nombre;
        return result;
    }
    result = "ERROR_VARIABLE_NO_DEFINIDA";
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
    aumentarReferenciaVariable(nombre);
    string valor;
    if (valorAsignado != 0) {
        valor = analizarLinea(scope,numeroLinea,nombre,tipo,linea,valorAsignado);
    } else {
        valor = "0";
    }
    instruccion.setContendido(valor);
    listaInstrucciones.push_back(instruccion);
}

string lectorTextEdit::realizarOperacion(vector<vector<string>> operaciones,string tipo, int scope, string expresion) {
    typedef exprtk::symbol_table<double> symbol_table_t;
    typedef exprtk::expression<double>     expression_t;
    typedef exprtk::parser<double>             parser_t;
    symbol_table_t symbol_table;
    expression_t   expression;
    parser_t       parser;

    string resultado;
    vector<string> nombres;
    vector <double> valores;

    for (int i = 0; i< operaciones[0].size(); i++) {
        nombres.push_back(operaciones[0][i]);
        valores.push_back(0);
        symbol_table.add_variable(nombres[i],valores[i]);
    }

    expression.register_symbol_table(symbol_table);
    parser.compile(expresion,expression);

    for (int i = 0; i < operaciones[0].size(); i++) {
        try {
            stoi(operaciones[0][i]);
        } catch(std::invalid_argument& e) {
            try {
                valores[i] = stoi(buscarValor(operaciones[0][i],tipo,scope));
            } catch(std::invalid_argument& e) {
            }
        }
    }

    if (tipo == "int") {
        resultado = std::to_string((int) expression.value());
    }
    if (tipo == "double") {
        resultado = std::to_string(expression.value());
    }
    if (tipo == "float") {
        resultado = std::to_string((float) expression.value());
    }
    if (tipo == "long") {
        resultado = std::to_string((long) expression.value());
    }
    if (tipo == "char") {
        resultado = std::to_string((char) expression.value());
    }
    return resultado;
}

string lectorTextEdit::buscarNombreVariable(string nombre) {
    Grafo aux;
    string indice;

    for (int i = 0; i < listaInstrucciones.size(); i++) {
        aux = listaInstrucciones[i];
        if (aux.getNombreVariable() == nombre) {
            indice = std::to_string(i);
        }
    }
    if (indice.empty()) {
        return "ERROR_VARIABLE_NO_DEFINIDA";
    }
    return indice;
}

void
lectorTextEdit::definirOperacionSobreVariable(string linea, string nombre, int scope, string tipo, int numeroLinea) {
    Grafo operacion = Grafo();
    operacion.setNombreVariable(nombre);
    operacion.setScope(scope);
    operacion.setTipoVariable(tipo);
    operacion.setNumeroLinea(numeroLinea);
    string valor;
    if (tipo != "ND") {
        valor = analizarLinea(scope,numeroLinea,nombre,tipo,linea,nombre.size());
    } else {
        valor = "La variable: " + nombre + " no está definida";
    }
    operacion.setContendido(valor);
    listaInstrucciones.push_back(operacion);
}

string lectorTextEdit::analizarLinea(int scope, int numeroLinea, string nombre, string tipo, string linea, int valorAsignado) {
    vector<int> operaciones;
    vector<char> operadores = {'/','*','%','+','-',')','('};
    int parentesis = 0;
    string valor;
    string valorAux;
    if (valorAsignado != 0) {
        for (int i = valorAsignado + 1; i < linea.size(); i++) {
            for (int j = 0; j < operadores.size(); j++) {
                if (operadores[j] == linea[i]) {
                    operaciones.push_back(i-(valorAsignado + 1));
                }
                if (i == 6) {
                    parentesis ++;
                }
                if (i == 5) {
                    parentesis --;
                }
            }
            valor += linea[i];
        }
        if (parentesis != 0) {
            valor = "ERROR_FALTA_PARENTESIS";
        }
        if (operaciones.empty()) {
            valor = valor.substr(0,valor.size()-1);
            try {
                stoi(valor);
            } catch(std::invalid_argument& e) {
                if ( valor  != "ERROR_FALTA_PARENTESIS") {
                    valorAux = buscarValor(valor,tipo,scope);
                    if (valorAux == "ERROR_VARIABLE_NO_DEFINIDA") {
                        valor = valor + " no está definida ";
                    } else {
                        valor = valorAux;
                    }
                    if (valorAux == "ERROR_VARIABLE_FUERA_SCOPE") {
                        valor = valor + " no está dentro del scope de: " + nombre;
                    } else {
                        valor = valorAux;
                    }
                } else {
                    valor = "Falta un paréntesis en la línea: "+std::to_string(numeroLinea);
                }
            }
        } else {
            vector<vector<string>> res = ordenarOperaciones(operaciones,valor);
            valor = realizarOperacion(res,tipo,scope,valor);
        }
    }
    else {
        valor = "El valor no está iniciado";
    }
    return valor;
}

void lectorTextEdit::imprimir(string texto, int numLinea) {
    Grafo aux = Grafo();
    aux.setNumeroLinea(numLinea);
    texto = texto.substr(0,texto.size()-1);
    string nombre = buscarNombreVariable(texto);
    if (nombre == "ERROR_VARIABLE_NO_DEFINIDA") {
        aux.setContendido(texto);
        aux.setNombreVariable("Cout");
    } else {
        aux.setNombreVariable(texto);
        aux.setContendido(listaInstrucciones[stoi(nombre)].getContenido());
    }
    listaInstrucciones.push_back(aux);
}

std::vector<Grafo> lectorTextEdit::getListaInstrucciones() {
    return listaInstrucciones;
}

void lectorTextEdit::aumentarReferenciaVariable(string nombre) {
    for (int i = 0; i < numReferenciaVariables[0].size(); i++) {
        if (nombre == numReferenciaVariables[0][i]) {
            numReferenciaVariables[1][i] = stoi(numReferenciaVariables[1][i]) + 1;
            return;
        }
    }
    numReferenciaVariables[0].push_back(nombre);
    numReferenciaVariables[1].push_back(to_string(1));
}

void lectorTextEdit::crearVariablesStruct(int scope, int numeroLinea, string linea) {
    Grafo aux = Grafo();
    linea = linea.substr(6,linea.size()-1);
    string nombreTipoStruct;
    string nombreStruct;
    for (int i = 0; i < linea.size()-1; i++) {
        nombreTipoStruct += linea[i];
        for (int j = 0; j < nombreEstructuras.size(); j++) {
            if (nombreEstructuras[j] == nombreTipoStruct) {
                nombreStruct = linea.substr(i+1,linea.size()-1);
                i = linea.size();
                break;
            }
        }
    }
    if (nombreTipoStruct == linea) {
        aux.setContendido("La estructura " + nombreTipoStruct + " no se encuentra definida");
        aux.setNumeroLinea(numeroLinea);
        aux.setScope(scope);
        listaInstrucciones.push_back(aux);
    } else {
        string nombreStructMiembro;
        vector<string> miembros;
        for (int i = 0; i < miembrosEstructuras[0].size(); i++) {
            for (int j = 0; j < miembrosEstructuras[0][i].size(); j++) {
                if (miembrosEstructuras[0][i][j] == '.') {
                    break;
                }
                nombreStructMiembro += miembrosEstructuras[0][i][j];
            }
            if (nombreStructMiembro == nombreTipoStruct) {
                miembros.push_back(miembrosEstructuras[0][i].substr(nombreStructMiembro.size()+1,miembrosEstructuras[0][i].size()));
            }
            else {
                break;
            }
            nombreStructMiembro = "";
        }
        nombreStructMiembro = "";
        enStruct = "def";
        for (int i = 0; i < miembros.size(); i++) {
            nombreStructMiembro.append(miembrosEstructuras[1][i]);
            nombreStructMiembro.append(nombreStruct.substr(0,nombreStruct.size()-1));
            nombreStructMiembro.append(".");
            nombreStructMiembro.append(miembros[i]);
            nombreStructMiembro.append(";");
            agregarInstruccion(nombreStructMiembro,numeroLinea,scope);
            nombreStructMiembro = "";
        }

    }
}

void lectorTextEdit::inicializarMemoria(QTextEdit *log) {
    comunicador com;
    formuladorMensajes msj = formuladorMensajes(26,cantidadTiposDatos);
    com.setListaInstrucciones(listaInstrucciones);
    com.sendMsj(msj.getMensaje());
    log->append(QString::fromStdString(msj.getTipoRequest()));
    msj = formuladorMensajes(28,numReferenciaVariables);
    com.sendMsj(msj.getMensaje());
    log->append(QString::fromStdString(msj.getTipoRequest()));
    msj = formuladorMensajes(12);
    com.sendMsj(msj.getMensaje());
    log->append(QString::fromStdString(msj.getTipoRequest()));

}
