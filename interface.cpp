#include <iostream>
#include <sstream>
#include <string>
#include "database.h"
#include "interface.h"

using namespace std;

void Interface::menu() {
    cout << "add    - Add new medicine" << endl;
    cout << "search - Search medicine in database" << endl;
    cout << "remove - Remove medicine from database" << endl;
    cout << "edit   - Edit medicine" << endl;
    cout << "print  - Print database" << endl;
    cout << "quit   - Quit" << endl;
}

void Interface::add(DataBase* db) {
    string name;
    string purpose;
    int price;
    cin.ignore();
    cout << "Name: ";
    getline(cin, name);
    cout << "Purpose: ";
    getline(cin, purpose);
    cout << "Price: ";
    cin >> price;
    cout << endl;
    db->add(name, purpose, price);
}

void Interface::remove(DataBase* db) {
    string name;
    cin.ignore();
    cout << "Name: ";
    getline(cin, name);
    db->remove(name);
}

void Interface::search(DataBase* db) {
    cin.ignore();
    int selection;
    string name, purpose;
    int price;
    cout << "Search by:\nName [0]\nPurpose [1]\nPrice [2]\n ";

    cin >> selection;

    switch (selection) {
    case 0: {
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        Meds* med = NULL;
        db->search(name, &med);
        if (med) {
            cout << *med << endl;
        }
        else {
            cout << "No medicine with name " << name << " was found" << endl;
        }
        break;
    }
    case 1: {
        cout << "Purpose: ";
        cin.ignore();
        getline(cin, purpose);
        List* list_purpose = NULL;
        db->search(purpose, &list_purpose);
        if (list_purpose->size() != 0) {
            cout << *list_purpose << endl;
        }
        else {
            cout << "No medicines with purpose " << purpose << " was found" << endl;
        }
        break;
    }
    case 2: {
        cout << "Price: ";
        cin >> price;
        List* list_price = NULL;
        db->search(price, &list_price);
        if (list_price->size() != 0) {
            cout << *list_price << endl;
        }
        else {
            cout << "No medicines with price " << price << " was found" << endl;
        }
        break;
    }
    default:
        cout << "Incorrect selection, please chose [0,1,2]" << endl;
    }
}
void Interface::edit(DataBase* db) {
    string name;
    string new_name;
    string new_purpose;
    int new_price;

    int selection = 0;

    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    Meds* med = NULL;
    db->search(name, &med);
    if (!med) {
        cout << name << " cannot be found database" << endl;
        return;
    }
    cout << "Edit name?\nNo [0]\nYes [1]\n ";
    cin >> selection;
    if (selection == 1) {
        cout << "New name: ";
        cin.ignore();
        getline(cin, new_name);
    }
    else if (selection == 0) {
        new_name = med->getName();
    }
    else {
        cout << "Incorrect selection, please chose [0,1]" << endl;
        return;
    }

    cout << "Edit purpose?\nNo [0]\nYes [1]\n ";
    cin >> selection;
    if (selection == 1) {
        cout << "New purpose: ";
        cin.ignore();
        getline(cin, new_purpose);
    }
    else if (selection == 0) {
        new_purpose = med->getPurpose();
    }
    else {
        cout << "Incorrect selection, please chose [0,1]" << endl;
        return;
    }
    cout << "Edit price?\nNo [0]\nYes [1]\n ";
    cin >> selection;
    if (selection == 1) {
        cout << "New price: ";
        cin >> new_price;
    }
    else if (selection == 0) {
        new_price = med->getPrice();
    }
    db->remove(name);
    db->add(new_name, new_purpose, new_price);
};



void Interface::print(DataBase* db) {
    db->print();
};


void Interface::run(DataBase* db) {
    cout << "Welcome to my programm!" << endl;
    cout << "-----------------------" << endl;
    cout << "Type \"menu\"" << endl;
    string command;
    while (true) {
        cout << "--> " << flush;
        cin.clear();
        cin >> command;
        if (command == "menu") {
            menu();
        }
        else if (command == "add") {
            add(db);
        }
        else if (command == "search") {
            search(db);
        }
        else if (command == "edit") {
            edit(db);
        }
        else if (command == "remove") {
            remove(db);
        }
        else if (command == "print") {
            print(db);
        }
        else if (command == "quit") {
            break;
        }
        else {
            cout << "Incorrect command. type 'menu' to get list of valid commands" << endl;
        }
    }
}