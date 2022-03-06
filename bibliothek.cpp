#include "bibliothek.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <locale>
#include <fstream>
#include <type_traits>
Bibliothek::Bibliothek()
{

}

void Bibliothek::insert_media()
{
    char subselection;
    cout << "\n(a) Buch anlegen\n(b) CD anlegen\n(c) Hoerbuch anlegen\n(d) Kunde registrieren\n";
    cout << "Select> ";
    cin >> subselection;
    if(subselection == 'a') {
        string author, title;
        int seitenzahl;
        cout << "\n-der Autor> ";
        cin.ignore();
        getline(cin, author);
        cout << "-der Titel> ";
        getline(cin, title);
        cout << "-die Seitenzahl> ";
        cin >> seitenzahl;
        Kunde* kunde = new Kunde();
        Buch* book = nullptr;
        if(alleMedien.size() > 0)
        {
            book = new Buch(author, title, alleMedien.back()->getId(), kunde, '+', seitenzahl);
            alleMedien.push_back(book);

        }
        else
        {
            book = new Buch(author, title, 0, kunde, '+', seitenzahl);
            alleMedien.push_back(book);

        }
        //alleMedien.push_back(book);
    } else if(subselection == 'b') {
        string author, title, spieldauer;
        cout << "\n-der Artist> ";
        cin.ignore();
        getline(cin, author);
        cout << "-der Titel> ";
        getline(cin, title);
        cout << "-die Spieldauer> ";
        cin >> spieldauer;
        Kunde* kunde = new Kunde();
        CD* cd = nullptr;
        if(alleMedien.size() > 0)
        {
            cd = new CD(author,title, alleMedien.back()->getId(), kunde, '+', spieldauer);
        }
        else
        {
            cd = new CD(author, title, 0, kunde,'+', spieldauer);
        }
        alleMedien.push_back(cd);
    } else if(subselection == 'c') {
        string author, title, spieldauer;
        int seitenzahl;
        cout << "\n-der Autor> ";
        cin.ignore();
        getline(cin, author);
        cout << "-der Titel> ";
        getline(cin, title);
        cout << "-die Seitenzahl> ";
        cin >> seitenzahl;
        cout << "-die Spieldauer> ";
        cin >> spieldauer;
        Kunde* kunde = new Kunde();
        Hoerbuch* hoerbuch = nullptr;
        if(alleMedien.size() > 0)
        {
            hoerbuch = new Hoerbuch(author, title, alleMedien.back()->getId(), kunde, '+', seitenzahl, spieldauer);
        }
        else
        {
            hoerbuch = new Hoerbuch(author, title, 0, kunde, '+', seitenzahl, spieldauer);
        }
        alleMedien.push_back(hoerbuch);
    } else if(subselection == 'd') {
        string vorname, nachname;
        cout << "\n-Ihre Vorname? ";
        cin.ignore();
        getline(cin, vorname);
        cout << "-Ihre Nachname? ";
        getline(cin, nachname);
        Kunde* neue_kunde = nullptr;
        if(alleKunden.size() > 0)
        {
            neue_kunde = new Kunde(vorname, nachname, alleKunden.back()->get_id()+1);
        }
        else
        {
            neue_kunde = new Kunde(vorname, nachname, 0);
        }
        alleKunden.push_back(neue_kunde);
    }
}

void Bibliothek::delete_media()
{
    int id;
    bool mediaDeleted = false;
    cout << "\n-ID des Mediums eingeben> ";
    cin >> id;
    vector<Medien*>::iterator it;
    for (it = alleMedien.begin(); it != alleMedien.end(); )
    {
        if((*it)->getId()==id && (*it)->getZustand()=='+')
        {
            delete *it;
            it = alleMedien.erase(it);
            mediaDeleted = true;
        }
        else {
            ++it;
        }
    }
    if(mediaDeleted == false)
    {
        cout << "\nDas Medium steht nicht zur Verfuegung.\n";
    }
}

