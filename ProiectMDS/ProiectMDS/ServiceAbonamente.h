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

	void stergeAbonament(Abonament a) {
		this->repository.stergeAbonament(a);
	}

	void findAbonament(string denumire) {
		this->repository.findAbonament(denumire);
	}

	void updateAbonament(Abonament av, Abonament an) {
		this->repository.updateAbonament(av, an);
	}

};

