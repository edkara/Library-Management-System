#include <iostream>
#include "bibliothek.h"
#include "MLibrary.h"
#include "buch.h"
using namespace std;

int main()
{
    MLibrary MyLibrary;
    bool enter = true;
    char selection;
    char subselection;
    cout << "Bibliotheksverwaltung\n";
    while(enter)
    {
        cout << "\n(1) Media anlegen / Kunde anmelden\n";
        cout << "(2) Media loeschen / Media suchen\n";
        cout << "(3) Bestand / Kunden anzeigen\n";
        cout << "(4) Media nach Autor\n";
        cout << "(5) Media empfehlen\n";
        cout << "(6) Bibliothek speichern\n";
        cout << "(7) Bibliothek laden\n";
        cout << "(8) Media ausleihen\n";
        cout << "(9) Media zurueckgeben\n";
        cout << "(0) Programm verlassen\n";
        cout << "    Select> ";
        cin >> selection;
        switch(selection)
        {
        case '1':
            MyLibrary.mediaEinfuegen();
            continue;
        case '2':
            cout << "\n(1) Media loeschen\n(2) Media suchen\n";
            cout << "Select> ";
            cin >> subselection;
            if(subselection== '1')
            {
                MyLibrary.mediaLoeschen();
                continue;
            } else if(subselection == '2')
            {
                MyLibrary.mediaSuchen();
                continue;
            }
            continue;
        case '3':
            MyLibrary.mediaAnzeigen();
            continue;
        case '4':
            MyLibrary.mediaMitAuthorZuerstAnzeigen();
            continue;
        case '5':
            cout << "\n(1) Buch empfehlen\n(2) CD empfehlen\n(3) Hoerbuch empfehlen\n";
            cout << "Select> ";
            cin >> subselection;
            if(subselection == '1')
            {

                continue;
            } else if(subselection == '2')
            {

                continue;
            } else if(subselection == '3')
            {

                continue;
            }
            continue;
        case '6':
            if(selection== '6'){
                string author;
                cout << "Autor: ";
                cin.ignore();
                getline(cin, author);
                MyLibrary.mediaAusBestimmtenAuthor(author);
                continue;
            }
        case '7':
            MyLibrary.mediaImportieren();
            MyLibrary.kundenImportieren();
            cout << "\n Die Anzahl der Buecher ist: " << MyLibrary.anzahlDerMedienZaehlen() << endl;
            continue;
        case '8':
            cout << "Ich zaehle die Woerter: " << endl;
            MyLibrary.alleWoerterZaehlen();
            continue;
        case '9':

            continue;
        case '0':
            if(selection == '0')
            {
                enter = false;
                break;
            }
        default: cout << "\nUngueltige Eingabe\n";
        }
    }

}
