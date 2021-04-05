#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include "Player.h"

typedef struct {
  Player players[PLAYERS_COUNT];
} BattleField;

void createPlayers(BattleField* bf);

void buyPistols(BattleField* bf);

void startBattle(BattleField* bf);

#endif /* BATTLEFIELD_H_ */
