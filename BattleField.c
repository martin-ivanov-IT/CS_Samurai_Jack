#include "BattleField.h"
#include "DesertEagle.h"
#include "Glock.h"

#include <stdio.h>
#include <stdlib.h>
#include <Pistol.h>

void createPlayers(BattleField *bf) {
  if (bf) {} //silence ununsed variable warning. Remove me

  int playerHealth = 0;
  int playerArmor = 0;

  for (int i = 0; i < PLAYERS_COUNT; ++i) {
    scanf("%d %d", &playerHealth, &playerArmor);
    Player player;
    initPlayer(&player, playerHealth, playerArmor, i);
    bf->players[i] = player;
  }
}

void buyPistols(BattleField *bf) {
  //if (bf) {} //silence ununsed variable warning. Remove me

  int pistolId = 0;
  int pistolDamagePerRound = 0;
  int pistolClipSize = 0;
  int pistolRemainingAmmo = 0;

  for (int i = 0; i < PLAYERS_COUNT; ++i) {
    scanf("%d %d %d %d", &pistolId, &pistolDamagePerRound, &pistolClipSize,
        &pistolRemainingAmmo);
    if(pistolId == GLOCK){
      
    }
    else if(pistolId == DESERT_EAGLE){

    }
    initPistol(&pistol, pistolId, pistolDamagePerRound, pistolClipSize, pistolRemainingAmmo);
    Player* player = takePlayerById(bf->players, i);
    playerTakeGun(player, pistol);
    
  }
}

void startBattle(BattleField *bf) {
  if (bf) {} //silence ununsed variable warning. Remove me
}

