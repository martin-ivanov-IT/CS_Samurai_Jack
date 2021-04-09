#include "DesertEagle.h"
static bool DesertEagle_Fire(Pistol*  me, PlayerVitalData* playerVitalData);
static void hurtArmor(PlayerVitalData* enemy, Pistol* glock);
static void hurtHealth (PlayerVitalData* enemy, Pistol* glock);

void initDesertEagle(DesertEagle* desertEagle, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo){
    initPistol(desertEagle, pistolType, damagePerRound, clipSize, inputAmmo);
    desertEagle->fire = &DesertEagle_Fire;
}

static bool DesertEagle_Fire( DesertEagle* desertEagle, PlayerVitalData* enemy){
    hurtHealth(enemy, desertEagle);
    hurtArmor(enemy, desertEagle);
    desertEagle->currClipBullets--;
    enemy->printCondition(enemy);
    if(!enemy->isAlive(enemy)){
        return false;
    }
    return true;
}

static void hurtHealth (PlayerVitalData* enemy, DesertEagle* desertEagle){
    if(enemy->hasArmor(enemy)){

        enemy->health -= desertEagle->damagePerRound*DESERTEAGLE_HEALTH_DAMAGE_RATE;
    }

    else{
        enemy->health -= desertEagle->damagePerRound;
    }
}

static void hurtArmor(PlayerVitalData* enemy, DesertEagle* desertEagle){
    if(enemy->hasArmor(enemy)){
        enemy->armor -= desertEagle->damagePerRound*DESERTEAGLE_ARMOR_DAMAGE_RATE;
    }
}