bool Bibliothek::cmp_order(const Medien* a, const Medien* b)
{
    return  a->getId() < b->getId();
}

bool Bibliothek::cmp_idCustomer(const Kunde *a, const Kunde *b)
{
    return  a->get_id() < b->get_id();
}

void Bibliothek::display_media()
{
    char subselection;
    cout << "\n(a) Medien anzeigen\n(b) Kunden anzeigen\n";
    cout << "Select> ";
    cin >> subselection;
    if(subselection == 'a')
    {
        sort(alleMedien.begin(), alleMedien.end(), cmp_order);
        cout <<'\n'<<setw(2)<<setfill(' ')<< left << "T"<< setw(3)<< setfill(' ')<< left << "| ID"<< setw(25) << setfill(' ')<< left << "| Autor"<< setw(25) << setfill(' ')<< left << "| Titel" << setw(6)<< setfill(' ')<< left << "|"<< setw(2)<< setfill(' ')<< left << "|"<< setw(3)<< setfill(' ')<< left << "|ID" << setw(8)  << setfill(' ')<< left << "| Entleiher";
        cout << setw(81) << setfill('-')<< "\n";
        for(Medien* basepointer : alleMedien)
        {
            if(Buch* pointerb = dynamic_cast<Buch*>(basepointer))
            {
                pointerb->mediaAnzeigen();
            }
        }
        cout << "\n" << setw(81) << setfill('-')<< "\n";
        for(Medien* basepointer : alleMedien)
        {
            if(CD* pointerb = dynamic_cast<CD*>(basepointer))
            {
                pointerb->mediaAnzeigen();
            }
        }
        cout << "\n" << setw(81) << setfill('-')<< "\n";
        for(Medien* basepointer : alleMedien)
        {
            if(Hoerbuch* pointerb = dynamic_cast<Hoerbuch*>(basepointer))
            {
                pointerb->mediaAnzeigen();
            }
        }
    } else if(subselection == 'b') {
        sort(alleKunden.begin(), alleKunden.end(), cmp_idCustomer);
        cout << '\n' << setw(3)  << setfill(' ')<< left <<"ID"<< setw(16)  << setfill(' ')<< left <<"| Vorname" << setw(15)  << setfill(' ')<< left <<"| Nachname";
        cout << setw(81) << setfill('-') << "\n";
        for(Kunde* basepointer : alleKunden)
        {
            basepointer->kunde_anzeigen();
            /*if(basepointer->get_id()!=0)
            {
                basepointer->kunde_anzeigen();
            }*/
        }
    }
}

bool Bibliothek::cmp_author(const Medien* a, const Medien* b)
{
    return  a->getAuthor().compare(b->getAuthor()) < 0;
}

void Bibliothek::display_media_author()
{
    sort(alleMedien.begin(), alleMedien.end(), cmp_author);
    cout << "\n"<< setw(2) << setfill(' ') << left << "T" << setw(25) << setfill(' ')<< left << "| Autor"<< setw(25) << setfill(' ')<< left << "| Titel"<< setw(3) << setfill(' ')<< left << "| ID"<< setw(6)<< setfill(' ')<< left << "|"<< setw(2)<< setfill(' ')<< left << "|"<< setw(3)<< setfill(' ')<< left << "|ID"<< setw(8)  << setfill(' ')<< left << "| Entleiher";
    cout << setw(81) << setfill('-')<< "\n";
    for(Medien* basepointer : alleMedien)
    {
        if(Buch* pointerb = dynamic_cast<Buch*>(basepointer))
        {
            pointerb->mediaAnzeigen_author();
        }
    }
    cout << "\n" << setw(81) << setfill('-')<< "\n";
    for(Medien* basepointer : alleMedien)
    {
        if(CD* pointerb = dynamic_cast<CD*>(basepointer))
        {
            pointerb->mediaAnzeigen_author();
        }
    }
    cout << "\n" << setw(81) << setfill('-')<< "\n";
    for(Medien* basepointer : alleMedien)
    {
        if(Hoerbuch* pointerb = dynamic_cast<Hoerbuch*>(basepointer))
        {
            pointerb->mediaAnzeigen_author();
        }
    }
}

