/*
 * Magazin.h
 *
 *  Created on: 22.06.2019
 *      Author: firas
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"

class Magazin: public Medium
{
public:
	Magazin();

	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);

	virtual ~Magazin();

	void ausgabe() const;

    bool ausleihen(Person person, Datum ausleihdatum);

protected:
	Datum initDatumAusgabe;
	std::string initSparte;
};

#endif /* MAGAZIN_H_ */
