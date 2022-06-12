#pragma once

#include <string>
#include <chrono>
#include <type_traits>
#include <format>
#include <regex>

using std::string;
using std::regex;
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

	bool esteValid(Adresa a) {
		bool rez;
		rez	= !std::regex_match(a.oras, std::regex("^[A-Za-z]+$")) && !std::regex_match(a.strada, std::regex("^[A-Za-z]+$")) && !std::regex_match(a.numar, std::regex("^[0-9]+$"));
		return rez;
	}
};
