#pragma once
#include "RepositoryFacilitati.h"

class ServiceFacilitati
{

private:
	RepositoryFacilitati repository;
public:
	ServiceFacilitati(RepositoryFacilitati repo) : repository{ repo } {};

	void addFacilitate(Facilitate f) {
		f.esteValid();
		this->repository.addFacilitate(f);
	}

	vector <Facilitate> getFacilitati() {
		return this->repository.getFacilitati();
	}
	void stergeFacilitate(Facilitate f) {
		this->repository.stergeFacilitate(f);
	}

	Facilitate findFacilitate(string denumire) {
		return this->repository.findFacilitate(denumire);
	}

	void updateFacilitate(Facilitate fv, Facilitate fn) {
		this->repository.updateFacilitate(fv, fn);
	}

};

