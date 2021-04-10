#include "Pistol.h"
static bool isPistolEmpty(Pistol*const pistol);
static void reloadPistol(Pistol*const pistol);
void initPistol(Pistol* const pistol, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo){
    pistol->pistolType = pistolType;
    pistol->damagePerRound = damagePerRound;
    pistol->clipSize = clipSize;
    pistol->remainingAmmo = inputAmmo;
    pistol->currClipBullets = clipSize;
    pistol->isPistolEmpty = isPistolEmpty;
    pistol->reloadPistol = reloadPistol;
}

static bool isPistolEmpty(Pistol*const pistol){
    if(pistol->currClipBullets <= 0){
        reloadPistol(pistol);
        return true;
    }
    return false;
}

static void reloadPistol(Pistol*const pistol){
    if(pistol->remainingAmmo <=0 ){
        printf("No ammo left\n");
        return;
    }
    if(pistol->remainingAmmo >= pistol->clipSize){
        pistol->currClipBullets = pistol->clipSize;
        pistol->remainingAmmo -= pistol->clipSize;
    }
    else{
        pistol->currClipBullets += pistol->remainingAmmo;
        pistol->remainingAmmo = 0;
    }

    printf("Reloading...\n");
    printf("currClipBullets: %d, remainingAmmo: %d\n",pistol->currClipBullets, pistol->remainingAmmo);
}