void Bibliothek::recommend_book()
{
    srand(time(0));
    char selectEmpf;
    cout << "\n(a) vom bestimmten Author?\n(b) Best Seller?\n";
    cout << "Select> ";
    cin >> selectEmpf;
    if(selectEmpf == 'a')
    {
        string author;
        cout << "\n-der gewuenschte Autor eingeben> ";
        cin.ignore();
        getline(cin, author);
        vector<Buch*> booksWrittenBy;
        for(Medien* basepointer : alleMedien)
        {
            if(Buch* pointerb = dynamic_cast<Buch*>(basepointer))
            {
                if(pointerb->getZustand() == '+' && pointerb->getAuthor() == author)
                {
                    booksWrittenBy.push_back(pointerb);
                }
            }
        }
        if(booksWrittenBy.size() > 0)
        {
            int myRandom = rand() % booksWrittenBy.size();
            cout << "\n"<< setw(2) << setfill(' ') << left << "T" << setw(25) << setfill(' ')<< left << "| Autor"<< setw(25) << setfill(' ')<< left << "| Titel"<< setw(4)  << setfill(' ')<< left << "| ID"<< setw(6)<< setfill(' ')<< left << "|"<< setw(2)<< setfill(' ')<< left << "|"<< setw(3)<< setfill(' ')<< left << "|ID"<< setw(8)  << setfill(' ')<< left << "| Entleiher";
            cout << setw(81) << setfill('-')<< "\n";
            booksWrittenBy.at(myRandom)->mediaAnzeigen_author();
        } else cout << "\nBuecher des bevorzugten Author sind im Moment nicht vorhanden!\n";
    } else if(selectEmpf == 'b')
    {
        vector<Buch*> randomBooks;
        for(Medien* basepointer : alleMedien)
        {
            if(Buch* pointerb = dynamic_cast<Buch*>(basepointer))
            {
                if(pointerb->getZustand()=='+')
                {
                    randomBooks.push_back(pointerb);
                }
            }
        }
        if(randomBooks.size() > 0)
        {
            int myRandom = rand() % randomBooks.size();
            cout << "\n"<< setw(2) << setfill(' ') << left << "T" << setw(25) << setfill(' ')<< left << "| Autor"<< setw(25) << setfill(' ')<< left << "| Titel"<< setw(4)  << setfill(' ')<< left << "| ID"<< setw(6)<< setfill(' ')<< left << "|"<< setw(2)<< setfill(' ')<< left << "|"<< setw(3)<< setfill(' ')<< left << "|ID"<< setw(8)  << setfill(' ')<< left << "| Entleiher";
            cout << setw(81) << setfill('-')<< "\n";
            randomBooks.at(myRandom)->mediaAnzeigen_author();
        } else cout << "\nAlle Buecher sind momentan ausgeliehen!\n";
    }
}

