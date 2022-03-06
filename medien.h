#ifndef MEDIEN_H
#define MEDIEN_H
#include "kunde.h"
#include <iostream>
using namespace std;

class Medien {
public:
    Medien();
    Medien(string author, string title, int lastId, Kunde* ausleiher, char zustand);
    string getAuthor() const;
    void setAuthor(string author);
    string getTitle() const;
    void setTitle(string title);
    int getId() const;
    void setId(int id);
    char getZustand() const;
    void setZustand(char zustand);
    Kunde* getKunde() const;
    void setKunde(Kunde* ausleiher);
    virtual void mediaAnzeigen();
    virtual void mediaAnzeigen_author() = 0;
    virtual ~Medien();
private:
    string author;
    string title;
    int id;
    Kunde* ausleiher;
    char zustand;
};

inline ostream& operator<<(ostream& ausgabe, const Medien& medium)
{
    ausgabe<<setw(3) << setfill(' ') << left << medium.getId() <<"| " << setw(15) << setfill(' ') << left << medium.getAuthor() <<"| "<< setw(20) << setfill(' ') << left << medium.getTitle() << "|" << medium.getZustand() << "|" << medium.getKunde()->get_vorname() << " " << medium.getKunde()->get_nachname();
    return ausgabe;
}

#endif // MEDIEN_H
