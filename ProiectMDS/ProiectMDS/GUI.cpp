#include "GUI.h"
#include "Facilitate.h"

void GUI::initConnect() {


	
	QObject::connect(bExit, &QPushButton::clicked, [&]() {
		close();
		});

	QObject::connect(bFacilitati, &QPushButton::clicked, [&](){
		windowFacilitati->show();
		
		});

	QObject::connect(bAbonamente, &QPushButton::clicked, [&]() {
		windowAbonamente->show();

		});


	QObject::connect(lstFacilitati, &QListWidget::itemDoubleClicked, [&]() {

		auto el = lstFacilitati->currentItem()->text();

		Facilitate f = serviceFacilitati.findFacilitate(el.toStdString());

		

		QStringList splitted = el.split(", ");


		denumireFacilitate->setText(QString::fromStdString(f.getDenumire()));
		descriereFacilitate->setText(QString::fromStdString(f.getDescriere()));
		pretIndividualFacilitate->setText(QString::number(f.getPret()));

		});

	QObject::connect(lstAbonamente, &QListWidget::itemDoubleClicked, [&]() {

		string abonament = lstAbonamente->currentItem()->text().toStdString();

		Abonament a = serviceAbonamente.findAbonament(abonament);
		infoDenumireAbonament->setText(QString::fromStdString(a.getDenumire()));
		infoPretAbonament->setText(QString::number(a.getPret()));

		vector <Facilitate> facilitati = a.getFacilitati();

		facilitatiAbonament->clear();

		for (Facilitate f : facilitati) {
			string denumire = f.getDenumire();
			QListWidgetItem* current = new QListWidgetItem();
			current->setText(QString::fromStdString(denumire));
			facilitatiAbonament->addItem(current);
		}


		});


	QObject::connect(bAdaugaFacilitate, &QPushButton::clicked, [&]() {
		try {
			string denumire = denumireFacilitate->text().toStdString();
			string descriere = descriereFacilitate->text().toStdString();
			int pret = pretIndividualFacilitate->text().toInt();

			Facilitate f(denumire, descriere, pret);

			serviceFacilitati.addFacilitate(f);
			loadDataFacilitati(serviceFacilitati.getFacilitati());

			denumireFacilitate->clear();
			descriereFacilitate->clear();
			pretIndividualFacilitate->clear();

		}
		catch (runtime_error err) {
			QString mesaj = QString::fromStdString(err.what());
			QMessageBox::information(nullptr, "Eroare", mesaj);
		}
		});

	QObject::connect(bStergeFacilitate , &QPushButton::clicked, [&]() {
		try {
			string denumire = denumireFacilitate->text().toStdString();
			string descriere = descriereFacilitate->text().toStdString();
			int pret = pretIndividualFacilitate->text().toInt();

			Facilitate f(denumire, descriere, pret);

			serviceFacilitati.stergeFacilitate(f);
			loadDataFacilitati(serviceFacilitati.getFacilitati());

			denumireFacilitate->clear();
			descriereFacilitate->clear();
			pretIndividualFacilitate->clear();
		}
		catch (runtime_error err) {
			QString mesaj = QString::fromStdString(err.what());
			QMessageBox::information(nullptr, "Eroare", mesaj);
		}

		});
	QObject::connect(bModificaFacilitate, &QPushButton::clicked, [&]() {
		windowFacilitatiModifica->show();

		});


	QObject::connect(bModificaFacilitate2, &QPushButton::clicked, [&]() {
		try {
			string denumire = denumireFacilitate->text().toStdString();
			string descriere = descriereFacilitate->text().toStdString();
			int pret = pretIndividualFacilitate->text().toInt();

			Facilitate f(denumire, descriere, pret);



			string denumireModifica = denumireFacilitateModifica->text().toStdString();
			string descriereModifica = descriereFacilitateModifica->text().toStdString();
			int pretModifica = pretIndividualFacilitateModifica->text().toInt();

			Facilitate f2(denumireModifica, descriereModifica, pretModifica);

			serviceFacilitati.updateFacilitate(f, f2);

			loadDataFacilitati(serviceFacilitati.getFacilitati());
			windowFacilitatiModifica->hide();

			denumireFacilitate->clear();
			descriereFacilitate->clear();
			pretIndividualFacilitate->clear();
			denumireFacilitateModifica->clear();
			descriereFacilitateModifica->clear();
			pretIndividualFacilitateModifica->clear();

		}
		catch (runtime_error err) {
			QString mesaj = QString::fromStdString(err.what());
			QMessageBox::information(nullptr, "Eroare", mesaj);
		}

		});

	QObject::connect(bAbonamente, &QPushButton::clicked, [&]() {
		windowAbonamente->show();
		loadDataFacilitatiAbonamente(serviceFacilitati.getFacilitati());
		});


	QObject::connect(bAdaugaAbonament, &QPushButton::clicked, [&]() {
			windowAdaugaAbonament->show();
			
		});

	QObject::connect(lstFacilitatiAbonamente, &QListWidget::itemSelectionChanged, [&]() {
		vector <Facilitate> facilitati;
		auto lista = lstFacilitatiAbonamente->QListWidget::selectedItems();

		int pretCalculat = 0;
		for (auto facilitate : lista)
		{
			auto numeFacilitate = facilitate->text().toStdString();
			Facilitate f = serviceFacilitati.findFacilitate(numeFacilitate);
			facilitati.push_back(f);
			pretCalculat += f.getPret();
		}

		pretFacilitatiCalculat->setText(QString::fromStdString(to_string(pretCalculat)));
		
		});

	QObject::connect(bAdaugaAbonament2, &QPushButton::clicked, [&]() {
		try {
			string denumire = denumireAbonament->text().toStdString();
			int pret = pretAbonament->text().toInt();

			auto lista = lstFacilitatiAbonamente->QListWidget::selectedItems();
			vector <Facilitate> facilitati;
			int pretCalculat = 0;
			for (auto facilitate : lista)
			{
				auto numeFacilitate = facilitate->text().toStdString();
				Facilitate f = serviceFacilitati.findFacilitate(numeFacilitate);
				facilitati.push_back(f);
				pretCalculat += f.getPret();
			}

			pretFacilitatiCalculat->setText(QString::fromStdString(to_string(pretCalculat)));

			Abonament a(denumire, pret, facilitati);
			serviceAbonamente.addAbonament(a);
			loadDataFacilitatiAbonamente(serviceFacilitati.getFacilitati());
			loadDataAbonamente(serviceAbonamente.getAbonamente());

			windowAdaugaAbonament->close();
			
		}
		catch (runtime_error err) {
			QString mesaj = QString::fromStdString(err.what());
			QMessageBox::information(nullptr, "Eroare", mesaj);
		}

		});

	QObject::connect(bStergeAbonament, &QPushButton::clicked, [&]() {
		try {
			lstAbonamente->setCurrentRow(0);
			if (lstAbonamente->selectedItems().count() == 0)
				throw(runtime_error("Nu exista abonamente"));
			string denumire = lstAbonamente->currentItem()->text().toStdString();

			Abonament a = serviceAbonamente.findAbonament(denumire);

			serviceAbonamente.stergeAbonament(a);

			loadDataFacilitatiAbonamente(serviceFacilitati.getFacilitati());
			loadDataAbonamente(serviceAbonamente.getAbonamente());

		}
		catch (runtime_error err) {
			QString mesaj = QString::fromStdString(err.what());
			QMessageBox::information(nullptr, "Eroare", mesaj);
		}

		});


	QObject::connect(bClientNou, &QPushButton::clicked, [&]() {
		try {
			if (serviceAbonamente.getAbonamente().size() == 0)
				throw runtime_error("Nu exista niciun abonament. Pentru a avea clienti trebuie sa existe abonamente.");
			windowAdaugaClient->show();
			loadDataAbonamenteClienti(serviceAbonamente.getAbonamente());
		}
		catch (runtime_error err) {
			QString mesaj = QString::fromStdString(err.what());
			QMessageBox::information(nullptr, "Eroare", mesaj);
		}
		});
	

	QObject::connect(bAdaugaClient, &QPushButton::clicked, [&]() {
		try {
			lstAbonamenteClienti->setCurrentRow(0);
			string nume = numeClient->text().toStdString();
			string prenume = prenumeClient->text().toStdString();
			string CNP = CNPClient->text().toStdString();

			string orasC = oras->text().toStdString();
			string stradaC = strada->text().toStdString();
			string numarC = numar->text().toStdString();
			string detaliiC = detalii->text().toStdString();

			Adresa adresa(orasC, stradaC, numarC, detaliiC);

			/*string denumire = serviceAbonamente.findAbonament(lstAbonamenteClienti->currentItem()->text().toStdString()).getDenumire();
			int pret = serviceAbonamente.findAbonament(lstAbonamenteClienti->currentItem()->text().toStdString()).getPret();
			vector <Facilitate> facilitati = serviceAbonamente.findAbonament(lstAbonamenteClienti->currentItem()->text().toStdString()).getFacilitati();
			
			Abonament abonament(denumire, pret, facilitati);*/
			Abonament abonament(serviceAbonamente.findAbonament(lstAbonamenteClienti->currentItem()->text().toStdString()));


			chrono::system_clock::time_point now = chrono::system_clock::now();
			time_t tt = chrono::system_clock::to_time_t(now);
			tm local_tm = *localtime(&tt);
			
			int zi = local_tm.tm_mday;
			int an = local_tm.tm_year + 1900;
			int luna = local_tm.tm_mon + 2;
			if (luna > 12) {
				luna = 1;
				an += 1;
			}

			if (luna == 2) {
				if (zi > 28)
					luna += 1;
					zi = zi - 28;
			}


			Date data(zi, luna, an);

			Client c(adresa, nume, prenume, CNP, abonament, data);

			serviceClienti.addClient(c);
			loadDataAbonamenteClienti(serviceAbonamente.getAbonamente());
			windowAdaugaClient->hide();
		}
		catch (runtime_error err) {
			QString mesaj = QString::fromStdString(err.what());
			QMessageBox::information(nullptr, "Eroare", mesaj);
		}


		});
	QObject::connect(bClienti, &QPushButton::clicked, [&]() {
		try {
			if (serviceClienti.getClienti().size() == 0)
				throw runtime_error("Nu exista clienti in baza de date");
			loadDataClienti(serviceClienti.getClienti());
			windowClienti->show();
		}
		catch (runtime_error err) {
			QString mesaj = QString::fromStdString(err.what());
			QMessageBox::information(nullptr, "Eroare", mesaj);
		}

		});

	QObject::connect(lstClienti, &QListWidget::itemDoubleClicked, [&]() {

		auto el = lstClienti->currentItem()->text();
		QStringList splitted = el.split(", ");

		Client c (serviceClienti.findClient(splitted[2].toStdString()));

		afisareNumeClient->setText(QString::fromStdString(c.getNume()));
		afisarePrenumeClient->setText(QString::fromStdString(c.getPrenume()));
		afisareAdresaClient->setText(QString::fromStdString(c.getAdresa().getOras()+
			", Strada " + c.getAdresa().getStrada() +
			", numarul " + c.getAdresa().getNumar() +
			".\n Alte detalii: " + c.getAdresa().getDetalii()));
		afisareAbonamentClient->setText(QString::fromStdString(c.getAbonament().getDenumire()));
		afisareDataExpirareAbonamentClient->setText(QString::fromStdString(to_string(c.getData().getZi())+"."
		+ to_string(c.getData().getLuna())+"."
		+ to_string(c.getData().getAn())));


		});
	QObject::connect(bStergeClient, &QPushButton::clicked, [&]() {
		try {
			if (serviceClienti.getClienti().size() == 0)
				throw runtime_error("Nu exista clienti!");

			auto el = lstClienti->currentItem()->text();
			QStringList splitted = el.split(", ");

			Client c(serviceClienti.findClient(splitted[2].toStdString()));
			serviceClienti.deleteClient(c);
			loadDataClienti(serviceClienti.getClienti());
			lstClienti->setCurrentRow(0);

		}
		catch (runtime_error err) {
			QString mesaj = QString::fromStdString(err.what());
			QMessageBox::information(nullptr, "Eroare", mesaj);
		}


		});
	QObject::connect(bIdentificaClient, &QPushButton::clicked, [&]() {
		
		windowVerificaAbonament->show();
			
		});
	QObject::connect(bVerificaValabilitate, &QPushButton::clicked, [&]() {

		string CNP = inputCNP->text().toStdString();

		try {
			if (serviceClienti.existaClient(CNP))
			{


				chrono::system_clock::time_point now = chrono::system_clock::now();
				time_t tt = chrono::system_clock::to_time_t(now);
				tm local_tm = *localtime(&tt);

				int zi = local_tm.tm_mday;
				int an = local_tm.tm_year + 1900;
				int luna = local_tm.tm_mon;
				if (luna > 12) {
					luna = 1;
					an += 1;
				}

				if (luna == 2) {
					if (zi > 28)
						luna += 1;
					zi = zi - 28;
				}

				Client c(serviceClienti.findClient(CNP));
				bool ok = true;
				if (c.getData().getAn() < an)
					ok = false;
				else if (c.getData().getAn() == an && c.getData().getLuna() < luna)
					ok = false;
				else if (c.getData().getAn() == an && c.getData().getLuna() == luna && c.getData().getZi() < zi)
					ok = false;

				if (ok)
				{
					QString mesaj = QString::fromStdString("Abonament valid!");
					QMessageBox::information(nullptr, "Eroare", mesaj);
				}

				else {
					QString mesaj = QString::fromStdString("Abonament expirat!");
					QMessageBox::information(nullptr, "Eroare", mesaj);
				}

			}

			else {
				QString mesaj = QString::fromStdString("Client inexistent!");
				QMessageBox::information(nullptr, "Eroare", mesaj);
			}

		}
		catch (runtime_error err) {
			QString mesaj = QString::fromStdString(err.what());
			QMessageBox::information(nullptr, "Eroare", mesaj);
		}
		});

	QObject::connect(bReinnoiesteAbonament, &QPushButton::clicked, [&]() {

		try {
			string CNP = inputCNP->text().toStdString();

			if (serviceClienti.existaClient(CNP))
			{


				chrono::system_clock::time_point now = chrono::system_clock::now();
				time_t tt = chrono::system_clock::to_time_t(now);
				tm local_tm = *localtime(&tt);
					
				int zi = local_tm.tm_mday;
				int an = local_tm.tm_year + 1900;
				int luna = local_tm.tm_mon + 1;
				if (luna > 12) {
					luna = 1;
					an += 1;
				}

				if (luna == 2) {
					if (zi > 28)
						luna += 1;
					zi = zi - 28;
				}
				Date dNou(zi, luna + 1, an);
				Client c(serviceClienti.findClient(CNP));
				serviceClienti.deleteClient(c);

				c.setData(dNou);
				serviceClienti.addClient(c);

				loadDataClienti(serviceClienti.getClienti());

			}

			else {
				QString mesaj = QString::fromStdString("Client inexistent!");
				QMessageBox::information(nullptr, "Eroare", mesaj);
			}

		}
		catch (runtime_error err) {
			QString mesaj = QString::fromStdString(err.what());
			QMessageBox::information(nullptr, "Eroare", mesaj);
		}
		});
}

