#pragma once
#include <QtDebug>
#include <QTableWidget> 
#include "ServiceClienti.h"
#include "ServiceFacilitati.h"
#include "ServiceAbonamente.h"
#include <qwhatsthis.h>
#include <qslider.h>
#include <qspinbox.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/qmainwindow.h>
#include <qapplication.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qboxlayout.h>
#include <QFormLayout> 
#include <QtWidgets/qlistwidget.h>
#include <qdebug.h>
#include <qmessagebox.h>
#include <vector>
#include <string>
#include <QtDebug>
#include <QTableWidget> 
#include <qwhatsthis.h>
#include <qslider.h>
#include <qspinbox.h>

class GUI : public QWidget
{

public:
	GUI(ServiceFacilitati& serviceFacilitati, ServiceAbonamente& serviceAbonamente, ServiceClienti& serviceClienti) : serviceAbonamente{ serviceAbonamente }, serviceClienti{ serviceClienti }, serviceFacilitati{ serviceFacilitati }
	{
		initGUI();
		loadData();
		initConnect();
	};

private:

	void initConnect();
	void initGUI();

	void loadData() {};

	ServiceFacilitati& serviceFacilitati;
	ServiceAbonamente& serviceAbonamente;
	ServiceClienti& serviceClienti;
	QPushButton* bExit = new QPushButton{ "&Exit" };
	QPushButton* bFacilitati = new QPushButton{ "&Facilitati" };
	QPushButton* bClienti = new QPushButton{ "&Lista clienti existenti" };
	QPushButton* bClientNou = new QPushButton{ "&Inregistreaza un client nou" };
	QPushButton* bIdentificaClient = new QPushButton{ "&Identifica un client" };

	QPushButton* bAbonamente = new QPushButton{ "&Abonamente" };
	QWidget* windowFacilitati = new QWidget;
	QListWidget* lstFacilitati = new QListWidget;

};

