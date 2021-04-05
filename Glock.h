#include "Pistol.h"
#include "Player.h"
#include <stdbool.h>

typedef Pistol Glock;

void initGlock(Glock* glock, enum PistolType pistolType, int damagePerRound, int clipSize, int inputAmmo);
