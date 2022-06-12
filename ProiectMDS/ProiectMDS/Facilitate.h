#pragma once

#include <string>
#include <vector>
#include <stdexcept>

using std::string;


class Facilitate
{

private:
	string descriere, denumire;
	int pretIndividual;
public:
	Facilitate(string denumire, string descriere, int pretIndividual);

	string getDenumire();
	string getDescriere();
	int getPret();

	void setDenumire(string denumire);
	void setDescriere(string descriere);
	void setPret(int pretIndividual);

	bool esteValid() {
		
		if (this->pretIndividual < 0) {
			throw invalid_argument("Pretul nu poate sa fie negativ.");
		}
	}


	friend bool operator==(Facilitate& lhs, Facilitate& rhs) {
		return !lhs.getDenumire().compare(rhs.getDenumire());
	}

	friend bool operator!=(Facilitate& lhs, Facilitate& rhs) {
		return !(rhs == lhs);
	}
};

