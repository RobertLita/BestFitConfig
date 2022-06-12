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
		for (const auto& abonament : this->abonamente) {
			if (a.equalsAbonamente(abonament)) {
				throw error1("Abonamentul exista deja!")
			}
		}

		this->abonamente.push_back(a);
	}

	

	void deleteAbonament(Abonament a) {
		for (Abonament ab : abonamente) {
			
			if (a.equalsAbonamente(ab))
				abonamente.erase(i);
	
		}
	}

};

