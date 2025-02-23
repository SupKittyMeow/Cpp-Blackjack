#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card(string s, string r, int v) {
  suit = s;
  rank = r;
  value = v;
}

string Card::getSuit() { return suit; }
string Card::getRank() { return rank; }
int Card::getValue() { return value; }

