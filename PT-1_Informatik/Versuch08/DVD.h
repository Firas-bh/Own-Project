/*
 * DVD.h
 *
 *  Created on: 22.06.2019
 *      Author: firas
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

class DVD: public Medium
{
public:
	DVD();

	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

	virtual ~DVD();

	void ausgabe() const;

	bool ausleihen(Person person, Datum ausleihdatum);

	bool ausgeliehen() const;

protected:
	int initAltersfreigabe;
	std::string initGenre;
};

#endif /* DVD_H_ */
