#include "DesertEagle.h"
void initDesertEagle(DesertEagle* desertEagle, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo){
    initPistol(desertEagle, pistolType, damagePerRound, clipSize, inputAmmo);
}

static void hurtArmor(Player* enemy, DesertEagle* desertEagle){
    if(hasPlayerArmor(enemy)){
        enemy->playerData.armor -= desertEagle->damagePerRound*DESERTEAGLE_ARMOR_DAMAGE_RATE;
    }
}

static void hurtHealth (Player* enemy, DesertEagle* desertEagle){
    if(hasPlayerArmor(enemy)){

        enemy->playerData.health -= desertEagle->damagePerRound*DESERTEAGLE_HEALTH_DAMAGE_RATE;
    }

    else{
        enemy->playerData.health -= desertEagle->damagePerRound;
    }
}

bool fireDesertEagle(Player* enemy, DesertEagle* desertEagle){
    hurtHealth(enemy, desertEagle);
    hurtArmor(enemy, desertEagle);
    desertEagle->currClipBullets--;
    printPlayerCondition(enemy);

    if(!isPlayerAlive(enemy)){
        return false;
    }
    return true;
}

