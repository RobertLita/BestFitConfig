#pragma once

#include <cstring>
#include <string>

class Date
{
    int zi, luna, an;

public:

    Date() { this->zi = 1; this->luna = 1; this->an = 2022; };
    Date(int zi, int luna, int an) : zi{ zi }, luna{ luna }, an{ an } {};
    Date(char* data) {
        this->zi = 0;
        this->luna = 0;
        this->an = 0;
        char* token = strtok(data, ".");
        while (token != NULL)
        {
            if (this->zi == 0) this->zi = atoi(token);
            if (this->luna == 0) this->luna = atoi(token);
            if (this->an == 0) this->an = atoi(token);
            token = strtok(NULL, "-");
        }
    }

    int getZi() { return zi; };

    int getLuna() { return luna; };

    int getAn() { return an; };

    void setZi(int v) {
        this->zi = v;
    }

    void setLuna(int v) {
        this->luna = v;
    }

    void setAn(int v) {
        this->an = v;
    }

    friend bool operator==(const Date& lhs, const Date& rhs) {
        return lhs.zi == rhs.zi &&
            lhs.luna == rhs.luna &&
            lhs.an == rhs.an;
    }

    friend bool operator!=(const Date& lhs, const Date& rhs) {
        return !(rhs == lhs);
    }

    bool esteValid() {
        if (this->an == 2022) {
            if (this->luna <= 12 && this->luna > 0) {
                if (this->luna == 2) {
                    if (this->zi > 0 && this->zi <= 28)
                        return true;
                }
                if (this->zi > 0 && this->zi <= 31)
                    return true;
            }
        }
        return false;

    }


};

