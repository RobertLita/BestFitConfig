#pragma once

#include <string>
#include <regex>

using std::string;
using std::regex_match;

class Adresa
{
private:
	string oras, strada, numar, detalii;
public:
	Adresa();

	Adresa(string oras, string strada, string numar, string detalii) {
		this->oras = oras;
		this->strada = strada;
		this->numar = numar;
		this->detalii = detalii;
	}

	string getOras() { return this->oras; };
	string getStrada() { return this->strada; };
	string getNumar() { return this->numar; };
	string getDetalii() { return this->detalii; };

	void setOras(string oras) {
		this->oras = oras;
	}
	void setStrada(string strada) {
		this->strada = strada;

	}

	void setNumar(string numar) {
		this->numar = numar;
	}

	void setDetalii(string detalii) {
		this->detalii = detalii;
	}

	friend bool operator==(const Adresa& lhs, const Adresa& rhs) {
		return !(lhs.oras.compare(rhs.oras)||
			lhs.strada.compare(rhs.strada) ||
			lhs.numar.compare(rhs.numar) ||
			lhs.detalii.compare(rhs.detalii));
	}

	friend bool operator!=(const Adresa& lhs, const Adresa& rhs) {
		return !(rhs == lhs);
	}
	bool esteValid() {
		bool rez;
		rez = !std::regex_match(oras, std::regex("^[A-Za-z]+$")) && !std::regex_match(strada, std::regex("^[A-Za-z]+$")) && !std::regex_match(numar, std::regex("^[0-9]+$"));
		return rez;
	}

};
