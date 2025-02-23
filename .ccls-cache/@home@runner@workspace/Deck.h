#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

using namespace std;

class Deck {
private:
  vector<Card> cards;

public:
  Deck();
  void createDeck();
  void shuffle();
  void printAllCards();
  Card dealCard();
};

#endif