#include "DesertEagle.h"

static bool DesertEagle_Fire(Pistol* me, PlayerVitalData* playerVitalData);
static void hurtEnemy(PlayerVitalData* enemy, DesertEagle* desertEagle);

void initDesertEagle(DesertEagle* desertEagle, enum PistolType pistolType,
                 int damagePerRound, int clipSize, int inputAmmo){
    initPistol(desertEagle, pistolType, damagePerRound, clipSize, inputAmmo);
    desertEagle->fire = &DesertEagle_Fire;
}

static bool DesertEagle_Fire( DesertEagle* desertEagle, PlayerVitalData* enemy){
    
    if(desertEagle->isPistolEmpty(desertEagle)){
        desertEagle->reloadPistol(desertEagle);
        printf("\n");
        return false;
    }
    hurtEnemy(enemy, desertEagle);
    enemy->printCondition(enemy);
    if(!enemy->isAlive(enemy)){
        return true;
    }
    desertEagle->currClipBullets--;
    printf("\n");
    return false;
}

//produce damage to health and armor of enemy player
static void hurtEnemy(PlayerVitalData* enemy, DesertEagle* desertEagle){
    if(enemy->hasArmor(enemy)){
        enemy->armor -= desertEagle->damagePerRound*DESERTEAGLE_ARMOR_DAMAGE_RATE;  
        enemy->health -= desertEagle->damagePerRound*DESERTEAGLE_HEALTH_DAMAGE_RATE;
    }
    else{
        enemy->health -= desertEagle->damagePerRound;
    }
}


