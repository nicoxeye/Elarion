#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_SIZE 20
#define PLAYER_START_HEALTH 100
#define PLAYER_START_ATTACK 10

typedef enum{
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

typedef struct {
    char name[MAX_NAME_SIZE];
    int hp;
    int attack;
} Enemy;

typedef struct {
    char name[MAX_NAME_SIZE];
    int heal;
} Item;


Player chooseClassPlayer() {
    Player player;
    printf("Choose your class: \n");
    printf("1. Warrior\n2. Mage\n3. Rogue\n4. Cleric\n");
    int input;
    scanf("%d", &input);

    switch(input){
        case 1:
            printf("You've chosen Warrior as your class!\n");
            player.class = Warrior;
            break;
        case 2:
            printf("You've chosen Mage as your class!\n");
            player.class = Mage;
            break;
        case 3:
            printf("You've chosen Rogue as your class!\n");
            player.class = Rogue;
            break;
        case 4:
            printf("You've chosen Cleric as your class!\n");
            player.class = Cleric;
            break;
        default:
            printf("There's no class like that (yet)\n\n");
            chooseClassPlayer();
    }
    return player;
}


Player createPlayer() {
    Player player;

    char pname[MAX_NAME_SIZE];
    printf("Whats your name Player: \n");
    scanf("%s", &pname);
    printf("Welcome to Elarion %s!\n", pname);

    player = chooseClassPlayer();

    // values assignment 
    strcpy(player.name, pname);
    player.hp = PLAYER_START_HEALTH;
    player.attack = PLAYER_START_ATTACK;
    player.xp = 0;

    return player;
}

Enemy generateEnemy() {
    Enemy e;
    char *names[] = {"Goblin", "Orc", "Wolf"};
    strcpy(e.name, names[rand() % 3]);
    e.hp = 20 + rand() % 11;
    e.attack = 3 + rand() % 4;
    return e;
}

void attackEnemy(Player *p, Enemy *e) {
    e->hp -= p->attack;
    printf("Player just attacked %s for %d points of health!\n", e, p->attack);
}

void attackPlayer(Enemy *e, Player *p){
    p->hp -= e->attack;
    printf("%s just attacked %s for %d points of health!\n", e, p->name, e->attack);
}

bool isAlivePlayer(Player *player) {
    return player->hp > 0;
}


int main() {
    srand(time(NULL));
    printf("===== Elarion =====\n\n");

    Player player = createPlayer();
    Enemy enemy = generateEnemy();
    attackEnemy(&player, &enemy);
    attackPlayer(&enemy, &player);

    //to pause
    getchar();
    getchar();

    return 0;
}