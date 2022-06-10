#pragma once
#include "Facilitate.h"
#include <string>
#include <vector>

using std::string, std::vector;

class Abonament
{
private:
	vector<Facilitate> facilitati;
	float pretTotal;
	string denumire;
public:
	Abonament();
	Abonament(const Abonament& ot) {
		this->pretTotal = ot.pretTotal;
		this->denumire = ot.denumire;
		this->facilitati = ot.facilitati;

	}
	Abonament(string denumire, float pretTotal) {
		this->denumire = denumire;
		this->pretTotal = pretTotal;
	}

	vector <Facilitate> getFacilitati();
	float getPret();

	void adaugaFacilitate(Facilitate f);

	void setPret(float pretTotal);


};

