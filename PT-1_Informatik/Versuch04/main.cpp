//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXIX
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#define ERDE_RADIUS_KM 6371000
#define PLATTFORM_HOEHE 555.7
#define MENSCH_GROESSE 1.70

#define WINKEL 0.00000001

int main()
{
	// Erdradius
	Vektor erde(0, ERDE_RADIUS_KM, 0);

	// Sichthöhe Mensch
	Vektor mensch(0, (ERDE_RADIUS_KM+MENSCH_GROESSE + PLATTFORM_HOEHE), 0 );

	// Sichtvektor soll Erde tangieren
	Vektor sichtlinie = mensch.sub(erde);
	int zaehler=0;
	double rad = 0;
	do
	{
		zaehler++;
		// Erhöhe Winkel langsam
		rad += WINKEL;
		//x=(sichtlinie.winkel(erde));
		//std::cout<<sichtlinie.winkel(erde)<<std::endl;
		erde.rotiereUmZ(WINKEL);
		sichtlinie = erde.sub(mensch);

	} while((sichtlinie.skalarProd(erde))<=0); // Prüfe Orthogonalität

	// Berechnen der Distanz als Zahlenwert
	double sichtlinie_entfernung = sichtlinie.laenge();
	double deg = rad * 180 / M_PI;

	std::cout << "Sie können " << sichtlinie_entfernung/1000 << " Km weit sehen."<< std::endl;
	std::cout << "Sie sind " << PLATTFORM_HOEHE  << " Meter hoch." << std::endl;
	std::cout << "Der Winkel bterägt " << deg << " Grad." << std::endl;
	std::cout << "Anzahl Schritte: " << std::fixed << zaehler << std::endl;

	return 0;
}

