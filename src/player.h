#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include "utility.h"

#define MAX_NAME_SIZE 20
#define PLAYER_START_HEALTH 100
#define PLAYER_START_ATTACK 10

typedef enum {
    Warrior,
    Mage,
    Rogue,
    Cleric
} Class;

typedef struct {
    char name[MAX_NAME_SIZE];
    int hp;
    int attack;
    int xp;
    Class class;
} Player;

Player createPlayer(void);
Player chooseClassPlayer(void);
bool isAlivePlayer(Player *player);

#endif
