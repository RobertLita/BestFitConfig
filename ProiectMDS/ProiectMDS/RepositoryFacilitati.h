#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Facilitate.h"
#include <stdexcept>

using std::vector, std::string, std::fstream;

class RepositoryFacilitati
{
private:
	vector <Facilitate> facilitati;

public:
	RepositoryFacilitati() {};



	void addFacilitate(Facilitate f) {
		for (auto& facilitate : this->facilitati) {
			if (facilitate == f) {
				throw std::runtime_error("Facilitatea exista deja!");
			}
		}
		
		this->facilitati.push_back(f);
		
	}

	void stergeFacilitate(Facilitate f) {
		if (f.esteValid()) {
			int pozitie = -1;
			for (int i = 0; i < this->facilitati.size(); i++)
				if (this->facilitati[i] == f) {
					pozitie = i;
				}
			if (pozitie == -1) {
				throw std::runtime_error("Nu exista acest client!");
			}
			this->facilitati.erase(this->facilitati.begin() + pozitie);
		}
	}

	Facilitate findFacilitate(string denumire) {
		for (auto& facilitate : this->facilitati) {
			if (facilitate.getDenumire() == denumire) {
				return facilitate;
			}
		}
	}

	void updateFacilitate(Facilitate fv, Facilitate fn) {
		stergeFacilitate(fv);
		addFacilitate(fn);
	}



};

