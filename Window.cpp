//
// Created by andres on 16/03/18.
//

#include <QtCore/QObject>
#include "Window.h"
#include "dependencias/Server/headers/formuladorMensajes.h"
#include "dependencias/Server/headers/comunicador.h"

Window::Window(QWidget *parent) :
        QWidget(parent) {
    setFixedSize(900, 650);
    this->setWindowTitle("C! IDE");

    contenedor_Botones = new QLabel(this);
    contenedor_Botones->setGeometry(665, 0, 235, 28);
    contenedor_Botones->setFrameStyle(1);
    contenedor_Botones->show();

    etiqueta_Ram = new QLabel(this);
    etiqueta_Ram->setText("Dir                       Valor   Nomb   Ref");
    etiqueta_Ram->setGeometry(665,28,235,25);
    etiqueta_Ram->setFrameStyle(1);
    etiqueta_Ram->show();

    contenedor_Dir = new QTextEdit(this);
    contenedor_Dir->setGeometry(665,50,105,500);
    contenedor_Dir->setReadOnly(true);
    contenedor_Dir->setFrameStyle(1);
    contenedor_Dir->show();

    contenedor_Nombres = new QTextEdit(this);
    contenedor_Nombres->setGeometry(770,50,50,500);
    contenedor_Nombres->setReadOnly(true);
    contenedor_Nombres->setFrameStyle(1);
    contenedor_Nombres->show();

    contenedor_Valor = new QTextEdit(this);
    contenedor_Valor->setGeometry(820,50,40,500);
    contenedor_Valor->setReadOnly(true);
    contenedor_Valor->setFrameStyle(1);
    contenedor_Valor->show();

    contenedor_Ref = new QTextEdit(this);
    contenedor_Ref->setFrameStyle(1);
    contenedor_Ref->setGeometry(860,50,40,500);
    contenedor_Ref->setReadOnly(true);
    contenedor_Ref->show();

    editor = new QTextEdit(this);
    editor->setGeometry(25, 0, 640, 500);
    editor->show();
    editor->setFrameStyle(1);

    numLineas = new QLabel(this);
    numLineas->setGeometry(0, 0, 25, 500);
    numLineas->show();
    numLineas->setFrameStyle(1);
    numLineas->setAlignment(Qt::AlignTop);
    numLineas->setText(QString::fromStdString(agregarLineas()));

    salida = new QTextEdit(">", this);
    salida->setFrameStyle(1);
    salida->setGeometry(0, 500, 900, 75);
    salida->setReadOnly(true);
    salida->show();

    log = new QTextEdit("", this);
    log->setText("IDE iniciado");
    log->setFrameStyle(1);
    log->setGeometry(0, 575, 900, 75);
    log->setReadOnly(true);
    log->show();

    clearLog = new QToolButton(log);
    clearLog->setIcon(QIcon("../uiImages/botonLimpiarLog.png"));
    clearLog->setIconSize(QSize(12,12));
    clearLog->setAutoFillBackground(true);
    clearLog->setGeometry(865, 1, 20, 20);
    clearLog->show();

    ejecutar = new QToolButton(contenedor_Botones);
    ejecutar->setIcon(QIcon("../uiImages/botonPlayVerde.png"));
    ejecutar->setIconSize(QSize(15, 15));
    ejecutar->setAutoFillBackground(true);
    ejecutar->setGeometry(1, 1, 25, 25);
    ejecutar->show();

    debug = new QToolButton(contenedor_Botones);
    debug->setIcon(QIcon("../uiImages/botonDebugVerde.png"));
    debug->setIconSize(QSize(15, 15));
    debug->setAutoFillBackground(true);
    debug->setGeometry(30, 1, 25, 25);
    debug->show();

    stop = new QToolButton(contenedor_Botones);
    stop->setIcon(QIcon("../uiImages/botonStopRojo.png"));
    stop->setIconSize(QSize(15, 15));
    stop->setAutoFillBackground(true);
    stop->setGeometry(60, 1, 25, 25);
    stop->show();

    siguienteDebug = new QToolButton(contenedor_Botones);
    siguienteDebug->setIcon(QIcon("../uiImages/boton_Siguiente_Debug.png"));
    siguienteDebug->setIconSize(QSize(85,55));
    siguienteDebug->setGeometry(85,1,65,25);
    siguienteDebug->hide();

    connect(ejecutar,SIGNAL(clicked()),this,SLOT(BotonEjecutarCodigo()));
    connect(clearLog,SIGNAL(clicked()),this,SLOT(BotonClearLog()));
    connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(quitMyApp()));
    connect(debug,SIGNAL(clicked()),this,SLOT(BotonDebugCodigo()));
    connect(stop,SIGNAL(clicked()),this,SLOT(BotonDetenerEjecucionCodigo()));
    connect(siguienteDebug,SIGNAL(clicked()),this,SLOT(BotonAvanzarDebug()));

}

