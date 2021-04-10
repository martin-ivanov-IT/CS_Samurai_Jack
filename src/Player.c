#include "Defines.h"
#include "Player.h"
#include <stdlib.h>
#include <stdio.h>

static void playerTakeGun(Player* player, Pistol const*const pistol);
static void printPlayerCondition(PlayerVitalData* player);
static bool hasPlayerArmor(PlayerVitalData* player);
static bool isPlayerAlive(PlayerVitalData* player);

static void  initPlayerVitalData(PlayerVitalData* const playerData, int health, int armor){
    playerData->health = health;
    playerData->armor = armor;
    playerData->isAlive = &isPlayerAlive;
    playerData->printCondition = &printPlayerCondition;
    playerData->hasArmor = &hasPlayerArmor;
}

void initPlayer(Player* const player, int health, int armor, int playerId){
    initPlayerVitalData(&player->playerData, health, armor);
    player->playerId = playerId;
    player->takeGun = &playerTakeGun;
}

static void playerTakeGun(Player* player, Pistol const*const pistol){
    player->pistol = *pistol;
}

static void printPlayerCondition(PlayerVitalData* player){
    printf("Enemy left with: %d health and %d armor \n",player->health, player->armor);
}

static bool hasPlayerArmor(PlayerVitalData* player){
    if(player->armor > 0){
        return true;
    }
    else{
        return false;
    }
}

static bool isPlayerAlive(PlayerVitalData* player){
    if(player->health > 0){
        return true;
    }
    return false;
}