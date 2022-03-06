#ifndef CD_H
#define CD_H
#include "medien.h"
#include <iomanip>
using namespace std;

class CD : public virtual Medien{
public:
    CD(string author, string title, int lastId, Kunde* ausleiher, char zustand, string spieldauer);
    void setSpieldauer(string spieldauer);
    string getSpieldauer() const;
    void mediaAnzeigen() override;
    void mediaAnzeigen_author() override;
    ~CD() override;
private:
    string spieldauer;
};
#endif // CD_H
