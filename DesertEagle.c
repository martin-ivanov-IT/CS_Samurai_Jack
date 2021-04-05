#include "DesertEagle.h"
void initDesertEagle(DesertEagle* desertEagle, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo){
    initPistol(desertEagle, pistolType, damagePerRound, clipSize, inputAmmo);
    desertEagle->fire =  fire;
}

static bool fire(Player* enemy, DesertEagle* desertEagle){
    hurtHealth(enemy, desertEagle);
    hurtArmor(enemy, desertEagle);
    printPlayerCondition(enemy);
    if(enemy->playerData.health <= 0){
        return false;
    }
}

static void hurtArmor(Player* enemy, DesertEagle* desertEagle){
    if(hasPlayerArmor(enemy)){
        enemy->playerData.armor -= desertEagle->damagePerRound/2;
    }
}

static void hurtHealth (Player* enemy, DesertEagle* desertEagle){
    if(hasPlayerArmor(enemy)){

        enemy->playerData.health -= (double)desertEagle->damagePerRound*0.75;
    }

    else{
        enemy->playerData.health -= (double)desertEagle->damagePerRound*0.25;
    }
}