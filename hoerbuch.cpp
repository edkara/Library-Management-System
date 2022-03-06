#include "hoerbuch.h"

Hoerbuch::Hoerbuch(string author, string title, int lastId, Kunde* ausleiher, char zustand, int seitenzahl, string spieldauer)
    : Medien{author, title, lastId, ausleiher, zustand}, Buch{author, title, lastId, ausleiher, zustand, seitenzahl}, CD{author, title, lastId, ausleiher, zustand, spieldauer}
{

}

void Hoerbuch::mediaAnzeigen()
{
    cout << "|" << setw(3) << setfill(' ') << left << this->getId()
         << "|"  << setw(24) << setfill(' ') << this->getAuthor()
         << "|" << setw(24) << setfill(' ')<< left << this->getTitle()
         << "|" << setw(5)  << setfill(' ')<< left << this->getSpieldauer()
         << "|" << setw(1)  << setfill(' ')<< left << this->getZustand()
         << "|" << setw(2)  << setfill(' ')<< right << this->getKunde()->get_id()
         << "|" << setw(8) << setfill(' ') << left << this->getKunde()->get_nachname()<< '\n';
}

void Hoerbuch::mediaAnzeigen_author()
{
    cout << "|"<< setw(24) << setfill(' ') << this->getAuthor()
         << "|" << setw(24) << setfill(' ')<< left << this->getTitle()
         << "|" << setw(3) << setfill(' ') << left << this->getId()
         << "|" << setw(5)  << setfill(' ')<< left << this->getSpieldauer()
         << "|" << setw(1)  << setfill(' ')<< left << this->getZustand()
         << "|" << setw(2)  << setfill(' ')<< right << this->getKunde()->get_id()
         << "|" << setw(8) << setfill(' ') << left << this->getKunde()->get_nachname()<< '\n';
}

Hoerbuch::~Hoerbuch()
{

}

