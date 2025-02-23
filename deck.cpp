#include "Deck.h"
#include <iostream>
#include <vector>

using namespace std;

vector<Card> cards;

Deck(vector<Card> c) {
  cards = c;
};

void shuffle();
Card dealCard();