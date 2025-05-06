/*
 * Magazin.cpp
 *
 *  Created on: 22.06.2019
 *      Author: firas
 */

#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte) : Medium(initTitel),
															initDatumAusgabe(initDatumAusgabe), initSparte(initSparte)
{
	// TODO Auto-generated constructor stub

}

void Magazin::ausgabe() const
{
	Medium::ausgabe();

    std::cout << "Ausgabe: " << initDatumAusgabe <<std::endl;
    std::cout <<"Sparte: " << initSparte << std::endl;

}

Magazin::~Magazin()
{
	// TODO Auto-generated destructor stub
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
	if (abs(this->initDatumAusgabe - ausleihdatum ) >> 1)
	{
		Medium::ausleihen(person, ausleihdatum);
		return true;
	}
	else
	{
		std::cout <<" Das Magazin darf nicht ausgeliehen, es handelt sich um die neuste Ausgabe" << std::endl;
		return false;

	}
}
