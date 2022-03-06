#ifndef PERSON_H
#define PERSON_H
#include <iomanip>
#include <iostream>
using namespace std;

class Kunde{
public:
    Kunde(string vorname = "", string nachname = "", int lastId = 0);
    string get_vorname() const;
    void set_vorname(string vorname);
    string get_nachname() const;
    void set_nachname(string nachname);
    int get_id() const;
    void set_id(int id);
    void kunde_anzeigen();
private:
    string vorname;
    string nachname;
    int id;
};

#endif // PERSON_H
