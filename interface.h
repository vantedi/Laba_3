#ifndef _INTERFACE_H
#define _INTERFACE_H

#include "database.h"

class Interface {
 public:
    void add(DataBase* db);
    void remove(DataBase* db);
    void edit(DataBase* db);
    void search(DataBase* db);
    void print(DataBase* db);
    void run(DataBase* db);
    void menu();
};

#endif
