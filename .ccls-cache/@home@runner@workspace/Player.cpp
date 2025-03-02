#include "Player.h"
#include "Deck.h"
#include <iostream>

Player::Player() { heldCards = vector<Card>(); };

int Player::getHandValue() {
  int value = 0;
  for (Card card : heldCards) {
    value += card.getValue();
  }
  return value;
}

bool Player::isBusted() {
  if (getHandValue() > 21) {
    return true;
  } else {
    return false;
  }
}

void Player::addCard(const Card &card) { heldCards.push_back(card); };

void Player::printHand() {
  string printText;
  for (Card card : heldCards) {
    printText += card.toString() += ", ";
  }

  printText.pop_back();
  printText.pop_back();
  printText.append(".");

  cout << printText << endl;
};

void Player::printDealerHand() {
  string printText;
  cout << heldCards[0].toString() << endl;
};

void Player::resetHand() { heldCards.clear(); };