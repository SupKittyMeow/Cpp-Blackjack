#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Player.h"
#include "Deck.h"

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
    bool determineWinner();
    bool askToPlayAgain();
};
#endif