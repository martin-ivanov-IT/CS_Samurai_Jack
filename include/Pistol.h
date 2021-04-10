#ifndef PISTOL_H_
#define PISTOL_H_

#include "Defines.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct Pistol{
  enum PistolType pistolType;
  int damagePerRound;
  int clipSize;
  int currClipBullets;
  int remainingAmmo;
  bool (*isPistolEmpty)(struct Pistol* pistol);
  bool (*fire)(struct Pistol* me, PlayerVitalData* playerData);
 }Pistol;

void initPistol(Pistol* const pistol, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo);
#endif /* PISTOL_H_ */
