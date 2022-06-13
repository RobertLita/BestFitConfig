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

	Client findClient(string CNP) {
		return this->repository.findClient(CNP);
	}
	bool existaClient(string CNP) {
		return this->repository.existaClient(CNP);
	}


	void updateClient(Client cv, Client cn) {
		this->repository.updateClient(cv, cn);
	}
	vector <Client> getClienti() {
		return repository.getClienti();
	}
};

