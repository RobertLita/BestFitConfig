#pragma once

#include <string>
#include <vector>
#include <stdexcept>

using std::string, std::runtime_error;


class Facilitate
{

private:
    string descriere, denumire;
    int pretIndividual;
public:
    Facilitate(string denumire, string descriere, int pretIndividual) {
    
        this->denumire = denumire;
        this->descriere = descriere;
        this->pretIndividual = pretIndividual;
           
    };

    string getDenumire();
    string getDescriere();
    int getPret();

    void setDenumire(string denumire);
    void setDescriere(string descriere);
    void setPret(int pretIndividual);

    bool esteValid() {

        if (this->pretIndividual <= 0) {
            throw runtime_error("Pretul nu poate sa fie negativ sau 0.");
        }

        return true;
    }


    friend bool operator==(Facilitate& lhs, Facilitate& rhs) {
        return !lhs.getDenumire().compare(rhs.getDenumire());
    }

    friend bool operator!=(Facilitate& lhs, Facilitate& rhs) {
        return !(rhs == lhs);
    }
};