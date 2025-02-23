
#include "Deck.h"
#include <iostream>
#include <vector>

using namespace std;

Deck::Deck(vector<Card> c) { cards = c; }

void Deck::shuffle() {
  // Implementation needed
}

Card Deck::dealCard() {
  // Implementation needed
  return cards[0]; // Temporary return statement
}
