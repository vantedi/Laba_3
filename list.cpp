#include <iostream>
#include <fstream>
#include "meds.h"
#include "list.h"

using namespace std;

Item::Item(Meds* med):med(med) {
  next = NULL;
}

Item::Item(Meds* med, Item* next):med(med),next(next) {}

Item::~Item() {
  delete(med);
  next = NULL;
}
void Item::setMeds(Meds* m) {
  med = m;
}
Meds* Item::getMeds() const {
  return med;
}
void Item::setNext(Item* n) {
  next=n;
}
Item* Item::getNext() const {
  return next;
}

bool Item::operator==(Item const &item) {
  return (*med == *item.getMeds());
}

List::List() {
  head = NULL;
}

List::List(Item* item) {
  head = item;
}
List::~List() {
  if (is_empty()) {
    return;
  }
  Item* current = head;
  Item* next;
  while (current) {
    next = current->getNext();
    delete(current);
    current=next;
  }
}

bool List::is_empty() const {
  return head == NULL ? true : false;
}

Item* List::last() {
   Item* current = head;
   if ( is_empty() ) {
     return head;
   }
   else {
     while (current->getNext()) {
       current = current->getNext();
     }
     return current;
   }
}

void List::add(Item* item) {
  if ( is_empty() ) {
    head = item;
  }
  else {
    Item* last_item = last();
    last_item->setNext(item);
  }
}

void List::add(Meds* med) {
    Item* new_item = new Item(med);
    if ( is_empty() ) {
	head = new_item;
    }
    else {
	Meds* m = NULL;
	
	search(med->getName(), &m);
	if (!m) {
	    Item* last_item = last();
	    last_item->setNext(new_item);
	}
	else {
	    cout << med->getName() << " already in list" << endl;
	}
    }
}

void List::search(string name, Meds **med) {
    if (is_empty()) {
	return;
    }
    else {
	bool not_found = true;
	*med = new Meds(name, "", 0);
	Item* current = head;
	while (current && not_found ) {
	    if (current->getMeds()->getName() == name) {
		(*med)->setName(current->getMeds()->getName());
		(*med)->setPurpose(current->getMeds()->getPurpose());
		(*med)->setPrice(current->getMeds()->getPrice());
		not_found = false;
	    }
	    current = current->getNext();
	}
	if (not_found) {
	    delete(*med);
	    *med = NULL;
	}
    }
 }
void List::search(string purpose, List **results) {
    if (is_empty()) {
	return;
    }
    else {
	*results = new List();
	Item* current = head;
	while (current) {
	    if (current->getMeds()->getPurpose() == purpose) {
		Item* item = new Item(current->getMeds());
		(*results)->add(item);
	    }
	    current = current->getNext();
	}
    }
}

void List::search(int price, List **results) {
    if (is_empty()) {
	return;
    }
    else {
	*results = new List();
	Item* current = head;
	while (current) {
	    if (current->getMeds()->getPrice() == price) {
		Item* item = new Item(current->getMeds());
		(*results)->add(item);
	    }
	    current = current->getNext();
	}
    }
}
void List::print() {
  if (is_empty()) {
    cout << "Nothing to print. List is Empty" << endl;
    return;
  }
  Item  *current = head;
  while (current) {
      Meds *meds = current->getMeds();
      cout << *meds << endl;
      
      current = current->getNext();
  }
  return;
}

void List::remove(string name) {
    if ( is_empty() ) {
	return;
    }
    Item* current = head;
    Item* tmp;
    bool not_removed = true;
    if (head->getMeds()->getName() == name) {
	tmp = head->getNext();
	delete(head->getMeds());
	head = tmp;
	return;
    }
    
    while (current && not_removed) {
	Item* tmp = current->getNext()->getNext();
	if (current->getNext()->getMeds()->getName() == name) {
	    delete(current->getNext());
	    current->setNext(tmp);
	    not_removed = false;
	}
	current = current->getNext();
    }
    return;
}

int List::size() const {
    int list_size = 0;
    if (!is_empty()) {
	Item *current = head;
	while (current) {
	    list_size++;
	    current=current->getNext();
	}
    }
    return list_size;
}

ostream& operator<<(ostream& out, List const &list) {
    Item *current = list.head;
    while (current) {
	out << *current->getMeds() << endl;
	current = current->getNext();
    }
    return out;
}

ofstream& operator<<(ofstream& ofile, List const &list) {
    int list_size = list.size();
    Item *current = list.head;
    ofile.write(reinterpret_cast<const char*>(&list_size), sizeof(list_size));
    while (current) {
	ofile << *current->getMeds();
	current = current->getNext();
    }
    return ofile;
}
    
ifstream& operator>>(ifstream& ifile, List &list) {
    int list_size;
    ifile.read(reinterpret_cast<char*>(&list_size), sizeof(list_size));
    for (int i=0; i < list_size; i++) {
	Meds* med = new Meds();
	ifile >> *med;
	Item* item = new Item(med);
	item->setNext(NULL);
	list.add(item);
    }
 
    return ifile;
}
