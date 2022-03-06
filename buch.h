#ifndef BUCH_H
#define BUCH_H
#include "medien.h"
#include <iomanip>
using namespace std;

class Buch : public virtual Medien{
public:
    Buch(string author, string title, int lastId, Kunde* ausleiher, char zustand, int seitenzahl);
    void setSeitenzahl(int seitenzahl);
    int getSeitenzahl() const;
    void mediaAnzeigen() override;
    void mediaAnzeigen_author() override;
    ~Buch() override;
private:
    int seitenzahl;
};

#endif // BUCH_H
