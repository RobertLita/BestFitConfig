#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Client.h"

using std::vector, std::string;

class RepositoryClienti
{
private:
	vector <Client> clienti;
public:

	RepositoryClienti() {
		//incarcaClienti();
	};

	//	vector<Client> incarcaClienti() {
	//        fstream fin;
	//        fin.open("clienti.csv", ios::in);
	//        vector<string> row;
	//        string line, word, temp;
	//        while(fin >> temp) {
	//            row.clear();
	//            getline(fin, line);
	//            stringstream s(line);
	//            while (getline(s, word, ',')) {
	//                row.push_back(word);
	//            }
	//        }
	//	}

	void addClient(Client c) {
		for (auto& client : this->clienti) {
			if (client == c) {
				throw runtime_error("Clientul exista deja!");
			}
		}
		if (c.esteValid()) {
			this->clienti.push_back(c);
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
		}
	}

	Client findClient(string CNP) {
		for (auto& client : this->clienti) {
			if (client.getCNP() == CNP) {
				return client;
			}
		}
	}

	void updateClient(Client cv, Client cn) {
		deleteClient(cv);
		addClient(cn);
	}

};

