#include "BattleField.h"
#include "DesertEagle.h"
#include "Glock.h"

#include <stdio.h>
#include <stdlib.h>
#include "Pistol.h"
#include "Player.h"

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
    bf->players[i].takeGun(&bf->players[i], &pistol);
    
  }
}

void startBattle(BattleField *bf) {
  if (bf) {} //silence ununsed variable warning. Remove me
  Player* atacker = &bf->players[0];
  Player* enemy = &bf->players[1];
  while(true){
    printf("PlayerID %d turn:\n",atacker->playerId);
    if(atacker->pistol.isPistolEmpty(&atacker->pistol)){
      atacker->pistol.reloadPistol(&atacker->pistol);
    }
    else{
      if(!atacker->pistol.fire(&atacker->pistol, &enemy->playerData)){
          printWinner(atacker);
          break;
      }
    }
    printf("\n");
    swapPositions(atacker, enemy);
  }
}
void swapPositions (Player *atacker, Player *enemy){
    Player temp = *atacker;
    *atacker = *enemy;
    *enemy = temp;
}

void printWinner(Player* player){
  printf("Player with ID: %d wins!\n",player->playerId);
}


