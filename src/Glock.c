#include "Glock.h"

void initGlock(Glock* glock, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo){
    initPistol(glock,pistolType, damagePerRound,clipSize, inputAmmo);
}
static void hurtArmor(Player* enemy, Glock* glock){
    if(hasPlayerArmor(enemy)){
        enemy->playerData.armor -= glock->damagePerRound * GLOCK_ARMOR_DAMAGE_RATE;
        if(enemy->playerData.armor < 0){
            enemy->playerData.health += enemy->playerData.armor;
            enemy->playerData.armor = 0;
        }
    }
}

static void hurtHealth (Player* enemy, Glock* glock){
    if(hasPlayerArmor(enemy)){
        enemy->playerData.health -= glock->damagePerRound * GLOCK_HEALTH_DAMAGE_RATE;
    }

    else{
        enemy->playerData.health -= glock->damagePerRound;
    }
}
bool fireGlock(Player* enemy, Glock* glock){
    for (int i = 0; i < ROUNDS_PER_FIRE; i++)
    {
        if(glock->currClipBullets==0){
            reloadPistol(glock);
            break;
        }

        hurtHealth(enemy, glock);
        hurtArmor(enemy, glock);
        glock->currClipBullets--;
        printPlayerCondition(enemy);

        if(!isPlayerAlive(enemy)){
            return false;
        }

    }     
    return true;
}
