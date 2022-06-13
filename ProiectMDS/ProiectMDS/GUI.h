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
#include <QtDebug>
#include <ctime>

class GUI : public QWidget
{

public:
	GUI(ServiceFacilitati& serviceFacilitati, ServiceAbonamente& serviceAbonamente, ServiceClienti& serviceClienti):
		serviceAbonamente{ serviceAbonamente },
		serviceClienti{ serviceClienti },
		serviceFacilitati{ serviceFacilitati }
	{
		initGUI();
		void loadDataFacilitati(vector <Facilitate> facilitati);
		void loadDataFacilitatiAbonamente(vector <Facilitate> facilitati);
		void loadDataAbonamenteClienti(vector <Abonament> abonamente);
		void loadDataAbonamente(vector <Abonament> abonamente);
		void loadDataClienti(vector <Client> clienti);
		initConnect();
	};

private:

	void initConnect();
	void initGUI();

	void loadDataFacilitati(vector <Facilitate> facilitati);
	void loadDataAbonamente(vector <Abonament> abonamente);
	void loadDataClienti(vector <Client> clienti);
	void loadDataFacilitatiAbonamente(vector <Facilitate> facilitati);
	void loadDataAbonamenteClienti(vector <Abonament> abonamente);


	ServiceFacilitati& serviceFacilitati;
	ServiceAbonamente& serviceAbonamente;
	ServiceClienti& serviceClienti;
	QPushButton* bExit = new QPushButton{ "&Exit" };
	QPushButton* bFacilitati = new QPushButton{ "&Facilitati" };
	QPushButton* bClienti = new QPushButton{ "&Lista clienti existenti" };
	QPushButton* bClientNou = new QPushButton{ "&Inregistreaza un client nou" };
	QPushButton* bIdentificaClient = new QPushButton{ "&Verifica abonament client" };

	QPushButton* bAbonamente = new QPushButton{ "&Abonamente" };
	QWidget* windowFacilitati = new QWidget;

	QListWidget* lstFacilitati = new QListWidget;

	// denumire, descirere, pret individual
	QLineEdit* denumireFacilitate = new QLineEdit;
	QLineEdit* descriereFacilitate = new QLineEdit;
	QLineEdit* pretIndividualFacilitate = new QLineEdit;
	QLabel* facilitatiileSunt = new QLabel{"Facilitati existente:"};
	QFormLayout* facilitatiForm = new QFormLayout;
	QPushButton* bStergeFacilitate = new QPushButton{ "&Sterge facilitate" };
	QPushButton* bModificaFacilitate = new QPushButton{ "&Modifica facilitate" };
	QPushButton* bAdaugaFacilitate = new QPushButton{ "&Adauga facilitate" };

	QWidget* windowFacilitatiModifica = new QWidget;
	QFormLayout* facilitatiFormModifica = new QFormLayout;
	QLineEdit* denumireFacilitateModifica = new QLineEdit;
	QLineEdit* descriereFacilitateModifica = new QLineEdit;
	QLineEdit* pretIndividualFacilitateModifica = new QLineEdit;
	QPushButton* bModificaFacilitate2 = new QPushButton{ "&Modifica facilitatea selectata" };



	QWidget* windowAbonamente = new QWidget;
	QListWidget* lstAbonamente = new QListWidget;
	QListWidget* lstFacilitatiAbonamente = new QListWidget;
	

	QPushButton* bStergeAbonament = new QPushButton{ "&Sterge abonament" };
	QPushButton* bAdaugaAbonament = new QPushButton{ "&Adauga abonament" };
	QPushButton* bAdaugaAbonament2 = new QPushButton{ "&Adauga abonament" };

	QWidget* windowAdaugaAbonament = new QWidget;
	QFormLayout* adaugaAbonamentForm = new QFormLayout;
	QLineEdit* denumireAbonament = new QLineEdit;
	QLineEdit* pretAbonament = new QLineEdit;
	QLabel* abonamenteleSunt = new QLabel{ "Lista abonamente:" };

	QLabel* pretFacilitatiCalculat = new QLabel;

	QListWidget* facilitatiAbonament = new QListWidget;
	QFormLayout* infoAbonamentForm = new QFormLayout;

	QLabel* infoDenumireAbonament = new QLabel;
	QLabel* infoPretAbonament = new QLabel;


	QWidget* windowAdaugaClient = new QWidget;
	QLineEdit* numeClient = new QLineEdit;
	QLineEdit* prenumeClient = new QLineEdit;
	QLineEdit* CNPClient = new QLineEdit;
	QLineEdit* oras = new QLineEdit;
	QLineEdit* strada = new QLineEdit;
	QLineEdit* numar = new QLineEdit;
	QLineEdit* detalii = new QLineEdit;
	QListWidget* lstAbonamenteClienti = new QListWidget;

	QFormLayout* formClient = new QFormLayout;
	QFormLayout* formClientAdresa = new QFormLayout;

	QPushButton* bAdaugaClient = new QPushButton{"&Adauga clientul"};

	QWidget* windowClienti = new QWidget;
	QListWidget* lstClienti = new QListWidget;

	QLabel* afisareNumeClient = new QLabel;
	QLabel* afisarePrenumeClient = new QLabel;
	QLabel* afisareAdresaClient = new QLabel;
	QLabel* afisareAbonamentClient = new QLabel;
	QLabel* afisareDataExpirareAbonamentClient = new QLabel;

	QPushButton* bStergeClient = new QPushButton{"&Sterge clientul"};

	QWidget* windowVerificaAbonament= new QWidget;
	QLineEdit* inputCNP = new QLineEdit;

	QPushButton* bVerificaValabilitate = new QPushButton{ "&Verifica valabilitate abonament" };
	QPushButton* bReinnoiesteAbonament = new QPushButton{ "&Reinnoieste abonament" };



};

