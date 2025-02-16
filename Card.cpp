#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

string suit;
string rank;
int value;

Card(string s, string r, int v) {
  suit = s;
  rank = r;
  value = v;
};

string getSuit() { return suit; }
string getRank() { return rank; }
int getValue() { return value; }

