#ifndef PISTOL_H_
#define PISTOL_H_

#include "Defines.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct {
  enum PistolType pistolType;
  int damagePerRound;
  int clipSize;
  int currClipBullets;
  int remainingAmmo;
}Pistol;

void initPistol(Pistol* pistol, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo);
bool isPistolEmpty(Pistol* pistol);
void reloadPistol(Pistol* pistol);
#endif /* PISTOL_H_ */
