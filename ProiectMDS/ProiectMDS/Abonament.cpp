#include "Abonament.h"


vector <Facilitate> Abonament::getFacilitati() {
    return this->facilitati;
}


int Abonament::getPret() {
    return this->pretTotal;
}

string Abonament::getDenumire() {
    return this->denumire;
}


void Abonament::adaugaFacilitate(Facilitate f) {
    this->facilitati.push_back(f);
}

void Abonament::setPret(int pretTotal) {
    this->pretTotal = pretTotal;
}

void Abonament::setDenumire(string denumire) {
    this->denumire = denumire;
}