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
#include <string>

class GUI : public QWidget
{

public:
	GUI(ServiceFacilitati& serviceFacilitati, ServiceAbonamente& serviceAbonamente, ServiceClienti& serviceClienti) : serviceAbonamente{ serviceAbonamente }, serviceClienti{ serviceClienti }, serviceFacilitati{ serviceFacilitati }
	{
		initGUI();
		void loadDataFacilitati(vector <Facilitate> facilitati);
		void loadDataAbonamente(vector <Abonament> abonamente);
		void loadDataClienti(vector <Client> Clienti);
		initConnect();
	};

private:

	void initConnect();
	void initGUI();

	void loadDataFacilitati(vector <Facilitate> facilitati);
	void loadDataAbonamente(vector <Abonament> abonamente);
	void loadDataClienti(vector <Client> Clienti);

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

	// denumire, descirere, pret individual
	QLineEdit* denumireFacilitate = new QLineEdit;
	QLineEdit* descriereFacilitate = new QLineEdit;
	QLineEdit* pretIndividualFacilitate = new QLineEdit;
	QFormLayout* facilitatiForm = new QFormLayout;
	QPushButton* bStergeFacilitate = new QPushButton{ "&Sterge facilitate" };
	QPushButton* bModificaFacilitate = new QPushButton{ "&Modifica facilitate" };
	QPushButton* bAdaugaFacilitate = new QPushButton{ "&Adauga facilitate" };


	QWidget* windowAbonamente = new QWidget;
	QListWidget* lstAbonamente = new QListWidget;

	QPushButton* bStergeAbonament = new QPushButton{ "&Sterge abonament" };
	QPushButton* bAdaugaAbonament = new QPushButton{ "&Adauga abonament" };


};

