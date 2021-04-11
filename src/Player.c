#include "Defines.h"
#include "Player.h"
#include <stdlib.h>
#include <stdio.h>

static void playerTakeGun(Player* player, Pistol* pistol);
static void printPlayerCondition(PlayerVitalData* player);
static bool hasPlayerArmor(PlayerVitalData* player);
static bool isPlayerAlive(PlayerVitalData* player);

static void  initPlayerVitalData(PlayerVitalData* playerData, int health, int armor){
    playerData->health = health;
    playerData->armor = armor;
    playerData->isAlive = &isPlayerAlive;
    playerData->printCondition = &printPlayerCondition;
    playerData->hasArmor = &hasPlayerArmor;
}

void initPlayer(Player* player, int health, int armor, int playerId){
    initPlayerVitalData(&player->playerData, health, armor);
    player->playerId = playerId;
    player->takeGun = &playerTakeGun;
}

static void playerTakeGun(Player* player, Pistol* pistol){
    player->pistol = *pistol;
}

static void printPlayerCondition(PlayerVitalData* player){
    printf("Enemy left with: %d health and %d armor \n",player->health, player->armor);
}

static bool hasPlayerArmor(PlayerVitalData* player){
    return player->armor > 0;
}

static bool isPlayerAlive(PlayerVitalData* player){
    return player->health > 0;
}