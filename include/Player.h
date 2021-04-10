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
  void (* takeGun)(struct Player*const player, Pistol const*const pistol);
} Player;

struct PlayerVtable{
  void (* takeGun)(Player* player, Pistol* pistol);
};

void initPlayer(Player* const player, int health, int armor, int playerId);


#endif /* PLAYER_H_ */
