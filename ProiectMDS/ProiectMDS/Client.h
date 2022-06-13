#pragma once
#include "Adresa.h"
#include "Abonament.h"
#include <string>
#include <stdexcept>
#include "Date.h"

using namespace std;

class Client
{
private:
	Adresa adresa;
	string nume, prenume, CNP;
	Abonament abonament;
	Date data_expirare;

public:
	Client(Adresa adresa, string nume, string prenume, string CNP, Abonament abonament, Date data) {
		this->adresa = adresa;
		this->nume = nume;
		this->prenume = prenume;
		this->abonament = abonament;
		this->CNP = CNP;
		this->data_expirare = data;
	}

	Client(const Client& ot) {
		this->adresa = ot.adresa;
		this->nume = ot.nume;
		this->prenume = ot.prenume;
		this->abonament = ot.abonament;
		this->CNP = ot.CNP;
		this->data_expirare = ot.data_expirare;
	}

	Client() = default;


	Adresa getAdresa() { return this->adresa; }

	string getNume() { return this->nume; }

	string getPrenume() { return this->prenume; }

	string getCNP() { return this->CNP; }

	void setCNP(string cnp) {
		this->CNP = cnp;
	}

	void setAdresa(Adresa a) {
		this->adresa = a;
	}

	void setData(Date d) {
		this->data_expirare.setZi(d.getZi());
		this->data_expirare.setLuna(d.getLuna());
		this->data_expirare.setAn(d.getAn());

	}

	Date getData() { return this->data_expirare; }

	Abonament getAbonament() { return this->abonament; }

	void setAdresa(string oras, string strada, string numar, string detalii) {
		this->adresa.setStrada(strada);
		this->adresa.setOras(oras);
		this->adresa.setNumar(numar);
		this->adresa.setDetalii(detalii);

	}

	void setNume(string nume) {
		this->nume = nume;
	}

	void setPrenume(string prenume) {
		this->prenume = prenume;
	}

	void setAbonament(Abonament ot) {
		this->abonament = ot;
	}

	bool esteValid() {
		if (this->CNP.length() != 13) {
			throw runtime_error("CNP-ul trebuie sa aiba lungimea 13!");
		}
		for (char i : this->CNP) {
			if (isalpha(i)) {
				throw runtime_error("CNP-ul trebuie sa contina doar cifre!");
			}
		}

		for (char i : this->nume) {
			if (!isalpha(i) && i != ' ' && i != '-') {
				throw runtime_error("Numele trebuie sa contina doar litere!");
			}
		}

		for (char i : this->prenume) {
			if (!isalpha(i) && i != ' ' && i != '-') {
				throw runtime_error("Preumele trebuie sa contina doar litere!");
			}
		}

		return this->adresa.esteValid() && this->data_expirare.esteValid();
	}

	friend bool operator==(Client& lhs, Client& rhs) {
		return !lhs.getCNP().compare(rhs.getCNP());
	}

	friend bool operator!=(Client& lhs, Client& rhs) {
		return !(rhs == lhs);
	}

};

