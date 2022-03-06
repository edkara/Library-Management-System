#include "MLibrary.h"

MLibrary::MLibrary(){

}

void MLibrary::mediaEinfuegen(){
    char selection;
    cout << "\n(a) Buch anlegen\n(b) CD anlegen\n";
    cout << "(c) Hoerbuch anlegen\n(d) Kunde registrieren\n";
    cout << "Select> ";
    cin >> selection;
    if(selection == 'a') {
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
        if(meineMedien.size() > 0)
        {
            book = new Buch(author, title, 22, kunde, '+', seitenzahl);
        }
        else
        {
            book = new Buch(author, title, 0, kunde, '+', seitenzahl);
        }
        meineMedien.insert(make_pair("B", book));
    } else if(selection == 'b') {
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
        if(meineMedien.size() > 0)
        {
            cd = new CD(author,title, 22, kunde, '+', spieldauer);
        }
        else
        {
            cd = new CD(author, title, 0, kunde,'+', spieldauer);
        }
        meineMedien.insert(make_pair("C", cd));
    } else if(selection == 'c') {
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
        if(meineMedien.size() > 0)
        {
            hoerbuch = new Hoerbuch(author, title, 22, kunde,
                                    '+', seitenzahl, spieldauer);
        }
        else
        {
            hoerbuch = new Hoerbuch(author, title, 0, kunde,
                                    '+', seitenzahl, spieldauer);
        }
        meineMedien.insert(make_pair("H", hoerbuch));
    } else if(selection == 'd') {
        int key;
        string vorname, nachname;
        cout << "\n-Ihre Vorname? ";
        cin.ignore();
        getline(cin, vorname);
        cout << "-Ihre Nachname? ";
        getline(cin, nachname);
        cout << "-Key value? ";
        cin >> key;
        Kunde* neue_kunde = nullptr;
        if(meineKunden.size() > 0)
        {
            neue_kunde = new Kunde(vorname, nachname, 22+1);
        }
        else
        {
            neue_kunde = new Kunde(vorname, nachname, 0);
        }
        meineKunden.insert(make_pair(key, neue_kunde));
    }
}

void MLibrary::mediaAnzeigen(){
    char subselection;
    cout << "\n(a) Medien anzeigen\n(b) Kunden anzeigen\n";
    cout << "Select> ";
    cin >> subselection;
    if(subselection == 'a')
    {
        cout <<'\n'<<setw(2)<<setfill(' ')<< left << "T"<< setw(3)<< setfill(' ')<< left
            << "| ID"<< setw(25) << setfill(' ')<< left << "| Autor"<< setw(25) << setfill(' ')<< left << "| Titel" << setw(6)<< setfill(' ')<< left << "|"<< setw(2)<< setfill(' ')<< left << "|"<< setw(3)<< setfill(' ')<< left << "|ID" << setw(8)  << setfill(' ')<< left << "| Entleiher";
        cout << setw(81) << setfill('-')<< "\n";
        for(auto &p : meineMedien){
            if(Buch *pointerb = dynamic_cast<Buch*>(p.second)){
                cout << "B";
                pointerb->mediaAnzeigen();
            }
        }
        cout << "\n" << setw(81) << setfill('-')<< "\n";
        for(auto &p : meineMedien){
            if(CD *pointerb = dynamic_cast<CD*>(p.second)){
                cout << "C";
                pointerb->mediaAnzeigen();
            }
        }
        cout << "\n" << setw(81) << setfill('-')<< "\n";
        for(auto &p : meineMedien){
            if(Hoerbuch *pointerb = dynamic_cast<Hoerbuch*>(p.second)){
                cout << "H";
                pointerb->mediaAnzeigen();
            }
        }

    } else if(subselection == 'b') {
        cout << '\n' << setw(3)  << setfill(' ')<< left <<"ID"<< setw(16)  << setfill(' ')<< left <<"| Vorname" << setw(15)  << setfill(' ')<< left <<"| Nachname";
        cout << setw(81) << setfill('-') << "\n";
        for(auto &basepointer : meineKunden)
        {
            cout << basepointer.first;
            basepointer.second->kunde_anzeigen();
        }
    }
}

