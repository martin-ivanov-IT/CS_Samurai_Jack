#include "Glock.h"

static bool Glock_fire(Pistol*const  me, PlayerVitalData*const playerVitalData);
static void hurtArmor(PlayerVitalData*const enemy, Pistol const*const glock);
static void hurtHealth (PlayerVitalData*const enemy, Pistol const*const glock);

void initGlock(Glock* const glock, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo){
    initPistol(glock,pistolType, damagePerRound,clipSize, inputAmmo);
    glock->fire = &Glock_fire;
}

static bool Glock_fire(Pistol*const glock, PlayerVitalData*const enemy){
    for (int i = 0; i < ROUNDS_PER_FIRE; i++)
    {
        if(glock->currClipBullets==0){
            glock->reloadPistol(glock);
            break;
            
        }

        hurtHealth(enemy, glock);
        hurtArmor(enemy, glock);
        glock->currClipBullets--;
        
        enemy->printCondition(enemy);

        if(!enemy->isAlive(enemy)){
            return false;
        }

    }     
    return true;
}

static void hurtArmor(PlayerVitalData*const enemy, Pistol const*const glock){
    if(enemy->hasArmor(enemy)){
        enemy->armor -= glock->damagePerRound * GLOCK_ARMOR_DAMAGE_RATE;
        if(enemy->armor < 0){
            enemy->health += enemy->armor;
            enemy->armor = 0;
        }
    }
}

static void hurtHealth (PlayerVitalData*const enemy, Pistol const*const glock){
    if(enemy->hasArmor(enemy)){
        enemy->health -= glock->damagePerRound * GLOCK_HEALTH_DAMAGE_RATE;
    }

    else{
        enemy->health -= glock->damagePerRound;
    }
}
