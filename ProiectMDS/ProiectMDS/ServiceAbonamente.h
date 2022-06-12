#pragma once
#include "RepositoryAbonamente.h"

class ServiceAbonamente
{

private:
	RepositoryAbonamente repository;
public:
	ServiceAbonamente(RepositoryAbonamente repo) : repository{ repo } {};

	void addAbonament(Abonament a) {
		this->repository.addAbonament(a);
	}
};

