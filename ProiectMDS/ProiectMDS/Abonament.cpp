#include "Abonament.h"


vector <Facilitate> Abonament::getFacilitati() {
	return this->facilitati;
}


float Abonament::getPret() {
	return this->pretTotal;
}

void Abonament::adaugaFacilitate(Facilitate f) {
	this->facilitati.push_back(f);
}

void Abonament::setPret(float pretTotal) {
	this->pretTotal = pretTotal;
}