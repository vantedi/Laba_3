#include <iostream>
#include <string>
#include "meds.h"

using namespace std;

Meds::Meds() {
}
Meds::Meds(string name,string purpose, int price):name(name),purpose(purpose),price(price)
{};

string Meds::getName() {
  return name;
}

void Meds::setName(string n) {
  name = n;
}

string Meds::getPurpose() {
  return purpose;
}

void Meds::setPurpose(string p) {
  purpose = p;
}

int Meds::getPrice() {
  return price;
}
void Meds::setPrice(int p) {
  price = p;
}

bool Meds::operator == (Meds& meds) {
    return (name == meds.getName() &&
	    purpose == meds.getPurpose() &&
	    price == meds.getPrice());

    
}

ostream& operator<<(ostream& out, Meds const& med) {
    out << "Meds("
	<< med.name << ", "
	<< med.purpose << ", "
	<< med.price
	<< ")";
    return out;
}

ofstream& operator<<(ofstream &ofile, Meds const &med) {
    auto name_size = static_cast<int>(med.name.size());
    ofile.write(reinterpret_cast<char*>(&name_size), sizeof(name_size));
    ofile.write(med.name.data(), med.name.size());
    auto purpose_size = static_cast<int>(med.purpose.size());
    ofile.write(reinterpret_cast<char*>(&purpose_size), sizeof(purpose_size));
    ofile.write(med.purpose.data(), med.purpose.size());

    ofile.write(reinterpret_cast<const char*>(&med.price), sizeof(med.price));

    return ofile;
}

ifstream& operator>>(ifstream &ifile, Meds &med) {
    int name_size, purpose_size;
    ifile.read(reinterpret_cast<char*>(&name_size), sizeof(name_size));
    med.name.resize(name_size);
    ifile.read(reinterpret_cast<char*>(&med.name.front()), name_size);
    
    ifile.read(reinterpret_cast<char*>(&purpose_size), sizeof(purpose_size));
    med.purpose.resize(purpose_size);
    ifile.read(reinterpret_cast<char*>(&med.purpose.front()), purpose_size);
    
    ifile.read(reinterpret_cast<char*>(&med.price), sizeof(med.price));
    return ifile;
}
