//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXIX
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int iErste = 0;
    int iZweite = 0;

    // Hier folgt Ihr eigener Code
    std::cout << "Geben Sie die Zahl1: ";
    std::cin >> iErste;
    std::cout << "Geben Sie die Zahl2: ";
    std::cin >> iZweite;
    int iSumme = iErste + iZweite;
    int iQuotient = iErste / iZweite;
    std::cout << "Die Summe beträgt: " <<iSumme<<std::endl;
    std::cout << "Die Divison beträgt: "<<iQuotient<<std::endl;

    // Zweite Rechnung
    double dSumme = (double)iErste + (double)iZweite;
    double dQuotient = (double)iErste / (double)iZweite;
    std::cout << "Die Summe beträgt: " <<dSumme<<std::endl;
    std::cout << "Die Divison beträgt: "<<dQuotient<<std::endl;

    // Typecasting
    double dErste = 1.0 * iErste;
    double dZweite = 1.0 * iZweite;
    double dSummeCast = dErste + dZweite;
    double dQuotientCast = (double)(1.0*iErste) / (double)(1.0*iZweite);
    std::cout << "Die Summe beträgt: " <<dSummeCast<<std::endl;
    std::cout << "Die Divison beträgt: "<<dQuotientCast<<std::endl;

    //Eingabe Benutzer's Name und Vorname
    std::cout <<"Geben Sie Ihre Vorname: ";
    string Vorname;
    std::cin >> Vorname;
    std::cout <<"Geben Sie Ihre Nachname: ";
    string Nachname;
    std::cin >> Nachname;
    std::string sVorname = Vorname;
    std::string sNachname = Nachname;
    std::string sVornameName = sVorname + ' ' + sNachname;
    std::string sNameVorname = sNachname +' ' + sVorname;
    std::cout << sVornameName <<std::endl;
    std::cout << sNameVorname <<std::endl;

    //Begin 1.Block
    {
    	//a)
    	int iFeld[2] = {1 ,2};
    	std::cout<<"Wert 1 von iFeld beträgt: "<<iFeld[0]<<std::endl;
    	std::cout<<"Wert 2 von iFeld beträgt: "<<iFeld[1]<<std::endl;

    	//b)
    	int spielfeld[2][3]= {{1, 2, 3}, {4, 5, 6}};
    	std::cout << "Spielfeld:\n"<< spielfeld[0][0]<<" ";
    	std::cout <<spielfeld[0][1] << " ";
    	std::cout <<spielfeld[0][2] << " "<<std::endl;
    	std::cout <<spielfeld[1][0] << " ";
    	std::cout <<spielfeld[1][1] << " ";
    	std::cout <<spielfeld[1][2] << " "<<std::endl;

    	//c)
    	const int iZweite = 1;
    	std::cout <<"Konstante: "<< iZweite<<std::endl;
    }

    std::cout <<"Konstante: "<< iZweite<<std::endl;

    //6)Buchstaben in ASCII Zahlen
    std::string str = sVorname;
    char iName1 = str[0];
    std::cout<<"1.Buchstabe in ASCII: "<<int(iName1)<<std::endl;
    char iName2 = str[1];
    std::cout<<"2.Buchstabe in ASCII: "<<int(iName2)<<std::endl;

    //7) Zahlen die Position der Buchstaben im deutschen Alphabet
    int i1 = iName1 % 32;
    int i2 = iName2 % 32;
	std::cout<<"Stelle im deutschen Alphabet: "<<i1<<std::endl;
    std::cout<<"Stelle im deutschen Alphabet: "<<i2<<std::endl;




    return 0;
}


