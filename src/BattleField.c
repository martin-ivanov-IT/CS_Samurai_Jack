#include "BattleField.h"

void createPlayers(BattleField *bf) {
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
    bf->players[i].pistol = pistol;
  }
}

void startBattle(BattleField *bf) {
  Player* atacker = &bf->players[0];
  Player* enemy = &bf->players[1];
  
  //while loop while both players are still alive
  while(atacker->playerData.isAlive && atacker->playerData.isAlive){
    printf("PlayerID %d turn:\n",atacker->playerId);

    //rerurns true if enemy palyer is killed by atacker pistol fire atack 
    if(atacker->pistol.fire(&atacker->pistol, &enemy->playerData)){
          printWinner(atacker);
          break;
    }
    swapPositions(atacker, enemy);
  }
}

// swaps positions of atacker and enemy
void swapPositions (Player *atacker, Player *enemy){
    Player temp = *atacker;
    *atacker = *enemy;
    *enemy = temp;
}

void printWinner(Player* player){
  printf("Player with ID: %d wins!\n",player->playerId);
}


