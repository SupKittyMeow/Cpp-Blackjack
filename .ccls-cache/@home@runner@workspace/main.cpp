#include "Card.h"
#include "Deck.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
  Deck deck = Deck();
  deck.shuffle();
  cout << deck.dealCard().toString();
}