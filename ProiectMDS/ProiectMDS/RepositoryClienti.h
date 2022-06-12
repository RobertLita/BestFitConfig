#pragma once

#include <vector>
#include <string>
#include "Client.h"

using std::vector, std::string;

class RepositoryClienti
{
private:
	vector <Client> clienti;
public:

	RepositoryClienti() {};

	void addClient(Client c) {
		this->clienti.push_back(c);
	}


};

