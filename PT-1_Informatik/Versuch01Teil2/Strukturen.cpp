/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXIX
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>


int main()
{
	//Person Struktur definieren
	struct Person
	{
		std::string sNachname;
		std::string sVorname;
		int iGeburtsjahr;
		int iAlter;
	};
	Person nBenutzer;
	std::cout<<"Nachname: ";
	std::cin>> nBenutzer.sNachname;
	std::cout<<"\nVorname: ";
	std::cin>> nBenutzer.sVorname;
	std::cout<<"\nGeburtsjahr: ";
	std::cin>> nBenutzer.iGeburtsjahr;
	std::cout<<"\nAlter: ";
	std::cin>> nBenutzer.iAlter;

	//Person output
	std::cout<<"Benutzer Nachname ist:\t\t"<<nBenutzer.sNachname;
	std::cout<<"\nBenutzer Vorname ist:\t\t"<<nBenutzer.sVorname;
	std::cout<<"\nBenutzer Geburtsjahr ist:\t"<<nBenutzer.iGeburtsjahr;
	std::cout<<"\nBenutzer Alter ist:\t\t"<<nBenutzer.iAlter<<"\n\n";

	//Einzelne Elemente Kopieren
	Person nKopie;
	nKopie.sNachname = nBenutzer.sNachname;
	nKopie.sVorname = nBenutzer.sVorname;
	nKopie.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopie.iAlter = nBenutzer.iAlter;

	//Gesamte Struktur kopieren
	Person nKopieGesamt = nBenutzer;

	//Einzelne Elemente Ausgabe
	std::cout<<" nKopieEinzeln:"<<std::endl;
	std::cout<<"Benutzer Nachname ist:\t\t"<<nKopie.sNachname;
	std::cout<<"\nBenutzer Vorname ist:\t\t"<<nKopie.sVorname;
	std::cout<<"\nBenutzer Geburtsjahr ist:\t"<<nKopie.iGeburtsjahr;
	std::cout<<"\nBenutzer Alter ist:\t\t"<<nKopie.iAlter<<"\n\n";

	//Kopie gesamte Struktur Ausgabe
	std::cout<<"nKopieGesamt: "<<std::endl;
	std::cout<<"Benutzer Nachname ist:\t\t"<<nKopieGesamt.sNachname;
	std::cout<<"\nBenutzer Vorname ist:\t\t"<<nKopieGesamt.sVorname;
	std::cout<<"\nBenutzer Geburtsjahr ist:\t"<<nKopieGesamt.iGeburtsjahr;
	std::cout<<"\nBenutzer Alter ist:\t\t"<<nKopieGesamt.iAlter;




    return 0;
    
}
