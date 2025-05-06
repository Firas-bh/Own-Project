//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXIX
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}
double Vektor::laenge() const
{
	return sqrt(x*x + y*y + z*z);
}

Vektor Vektor::sub(const Vektor& input) const
{
	return Vektor(this->x - input.x, this->y - input.y, this->z - input.z);
}

double Vektor::skalarProd(const Vektor& input) const
{
	return this->x*input.x+this->y*input.y+this->z*input.z;
}

double Vektor::winkel(const Vektor& input) const
{
	/*double a = skalarProd(input);
	double b = this->laenge();
	double c = input.laenge();
	double e = (this->skalarProd(input)/(this->laenge()*input.laenge()));
*/
	return acos(this->skalarProd(input)/(this->laenge()*input.laenge()));
}

void Vektor::rotiereUmZ(const double rad)
{
	double a =this->x*cos(rad)-this->y*sin(rad);
	double b =this->y*cos(rad)+this->x*sin(rad);


	this->x = a;
	this->y = b;
}
