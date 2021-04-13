#include "BattleField.h"

static void swapPositions (Player *atacker, Player *enemy);
static void printTurn(int playerId);
static void printWinner(Player* player);

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
  }
}

void startBattle(BattleField *bf) {
  Player* atacker = &bf->players[0];
  Player* enemy = &bf->players[1];
  
  printTurn(atacker->playerId);
  while(!(atacker->pistol.fire(&atacker->pistol, &enemy->playerData))){
    swapPositions(atacker, enemy);
    printTurn(atacker->playerId);
  }
  printWinner(atacker);
}

// swaps positions of atacker and enemy
static void swapPositions (Player *atacker, Player *enemy){
    Player temp = *atacker;
    *atacker = *enemy;
    *enemy = temp;
}

static void printTurn(int playerId){
  printf("PlayerID %d turn:\n",playerId);
}

static void printWinner(Player* player){
  printf("Player with ID: %d wins!\n",player->playerId);
}




