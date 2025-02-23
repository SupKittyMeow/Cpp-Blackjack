#include "Deck.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

Deck::Deck() {
  cards = vector<Card>();
  createDeck();
}

void Deck::createDeck() {
  cards.clear();

  string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  string ranks[14] = {"1", "2", "3",  "4",    "5",     "6",    "7",
                      "8", "9", "10", "Jack", "Queen", "King", "Ace"};
  int values[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
  for (int suit = 0; suit < 4; suit++) {
    for (int rank = 0; rank < 14; rank++) {
      cards.push_back(Card(suits[suit], ranks[rank], values[rank]));
    }
  }
}

void Deck::shuffle() {
  srand(time(0));
  auto rng = std::default_random_engine{};
  std::shuffle(cards.begin(), cards.end(), rng);
}

Card Deck::dealCard() {
  // TODO: check if deck is empty
  Card cardToDeal = cards[cards.size() - 1];
  cards.pop_back();
  return cardToDeal;
}

void Deck::printAllCards() {
  for (Card card : cards) {
    cout << card.toString() << endl;
  }
  cout << endl;
}