void Bibliothek::recommend_cd()
{
    srand(time(0));
    char selectEmpf;
    cout << "\n(a) vom bestimmten Artist?\n(b) Best Seller?\n";
    cout << "Select> ";
    cin >> selectEmpf;
    if(selectEmpf == 'a')
    {
        string author;
        cout << "\n-der gewuenschte Artist eingeben> ";
        cin.ignore();
        getline(cin, author);
        vector<CD*> CDsBy;
        for(Medien* basepointer : alleMedien)
        {
            if(CD* pointerb = dynamic_cast<CD*>(basepointer))
            {
                if(pointerb->getZustand()== '+' && pointerb->getAuthor() == author)
                {
                    CDsBy.push_back(pointerb);
                }
            }
        }
        if(CDsBy.size() > 0)
        {
            int myRandom = rand() % CDsBy.size();
            cout << "\n"<< setw(2) << setfill(' ') << left << "T" << setw(25) << setfill(' ')<< left << "| Autor"<< setw(25) << setfill(' ')<< left << "| Titel"<< setw(3)  << setfill(' ')<< left << "| ID"<< setw(6)<< setfill(' ')<< left << "|"<< setw(2)<< setfill(' ')<< left << "|"<< setw(3)<< setfill(' ')<< left << "|ID"<< setw(8)  << setfill(' ')<< left << "| Entleiher";
            cout << setw(81) << setfill('-')<< "\n";
            CDsBy.at(myRandom)->mediaAnzeigen_author();
        } else cout << "\nCDs des bevorzugten Artist sind im Moment nicht vorhanden.\n";
    } else if(selectEmpf == 'b')
    {
        vector<CD*> randomCDs;
        for(Medien* basepointer : alleMedien)
        {
            if(CD* pointerb = dynamic_cast<CD*>(basepointer))
            {
                if(pointerb->getZustand() == '+')
                {
                    randomCDs.push_back(pointerb);
                }
            }
        }
        if(randomCDs.size() > 0)
        {
            int myRandom = rand() % randomCDs.size();
            cout << "\n"<< setw(2) << setfill(' ') << left << "T" << setw(25) << setfill(' ')<< left << "| Autor"<< setw(25) << setfill(' ')<< left << "| Titel"<< setw(3)  << setfill(' ')<< left << "| ID"<< setw(6)<< setfill(' ')<< left << "|"<< setw(2)<< setfill(' ')<< left << "|"<< setw(3)<< setfill(' ')<< left << "|ID"<< setw(8)  << setfill(' ')<< left << "| Entleiher";
            cout << setw(81) << setfill('-')<< "\n";
            randomCDs.at(myRandom)->mediaAnzeigen_author();
        } else cout << "\nAlle CDs sind momentan ausgeliehen!\n";
    }
}

void Bibliothek::recommend_hoerbuch()
{
    srand(time(0));
    char selectEmpf;
    cout << "\n(a) vom bestimmten Artist?\n(b) Best Seller?\n";
    cout << "Select> ";
    cin >> selectEmpf;
    if(selectEmpf == 'a')
    {
        string author;
        cout << "\n-der gewuenschte Artist eingeben> ";
        cin.ignore();
        getline(cin, author);
        vector<Hoerbuch*> hbsBy;
        for(Medien* basepointer : alleMedien)
        {
            if(Hoerbuch* pointerb = dynamic_cast<Hoerbuch*>(basepointer))
            {
                if(pointerb->getZustand()== '+' && pointerb->getAuthor() == author)
                {
                    hbsBy.push_back(pointerb);
                }
            }
        }
        if(hbsBy.size() > 0)
        {
            int myRandom = rand() % hbsBy.size();
            cout << "\n"<< setw(2) << setfill(' ') << left << "T" << setw(25) << setfill(' ')<< left << "| Autor"<< setw(25) << setfill(' ')<< left << "| Titel"<< setw(3)  << setfill(' ')<< left << "| ID"<< setw(6)<< setfill(' ')<< left << "|"<< setw(2)<< setfill(' ')<< left << "|"<< setw(3)<< setfill(' ')<< left << "|ID"<< setw(8)  << setfill(' ')<< left << "| Entleiher";
            cout << setw(81) << setfill('-')<< "\n";
            hbsBy.at(myRandom)->mediaAnzeigen_author();
        } else cout << "\nCDs des bevorzugten Artist sind im Moment nicht vorhanden.\n";
    } else if(selectEmpf == 'b')
    {
        vector<Hoerbuch*> randomHBs;
        for(Medien* basepointer : alleMedien)
        {
            if(Hoerbuch* pointerb = dynamic_cast<Hoerbuch*>(basepointer))
            {
                if(pointerb->getZustand() == '+')
                {
                    randomHBs.push_back(pointerb);
                }
            }
        }
        if(randomHBs.size() > 0)
        {
            int myRandom = rand() % randomHBs.size();
            cout << "\n"<< setw(2) << setfill(' ') << left << "T" << setw(25) << setfill(' ')<< left << "| Autor"<< setw(25) << setfill(' ')<< left << "| Titel"<< setw(3)  << setfill(' ')<< left << "| ID"<< setw(6)<< setfill(' ')<< left << "|"<< setw(2)<< setfill(' ')<< left << "|"<< setw(3)<< setfill(' ')<< left << "|ID"<< setw(8)  << setfill(' ')<< left << "| Entleiher";
            cout << setw(81) << setfill('-')<< "\n";
            randomHBs.at(myRandom)->mediaAnzeigen_author();
        } else cout << "\nAlle CDs sind momentan ausgeliehen!\n";
    }
}

