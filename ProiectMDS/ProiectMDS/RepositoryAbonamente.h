#pragma once

#include <vector>
#include <string>
#include "Abonament.h"

using std::vector, std::string;

class RepositoryAbonamente
{
private:
	vector <Abonament> abonamente;

	RepositoryAbonamente();

	void addAbonament(Abonament a) {
		this->abonamente.push_back(a);
	}


};

