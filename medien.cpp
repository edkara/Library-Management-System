#include "medien.h"

Medien::Medien()
{

}

Medien::Medien(string author, string title, int lastId, Kunde* ausleiher, char zustand)
    : author(author), title(title), id(++lastId), ausleiher(ausleiher), zustand(zustand)
{

}

string Medien::getAuthor() const
{
    return this->author;
}

void Medien::setAuthor(string author)
{
    this->author=author;
}

string Medien::getTitle() const
{
    return this->title;
}

void Medien::setTitle(string title)
{
    this->title=title;
}

int Medien::getId() const
{
    return this->id;
}

void Medien::setId(int id)
{
    this->id=id;
}

char Medien::getZustand() const
{
    return this->zustand;
}

void Medien::setZustand(char zustand)
{
    this->zustand=zustand;
}

Kunde* Medien::getKunde() const
{
    return this->ausleiher;
}

void Medien::setKunde(Kunde* ausleiher)
{
    this->ausleiher=ausleiher;
}

void Medien::mediaAnzeigen()
{
    cout << "diese methode hier!\n\n\n";
}

Medien::~Medien()
{

}
