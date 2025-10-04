#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"

typedef struct {
    char name[MAX_NAME_SIZE];
    int hp;
    int attack;
} Enemy;

Enemy generateEnemy(void);
bool isAliveEnemy(Enemy *enemy);
void attackEnemy(Player *p, Enemy *e);
void attackPlayer(Enemy *e, Player *p);

#endif
