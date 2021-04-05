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
    Pistol pistol;
    if(pistolId == GLOCK){
      initGlock(&pistol, pistolId,pistolDamagePerRound, pistolClipSize, pistolRemainingAmmo);
    }
    else if(pistolId == DESERT_EAGLE){
      initDesertEagle(&pistol, pistolId,pistolDamagePerRound, pistolClipSize, pistolRemainingAmmo);
    }
    initPistol(&pistol, pistolId, pistolDamagePerRound, pistolClipSize, pistolRemainingAmmo);
    Player* player = takePlayerById(bf->players, i);
    playerTakeGun(&player, &pistol);
    
  }
}

void startBattle(BattleField *bf) {
  if (bf) {} //silence ununsed variable warning. Remove me
  for (int i = 0; i < PLAYERS_COUNT; ++i) {
    Player* currPlayer = &bf->players[i];
    Player* enemyPlayer = &bf->players[abs(i-1)];
    if(isPistolEmpty(&currPlayer->pistol)){
      playerReloadGun(currPlayer);
    }
    else{
      currPlayer->pistol.fire(&currPlayer->pistol, enemyPlayer);
      printPlayerCondition(enemyPlayer);
      if(!isPlayerAlive(enemyPlayer)){
        printWinner(currPlayer);
      }
    }
  }
}

void printWinner(Player* player){
  printf("Player with ID: %d wins!",player->playerId);
}

