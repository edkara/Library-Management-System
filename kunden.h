#ifndef KUNDEN_H
#define KUNDEN_H
#include <iostream>
#include <algorithm>
#include "kunde.h"
using namespace std;
class Kunden
{
public:
    Kunden();
    void insert_kunde();
    void delete_kunde();
private:
    vector<Person*> alleKunden;
};
#endif // KUNDEN_H
