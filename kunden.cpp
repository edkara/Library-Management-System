#include "kunden.h"

Kunden::Kunden()
{

}

void Kunden::insert_kunde()
{
    string vorname, nachname;
    cout << "\n-Ihre Vorname? ";
    cin.ignore();
    getline(cin, vorname);
    cout << "-Ihre Nachname? ";
    getline(cin, nachname);
    Person* kunde = nullptr;
    if(alleKunden.size() > 0)
    {
        kunde = new Person(vorname, nachname, alleKunden.back()->get_id());
    }
    else
    {
        kunde = new Person(vorname, nachname, 0);
    }
    alleKunden.push_back(kunde);
}

void Kunden::delete_kunde()
{
    int id;
    bool mediaDeleted = false;
    cout << "\n-ID des Kundes eingeben> ";
    cin >> id;
    vector<Person*>::iterator it;
    for (it = alleKunden.begin(); it != alleKunden.end(); )
    {
        if((*it)->get_id()==id)
        {
            delete *it;
            it = alleKunden.erase(it);
            mediaDeleted = true;
        }
        else {
            ++it;
        }
    }
    if(mediaDeleted == false)
    {
        cout << "\nDie eingegebene ID ist ungueltig.\n";
    }
}
