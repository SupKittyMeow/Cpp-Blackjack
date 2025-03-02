#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Deck.h"
#include "Player.h"

using namespace std;

class BlackJackGame {
private:
  Deck deck;
  Player player;
  Player dealer;

public:
  BlackJackGame();
  void gameLoop();
  void dealInitialCards();
  void playerTurn();
  void dealerTurn();
  void determineWinner();
  bool askToPlayAgain();
};
#endif