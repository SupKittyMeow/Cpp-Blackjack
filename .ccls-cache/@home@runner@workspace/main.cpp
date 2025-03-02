// TODO: Choose ace number amount, or just automate it based on if you go over
// with 11 or not

#include "BlackJackGame.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  BlackJackGame game = BlackJackGame();
  game.gameLoop();
  return 0;
}