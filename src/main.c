#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define TITLE "Elarion"
#define MAX_NAME_SIZE 20
#define PLAYER_START_HEALTH 100
#define PLAYER_START_ATTACK 10
#define MS 50

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


// lets the player to choose a class
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


// creates a player
Player createPlayer() {
    Player player;

    char pname[MAX_NAME_SIZE];
    printf("Whats your name Player: \n");
    scanf("%s", &pname);
    printf("Welcome to %s %s!\n", TITLE, pname);

    player = chooseClassPlayer();

    // values assignment 
    strcpy(player.name, pname);
    player.hp = PLAYER_START_HEALTH;
    player.attack = PLAYER_START_ATTACK;
    player.xp = 0;

    return player;
}


// generates an enemy with random stats
Enemy generateEnemy() {
    Enemy e;
    char *names[] = {"Goblin", "Orc", "Wolf"};
    strcpy(e.name, names[rand() % 3]);
    e.hp = 20 + rand() % 11;
    e.attack = 3 + rand() % 4;
    return e;
}


// player attacks enemy
void attackEnemy(Player *p, Enemy *e) {
    e->hp -= p->attack;
    printf("%s just attacked %s for %d points of health!\n", p->name, e, p->attack);
}


// enemy attacks player
void attackPlayer(Enemy *e, Player *p){
    p->hp -= e->attack;
    printf("%s just attacked %s for %d points of health!\n", e, p->name, e->attack);
}


// true/false if player is alive
bool isAlivePlayer(Player *player) {
    return player->hp > 0;
}


// true/false if enemy is alive
bool isAliveEnemy(Enemy *enemy) {
    return enemy->hp > 0;
}


// function to simulate a type writer like effect in a terminal
void write(char string[]){
    for (int i = 0; string[i]; i++){
        printf("%c", string[i]);
        fflush(stdout);
        Sleep(MS);
    }
}

// some backstory:]
void introduceWorld() {
    write("Welcome to Elarion.\n");
    write("You have found yourself in a world, a planet of some sort, completely unknown to you.\n");
    write("Everything you've known, everything you were, is lost now.\n");
    write("You must start anew.\n");
    write("You MUST start anew.\n");
}

void drawDice(int number){
    char xxxxxxxxx[] = "+-------+\n";
    char x_______x[] = "|       |\n";
    char x_o_____x[] = "| o     |\n";
    char x___o___x[] = "|   o   |\n";
    char x_____o_x[] = "|     o |\n";
    char x_o___o_x[] = "| o   o |\n";

    switch (number)
    {
    case 1:
        printf(xxxxxxxxx);
        printf(x_______x);
        printf(x___o___x);
        printf(x_______x);
        printf(xxxxxxxxx);
        break;
    case 2:
        printf(xxxxxxxxx);
        printf(x_o_____x);
        printf(x_______x);
        printf(x_____o_x);
        printf(xxxxxxxxx);
        break;
    case 3:
        printf(xxxxxxxxx);
        printf(x_o_____x);
        printf(x___o___x);
        printf(x_____o_x);
        printf(xxxxxxxxx);
        break;
    case 4:
        printf(xxxxxxxxx);
        printf(x_o___o_x);
        printf(x_______x);
        printf(x_o___o_x);
        printf(xxxxxxxxx);
        break;
    case 5:
        printf(xxxxxxxxx);
        printf(x_o___o_x);
        printf(x___o___x);
        printf(x_o___o_x);
        printf(xxxxxxxxx);
        break;
    case 6:
        printf(xxxxxxxxx);
        printf(x_o___o_x);
        printf(x_o___o_x);
        printf(x_o___o_x);
        printf(xxxxxxxxx);
        break;
    }
}

// randomizes the dice and then draws it using the drawDice function
void rollDice(){
    int num = 1 + rand() % 6;
    drawDice(num);
    printf("You rolled a %d!\n", num);
}


int main() {
    // seed to randomize rand()
    srand(time(NULL));
    //printf("===== %s =====\n\n", TITLE);

    //Player player = createPlayer();
    //Enemy enemy = generateEnemy();

    //attackEnemy(&player, &enemy);
    //attackPlayer(&enemy, &player);

    introduceWorld();

    rollDice();
    rollDice();
    rollDice();

    //to pause; debug
    getchar();
    getchar();

    return 0;
}