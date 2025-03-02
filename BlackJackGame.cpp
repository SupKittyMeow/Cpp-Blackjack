#include "BlackJackGame.h"
#include "Deck.h"
#include <iostream>

BlackJackGame::BlackJackGame() {
  Deck deck;
  Player player;
  Player dealer;
};

void BlackJackGame::gameLoop() {
  dealInitialCards();
  dealerTurn();
  playerTurn();
  determineWinner();
}

void BlackJackGame::dealInitialCards() {
  Deck::createDeck();
  
}

void BlackJackGame::playerTurn() {}

void BlackJackGame::dealerTurn() {}

bool BlackJackGame::determineWinner() {}

bool BlackJackGame::askToPlayAgain() {}