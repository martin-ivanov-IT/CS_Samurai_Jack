#include "Defines.h"
#include "Pistol.h"

void initPistol(Pistol* pistol, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo){
    pistol->pistolType = pistolType;
    pistol->damagePerRound = damagePerRound;
    pistol->clipSize = clipSize;
    pistol->remainingAmmo = inputAmmo;
}

bool isPistolEmpty(Pistol* pistol){
    if(pistol->currClipBullets <= 0){
        return true;
    }
    return false;
}
