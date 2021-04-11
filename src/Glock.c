#include "Glock.h"

static bool Glock_fire(Pistol*const  me, PlayerVitalData*const playerVitalData);
static void hurtEnemy(PlayerVitalData*const enemy, Glock const*const glock);

void initGlock(Glock* const glock, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo){
    initPistol(glock,pistolType, damagePerRound,clipSize, inputAmmo);
    glock->fire = &Glock_fire;
}

static bool Glock_fire(Pistol*const glock, PlayerVitalData*const enemy){
    for (int i = 0; i < ROUNDS_PER_FIRE; i++){
        if(glock->isPistolEmpty(glock)){
            glock->reloadPistol(glock);
            printf("\n");
            return false;
        }
        hurtEnemy(enemy, glock);
        enemy->printCondition(enemy);
        if(!enemy->isAlive(enemy)){
            return true;
        }
        glock->currClipBullets--; 
    }     
    printf("\n");
    return false;
}

//produce damage to health and armor of enemy player
static void hurtEnemy(PlayerVitalData*const enemy, Glock const*const glock){
    if(enemy->hasArmor(enemy)){
         enemy->health -= glock->damagePerRound * GLOCK_HEALTH_DAMAGE_RATE;
         enemy->armor -= glock->damagePerRound * GLOCK_ARMOR_DAMAGE_RATE;
        if(enemy->armor < 0){
            enemy->health += enemy->armor;
            enemy->armor = 0;
        }
    }
    else{
        enemy->health -= glock->damagePerRound;
    }
}

