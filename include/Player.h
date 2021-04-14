#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdbool.h>
#include "Defines.h"
#include"Pistol.h"
#include <stdio.h>


typedef struct Player {
  PlayerVitalData playerData;
  Pistol pistol;
  int playerId;
  void (* takeGun)(struct Player* player, Pistol* pistol);
} Player;

void initPlayer(Player* player, int health, int armor, int playerId);


#endif /* PLAYER_H_ */
