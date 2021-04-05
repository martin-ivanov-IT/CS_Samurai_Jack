#ifndef PISTOL_H_
#define PISTOL_H_

#include "Defines.h"
#include "Player.h"

typedef bool (*Fire)(Pistol* pistol ,  Player* enemy);

typedef struct {
  enum PistolType pistolType;
  int damagePerRound;
  int clipSize;
  int currClipBullets;
  int remainingAmmo;
  Fire fire;
} Pistol;

void initPistol(Pistol* pistol, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo);
bool isPistolEmpty(Pistol* pistol);
#endif /* PISTOL_H_ */
