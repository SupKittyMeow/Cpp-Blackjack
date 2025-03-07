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
  cout << "\nDealer's first hand: ";
  dealer.printDealerHand();
  playerTurn();
  if (player.getHandValue() <= 21) {
    dealerTurn();
  }

  determineWinner();
  if (askToPlayAgain() == true) {
    gameLoop();
  } else {
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
  int handValue = player.getHandValue();
  if (handValue > 21) {
    cout << "\nYou're over with a value of " << handValue << "!" << endl;
    return;
  }

  cout << "Your hand: ";
  player.printHand();
  cout << "With a value of " << handValue << endl << endl;

  cout << "Would you like to hit or stand?" << endl;
  cout << "(Write hit or h to hit, and stand or s to stand)" << endl;

  string value;
  cin >> value;

  std::transform(value.begin(), value.end(), value.begin(),
                 [](unsigned char c) { return std::toupper(c); });

  if (value == "HIT" || value == "H") {
    Card newCard = deck.dealCard();
    player.addCard(newCard);
    cout << "\nYou drew a " << newCard.toString() << endl;
    playerTurn();
    return;
  } else if (value == "STAND" || value == "S") {
    return;
  } else {
    cout << "\nPlease write hit or h to hit, and stand or s to stand." << endl
         << endl;
    playerTurn();
    return;
  }
}

void BlackJackGame::dealerTurn() {
  cout << "\nDealer's hand: ";
  dealer.printHand();
  cout << "With a value of " << dealer.getHandValue() << endl;

  while (dealer.getHandValue() < 17) {
    dealer.addCard(deck.dealCard());
    cout << "Dealer drew! New hand: ";
    dealer.printHand();
    cout << "With a value of " << dealer.getHandValue() << endl;
  }
}

void BlackJackGame::determineWinner() {
  cout << "\n-----\n\nGame ended! Here's the results:" << endl;
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
  cout << "\n-----\n\nWould you like to play again?" << endl;
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