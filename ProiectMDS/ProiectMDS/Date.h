#pragma once
class Date
{
	int zi, luna, an;

public:

	Date() { this->zi = 1; this->luna = 1; this->an = 2022; };
	Date(int zi, int luna, int an) : zi{ zi }, luna{ luna }, an{ an } {};

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
};

