#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>

using namespace std;

class Player {
private:
  vector<Card> heldCards;

public:
  Player();
  int getHandValue();
  bool isBusted();
  void addCard(const Card &card);
  void printHand();
  void printDealerHand();
  void resetHand();
};

#endif