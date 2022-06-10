#pragma once

#include <vector>
#include <string>
#include "Facilitate.h"

using std::vector, std::string;

class RepositoryFacilitati
{
private:
	vector <Facilitate> facilitati;

	RepositoryFacilitati();

	void addClient(Facilitate f) {
		this->facilitati.push_back(f);
	}


};

