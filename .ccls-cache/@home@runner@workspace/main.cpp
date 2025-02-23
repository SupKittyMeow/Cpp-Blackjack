#include "Card.cpp"
#include "Card.h"
#include "Deck.cpp"
#include "Deck.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
  Deck deck = Deck();
  deck.printAllCards();
}