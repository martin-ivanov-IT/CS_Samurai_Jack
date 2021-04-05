#include "Pistol.h"
#include "Player.h"
#include <stdbool.h>
#include <stdlib.h>

typedef Pistol Glock;

void initGlock(Glock* glock, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo);
bool fireGlock(Player* enemy, Glock* glock);
