#include "GUI.h"

void GUI::initConnect() {
	
	QObject::connect(bExit, &QPushButton::clicked, [&]() {
		close();
		});

	QObject::connect(bFacilitati, &QPushButton::clicked, [&](){
		windowFacilitati->show();
		
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
	windowFacilitati->setLayout(lyFacilitati);


}