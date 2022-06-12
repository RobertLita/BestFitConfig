#pragma once

#include <vector>
#include <string>
#include "Abonament.h"

using std::vector, std::string;

class RepositoryAbonamente
{
private:
	vector <Abonament> abonamente;

public:

	RepositoryAbonamente() {};

	void addAbonament(Abonament a) {
		for (auto& abonament : this->abonamente) {
			if (abonament == a) {
				throw std::runtime_error("Facilitatea exista deja!");
			}
		}

		this->abonamente.push_back(a);

	}

	void stergeAbonament(Abonament a) {
		if (a.esteValid()) {
			int pozitie = -1;
			for (int i = 0; i < this->abonamente.size(); i++)
				if (this->abonamente[i] == a) {
					pozitie = i;
				}
			if (pozitie == -1) {
				throw std::runtime_error("Nu exista acest client!");
			}
			this->abonamente.erase(this->abonamente.begin() + pozitie);
		}
	}

	Abonament findAbonament(string denumire) {
		for (auto& abonament : this->abonamente) {
			if (abonament.getDenumire() == denumire) {
				return abonament;
			}
		}
	}

	void updateAbonament(Abonament av, Abonament an) {
		stergeAbonament(av);
		addAbonament(an);
	}

};

