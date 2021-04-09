#ifndef DEFINES_H_
#define DEFINES_H_

#include <stdbool.h>

enum PistolType {
  GLOCK, DESERT_EAGLE
};

enum GlockDefines {
  ROUNDS_PER_FIRE = 3
};

enum PlayerDefines {
  PLAYER_ONE, PLAYER_TWO, PLAYERS_COUNT
};

typedef struct PlayerVitalData{
  int health;
  int armor;
  bool (* isAlive)(struct PlayerVitalData* player);
  bool (* hasArmor)(struct PlayerVitalData* player);
  void (*printCondition)(struct PlayerVitalData* player);
} PlayerVitalData;


#define DESERTEAGLE_ARMOR_DAMAGE_RATE 0.25
#define DESERTEAGLE_HEALTH_DAMAGE_RATE 0.75

#define GLOCK_ARMOR_DAMAGE_RATE 0.50
#define GLOCK_HEALTH_DAMAGE_RATE 0.50

#endif /* DEFINES_H_ */