void Bibliothek::export_customers()
{
    sort(alleKunden.begin(), alleKunden.end(), cmp_idCustomer);
    ofstream customersFile;
    customersFile.open("../meine_kunde.csv", fstream::out|fstream::trunc);
    if(!customersFile)
    {
        cerr << "meine_kunde.csv kann nicht geoeffnet werden!\n";
    }
    if(customersFile.is_open())
    {
        for(Kunde* basepointer : alleKunden)
        {
            customersFile << basepointer->get_id() << ";" << basepointer->get_vorname() << ";" << basepointer->get_nachname() << endl;
        }
    }
    customersFile.close();
}

vector<string> Bibliothek::line_customer(string line)
{
    vector<string> kunde;
    stringstream lineStream(line);
    string cell;
    while(getline(lineStream,cell, ';'))
    {
        kunde.push_back(cell);
    }
    if (!lineStream && cell.empty())
    {
        kunde.push_back("");
    }
    return kunde;
}

void Bibliothek::import_customers()
{
    ifstream loadCustomers;
    loadCustomers.open("../meine_kunde.csv", fstream::in);
    if(!loadCustomers)
    {
        cerr << "meine_kunde.csv kann nicht geoeffnet werden!\n";
    }
    string line;
    if(loadCustomers.is_open())
    {
        while(getline(loadCustomers, line))
        {
            vector<string> take_kunde = line_customer(line);
            Kunde* kunde = new Kunde(take_kunde.at(1), take_kunde.at(2), stoi(take_kunde.at(0)));
            alleKunden.push_back(kunde);
        }
    }
    loadCustomers.close();
}

vector<string> Bibliothek::line_media(string line)
{
    vector<string> media;
    //Take the line in stringstream
    stringstream lineStream(line);
    string cell;
    while(getline(lineStream,cell, ';'))
    {
        media.push_back(cell);
    }
    //This checks for a trailing ; with no data after it
    if (!lineStream && cell.empty())
    {
        //If there was a trailing ; then add an empty element
        media.push_back("");
    }
    return media;
}

void Bibliothek::import_media()
{
    ifstream loadBooks("../medien.txt");
    string line;
    if(loadBooks.is_open())
    {
        while(getline(loadBooks,line))
        {
            if(line.front()=='B')
            {
                vector<string> take_buch = line_media(line);
                Kunde* kunde = new Kunde(take_buch.at(7), take_buch.at(8), stoi(take_buch.at(6)));
                Buch* book = new Buch(take_buch.at(2), take_buch.at(3), stoi(take_buch.at(1))-1, kunde, take_buch.at(5)[0], stoi(take_buch.at(4)));
                alleMedien.push_back(book);
            } else if(line.front()=='C')
            {
                vector<string> take_cd = line_media(line);
                Kunde* kunde = new Kunde(take_cd.at(7), take_cd.at(8), stoi(take_cd.at(6)));
                CD* cd = new CD(take_cd.at(2), take_cd.at(3), stoi(take_cd.at(1))-1, kunde, take_cd.at(5)[0], take_cd.at(4));
                alleMedien.push_back(cd);
            } else if(line.front()=='H')
            {
                vector<string> take_hoerbuch = line_media(line);
                Kunde* kunde = new Kunde(take_hoerbuch.at(8), take_hoerbuch.at(9), stoi(take_hoerbuch.at(7)));
                Hoerbuch* hoerbuch = new Hoerbuch(take_hoerbuch.at(2), take_hoerbuch.at(3), stoi(take_hoerbuch.at(1))-1, kunde, take_hoerbuch.at(6)[0], stoi(take_hoerbuch.at(4)) ,take_hoerbuch.at(5));
                alleMedien.push_back(hoerbuch);
            }
        }
        cout << endl;
        loadBooks.close();
    } else cout << "\n .txt File does not exist yet." << endl;
}

