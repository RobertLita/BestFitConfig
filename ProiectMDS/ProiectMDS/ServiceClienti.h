#pragma once
#include "RepositoryClienti.h"

class ServiceClienti
{

private:
	RepositoryClienti repository;
public:
	ServiceClienti(RepositoryClienti repo) : repository{ repo } {};

	void addClient(Client c) {
		this->repository.addClient(c);
	}

	void deleteClient(Client c) {
		this->repository.deleteClient(c);
	}

	void findClient(string CNP) {
		this->repository.findClient(CNP);
	}

	void updateClient(Client cv, Client cn) {
		this->repository.updateClient(cv, cn);
	}
};

