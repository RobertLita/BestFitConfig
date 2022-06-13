#pragma once

#include <vector>
#include <string>
#include "Facilitate.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class RepositoryFacilitati
{
private:
	vector <Facilitate> facilitati;

public:
	RepositoryFacilitati() {
        this->facilitati = readFacilitati(); 
    };

	vector <Facilitate> getFacilitati (){
		return this->facilitati;
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

    void writeFacilitate(Facilitate f) {
        fstream fout;
        fout.open("facilitati.csv", ios_base::app);
        fout << f.getDenumire() << '#' << f.getDescriere() << '#' << f.getPret() << '\n';
        fout.close();
    }


    void deleteFacilitate(Facilitate f) {
        fstream fout;
        fout.open("facilitati.csv", std::ofstream::out | std::ofstream::trunc);
        fout.close();
        for (Facilitate f : this->facilitati) {
            writeFacilitate(f);
        }
    }

    void addFacilitate(Facilitate f) {
        for (auto& facilitate : this->facilitati) {
            if (facilitate == f) {
                throw std::runtime_error("Facilitatea exista deja!");
            }
        }

        this->facilitati.push_back(f);
        writeFacilitate(f);

    }

    void stergeFacilitate(Facilitate f) {
        if (f.esteValid()) {
            int pozitie = -1;
            for (int i = 0; i < this->facilitati.size(); i++)
                if (this->facilitati[i] == f) {
                    pozitie = i;
                }
            if (pozitie == -1) {
                throw std::runtime_error("Nu exista acesta facilitate!");
            }
            this->facilitati.erase(this->facilitati.begin() + pozitie);
            deleteFacilitate(f);
         }
    }

    Facilitate findFacilitate(string denumire) {
        for (auto& facilitate : this->facilitati) {
            if (facilitate.getDenumire() == denumire) {
                return facilitate;
            }
        }
    }

    void updateFacilitate(Facilitate fv, Facilitate fn) {
        stergeFacilitate(fv);
        addFacilitate(fn);

    }

    static Facilitate getFacilitateByName(string name, vector<Facilitate> fac) {
        for(Facilitate f : fac) {
            if(f.getDenumire() == name) return f;
        }
    }


};


