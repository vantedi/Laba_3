#ifndef _DB_H
#define _DB_H

#include <istream>
#include <string>
#include "meds.h"
#include "list.h"

using namespace std;

class DataBase {
    List *db;
    string filename;
 public:
    DataBase(string filename);
    ~DataBase();
    void add(string name, string purpose, int price);
    void remove(string name);
    void search(string name, Meds** meds); 
    void search(string purpose, List** list); 
    void search(int prince, List** list); 
    void print();
};
#endif
