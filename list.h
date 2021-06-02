#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include <fstream>
#include "meds.h"

using namespace std;

class Item {
  Meds *med;
  Item *next;
 public:
  Item();
  Item(Meds*);
  Item(Meds*, Item*);
  Item(Item*);
  ~Item();

  void setMeds(Meds*);
  Meds* getMeds() const ;
  void setNext(Item*);
  Item* getNext() const;
  size_t getSize();
  bool operator==(const Item&);
};

class List {
 private:
  Item* head;
  Item* last();

 public:
  List();
  List(Item*);
  ~List();
  void add(Item*);
  void add(Meds*);
  void search(string name, Meds **med);
  void search(string purpose, List **list);
  void search(int price, List **list);
  void remove(string name);
  int size() const;
  bool is_empty() const;
  void print();

  friend ostream& operator<<(ostream &out, List const &list);
  friend ofstream& operator<<(ofstream &ofile, List const &list);
  friend ifstream& operator>>(ifstream &ifile, List &list);
};


#endif
