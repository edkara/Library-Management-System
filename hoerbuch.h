#ifndef HOERBUCH_H
#define HOERBUCH_H
#include "buch.h"
#include "cd.h"
#include "medien.h"

class Hoerbuch : public Buch, public CD{
public:
    Hoerbuch(string author, string title, int lastId, Kunde* ausleiher, char zustand, int seitenzahl, string spieldauer);
    void mediaAnzeigen() override;
    void mediaAnzeigen_author() override;
    ~Hoerbuch() override;
};

#endif // HOERBUCH_H