string Window::agregarLineas() {
    string resultado;
    for (int i = 0; i <numeroMaxLinea; i++) {
        if (std::to_string(i).size() == 1) {
            resultado += "  ";
        };
        resultado += std::to_string(i)+"\n";
    }
    return resultado;
}

void Window::quitMyApp() {
    remove("a.cpp");
    remove("a.out");
}

void Window::BotonClearLog() {
    log->setText(QString::fromStdString(""));
}

QString Window::obtenerLecturaEditor() {
    return editor->toPlainText();
}

void Window::BotonEjecutarCodigo() {
    if (obtenerLecturaEditor().size() == 0){
        return;
    }
    lectura = lectorTextEdit(obtenerLecturaEditor());
    lectura.generarSalidaCodigo();
    lectura.ejecutarCodigo(log,salida);
}

void Window::BotonDetenerEjecucionCodigo() {
    debug->setEnabled(true);
    ejecutar->setEnabled(true);
    siguienteDebug->hide();
    editor->setReadOnly(false);
    if (indiceInstrucciones != instrucciones.size()) {
        log->append("Ejecución detenida");
    }
    lineaActual = 0;
    indiceInstrucciones = 0;
    log->append("Fin ejecución");
}

void Window::BotonDebugCodigo() {
    log->append("Iniciando Debug");
    if (obtenerLecturaEditor().size() == 0){
        return;
    }
    lectura = lectorTextEdit(obtenerLecturaEditor());
    lectura.debugCodigo(log,salida);
    debug->setEnabled(false);
    ejecutar->setEnabled(false);
    siguienteDebug->show();
    editor->setReadOnly(true);
    instrucciones = lectura.getListaInstrucciones();
    log->append("Instrucciones leídas");
    if (instrucciones.empty()) {
        BotonDetenerEjecucionCodigo();
    }
}

void Window::BotonAvanzarDebug() {
    if (indiceInstrucciones == instrucciones.size()) {
        BotonDetenerEjecucionCodigo();
        numLineas->setText(QString::fromStdString(agregarLineas()));
        return;
    } else {
        string contenido;
        if (instrucciones[indiceInstrucciones].getContenido().empty()) {
            contenido = "0";
        } else {
            contenido = instrucciones[indiceInstrucciones].getContenido();
        }
        salida->setText(QString::fromStdString(instrucciones[indiceInstrucciones].getNombreVariable() +" -> "+ contenido));
        lineaActual = instrucciones[indiceInstrucciones].getNumeroLinea();
        mostrarLinea();
        formuladorMensajes msj = formuladorMensajes(12);
        comunicador com;
        com.sendMsj(msj.getMensaje());
        log->append(QString::fromStdString(msj.getTipoRequest()));
        actualizarCuadroRam();
        indiceInstrucciones ++;
    }
}

void Window::mostrarLinea() {
    string resultado;
    for (int i = 0; i <numeroMaxLinea; i++) {
        if (i == lineaActual) {
            resultado += "->\n";
        } else {
            if (std::to_string(i).size() == 1) {
                resultado += "  ";
            }
            resultado += std::to_string(i)+"\n";
        }
    }
    numLineas->setText(QString::fromStdString(resultado));
}

void Window::actualizarCuadroRam() {
    int indice = 0;
    string linea;
    ifstream file ("./ContRam.txt");
    int i = 0;
    contenedor_Ref->clear();
    contenedor_Nombres->clear();
    contenedor_Valor->clear();
    contenedor_Ref->clear();
    while (getline(file,linea)) {
        if (i == 0) {
            log->append(QString::fromStdString(linea));
            i = 1;
        } else {
            if (indice == 0) {
                contenedor_Dir->append(QString::fromStdString(linea));
            }
            if (indice == 1) {
                contenedor_Valor->append(QString::fromStdString(linea));
            }
            if (indice == 2) {
                contenedor_Nombres->append(QString::fromStdString(linea));
            }
            if (indice == 3) {
                indice = -1;
                contenedor_Ref->append(QString::fromStdString(linea));
            }
            indice++;
        }
    }
    file.close();
}