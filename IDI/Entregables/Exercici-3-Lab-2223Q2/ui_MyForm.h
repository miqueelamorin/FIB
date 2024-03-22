/********************************************************************************
** Form generated from reading UI file 'MyForm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MyQLCDNumber.h"

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    MyQLCDNumber *Crono;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *Record;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *Start;
    QPushButton *Restart;
    QSpacerItem *horizontalSpacer;
    QPushButton *Exit;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QString::fromUtf8("MyForm"));
        MyForm->resize(640, 398);
        layoutWidget = new QWidget(MyForm);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 26, 601, 351));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        Crono = new MyQLCDNumber(layoutWidget);
        Crono->setObjectName(QString::fromUtf8("Crono"));
        Crono->setMinimumSize(QSize(0, 100));
        Crono->setStyleSheet(QString::fromUtf8(""));
        Crono->setSmallDecimalPoint(false);
        Crono->setDigitCount(12);
        Crono->setMode(QLCDNumber::Dec);
        Crono->setProperty("value", QVariant(0.000000000000000));

        verticalLayout->addWidget(Crono);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        Record = new QLabel(layoutWidget);
        Record->setObjectName(QString::fromUtf8("Record"));
        QFont font2;
        font2.setPointSize(14);
        Record->setFont(font2);

        horizontalLayout_2->addWidget(Record);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Start = new QPushButton(layoutWidget);
        Start->setObjectName(QString::fromUtf8("Start"));

        horizontalLayout->addWidget(Start);

        Restart = new QPushButton(layoutWidget);
        Restart->setObjectName(QString::fromUtf8("Restart"));

        horizontalLayout->addWidget(Restart);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Exit = new QPushButton(layoutWidget);
        Exit->setObjectName(QString::fromUtf8("Exit"));

        horizontalLayout->addWidget(Exit);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(MyForm);
        QObject::connect(Exit, SIGNAL(clicked()), MyForm, SLOT(close()));
        QObject::connect(Restart, SIGNAL(clicked()), Crono, SLOT(restaurar()));
        QObject::connect(Start, SIGNAL(clicked()), Crono, SLOT(iniciar_i_parar()));
        QObject::connect(Crono, SIGNAL(actualitzar_record(QString)), Record, SLOT(setText(QString)));
        QObject::connect(Crono, SIGNAL(color_temps(QString)), Crono, SLOT(setStyleSheet(QString)));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QCoreApplication::translate("MyForm", "Cronometre", nullptr));
        label_5->setText(QCoreApplication::translate("MyForm", "Cronometre", nullptr));
        label->setText(QCoreApplication::translate("MyForm", "Record:", nullptr));
        Record->setText(QCoreApplication::translate("MyForm", "--:--:--:---", nullptr));
        Start->setText(QCoreApplication::translate("MyForm", "&Start/Stop", nullptr));
        Restart->setText(QCoreApplication::translate("MyForm", "&Restart", nullptr));
        Exit->setText(QCoreApplication::translate("MyForm", "&Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H
