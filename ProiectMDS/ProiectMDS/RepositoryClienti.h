#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Client.h"
#include "RepositoryAbonamente.h"


using namespace std;

class RepositoryClienti
{
private:
	vector <Client> clienti;
public:

	RepositoryClienti() {
		this->clienti = readClienti();
	};
	void writeClient(Client c) {
		fstream fout;
		fout.open("clienti.csv", ios_base::app);
		fout << c.getCNP() << '#' << c.getNume() << '#' << c.getPrenume() << '#' << c.getAbonament().getDenumire() << '#'
			<< c.getAdresa().getOras() << '#' << c.getAdresa().getStrada() << '#' << c.getAdresa().getNumar() << '#'
			<< c.getAdresa().getDetalii() << '#' << c.getData().getZi() << '#' << c.getData().getLuna() << '#'
			<< c.getData().getAn() << '\n';
		fout.close();
	}
	void deleteClientF(Client c) {
		fstream fout;
		fout.open("clienti.csv", std::ofstream::out | std::ofstream::trunc);
		fout.close();
		for (Client c : this->clienti) {
			writeClient(c);
		}
	}


	void addClient(Client c) {
		for (auto& client : this->clienti) {
			if (client == c) {
				throw runtime_error("Clientul exista deja!");
			}
		}
		if (c.esteValid()) {
			this->clienti.push_back(c);
			writeClient(c);
		}
	}

	void deleteClient(Client c) {
		if (c.esteValid()) {
			int pozitie = -1;
			for (int i = 0; i < this->clienti.size(); i++)
				if (this->clienti[i] == c) {
					pozitie = i;
				}
			if (pozitie == -1) {
				throw runtime_error("Nu exista acest client!");
			}
			this->clienti.erase(this->clienti.begin() + pozitie);
			deleteClientF(c);
		}
	}

	Client findClient(string CNP) {
		for (auto& client : this->clienti) {
			if (client.getCNP() == CNP) {
				return client;
			}
		}
	}

	bool existaClient(string CNP) {
		for (auto& client : this->clienti) {
			if (client.getCNP() == CNP) {
				return true;
			}

		}
		return false;
	}

	void updateClient(Client cv, Client cn) {
		deleteClient(cv);
		addClient(cn);
	}

	vector <Client> getClienti() {
		return this->clienti;
	}

	vector<Facilitate> readFacilitati() {
		vector<Facilitate> fac;
		fstream fin;
		fin.open("facilitati.csv", ios::in);
		vector<string> row;
		string line, word, temp;
		while (getline(fin, temp)) {
			row.clear();
			stringstream s(temp);
			while (getline(s, word, '#')) {
				const std::string& str(word);
				row.push_back(word);
			}
			Facilitate f(row[0], row[1], atoi(row[2].c_str()));
			fac.push_back(f);
		}
		fin.close();
		return fac;
	}

	vector <Abonament> readAbonamente() {
		vector<Abonament> ab;
		fstream fin;
		fin.open("abonamente.csv", ios::in);
		auto facilitatiExistete = readFacilitati();
		vector<string> row;
		string line, word, temp;
		while (getline(fin, temp)) {
			row.clear();
			stringstream s(temp);
			while (getline(s, word, '#')) {
				const std::string& str(word);
				row.push_back(word);
			}
			Abonament a;
			a.setDenumire(row[0]);
			a.setPret(atoi(row[1].c_str()));
			vector<Facilitate> facilitati;
			for (int i = 2; i < row.size(); i++)
			{
				Facilitate f = RepositoryFacilitati::getFacilitateByName(row[i], facilitatiExistete);
				facilitati.push_back(f);
			}
			a.setFacilitati(facilitati);
			ab.push_back(a);
		}
		fin.close();
		return ab;
	}


	vector<Client> readClienti() {
		vector<Client> clienti;
		fstream fin;
		fin.open("clienti.csv", ios::in);
		vector<string> row;
		string line, word, temp;
		while (getline(fin, temp)) {
			row.clear();
			stringstream s(temp);
			while (getline(s, word, '#')) {
				const std::string& str(word);
				row.push_back(word);
			}
			Client c;
			c.setCNP(row[0]);
			c.setNume(row[1]);
			c.setPrenume(row[2]);
			Adresa adresa;
			adresa.setOras(row[4]);
			adresa.setStrada(row[5]);
			adresa.setNumar(row[6]);
			adresa.setDetalii(row[7]);
			Date d;
			d.setZi(atoi(row[8].c_str()));
			d.setLuna(atoi(row[9].c_str()));
			d.setAn(atoi(row[10].c_str()));
			c.setAdresa(adresa);
			c.setData(d);


			vector <Abonament> abonamente = readAbonamente();
			Abonament abonament = RepositoryAbonamente::getAbonamentByName(row[3], abonamente);
			c.setAbonament(abonament);
			clienti.push_back(c);
		}
		fin.close();
		return clienti;

	}


};

