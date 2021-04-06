#include "Defines.h"
#include "Pistol.h"
bool isPistolEmpty(Pistol* pistol);
void initPistol(Pistol* pistol, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo){
    pistol->pistolType = pistolType;
    pistol->damagePerRound = damagePerRound;
    pistol->clipSize = clipSize;
    pistol->remainingAmmo = inputAmmo;
    pistol->currClipBullets = clipSize;
}

bool isPistolEmpty(Pistol* pistol){
    if(pistol->currClipBullets <= 0){
        return true;
    }
    return false;
}

void reloadPistol(Pistol* pistol){
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
