#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

using namespace std;

class Deck {
private:
  vector<Card> cards;

public:
  Deck(vector<Card> cards);
  void shuffle();
  Card deal();
};

#endif