void Bibliothek::import_export_media()
{
    fstream myFile("../meine_kunde.csv", ios::out | ios::in | ios::app);
    char select;
    cout << "(1) Schreiben \n (2) Laden\n";
    cout << "Select> ";
    cin >> select;

    if(myFile.is_open())
    {
        if(select == '1')
        {
            string name, nachname;
            cout << "Vorname der Kunde? ";
            cin.ignore();
            getline(cin, name);
            cout << "Nachname der Kunde? ";
            getline(cin, nachname);
            Kunde* kunde = new Kunde(name, nachname);

            myFile << kunde->get_id() << ";" << kunde->get_vorname() << ";" << kunde->get_nachname() << endl;
        } else if(select == '2')
        {
            string line;
            while(getline(myFile, line))
            {
                vector<string> take_kunde = line_customer(line);
                Kunde* kunde = new Kunde(take_kunde.at(1), take_kunde.at(2), stoi(take_kunde.at(0)));
                alleKunden.push_back(kunde);

            }
        }
        myFile.close();
    } else cout << "\n Error! .txt file does not exist yet!\n";
}

void Bibliothek::export_media()
{
    try{
        sort(alleMedien.begin(), alleMedien.end(), cmp_order);
        ofstream booksFile("../medien.txt");
        if(booksFile.is_open())
        {
            for(Medien* basepointer : alleMedien)
            {
                if(Buch* pointerb = dynamic_cast<Buch*>(basepointer))
                {
                    if(Hoerbuch* pointerc = dynamic_cast<Hoerbuch*>(pointerb))
                    {
                        booksFile << 'H' << ";" <<pointerc->getId()<<";"<< pointerc->getAuthor()<<";" << pointerc->getTitle()<<";"<<pointerc->getSeitenzahl()<< ";" << pointerc->getSpieldauer()
                                  << ";"<<pointerc->getZustand()<< ";" << pointerc->getKunde()->get_id() << ";" << pointerc->getKunde()->get_vorname()<< ";" <<pointerc->getKunde()->get_nachname()<<"\n";
                    } else
                    {
                        booksFile << 'B' << ";" <<pointerb->getId()<<";"<< pointerb->getAuthor()<<";" << pointerb->getTitle()<<";"<<pointerb->getSeitenzahl()
                                  << ";"<<pointerb->getZustand()<< ";" << pointerb->getKunde()->get_id() << ";" << pointerb->getKunde()->get_vorname()<< ";" <<pointerb->getKunde()->get_nachname()<<"\n";
                    }
                } else if(CD* pointerb = dynamic_cast<CD*>(basepointer))
                {
                    if(Hoerbuch* pointerc = dynamic_cast<Hoerbuch*>(pointerb))
                    {
                        booksFile << 'H' << ";" <<pointerc->getId()<<";"<< pointerc->getAuthor()<<";" << pointerc->getTitle()<<";"<<pointerc->getSeitenzahl() << ";" << pointerc->getSpieldauer()
                                  << ";"<<pointerc->getZustand()<< ";" << pointerc->getKunde()->get_id() << ";" << pointerc->getKunde()->get_vorname()<< ";" <<pointerc->getKunde()->get_nachname()<<"\n";
                    }
                    else
                    {
                        booksFile << 'C' << ";" <<pointerb->getId()<<";"<< pointerb->getAuthor()<<";" << pointerb->getTitle()<<";"<<pointerb->getSpieldauer()
                                  << ";"<<pointerb->getZustand()<< ";"<<pointerb->getKunde()->get_id() << ";"<< pointerb->getKunde()->get_vorname()<< ";" <<pointerb->getKunde()->get_nachname()<<"\n";
                    }
                }
            }
            booksFile.close();
        } else throw "\nUnable to open file\n";

    } catch (const char* Text){
        cout << Text << endl;
    }
}

