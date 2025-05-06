/*
 * Buch.cpp
 *
 *  Created on: 22.06.2019
 *      Author: firas
 */

#include "Buch.h"

Buch::Buch(std::string initTitel, std::string initAutor): Medium(initTitel), initAutor(initAutor)
{
	// TODO Auto-generated constructor stub

}

Buch::~Buch()
{
	// TODO Auto-generated destructor stub
}

void Buch::ausgabe() const
{
	Medium::ausgabe();

	std::cout << "Autor: " << initAutor <<std::endl;
}
