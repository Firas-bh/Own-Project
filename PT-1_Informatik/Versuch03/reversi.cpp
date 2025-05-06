/*
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
 * @mainpage Reversi
 *
 * Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
 *
 */

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
	for (int j = 0; j < GROESSE_Y; j++)
	{
		for(int i = 0; i < GROESSE_X; i++)
		{
			spielfeld[j][i] = 0;
		}
	}
	spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
	spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
	spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
	spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
 * @brief Ausgabe des Spielfelds auf der Konsole
 *
 * Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
 * Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
 *
 *  @param spielfeld  Spielfeld, das ausgeben wird
 */
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
	std::cout << "   | ";

	//Start bei ASCII 65 = A
	for (int i = 65; i < 65 + GROESSE_X; ++i)
		std::cout << ((char) i) << " | " ;

	std::cout << std::endl;

	for (int j = 0; j < GROESSE_Y; ++j)
	{
		for(int i = 0; i < GROESSE_X; ++i)
		{
			std::cout << "---+";
		}
		std::cout << "---+" << std::endl;

		std::cout << " " << j + 1 << " |";
		for (int i = 0; i < GROESSE_X; ++i)
		{
			switch (spielfeld[j][i])
			{
			case 0:
				std::cout << "   " ;
				break;
			case 1:
				std::cout << " X ";
				break;
			case 2:
				std::cout << " O ";
				break;
			default:
				std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
				std::cout << "Abbruch .... " << std::endl;
				exit(0);
				break;
			}
			std::cout << "|";
		};  //for i
		std::cout <<  std::endl;
	}  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
	int zaehlerSpieler1 = 0;
	int zaehlerSpieler2 = 0;

	for (int j = 0; j < GROESSE_Y; ++j)
	{
		for (int i = 0; i < GROESSE_X; ++i)
		{
			if (spielfeld[j][i] == 1)
			{
				++zaehlerSpieler1;
			}
			if (spielfeld[j][i] == 2)
			{
				++zaehlerSpieler2;
			}

		}
	}

	if (zaehlerSpieler1 == zaehlerSpieler2)
	{
		return 0;
	}
	if (zaehlerSpieler1 < zaehlerSpieler2)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

/**
 * @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
 *
 * @param posX Index fuer die Spalte
 * @param posY Index fuer die Zeile
 * @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
 */
bool aufSpielfeld(const int posX, const int posY)
{
	// Hier erfolgt jetzt Ihre Implementierung ...
	if(posX<GROESSE_X && posX>=0 && posY<GROESSE_Y && posY>=0) return true;
	return false;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return true falls der Zug laut Reversi Regeln moeglich ist
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
	int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
	//               if aktuellerSpieler == 2 -> gegner = 1

	if (spielfeld[posY][posX] != 0) // ist das Feld leer?
	{
		return false;
	}

	// Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
	for (int j = -1; j <= 1; j++)
	{
		for (int i = -1;  i <= 1; i++)
		{
			// Hier erfolgt jetzt Ihre Implementierung ...
			if((spielfeld[posY+j][posX+i] == gegner) && aufSpielfeld(posY+j,posX+i) && ((i!=0)||(j!=0)))
			{
				int c = 1;
				while(aufSpielfeld(posY+j,posX+i))
				{
					if(!aufSpielfeld(posY+(c*j),posX+(c*i))) break;
					if(spielfeld[posY+(c*j)][posX+(c*i)] == aktuellerSpieler) return true;
					if(spielfeld[posY+c*j][posX+c*i] == 0) break;
					c++;
				}
			}
		}
	}
	return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{

	//Alle Richtungen bearbeiten
	for (int j = -1; j <= 1; j++)
	{
		for (int i = -1; i <= 1; i++)
		{
			// aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
			// allen Richtungen in Ihre eigenen Steine umgewandelt werden
			//
			// Hier erfolgt jetzt Ihre Implementierung ...
			spielfeld[posY][posX] = aktuellerSpieler;
			if(aufSpielfeld(posY+j,posX+i) && ((i!=0)||(j!=0)))
			{
				int g = 1;
				while(aufSpielfeld(posY+j,posX+i)){
					if(!aufSpielfeld(posY+(g*j),posX+(g*i))) break;
					if(spielfeld[posY+(g*j)][posX+(g*i)] == aktuellerSpieler)
					{
						g--;
						while(spielfeld[posY+(g*j)][posX+(g*i)] != aktuellerSpieler)
						{
							spielfeld[posY+(g*j)][posX+(g*i)] = aktuellerSpieler;
							g--;
						}
					}
					if(g==0) break;
					if(spielfeld[posY+g*j][posX+g*i] == 0) break;
					g++;
				}
			}
		}
	}

}
/**
 * @brief Berechnet Anzahl aller moeglichen Zuege des uebergebenen Spielers
 *
 * Ueberprueft mittles 2 for-Schleifen iterativ, ob ein Zuege auf allen Feldern
 * des Spielfeldes moeglich sind und erhöht wenn moeglich einen Zaehler. Dieser
 * Zaehler wird am Ende zurueck gegeben.
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return alle moeglichen Zuege des uebergebenen Spielers
 */

int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
	// Hier erfolgt jetzt Ihre Implementierung ...
	int z = 0;
	for(int j = 0; j < GROESSE_Y; j++){
		for(int i = 0; i < GROESSE_X; i++){
			if(zugGueltig(spielfeld, aktuellerSpieler, i, j))
				z++;
		}
	}

	return z;
}


bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
	if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
	{
		return false;
	}

	int posX;
	int posY;
	std::string symbolSpieler;
	if (aktuellerSpieler == 1)
	{
		symbolSpieler = "X";
	}
	else
	{
		symbolSpieler = "O";
	}

	while (true)
	{
		std::string eingabe;
		std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
		std::cin >> eingabe;
		posX = (int) eingabe[0] % 32 -1;
		posY = (int) eingabe[1] - 49;

		if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
		{
			//accept turn;
			break;
		}
		else
		{
			std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
		}
	}

	zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
	std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

	return true;
}

/**
 * @brief Ueberprueft den uebergebenen Spielmodi und startet dementsprechend das Spiel
 *
 * Iteriert durch die Zuege und prueft, ob ein Spieler im naechsten Zug einen Stein setzen kann
 * und wechselt dem entsprechend den Spieler. Prueft am Ende, ob das Spiel fertig ist oder nicht
 * und bestimmt einen Gewinner.
 *
 * @param spielerTyp Array zur bestimmung der Spielmodi
 */
void spielen(const int spielerTyp[2])
{
	int spielfeld[GROESSE_Y][GROESSE_X];

	//Erzeuge Startaufstellung
	initialisiereSpielfeld(spielfeld);

	int aktuellerSpieler = 1;
	zeigeSpielfeld(spielfeld);
	int gegner = 0;

	// solange noch Zuege bei einem der beiden Spieler moeglich sind
	//
	// Hier erfolgt jetzt Ihre Implementierung ...
	//Computer vs Mensch
	while(moeglicheZuege(spielfeld,1) || moeglicheZuege(spielfeld,2)){
		gegner = 3 - aktuellerSpieler;
		if(spielerTyp[0] != spielerTyp[1] && spielerTyp[0] == MENSCH){
			if(aktuellerSpieler == COMPUTER){
				computerZug(spielfeld, aktuellerSpieler);
			}
			else if (aktuellerSpieler == MENSCH){
				menschlicherZug(spielfeld, aktuellerSpieler);
			}
			if(moeglicheZuege(spielfeld,gegner) != 0){
				aktuellerSpieler = (aktuellerSpieler == 1 ? 2 : 1);
			}
			zeigeSpielfeld(spielfeld);
			continue;
		}

		//Mensch vs Mensch
		if(spielerTyp[0] == spielerTyp[1] && spielerTyp[0] == MENSCH){
			menschlicherZug(spielfeld, aktuellerSpieler);
			if(moeglicheZuege(spielfeld,gegner) != 0){
				aktuellerSpieler = (aktuellerSpieler == 1 ? 2 : 1);
			}
			zeigeSpielfeld(spielfeld);
			continue;
		}

		//Computer vs Computer
		if(spielerTyp[0] == spielerTyp[1] && spielerTyp[0] == COMPUTER){
			computerZug(spielfeld, aktuellerSpieler);
			if(moeglicheZuege(spielfeld,gegner) != 0){
				aktuellerSpieler = (aktuellerSpieler == 1 ? 2 : 1);
			}
			zeigeSpielfeld(spielfeld);
			continue;
		}


	}
	switch (gewinner(spielfeld))
	{
	case 0:
		std::cout << "----------------------------------"<< std::endl;
		std::cout << "UNENTSCHIEDEN!" << std::endl;
		std::cout << "----------------------------------" << std::endl << std::endl;
		break;
	case 1:
		std::cout << "----------------------------------"<< std::endl;
		std::cout << "SPIELER 1 GEWINNT!" << std::endl;
		std::cout << "----------------------------------" << std::endl << std::endl;
		break;
	case 2:
		std::cout << "----------------------------------"<< std::endl;
		std::cout << "SPIELER 2 GEWINNT!" << std::endl;
		std::cout << "----------------------------------" << std::endl << std::endl;
		break;
	}
}

int main()
{
	if (TEST == 1)
	{
		bool gesamtErgebnis = ganzenTestAusfuehren();
		if (gesamtErgebnis == true)
		{
			std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
		}
		else
		{
			std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
			exit(1);
		}
		std::cout << std::endl << std::endl;
	}


	// Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
	// implementiert haben (waeren sonst doppelt)
	//int spielfeld[GROESSE_Y][GROESSE_X];

	//initialisiereSpielfeld(spielfeld);

	//zeigeSpielfeld(spielfeld);
	bool again = true;
	int answer1 = 0;
	char answer2 = 0;
	do{
		system("CLS");
		// Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
		int spielerTyp[2];
		std::cout << "SPIELTYP AUSWÄEHLEN:" << std::endl;
		std::cout << "0 - Player vs Player" << std::endl;
		std::cout << "1 - Player vs Computer" << std::endl;
		std::cout << "2 - Computer vs Computer" << std::endl;
		std::cin >> answer1;
		switch (answer1) {
		case 0:
			spielerTyp[0] = MENSCH;
			spielerTyp[1] = MENSCH;
			break;
		case 1:
			spielerTyp[0] = MENSCH;
			spielerTyp[1] = COMPUTER;
			break;
		case 2:
			spielerTyp[0] = COMPUTER;
			spielerTyp[1] = COMPUTER;
			break;
		default:
			continue;
		}
		spielen(spielerTyp);
		while(true){
			std::cout << "Restart? (y/n): " << std::endl;
			std::cin >> answer2;
			if(answer2 == 89 || answer2 == 121){
				break;
			}
			else if(answer2 == 78 || answer2 == 110){
				again = false;
				break;
			}
		}
	}while(again);
	//
	// Hier erfolgt jetzt Ihre Implementierung ...

	return 0;
}
