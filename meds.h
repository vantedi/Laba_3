#ifndef _MEDS_H
#define _MEDS_H

#include <iostream>
#include <fstream>

using namespace std;

typedef string Name;
typedef string Purpose;
typedef int Price;
class Meds {
  string name;
  string  purpose;
  int price;
 public:
  Meds();
  Meds(string name, string purpose, int price);
  Name getName();
  void setName(string);
  Purpose getPurpose();
  void setPurpose(string);
  Price getPrice();
  void setPrice(int);

  bool operator == (Meds& meds);

  friend ostream& operator<<(ostream& out, Meds const& med);
  friend ofstream& operator<<(ofstream& ofile, Meds const &med);
  friend ifstream& operator>>(ifstream& ifile, Meds &med);
};

#endif
