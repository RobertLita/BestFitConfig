#pragma once
#include "Facilitate.h"
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Abonament
{
private:
    vector<Facilitate> facilitati;
    int pretTotal;
    string denumire;
public:
    Abonament() {};
    Abonament(const Abonament& ot) {
        this->pretTotal = ot.pretTotal;
        this->denumire = ot.denumire;
        this->facilitati = ot.facilitati;

    }
    Abonament(string denumire, int pretTotal) {
        this->denumire = denumire;
        this->pretTotal = pretTotal;
    }

    Abonament(string denumire, int pretTotal, vector<Facilitate> fac) {
        if (fac.size() == 0)
            throw runtime_error("Selectati cel putin o facilitate!");
        this->denumire = denumire;
        this->pretTotal = pretTotal;
        this->facilitati = fac;
    }


    void setFacilitati(vector<Facilitate>& facilitati) {
        this->facilitati = facilitati;
    }
    vector <Facilitate> getFacilitati();

    int getPret();

    string getDenumire();

    void adaugaFacilitate(Facilitate f);

    void setPret(int pretTotal);

    void  setDenumire(string denumire);

    bool esteValid() {

        if (this->pretTotal < 0) {
            throw runtime_error("Pretul nu poate sa fie negativ.");
        }
        return true;
    }


    friend bool operator==(Abonament& lhs, Abonament& rhs) {
        return !lhs.getDenumire().compare(rhs.getDenumire());
    }

    friend bool operator!=(Abonament& lhs, Abonament& rhs) {
        return !(rhs == lhs);
    }

};