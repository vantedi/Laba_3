#include <iostream>
#include <fstream>
#include "meds.h"
#include "list.h"
#include "database.h"

using namespace std;

DataBase::DataBase(string filename):filename(filename) {
    try {
	ifstream ifile(filename, ios::binary);
	db = new List();
	ifile >> *db;
    } catch (const ifstream::failure &e) {
	cout << "Error: " << e.what() << endl;
	delete(db);
	exit(1);
    }
}

DataBase::~DataBase() {
    try {
	ofstream wfile(filename, ios::binary | ios::trunc);
	wfile << *db;
	delete(db);
    } catch (const ofstream::failure &e) {
	cout << "Error: " << e.what()  << endl;
	exit(1);
    }
}

void DataBase::add(string name, string purpose, int price) {
    Meds* med = new Meds(name, purpose, price);
    db->add(med);
}

void DataBase::remove(string name) {
    db->remove(name);
}

void DataBase::search(string name, Meds** result) {
     db->search(name, result);
}
void DataBase::search(string purpose, List** results) {
     db->search(purpose, results);
}
void DataBase::search(int price, List** results) {
    db->search(price, results);
}

void DataBase::print() {
    cout << *db << endl;
}
