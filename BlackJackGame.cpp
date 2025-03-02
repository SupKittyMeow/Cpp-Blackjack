#include "BlackJackGame.h"
#include "Deck.h"
#include <algorithm>
#include <cctype>
#include <iostream>

BlackJackGame::BlackJackGame() {
  Deck deck;
  Player player;
  Player dealer;
};

void BlackJackGame::gameLoop() {
  dealInitialCards();
  cout << endl << "Your turn! ";
  playerTurn();
  if (player.getHandValue() <= 21)
  {
    dealerTurn();
  }
  
  determineWinner();
  if (askToPlayAgain() == true) {
    gameLoop();
  }
  else {
    return;
  }
}

void BlackJackGame::dealInitialCards() {
  deck.createDeck();
  deck.shuffle();

  player.resetHand();
  dealer.resetHand();

  player.addCard(deck.dealCard());
  dealer.addCard(deck.dealCard());
  player.addCard(deck.dealCard());
  dealer.addCard(deck.dealCard());
}

void BlackJackGame::playerTurn() {
  if (player.getHandValue() > 21)
  {
    return;
  }
  
  cout << "Your hand: ";
  player.printHand();
  cout << "With value: " << player.getHandValue();

  cout << endl << "Would you like to hit or stand" << endl;
  cout << "Write hit or h to hit, and stand or s to stand." << endl;
  
  string value;
  cin >> value;

  std::transform(value.begin(), value.end(), value.begin(),
                 [](unsigned char c) { return std::toupper(c); });

  if (value == "HIT" || value == "H") {
    player.addCard(deck.dealCard());
    playerTurn();
    return;
  } else if (value == "STAND" || value == "S") {
    return;
  } else {
    cout << "Please Write hit or h to hit, and stand or s to stand." << endl
         << endl;
    playerTurn();
    return;
  }
}

void BlackJackGame::dealerTurn() {
  cout << "Dealer's hand: ";
  dealer.printHand(); // TODO: print dealer first
                      // hand only or whatever
  cout << "With value: " << dealer.getHandValue() << endl;

  while (dealer.getHandValue() < 17) {
    dealer.addCard(deck.dealCard());
    cout << "Dealer drew! New hand: ";
    cout << "With value: " << dealer.getHandValue() << endl;
  }
}

void BlackJackGame::determineWinner() {
  cout << "Game ended! Here's the results:" << endl;
  cout << "Player hand: " << player.getHandValue() << endl;
  cout << "Dealer hand: " << dealer.getHandValue() << endl;

  if (player.isBusted()) {
    if (dealer.isBusted()) {
      cout << "Both you and the dealer are busted! Tie.";
    } else {
      cout << "You are busted! Dealer wins.";
    }
  } else if (dealer.isBusted()) {
    cout << "The Dealer is busted! You win.";
  } else if (player.getHandValue() > dealer.getHandValue()) {
    cout << "You have a greater value than the dealer! You win.";
  } else if (dealer.getHandValue() > player.getHandValue()) {
    cout << "The dealer has a greater value than you! The dealer wins.";
  } else {
    cout << "You have the same value as the dealer! Tie.";
  }

  cout << endl;
}

bool BlackJackGame::askToPlayAgain() {
  cout << "Would you like to play again?" << endl;
  cout << "Y or yes to play again, N or no to not." << endl;
  string value;
  cin >> value;

  std::transform(value.begin(), value.end(), value.begin(),
                 [](unsigned char c) { return std::toupper(c); });
  if (value == "Y" || value == "YES") {
    return true;
  } else if (value == "N" || value == "NO") {
    return false;
  } else {
    return askToPlayAgain();
  }
}