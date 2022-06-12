#include "GUI.h"

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

}

void GUI::initGUI() {

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

	QVBoxLayout* lyAbonamente = new QVBoxLayout{};

	lyAbonamente->addWidget(lstAbonamente);
	QHBoxLayout* lyAbonamenteButoane = new QHBoxLayout{};

	lyAbonamenteButoane->addWidget(bStergeAbonament);
	lyAbonamenteButoane->addWidget(bAdaugaAbonament);

	lyAbonamente->addLayout(lyAbonamenteButoane);

	windowAbonamente->setLayout(lyAbonamente);
}

void GUI::loadDataFacilitati(vector <Facilitate> facilitati) {
	lstFacilitati->clear();
	for (auto el : facilitati) {
		string facilitate = el.getDenumire() + ", " + el.getDescriere() + ", "
			+ std::to_string(el.getPret());
		QListWidgetItem* f = new QListWidgetItem(QString::fromStdString(facilitate));
		lstFacilitati->addItem(f);
	}
}

void GUI::loadDataAbonamente(vector <Abonament> abonamente) {
	return;
}