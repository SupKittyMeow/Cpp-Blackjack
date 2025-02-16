
#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

string Card::getSuit() { return this->suit; }
string Card::getRank() { return this->rank; }
int Card::getValue() { return this->value; }

Card::Card(string s, string r, int v) {
  suit = s;
  rank = r;
  value = v;
}
