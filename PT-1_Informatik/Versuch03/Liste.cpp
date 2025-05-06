#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student* pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, back);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        back = neuesElement;
    }
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student* pData)
{
	ListenElement* neuesElement = new ListenElement(pData, front, nullptr);

	if (back == nullptr)
	{
		front = neuesElement;
		back = neuesElement;
	}
	else
	{
		front->setPrev(neuesElement);
		front = neuesElement;
	}

}


/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enthält nur ein Listenelement
    {
        delete front;                                        // Listenelement löschen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setNext();
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student* Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
        cursor->getData()->ausgabe();

        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzen bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRuekwaerts() const
{
	ListenElement* cursor = back;

	while (cursor != nullptr)
	{
		cursor->getData()->ausgabe();

		cursor = cursor->getPrev();
	}
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popone(unsigned int popMatNr)
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	if (cursor->getData()->getMatNr() == popMatNr )
    	{
    		if(front == back)
    		{
    			front = nullptr;
    			back = nullptr;
    		}
    		else
    		{
    			if (cursor == front)
    			{
    		        front = front->getNext();
    		        front->setPrev(nullptr);
    			}
    			else
    			{
    				if (cursor == back)
    				{
    					back = back->getPrev();
    					back->setNext(nullptr);
    				}
    				else
    				{
						cursor->getPrev()->setNext(cursor->getNext());
						cursor->getNext()->setPrev(cursor->getPrev());
    				}
    			}
    		}
    		delete cursor;
    		break;
    	}
    	cursor = cursor->getNext();
    }
}


Student* Liste::ausgabeEinzeln(unsigned int ausMatNr)
{
    ListenElement* cursor = front;
	while (cursor != nullptr)
	{
		if (cursor->getData()->getMatNr() == ausMatNr)
		{
			return cursor->getData();
		}
		cursor = cursor->getNext();
	}
	return 0;
}
