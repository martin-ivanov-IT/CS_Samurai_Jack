#include "Defines.h"
#include "Player.h"
#include <stdlib.h>
#include <stdio.h>

static initPlayerVitalData(PlayerVitalData* playerData, int health, int armor){
    playerData->health = health;
    playerData->armor = armor;
}

void initPlayer(Player* player, int health, int armor, int playerId){
    initPlayerVitalData(&player->playerData, health, armor);
    player->playerId = playerId;
}

Player* takePlayerById(Player* players, int playerId){
    for (int i = 0; i < PLAYERS_COUNT; i++)
    {
        if(players[i].playerId == playerId){
            return &players[i];
        }
    }
    return NULL;
}

void printPlayerCondition(Player* player){
    printf("Enemy left with: %d health and %d armor",player->playerData.health, player->playerData.armor);
}

bool hasPlayerArmor(Player* player){
    if(player->playerData.armor > 0){
        return true;
    }
    else{
        return false;
    }
}

bool hasPlayerAmmo(Player* player){
    if(player->pistol.remainingAmmo<=0){
        return false;
    }
    return true;
}

void playerReloadGun(Player* player){
    if(player->pistol.remainingAmmo <=0 ){
        printf("No ammo left\n");
        return;
    }
    int reloadValue = player->pistol.clipSize - player->pistol.remainingAmmo;
    if(player->pistol.remainingAmmo > reloadValue){
        player->pistol.currClipBullets = player->pistol.clipSize;
    }
    else{
        player->pistol.currClipBullets += player->pistol.remainingAmmo;
    }
    peinf("reloading...");
}

bool isPlayerAlive(Player* player){
    if(player->playerData.health > 0){
        return true;
    }
    return false;
}