#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {
private:
  string suit;
  string rank;
  int value;

public:
  Card(string s, string r, int v);
  string getSuit();
  string getRank();
  int getValue();
};

#endif