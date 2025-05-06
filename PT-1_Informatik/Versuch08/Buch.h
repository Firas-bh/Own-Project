/*
 * Buch.h
 *
 *  Created on: 22.06.2019
 *      Author: firas
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

class Buch: public Medium
{
public:
	Buch();

	//Konstruktor mit Parametern
	Buch(std::string initTitel, std::string initAutor);

	virtual ~Buch();
	// ausgabe funktion mit Veerbung aus Basisklasse Memium
    void ausgabe() const;

protected:
    std::string initAutor;
};

#endif /* BUCH_H_ */
