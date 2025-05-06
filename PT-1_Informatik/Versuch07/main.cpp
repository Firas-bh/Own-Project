#include <iostream>
#include <string>
#include "Student.h"
#include <vector>
#include <algorithm>
using namespace std;


//globale Funktion für operator<<()
ostream& operator <<(ostream& aus, Student& student)
{
	student.ausgabe(aus);
	return aus;
}

int main()
{
	vector<Student> studentenListe;
    vector<Student>::iterator it = studentenListe.begin();
    vector<Student>::reverse_iterator revIt = studentenListe.rbegin();
    Student student = Student();


    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
     {
       student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
       studentenListe.push_back(student);
       student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
       studentenListe.push_back(student);
       student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
       studentenListe.push_back(student);
       student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
       studentenListe.push_back(student);
       student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
       studentenListe.push_back(student);
      }


    do
    {
       cout << "\nMenue:" <<endl
            << "-----------------------------" <<endl
            << "(1): Datenelement hinten hinzufuegen" <<endl
            << "(2): Datenelement hinten abhängrn" <<endl
            << "(3): Datenelement löschen" <<endl
	   	    << "(4): Datenelement hinzufuegen" <<endl
			<< "(5): Datenelement hinten löschen" <<endl
		    << "(6): Datenbank ausgeben" <<endl
			<< "(7): Datenbank in umgekehrter Reihenfolge ausgeben"<<endl
			<< "(8): Datenelement sortiert ausgeben"<<endl
            << "(9): Beenden" <<endl;
        cin >> abfrage;
        cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    string name = "";
                    string geburtstag = "";
                    string adresse = "";

                    cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(cin, name);    // ganze Zeile einselen inklusive aller Leerzeichen

                    cout << "Geburtsdatum: ";
                    getline(cin, geburtstag);

                    cout << "Adresse: ";
                    getline(cin, adresse);

                    cout << "Matrikelnummer: ";
                    cin >> matNr;
                    cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement hinten entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        studentenListe.pop_back();
                        cout << "Der folgende Student ist geloescht worden:" << endl;
                    }
                    else
                    {
                       cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenelement löschen
            case '3':
            	{
            		unsigned int matNr = 0;
            		cout<<"Matrikelnummer der zu löschenden Person eingeben: ";
            		cin>>matNr;
            		Student suche(matNr);

            		//Algorithm Funktion. Find() benutzt den operator ==
        			it = find(studentenListe.begin(), studentenListe.end(), suche);

            		if (it !=studentenListe.end() )
            		{
            			cout<<"Die folgende Person wurde geloöscht: ";
            			cout<<*it<<endl;
            			studentenListe.erase (it);
            		}
            		else
            		{
            			cout<<"Die Person wurde nicht gefunden"<<endl;
            		}

                }
                break;

           // Datenelement hinzufügen
            case '4':
                           {
                        	   if(!studentenListe.empty())
                        	   {
                        		   unsigned int matNr = 0;
                        		   unsigned int n = 0;
                        		   string name = "";
                        		   string geburtstag = "";
                        		   string adresse = "";



                        		   cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                        		   getline(cin, name);    // ganze Zeile einselen inklusive aller Leerzeichen

                        		   cout << "Geburtsdatum: ";
                        		   getline(cin, geburtstag);

                        		   cout << "Adresse: ";
                        		   getline(cin, adresse);

                        		   cout << "Matrikelnummer: ";
                        		   cin >> matNr;
                        		   cout<< "Bitte geben Sie die Zeilennummer für einfügen von Studentdaten ein:  "<<endl;
                        		   cin>> n;
                        		   cin.ignore(10, '\n');

                        		   student = Student(matNr, name, geburtstag, adresse);

                        		   studentenListe.insert (studentenListe.begin() +(n-1), student);
                        	   }
                        	   else
                        	   {
                        		   studentenListe.push_back(student);
                        	   }
                           }
                           break;

            //Datenelement hinten löschen
            case '5':
            	{
            		if(!studentenListe.empty())
            		{
            			studentenListe.erase (studentenListe.begin()+(studentenListe.size()-1));
            		}
                	else
                	{
                		cout << "Die Liste ist leer!\n";
                	}

            	}
                break;


            //Daten ausgeben
            case '6':
            	{
            		if(!studentenListe.empty())
            		{
            			for (it = studentenListe.begin(); it != studentenListe.end(); it++)
            			{
            				cout << *it <<endl;
            			}
            		}
                	else
                	{
                		cout << "Die Liste ist leer!\n";
                	}

            	}
                break;

            //Datenbank in umgekehrter Reihenfolge ausgeben
            case '7':
                {
                	if(!studentenListe.empty())
                	{
                		for (revIt = studentenListe.rbegin(); revIt != studentenListe.rend(); revIt++)
                		{
                			cout<< *revIt<<endl;
                		}

                	}
                	else
                	{
                		cout << "Die Liste ist leer!\n";
                	}
                }
                break;

            //Datenelement sortiert ausgeben
            case '8':
            	{
            		//Default Vergleich (< operator)
            		if(!studentenListe.empty())
            		{
            			std::sort(studentenListe.begin(), studentenListe.end());
            			for (it = studentenListe.begin(); it != studentenListe.end(); it++)
            			{
            				cout<< *it<<endl;
            			}
            		}
            	}
            	break;


            case '9':
                cout << "Das Programm wird nun beendet";
                break;

            default :
                cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '9');

    return 0;
}
