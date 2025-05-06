#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name = "", std::string geburtstag = "", std::string address = "");

    //Operatorenüberladung
    bool operator == (const Student& student) const;
    bool operator <  (const Student& student) const;
    bool operator >  (const Student& student) const;

    std::ostream& ausgabe(std::ostream& aus) const;

    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

#endif