void MLibrary::mediaLoeschen(){
    int id;
    bool mediaDeleted = false;
    cout << "\n-ID des Mediums eingeben> ";
    cin >> id;
    Library::iterator itr;
    for (itr = meineMedien.begin(); itr != meineMedien.end(); )
    {
        if((*itr).second->getId()==id && (*itr).second->getZustand()=='+')
        {
            delete (*itr).second;
            itr = meineMedien.erase(itr);
            mediaDeleted = true;
        }
        else {
            ++itr;
        }
    }
    if(mediaDeleted == false)
    {
        cout << "\nDas Medium steht nicht zur Verfuegung.\n";
    }
}

void MLibrary::mediaSuchen(){
    string wort;
    cout << "\nStichwort eingeben> ";
    cin >> wort;
    Library tmpMedia;
    bool found = false;
    Library::iterator itr;
    for(itr=meineMedien.begin(); itr!=meineMedien.end(); itr++){
        if(itr->second->getTitle().find(wort)!=string::npos){
            tmpMedia.insert(make_pair(itr->first, itr->second));
            found = true;
        }
    }
    if(found)
    {
        cout << "\n"<< setw(2) << setfill(' ') << left << "T" << setw(25) << setfill(' ')<< left << "| Autor"<< setw(25) << setfill(' ')<< left << "| Titel"<< setw(3)  << setfill(' ')<< left << "| ID"<< setw(6)<< setfill(' ')<< left << "|"<< setw(2)<< setfill(' ')<< left << "|"<< setw(3)<< setfill(' ')<< left << "|ID"<< setw(8)  << setfill(' ')<< left << "| Entleiher";
        cout << setw(81) << setfill('-')<< "\n";
        for(auto &media : tmpMedia)
        {
            cout << media.first;
            media.second->mediaAnzeigen_author();
        }
    } else cout << "\nFalsches Stichwort!\n";
}

void MLibrary::mediaMitAuthorZuerstAnzeigen(){
    cout << "\n"<< setw(2) << setfill(' ') << left << "T" << setw(25) << setfill(' ')<< left << "| Autor"<< setw(25) << setfill(' ')<< left << "| Titel"<< setw(3) << setfill(' ')<< left << "| ID"<< setw(6)<< setfill(' ')<< left << "|"<< setw(2)<< setfill(' ')<< left << "|"<< setw(3)<< setfill(' ')<< left << "|ID"<< setw(8)  << setfill(' ')<< left << "| Entleiher";
    cout << setw(81) << setfill('-')<< "\n";
    for(auto &p : meineMedien)
    {
        if(Buch* pointerb = dynamic_cast<Buch*>(p.second))
        {
            cout << "B";
            pointerb->mediaAnzeigen_author();
        }
    }
    cout << "\n" << setw(81) << setfill('-')<< "\n";
    for(auto &p : meineMedien)
    {
        if(CD* pointerb = dynamic_cast<CD*>(p.second))
        {
            cout << "C";
            pointerb->mediaAnzeigen_author();
        }
    }
    cout << "\n" << setw(81) << setfill('-')<< "\n";
    for(auto &p : meineMedien)
    {
        if(Hoerbuch* pointerb = dynamic_cast<Hoerbuch*>(p.second))
        {
            cout << "H";
            pointerb->mediaAnzeigen_author();
        }
    }
}

void MLibrary::alleBuecherAnzeigen(){
    cout <<'\n'<<setw(2)<<setfill(' ')<< left << "T"<< setw(3)<< setfill(' ')<< left << "| ID"<< setw(25) << setfill(' ')<< left << "| Autor"<< setw(25) << setfill(' ')<< left << "| Titel" << setw(6)<< setfill(' ')<< left << "|"<< setw(2)<< setfill(' ')<< left << "|"<< setw(3)<< setfill(' ')<< left << "|ID" << setw(8)  << setfill(' ')<< left << "| Entleiher";
    cout << setw(81) << setfill('-')<< "\n";
    for(auto &p : meineMedien)
    {
        if(Buch* pointerb = dynamic_cast<Buch*>(p.second))
        {
            cout << "B";
            pointerb->mediaAnzeigen_author();
        }
    }
}

