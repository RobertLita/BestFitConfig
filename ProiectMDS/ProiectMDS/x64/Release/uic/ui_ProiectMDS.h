/********************************************************************************
** Form generated from reading UI file 'ProiectMDS.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROIECTMDS_H
#define UI_PROIECTMDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProiectMDSClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProiectMDSClass)
    {
        if (ProiectMDSClass->objectName().isEmpty())
            ProiectMDSClass->setObjectName(QString::fromUtf8("ProiectMDSClass"));
        ProiectMDSClass->resize(600, 400);
        menuBar = new QMenuBar(ProiectMDSClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ProiectMDSClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProiectMDSClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ProiectMDSClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ProiectMDSClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ProiectMDSClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ProiectMDSClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ProiectMDSClass->setStatusBar(statusBar);

        retranslateUi(ProiectMDSClass);

        QMetaObject::connectSlotsByName(ProiectMDSClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProiectMDSClass)
    {
        ProiectMDSClass->setWindowTitle(QCoreApplication::translate("ProiectMDSClass", "ProiectMDS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProiectMDSClass: public Ui_ProiectMDSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROIECTMDS_H