void GUI::initGUI() {

	loadDataFacilitati(serviceFacilitati.getFacilitati());
	loadDataFacilitatiAbonamente(serviceFacilitati.getFacilitati());
	loadDataAbonamente(serviceAbonamente.getAbonamente());
	loadDataAbonamenteClienti(serviceAbonamente.getAbonamente());
	loadDataClienti(serviceClienti.getClienti());

	QVBoxLayout* lyMain = new QVBoxLayout{};
	setLayout(lyMain);
	lyMain->addWidget(bExit);
	lyMain->addWidget(bClienti);
	lyMain->addWidget(bClientNou);
	lyMain->addWidget(bIdentificaClient);
	lyMain->addWidget(bAbonamente);
	lyMain->addWidget(bFacilitati);


	QPalette paletteRed = bExit->palette();
	paletteRed.setColor(QPalette::ButtonText, QColor(Qt::red));
	paletteRed.setColor(QPalette::Button, QColor(Qt::red));
	bExit->setAutoFillBackground(true);
	bExit->setPalette(paletteRed);
	bExit->update();

	QVBoxLayout* lyFacilitati = new QVBoxLayout{};
	
	lyFacilitati->addWidget(facilitatiileSunt);

	lyFacilitati->addWidget(lstFacilitati);
	facilitatiForm->addRow("Denumire: ", denumireFacilitate);
	facilitatiForm->addRow("Descriere: ", descriereFacilitate);
	facilitatiForm->addRow("Pret: ", pretIndividualFacilitate);

	QHBoxLayout* lyFacilitatiButoane = new QHBoxLayout{};
	lyFacilitatiButoane->addWidget(bStergeFacilitate);
	lyFacilitatiButoane->addWidget(bAdaugaFacilitate);
	lyFacilitatiButoane->addWidget(bModificaFacilitate);

	lyFacilitati->addLayout(lyFacilitatiButoane);

	lyFacilitati->addLayout(facilitatiForm);
	windowFacilitati->setLayout(lyFacilitati);


	QVBoxLayout* lyFacilitatiModifica = new QVBoxLayout{};

	facilitatiFormModifica->addRow("Denumire noua: ", denumireFacilitateModifica);
	facilitatiFormModifica->addRow("Descriere noua: ", descriereFacilitateModifica);
	facilitatiFormModifica->addRow("Pret nou: ", pretIndividualFacilitateModifica);

	lyFacilitatiModifica->addLayout(facilitatiFormModifica);
	lyFacilitatiModifica->addWidget(bModificaFacilitate2);
	windowFacilitatiModifica->setLayout(lyFacilitatiModifica);

	QVBoxLayout* lyAbonamente = new QVBoxLayout{};

	lyAbonamente->addWidget(abonamenteleSunt);
	lyAbonamente->addWidget(lstAbonamente);
	QHBoxLayout* lyAbonamenteButoane = new QHBoxLayout{};

	lyAbonamenteButoane->addWidget(bStergeAbonament);
	lyAbonamenteButoane->addWidget(bAdaugaAbonament);

	lyAbonamente->addLayout(lyAbonamenteButoane);


	QHBoxLayout* lyInfoAbonament = new QHBoxLayout{};


	infoAbonamentForm->addRow("Denumire abonament: ", infoDenumireAbonament);
	infoAbonamentForm->addRow("Pret abonament: ", infoPretAbonament);
	infoAbonamentForm->addRow("Lista Facilitati: ", facilitatiAbonament);

	lyInfoAbonament->addLayout(infoAbonamentForm);

	lyAbonamente->addLayout(lyInfoAbonament);

	windowAbonamente->setLayout(lyAbonamente);
	lstFacilitatiAbonamente->setSelectionMode(QAbstractItemView::MultiSelection);




	QVBoxLayout* lyAdaugaAbonament = new QVBoxLayout{};
	lyAdaugaAbonament->addWidget(lstFacilitatiAbonamente);

	adaugaAbonamentForm->addRow("Denumire abonament: ", denumireAbonament);
	adaugaAbonamentForm->addRow("Pret abonament: ", pretAbonament);
	adaugaAbonamentForm->addRow("Total preturi facilitati: ", pretFacilitatiCalculat);


	lyAdaugaAbonament->addLayout(adaugaAbonamentForm);
	lyAdaugaAbonament->addWidget(bAdaugaAbonament2);
	windowAdaugaAbonament->setLayout(lyAdaugaAbonament);


	QVBoxLayout* lyAdaugaClient = new QVBoxLayout{};

	formClient->addRow("Nume: ", numeClient);
	formClient->addRow("Prenume: ", prenumeClient);
	formClient->addRow("CNP: ", CNPClient);
	
	formClientAdresa->addRow("Oras: ", oras);
	formClientAdresa->addRow("Strada: ", strada);
	formClientAdresa->addRow("Numar: ", numar);
	formClientAdresa->addRow("Alte detalii: ", detalii);


	QHBoxLayout* infoClient = new QHBoxLayout{};

	infoClient->addLayout(formClient);
	infoClient->addLayout(formClientAdresa);

	lyAdaugaClient->addLayout(infoClient);

	lyAdaugaClient->addWidget(lstAbonamenteClienti);
	lyAdaugaClient->addWidget(bAdaugaClient);
	windowAdaugaClient->setLayout(lyAdaugaClient);

	QVBoxLayout* totiClientii = new QVBoxLayout{};
	totiClientii->addWidget(lstClienti);
	
	QFormLayout* formInfoClienti = new QFormLayout;



	formInfoClienti->addRow("Nume client: ",afisareNumeClient);
	formInfoClienti->addRow("Prenume client: ", afisarePrenumeClient);
	formInfoClienti->addRow("Adresa client: ", afisareAdresaClient);
	formInfoClienti->addRow("Abonament: ", afisareAbonamentClient);
	formInfoClienti->addRow("Data expirare abonament: ", afisareDataExpirareAbonamentClient);

	totiClientii->addLayout(formInfoClienti);
	totiClientii->addWidget(bStergeClient);
	windowClienti->setLayout(totiClientii);
	
	QVBoxLayout* lyVerificaAbonament = new QVBoxLayout{};
	QFormLayout* formInfoAbonament = new QFormLayout;

	formInfoAbonament->addRow("CNP: ", inputCNP);
	
	lyVerificaAbonament->addLayout(formInfoAbonament);
	lyVerificaAbonament->addWidget(bVerificaValabilitate);
	lyVerificaAbonament->addWidget(bReinnoiesteAbonament);
	windowVerificaAbonament->setLayout(lyVerificaAbonament);


}

