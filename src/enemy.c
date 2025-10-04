#include "enemy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// generates a simple enemy
Enemy generateEnemy() {
    Enemy e;
    char *names[] = {"Goblin", "Orc", "Wolf"};
    strcpy(e.name, names[rand() % 3]);
    e.hp = 20 + rand() % 11;
    e.attack = 3 + rand() % 4;
    return e;
}

// true/false if enemy is alive
bool isAliveEnemy(Enemy *enemy) {
    return enemy->hp > 0;
}

// player attacks enemy
void attackEnemy(Player *p, Enemy *e) {
    e->hp -= p->attack;
    printf("%s attacked %s for %d damage!\n", p->name, e->name, p->attack);
}

// enemy attacks player
void attackPlayer(Enemy *e, Player *p) {
    p->hp -= e->attack;
    printf("%s attacked %s for %d damage!\n", e->name, p->name, e->attack);
}
