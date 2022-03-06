#ifndef MLIBRARY_H
#define MLIBRARY_H
#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>
#include "buch.h"
#include "cd.h"
#include "hoerbuch.h"
#include "kunde.h"
#include <queue>
using namespace std;

class MLibrary{
public:
    MLibrary();
    ~MLibrary();
    void mediaEinfuegen();
    void mediaAnzeigen();
    void mediaLoeschen();
    void mediaSuchen();
    void mediaMitAuthorZuerstAnzeigen();
    void alleBuecherAnzeigen();
    void mediaImportieren();
    void kundenImportieren();
    int anzahlDerMedienZaehlen();
    void alleWoerterZaehlen();
    void mediaAusBestimmtenAuthor(string &author);
    vector<string> line_customer(string line);
    vector<string> line_media(string line);
private:
    typedef multimap<string, Medien*> Library;
    Library meineMedien;
    typedef multimap<int, Kunde*> Customer;
    Customer meineKunden;
};

#endif // MLIBRARY_H
