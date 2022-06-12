#pragma once
#include "RepositoryFacilitati.h"

class ServiceFacilitati
{

private:
	RepositoryFacilitati repository;
public:
	ServiceFacilitati(RepositoryFacilitati repo) : repository{ repo } {};

	void addFacilitate(Facilitate f) {
		this->repository.addFacilitate(f);
	}

	void stergeFacilitate(Facilitate f) {
		this->repository.stergeFacilitate(f);
	}

	void findFacilitate(string denumire) {
		this->repository.findFacilitate(denumire);
	}

	void updateFacilitate(Facilitate fv, Facilitate fn) {
		this->repository.updateFacilitate(fv, fn);
	}
};

