#include "Glock.h"
void initGlock(Glock* glock, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo){
    initPistol(glock,pistolType, damagePerRound,clipSize, inputAmmo);
    glock->fire = fire;
}
static bool fire(Player* enemy, Glock* glock){
    hurtHealth(enemy, glock);
    hurtArmor(enemy, glock);
    printPlayerCondition(enemy);
    if(enemy->playerData.health <= 0){
        return false;
    }
}

static void hurtArmor(Player* enemy, Glock* glock){
    if(hasPlayerArmor(enemy)){
        enemy->playerData.armor -= glock->damagePerRound/2;
    }
}

static void hurtHealth (Player* enemy, Glock* glock){
    if(hasPlayerArmor(enemy)){
        enemy->playerData.health -= glock->damagePerRound/2;
    }

    else{
        enemy->playerData.health -= glock->damagePerRound;
    }
}