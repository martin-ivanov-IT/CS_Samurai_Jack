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
    initPistol(&pistol, pistolId,pistolDamagePerRound, pistolClipSize, pistolRemainingAmmo);
    //Player* player = &bf->players[i];
    bf->players[i].pistol = pistol;
    //playerTakeGun(player, &pistol);
  }
}

void startBattle(BattleField *bf) {
  if (bf) {} //silence ununsed variable warning. Remove me
  Player* atacker = &bf->players[0];
  Player* enemy = &bf->players[1];
  while(true){
    printf("PlayerID %d turn:\n",atacker->playerId);
    if(isPistolEmpty(&atacker->pistol)){
      reloadPistol(&atacker->pistol);
    }
    else{
      atackEnemy(atacker, enemy);
      if(atacker->pistol.pistolType == GLOCK){
        if(!fireGlock(enemy, &atacker->pistol)){
          printWinner(atacker);
          break;
        }
      }
      else if(atacker->pistol.pistolType == DESERT_EAGLE){
        if(!fireDesertEagle(enemy, &atacker->pistol)){
          printWinner(atacker);
          break;
        }
      }
      //printf("current gun ammo %d\n",atacker->pistol.currClipBullets);
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


