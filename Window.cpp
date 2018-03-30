//
// Created by andres on 16/03/18.
//

#include <QtCore/QObject>
#include "Window.h"

Window::Window(QWidget *parent) :
        QWidget(parent) {
    setFixedSize(900, 650);
    this->setWindowTitle("C! IDE");

    contenedor_Botones = new QLabel(this);
    contenedor_Botones->setGeometry(665, 0, 235, 28);
    contenedor_Botones->setFrameStyle(1);
    contenedor_Botones->show();

    contenedor_Ram = new QLabel(this);
    contenedor_Ram->setGeometry(665,28,235,472);
    contenedor_Ram->setFrameStyle(1);
    contenedor_Ram->show();

    editor = new QTextEdit(this);
    editor->setGeometry(15, 0, 650, 500);
    editor->show();
    editor->setFrameStyle(1);

    numLineas = new QLabel(this);
    numLineas->setGeometry(0, 0, 15, 500);
    numLineas->show();
    numLineas->setFrameStyle(1);
    numLineas->setAlignment(Qt::AlignTop);
    numLineas->setText("1\n");
    numeroMaxLinea = 1;

    salida = new QLabel(">", this);
    salida->setFrameStyle(1);
    salida->setGeometry(0, 500, 900, 75);
    salida->show();

    log = new QTextEdit("", this);
    log->setText("\n\n\n\n");
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

    connect(ejecutar,SIGNAL(clicked()),this,SLOT(BotonEjecutarCodigo()));
    connect(clearLog,SIGNAL(clicked()),this,SLOT(BotonClearLog()));
    connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(quitMyApp()));
    connect(debug,SIGNAL(clicked()),this,SLOT(BotonDebugCodigo()));

}

void Window::quitMyApp() {
    remove("a.cpp");
    remove("a.out");
}

void Window::BotonClearLog() {
    log->setText("\n\n\n\n");
}

QString Window::obtenerLecturaEditor() {
    return editor->toPlainText();
}

void Window::BotonEjecutarCodigo() {
    if (obtenerLecturaEditor().size() == 0){
        return;
    }
    lectorTextEdit lectura = lectorTextEdit(obtenerLecturaEditor());
    lectura.generarSalidaCodigo(log,salida);
}

void Window::BotonDetenerEjecucionCodigo() {

}

void Window::BotonDebugCodigo() {
    if (obtenerLecturaEditor().size() == 0){
        return;
    }
    lectorTextEdit lectura = lectorTextEdit(obtenerLecturaEditor());
    lectura.debugCodigo(log,salida);
}

void Window::cambiarNumeroLineas() {
    numeroMaxLinea ++;
    string numlineas;
    for (int i = 0; i < numeroMaxLinea; i++) {
        numlineas += std::to_string(i) + "\n";
    }
    numLineas->setText(QString::fromStdString(numlineas));
}

void Window::keyPressEvent(QKeyEvent *event) {
    if(event->key()==Qt::Key_Down) {
        cout << "Ok";
    }
}