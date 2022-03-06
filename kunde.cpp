#include "kunde.h"

Kunde::Kunde(string vorname, string nachname, int lastId)
    : vorname(vorname), nachname(nachname), id(lastId)
{

}

void Kunde::set_vorname(string vorname)
{
    this->vorname=vorname;
}

string Kunde::get_vorname() const
{
    return this->vorname;
}

void Kunde::set_nachname(string nachname)
{
    this->nachname=nachname;
}

string Kunde::get_nachname() const
{
    return this->nachname;
}

void Kunde::set_id(int id)
{
    this->id=id;
}

int Kunde::get_id() const
{
    return this->id;
}

void Kunde::kunde_anzeigen()
{
    cout << setw(3) << setfill(' ') << left << this->get_id()
         << "| "  << setw(14) << setfill(' ') << left << this->get_vorname()
         << "| " << setw(14) << setfill(' ')<< left << this->get_nachname() << '\n';
}
