#ifndef BIBLIOTHEK_H
#define BIBLIOTHEK_H
#include <algorithm>
#include <sstream>
#include <map>
#include "buch.h"
#include "cd.h"
#include "hoerbuch.h"
#include "kunde.h"
#include <queue>
using namespace std;

class Bibliothek{
public:
    Bibliothek();
    void insert_media();
    void delete_media();
    static bool cmp_order(const Medien* a, const Medien* b);
    static bool cmp_idCustomer(const Kunde* a, const Kunde* b);
    void display_media();
    static bool cmp_author(const Medien* a, const Medien* b);
    void display_media_author();
    void recommend_book();
    void recommend_cd();
    void recommend_hoerbuch();
    void export_customers();
    vector<string> line_customer(string line);
    void import_customers();
    void export_media();
    vector<string> line_media(string line);
    void import_media();
    void import_export_media();
    void borrow_media();
    void return_media();
    void find_media();
    void delete_library();
private:
    vector<Medien*> alleMedien;
    vector<Kunde*> alleKunden;
};




#endif // BIBLIOTHEK_H
