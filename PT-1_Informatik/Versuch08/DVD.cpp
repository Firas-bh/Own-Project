/*
 * DVD.cpp
 *
 *  Created on: 22.06.2019
 *      Author: firas
 */

#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) : Medium(initTitel), initAltersfreigabe(initAltersfreigabe),
initGenre(initGenre)
{
	// TODO Auto-generated constructor stub

}

DVD::~DVD()
{
	// TODO Auto-generated destructor stub
}

void DVD::ausgabe() const
{
	Medium::ausgabe();

    std::cout << "FSK: ab" << initAltersfreigabe << " Jahren" << std::endl;
    std::cout << "Genre: " << initGenre <<std::endl;

}
 bool DVD::ausleihen(Person person, Datum ausleihdatum)
 {
	 if (this-> initAltersfreigabe <=abs((person.getGeburtsdatum() - ausleihdatum)/12))
	 {
		 Medium::ausleihen(person, ausleihdatum);
		 return true;
	 }
	 else
	 {
		 std::cout << "Tut uns leid Sie sind zu jung" <<std::endl;
		 return false;
	 }
 }


