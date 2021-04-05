#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdbool.h>

#include "Pistol.h"
#include "Defines.h"

typedef struct {
  PlayerVitalData playerData;
  Pistol pistol;
  int playerId;
} Player;

void initPlayer(Player* player, int health, int armor, int playerId);
void playerTakeGun(Player* player, Pistol* pistol);
Player* takePlayerById(Player* players, int playerId);
void printPlayerCondition(Player* player);
bool hasPlayerArmor(Player* player);

#endif /* PLAYER_H_ */
