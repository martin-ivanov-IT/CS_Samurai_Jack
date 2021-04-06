#include "Glock.h"
#include "Player.h"

static bool Glock_fire(Pistol* me, PlayerVitalData* playerVitalData);
static void hurtArmor(PlayerVitalData* enemy, Glock* glock);
static void hurtHealth (PlayerVitalData* enemy, Glock* glock);

void initGlock(Glock* glock, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo){
    initPistol(glock,pistolType, damagePerRound,clipSize, inputAmmo);
    static const struct PistolVtable vtable = {
        &Glock_fire
    };
    glock->vptr = &vtable;
}

static bool Glock_fire(Pistol* glock, PlayerVitalData* enemy){
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

static void hurtArmor(PlayerVitalData* enemy, Glock* glock){
    if(hasPlayerArmor(enemy)){
        enemy->armor -= glock->damagePerRound * GLOCK_ARMOR_DAMAGE_RATE;
        if(enemy->armor < 0){
            enemy->health += enemy->armor;
            enemy->armor = 0;
        }
    }
}

static void hurtHealth (PlayerVitalData* enemy, Glock* glock){
    if(hasPlayerArmor(enemy)){
        enemy->health -= glock->damagePerRound * GLOCK_HEALTH_DAMAGE_RATE;
    }

    else{
        enemy->health -= glock->damagePerRound;
    }
}
