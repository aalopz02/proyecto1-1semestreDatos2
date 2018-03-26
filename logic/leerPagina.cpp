//
// Created by andres on 18/03/18.
//

#include "../headers/leerPagina.h"

leerPagina::leerPagina(int numeroLinea) {
    numeroLineaBuscar = numeroLinea;

}

void leerPagina::buscarArchivo() {
    string nombreArchivo = buscarLinea();
    ifstream archivo;
    archivo.open(nombreArchivo);
    string line;
    vector<string> listaLineas;
    if (archivo.is_open()) {
        while (getline (archivo,line)) {
            listaLineas.push_back(line);
        }
    }
    pagina1 = pagina(std::stoi(listaLineas[0]));
    pagina1.instruccion(listaLineas[1]+"\n"+listaLineas[2]+"\n"+listaLineas[3]+"\n");
    pagina1.instruccion(listaLineas[4]+"\n"+listaLineas[5]+"\n"+listaLineas[6]+"\n");
    if (std::stoi(listaLineas[7]) == 1) {
        pagina1.crearNueva();
    }

}

string leerPagina::buscarLinea() {
    mServer *mServer1 = mServer::getMemServer();
    int paginaMedia = (mServer1->obtenerCantidadPag() / 2);
    string nombreArchivo = std::to_string(paginaMedia)+".dat";
    ifstream archivo1;
    archivo1.open(nombreArchivo);
    string line;
    int numLinea;
    if (archivo1.is_open())
    {
        for (int linea = 0; getline (archivo1,line) && linea < 7; linea++) {
            if (linea == 6 || linea == 3) {
                numLinea = std::stoi(line);;
                if (numLinea == numeroLineaBuscar) {
                    return nombreArchivo;
                }
            }
        }
        archivo1.close();
    }
    else {
        cout << "El archivo no existe";
    }
    if (numeroLineaBuscar > numLinea) {
        return buscarLineaAux(paginaMedia+1, mServer1->obtenerCantidadPag()-1);
    }
    return buscarLineaAux(0,paginaMedia-1);

}

string leerPagina::buscarLineaAux(int inicio, int fin) {
    string nombreArchivo = std::to_string(inicio)+".dat";
    while (inicio != fin) {
        ifstream archivo1;
        archivo1.open(nombreArchivo);
        string line;
        int numLinea;
        if (archivo1.is_open())
        {
            for (int linea = 0; getline (archivo1,line) && linea < 7; linea++) {
                if (linea == 6 || linea == 3) {
                    numLinea = std::stoi(line);;
                    if (numLinea == numeroLineaBuscar) {
                        return nombreArchivo;
                    }
                }
            }
            archivo1.close();
        }
        inicio++;
        nombreArchivo = std::to_string(inicio)+".dat";
    }
    return nombreArchivo;

}

pagina leerPagina::obtenepagina() {
    return pagina1;

}