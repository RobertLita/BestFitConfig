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
};

