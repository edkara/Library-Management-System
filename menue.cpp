#include"menue.h"

void Menue::start_menue()
{
    cout << "\n(1) Buch anlegen\n";
    cout << "(2) Buch loeschen\n";
    cout << "(3) Bestand anzeigen\n";
    cout << "(4) Buecher nach Autor\n";
    cout << "(5) Buch empfehlen\n";
    cout << "(6) Bibliothek speichern\n";
    cout << "(7) Bibliothek laden\n";
    cout << "(8) Buch ausleihen\n";
    cout << "(9) Buch zurueckgeben\n";
    cout << "(0) Programm verlassen\n";
    cout << "    Select> ";
}

void Menue::recommend_book_menue()
{
    cout << "\n    (a) favorisierter Autor eingeben\n";
    cout << "    (b) Bestseller vom Bestand waehlen\n";
    cout << "     Select> ";
}
