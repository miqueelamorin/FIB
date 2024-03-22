#include "MyQLCDNumber.h"

MyQLCDNumber::MyQLCDNumber(QWidget *parent):QLCDNumber(parent){ 
    connect(&tempo, SIGNAL(timeout()), this, SLOT(mostrar_temps()));
    temps = QTime(0,0,0,0);
    setDigitCount(12);
    display(temps.toString(Qt::ISODateWithMs));
    record = QTime(23,59,59,999);
    primera_vegada = true;
    estat_start = false;
}

void MyQLCDNumber::iniciar_i_parar(){
    if (not estat_start) tempo.start(1);
    else tempo.stop();

    estat_start = not estat_start;
}

void MyQLCDNumber::mostrar_temps(){
    temps = temps.addMSecs(1);

    if (not primera_vegada){
        if (temps < record) emit color_temps(QString("color: green;"));
        else if (temps == record) emit color_temps(QString("color: black;"));
        else emit color_temps(QString("color: red;"));
    }

    display(temps.toString(Qt::ISODateWithMs));
}

void MyQLCDNumber::restaurar(){
    tempo.stop();
    if (primera_vegada) primera_vegada = false;
    estat_start = false;

    if (temps < record) {
        record = temps;
        emit actualitzar_record(record.toString(Qt::ISODateWithMs));
    }

    temps = QTime(0,0,0,0);
    display(temps.toString(Qt::ISODateWithMs));
    emit color_temps(QString("color: black;"));
}
