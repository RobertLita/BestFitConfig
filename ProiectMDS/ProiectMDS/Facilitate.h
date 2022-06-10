#pragma once

#include <string>
#include <vector>

using std::string;


class Facilitate
{

private:
	string descriere, denumire;
	float pretIndividual;
public:
	Facilitate(string denumire, string descriere, float pretIndividual);

	string getDenumire();
	string getDescriere();
	float getPret();

	void setDenumire(string denumire);
	void setDescriere(string descriere);
	void setPret(float pretIndividual);

};