void Bibliothek::borrow_media()
{
    int id_media, id_kunde;
    bool borrowed = false;
    cout << "\n-ID des Kunden eingeben> ";
    cin >> id_kunde;
    cout << "-ID des Mediums eingeben> ";
    cin >> id_media;
    Kunde* kunde_tmp = nullptr;
    bool gefunden = false;
    for(Kunde* basepointer : alleKunden)
    {
        if(basepointer->get_id() == id_kunde)
        {
            kunde_tmp = basepointer;
            gefunden = true;
            break;
        }
    }
    if(gefunden)
    {
        for(Medien* basepointer : alleMedien)
        {
            if(basepointer->getId()==id_media && basepointer->getZustand() == '+')
            {
                basepointer->setZustand('-');
                basepointer->setKunde(kunde_tmp);
                borrowed = true;
                break;
            }
        }
        if(borrowed == false)
        {
            cout << "\nDas Medium ist im Moment nicht vorhanden.\n";
        }
    } else
    {
        cout << "\n-Kunde mit ID " << id_kunde << " ist nicht angemeldet!\n";
        cout << "-Mit Option (1)(c) im Hauptmenue zuerst Kunde registrieren\n";
    }
}

void Bibliothek::return_media()
{   
    int id_media, id_kunde;
    cout << "\n-ID des Kunden eingeben> ";
    cin >> id_kunde;
    cout << "-ID des Mediums eingeben> ";
    cin >> id_media;
    bool returned = false;
    for(Medien* basepointer : alleMedien)
    {
        if(basepointer->getId()==id_media && basepointer->getZustand() == '-' && basepointer->getKunde()->get_id()==id_kunde)
        {
            basepointer->setZustand('+');
            basepointer->setKunde(alleKunden.at(0));
            returned = true;
            break;
        }
    }
    if(!returned)
    {
        cout << "\n-Ungueltige ID des Mediums oder des Kunden!\n";
    }
}

void Bibliothek::find_media()
{
    string wort;
    cout << "\nStichwort eingeben> ";
    cin >> wort;
    vector<Medien*> tmp_media;
    bool found = false;
    for(Medien* basepointer : alleMedien)
    {
        if(basepointer->getTitle().find(wort)!=string::npos)
        {
            tmp_media.push_back(basepointer);
            found = true;
        }
    }
    if(found)
    {
        cout << "\n"<< setw(2) << setfill(' ') << left << "T" << setw(25) << setfill(' ')<< left << "| Autor"<< setw(25) << setfill(' ')<< left << "| Titel"<< setw(3)  << setfill(' ')<< left << "| ID"<< setw(6)<< setfill(' ')<< left << "|"<< setw(2)<< setfill(' ')<< left << "|"<< setw(3)<< setfill(' ')<< left << "|ID"<< setw(8)  << setfill(' ')<< left << "| Entleiher";
        cout << setw(81) << setfill('-')<< "\n";
        for(Medien* media : tmp_media)
        {
            media->mediaAnzeigen_author();
        }
    } else cout << "\nFalsches Stichwort!\n";
}


void Bibliothek::delete_library()
{
    for(Medien* basepointer : alleMedien)
    {
        delete basepointer;
    }
    alleMedien.clear();

    for(Kunde* basepointer : alleKunden)
    {
        delete basepointer;
    }
    alleKunden.clear();
}

