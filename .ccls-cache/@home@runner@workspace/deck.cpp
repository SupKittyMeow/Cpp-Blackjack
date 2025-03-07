
#include "Deck.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Deck::Deck(vector<Card> c) { cards = c; }

void Deck::createDeck() {
  cards.clear();

  string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  string ranks[14] = {"1", "2", "3",  "4",    "5",     "6",    "7",
                      "8", "9", "10", "Jack", "Queen", "King", "Ace"};
  int values[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
  for (int suit = 0; suit <= suits->length() - 1; suit++) {
    for (int rank = 0; rank <= ranks->length() - 1; rank++) {
      cards.push_back(Card(suits[suit], ranks[rank], values[rank]));
    }
  }
}

void Deck::shuffle() {
  // Implementation needed
}

Card Deck::dealCard() {
  // Implementation needed
  return cards[0]; // Temporary return statement
}
