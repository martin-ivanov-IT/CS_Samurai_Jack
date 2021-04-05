#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include "Player.h"
#include "Pistol.h"

typedef struct {
  Player players[PLAYERS_COUNT];
} BattleField;

void createPlayers(BattleField* bf);

void buyPistols(BattleField* bf);

void startBattle(BattleField* bf);

void printWinner(Player* player);

void swapPositions (Player *atacker, Player *enemy);

#endif /* BATTLEFIELD_H_ */
