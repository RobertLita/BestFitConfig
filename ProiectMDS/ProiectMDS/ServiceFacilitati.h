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
};

