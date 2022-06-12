#include "Facilitate.h"


string Facilitate::getDenumire() {
	return this->denumire;
}

string Facilitate::getDescriere() {
	return this->descriere;
}

int Facilitate::getPret() {
	return this->pretIndividual;
}

void Facilitate::setDenumire(string denumire) {
	this->denumire = denumire;
}


void Facilitate::setDescriere(string descriere) {
	this->descriere = descriere;
}

void Facilitate::setPret(int pret) {
	this->pretIndividual = pret;
}