void GUI::loadDataFacilitati(vector <Facilitate> facilitati) {
	lstFacilitati->clear();
	for (auto el : facilitati) {
		string facilitate = el.getDenumire();
		QListWidgetItem* f = new QListWidgetItem(QString::fromStdString(facilitate));
		lstFacilitati->addItem(f);
	}
}

void GUI::loadDataFacilitatiAbonamente(vector <Facilitate> facilitati) {
	lstFacilitatiAbonamente->clear();
	for (auto el : facilitati) {
		string facilitate = el.getDenumire();
		QListWidgetItem* f = new QListWidgetItem(QString::fromStdString(facilitate));
		lstFacilitatiAbonamente->addItem(f);
	}
}

void GUI::loadDataAbonamente(vector <Abonament> abonamente) {
	lstAbonamente->clear();
	
	for (auto el : abonamente) {
		string abonament = el.getDenumire();
		QListWidgetItem* f = new QListWidgetItem(QString::fromStdString(abonament));
		lstAbonamente->addItem(f);
	}
}

void GUI::loadDataAbonamenteClienti(vector <Abonament> abonamente) {
	lstAbonamenteClienti->clear();

	for (auto el : abonamente) {
		string abonament = el.getDenumire();
		QListWidgetItem* f = new QListWidgetItem(QString::fromStdString(abonament));
		lstAbonamenteClienti->addItem(f);
	}
}



void GUI::loadDataClienti(vector <Client> clienti) {
	lstClienti->clear();

	for (auto el : clienti) {
		string client = el.getNume() + ", " + el.getPrenume() + ", " + el.getCNP();
		QListWidgetItem* f = new QListWidgetItem(QString::fromStdString(client));
		lstClienti->addItem(f);
	}
}