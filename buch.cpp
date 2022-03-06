#include "buch.h"

Buch::Buch(string author, string title, int lastId, Kunde* ausleiher, char zustand, int seitenzahl)
    :Medien{author, title, lastId, ausleiher, zustand}
{
    this->seitenzahl = seitenzahl;
}

void Buch::setSeitenzahl(int seitenzahl)
{
    this->seitenzahl = seitenzahl;
}

int Buch::getSeitenzahl() const
{
    return this->seitenzahl;
}

void Buch::mediaAnzeigen()
{
    cout << "|" << setw(3) << setfill(' ') << left << this->getId()
         << "|"  << setw(24) << setfill(' ') << left << this->getAuthor()
         << "|" << setw(24) << setfill(' ')<< left << this->getTitle()
         << "|" << setw(5)  << setfill(' ')<< left << this->getSeitenzahl()
         << "|" << setw(1)  << setfill(' ')<< left << this->getZustand()
         << "|" << setw(2)  << setfill(' ')<< right << this->getKunde()->get_id()
         << "|" << setw(8) << setfill(' ') << left << this->getKunde()->get_nachname()<< '\n';
}

void Buch::mediaAnzeigen_author()
{
    cout << "|" <<setw(24) << setfill(' ') << left << this->getAuthor()
         << "|" << setw(24) << setfill(' ')<< left << this->getTitle()
         << "|" << setw(3) << setfill(' ') << left << this->getId()
         << "|" << setw(5)  << setfill(' ')<< left << this->getSeitenzahl()
         << "|" << setw(1)  << setfill(' ')<< left << this->getZustand()
         << "|" << setw(2)  << setfill(' ')<< right << this->getKunde()->get_id()
         << "|" << setw(8) << setfill(' ') << left << this->getKunde()->get_nachname()<< '\n';
}

Buch::~Buch()
{

}











