#include "DesertEagle.h"

static bool DesertEagle_Fire(Pistol*const  me, PlayerVitalData*const playerVitalData);
static void hurtArmor(PlayerVitalData*const enemy, Pistol const*const glock);
static void hurtHealth (PlayerVitalData*const enemy, Pistol const*const glock);

void initDesertEagle(DesertEagle * const desertEagle, enum PistolType pistolType,
                 int damagePerRound, int clipSize, int inputAmmo){
    initPistol(desertEagle, pistolType, damagePerRound, clipSize, inputAmmo);
    desertEagle->fire = &DesertEagle_Fire;
}

static bool DesertEagle_Fire( DesertEagle*const desertEagle, PlayerVitalData*const enemy){
    hurtHealth(enemy, desertEagle);
    hurtArmor(enemy, desertEagle);
    desertEagle->currClipBullets--;
    enemy->printCondition(enemy);
    if(!enemy->isAlive(enemy)){
        return false;
    }
    return true;
}

static void hurtHealth (PlayerVitalData*const enemy, DesertEagle const*const desertEagle){
    if(enemy->hasArmor(enemy)){

        enemy->health -= desertEagle->damagePerRound*DESERTEAGLE_HEALTH_DAMAGE_RATE;
    }

    else{
        enemy->health -= desertEagle->damagePerRound;
    }
}

static void hurtArmor(PlayerVitalData*const enemy, DesertEagle const*const desertEagle){
    if(enemy->hasArmor(enemy)){
        enemy->armor -= desertEagle->damagePerRound*DESERTEAGLE_ARMOR_DAMAGE_RATE;
    }
}

