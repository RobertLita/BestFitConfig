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
	int pretTotal;
	string denumire;
public:
	Abonament();
	Abonament(const Abonament& ot) {
		this->pretTotal = ot.pretTotal;
		this->denumire = ot.denumire;
		this->facilitati = ot.facilitati;

	}
	Abonament(string denumire, int pretTotal) {
		this->denumire = denumire;
		this->pretTotal = pretTotal;
	}



	vector <Facilitate> getFacilitati();

	int getPret();

	string getDenumire();

	void adaugaFacilitate(Facilitate f);

	void setPret(int pretTotal);

	void  setDenumire(string denumire);

	bool esteValid() {

		if (this->pretTotal < 0) {
			throw invalid_argument("Pretul nu poate sa fie negativ.");
		}
	}


	friend bool operator==(Abonament& lhs, Abonament& rhs) {
		return !lhs.getDenumire().compare(rhs.getDenumire());
	}

	friend bool operator!=(Facilitate& lhs, Facilitate& rhs) {
		return !(rhs == lhs);
	}

};

