#pragma once
#include "Facilitate.h"
#include <string>
#include <vector>
#include <stdexcept>

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

	bool esteValid() {
		for (char c : this->denumire) {
			if (!isalpha(c)) {
				throw invalid_argument("Denumirea trebuie sa contina doar litere.");
			}
		}
	}

	bool equalsAbonamente(Abonament a) {
		if (a.denumire == this->denumire && a.pretTotal == this->pretTotal && a.facilitati == this->facilitati)
			return true;
		return false;
	}


};

