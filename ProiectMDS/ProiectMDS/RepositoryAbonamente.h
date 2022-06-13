#pragma once

#include <vector>
#include <string>
#include "Abonament.h"
#include <fstream>
#include <sstream>
#include "RepositoryFacilitati.h"

using namespace std;

class RepositoryAbonamente
{
private:
    vector <Abonament> abonamente;

public:

    RepositoryAbonamente() {
        this->abonamente = readAbonamente();
    };

    void addAbonament(Abonament a) {
        for (auto& abonament : this->abonamente) {
            if (abonament == a) {
                throw std::runtime_error("Abonamentul exista deja!");
            }
        }

        this->abonamente.push_back(a);
        writeAbonament(a);

    }

    void stergeAbonament(Abonament a) {
        if (a.esteValid()) {
            int pozitie = -1;
            for (int i = 0; i < this->abonamente.size(); i++)
                if (this->abonamente[i] == a) {
                    pozitie = i;
                }
            if (pozitie == -1) {
                throw std::runtime_error("Nu exista acest abonament!");
            }
            this->abonamente.erase(this->abonamente.begin() + pozitie);
            deleteAbonament(a);

        }

    }

    Abonament findAbonament(string denumire) {
        for (auto& abonament : this->abonamente) {
            if (abonament.getDenumire() == denumire) {
                return abonament;
            }
        }
    }

    void updateAbonament(Abonament av, Abonament an) {
        stergeAbonament(av);
        addAbonament(an);
    }


    vector <Abonament> getAbonamente() {
        return this->abonamente;
    }

    void writeAbonament(Abonament a) {
        fstream fout;
        fout.open("abonamente.csv", ios_base::app);
        fout << a.getDenumire() << '#' << a.getPret();
        for (Facilitate f : a.getFacilitati()) {
            fout << '#' << f.getDenumire();
        }
        fout << '\n';
        fout.close();
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
                Facilitate f = RepositoryFacilitati::getFacilitateByName(row[i],facilitatiExistete);
                facilitati.push_back(f);
            }
            a.setFacilitati(facilitati);
            ab.push_back(a);
        }
        fin.close();
        return ab;
    }

    void deleteAbonament(Abonament a) {
        fstream fout;
        fout.open("abonamente.csv", std::ofstream::out | std::ofstream::trunc);
        fout.close();
        for (Abonament a : this->abonamente) {
            writeAbonament(a);
        }
    }

    static Abonament getAbonamentByName(string name, vector<Abonament> abonamente) {
        for (Abonament a : abonamente) {
            if (a.getDenumire() == name) return a;
        }
    }

};