void MLibrary::mediaImportieren(){
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
                Buch* book = new Buch(take_buch.at(2), take_buch.at(3), stoi(take_buch.at(1))-1,
                                      kunde, take_buch.at(5)[0], stoi(take_buch.at(4)));
                meineMedien.insert(make_pair("B", book));
            } else if(line.front()=='C')
            {
                vector<string> take_cd = line_media(line);
                Kunde* kunde = new Kunde(take_cd.at(7), take_cd.at(8), stoi(take_cd.at(6)));
                CD* cd = new CD(take_cd.at(2), take_cd.at(3), stoi(take_cd.at(1))-1,
                                kunde, take_cd.at(5)[0], take_cd.at(4));
                meineMedien.insert(make_pair("C", cd));
            } else if(line.front()=='H')
            {
                vector<string> take_hoerbuch = line_media(line);
                Kunde* kunde = new Kunde(take_hoerbuch.at(8), take_hoerbuch.at(9), stoi(take_hoerbuch.at(7)));
                Hoerbuch* hoerbuch = new Hoerbuch(take_hoerbuch.at(2), take_hoerbuch.at(3), stoi(take_hoerbuch.at(1))-1,
                                                  kunde, take_hoerbuch.at(6)[0], stoi(take_hoerbuch.at(4)) ,take_hoerbuch.at(5));
                meineMedien.insert(make_pair("H", hoerbuch));
            }
        }
        cout << endl;
        loadBooks.close();
    } else cout << "\n .txt File does not exist yet." << endl;
}

int MLibrary::anzahlDerMedienZaehlen(){
    int numerOfBooks = 0;
    ifstream loadBooks("../medien.txt");
    string line;
    if(loadBooks.is_open()){
        while(getline(loadBooks,line)){
            if(line.front()=='B'){
                numerOfBooks+=1;
            }
        }
    }
    return numerOfBooks;
}

void MLibrary::alleWoerterZaehlen(){
    vector<string> wordsInfile;
    ifstream file("../medien.txt");
    if(!file.is_open()){
        cout << "\nDie Datei konnte nicht geoeffnet werden!\n";
    } else{
        string line;
        while(getline(file,line)){
            vector<string> storeAttr = line_media(line);
            for(unsigned int i = 0; i < storeAttr.size(); i++){
                wordsInfile.push_back(storeAttr[i]);
            }
        }
        file.close();
    }
    cout << "\nDie Datei wurde gelesen\n";

    map<string,int> occurences;
    for(const string &oneWord : wordsInfile){
        if(occurences.count(oneWord)==0){
            occurences.insert(make_pair(oneWord, 1));
        } else{
            occurences[oneWord]++;
        }
    }
    cout << "\n Die Wordhaeufigkeit wurde ermittelt\n";

    priority_queue<pair<int,string>> dateiPriority;
    for(const auto &entry : occurences){
        dateiPriority.push(pair<int, string>(entry.second, entry.first));
    }
    cout << "\n Priority erstellt\n";

    for(unsigned int i = 0; i < dateiPriority.size(); i++){
        cout << dateiPriority.top().second << " : "
             << dateiPriority.top().first << endl;
        dateiPriority.pop();
    }
}

void MLibrary::kundenImportieren(){
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
            meineKunden.insert(make_pair(stoi(take_kunde.at(0)), kunde));
        }
    }
    loadCustomers.close();
}

vector<string> MLibrary::line_media(string line)
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

void MLibrary::mediaAusBestimmtenAuthor(string &author){
    multimap<string, Medien*> medienAuthor;
    for(auto &p : meineMedien){
        if(p.second->getAuthor()==author){
            medienAuthor.insert(make_pair(p.first, p.second));
        }
    }
    multimap<string, Medien*>::iterator itr;
    for(itr=medienAuthor.begin(); itr!=medienAuthor.end(); itr++){
        cout << itr->first << " " << itr->second->getAuthor() << " " << itr->second->getTitle() << endl;
    }
}

vector<string> MLibrary::line_customer(string line)
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

MLibrary::~MLibrary(){
    for(auto &p : meineMedien)
    {
        delete p.second;
    }
    meineMedien.clear();
}
