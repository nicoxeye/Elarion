#include "player.h"
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <stdio.h>


Player chooseClassPlayer() {
    Player player;
    write("Choose your class: \n");
    printf("1. Warrior\n2. Mage\n3. Rogue\n4. Cleric\n");
    int input;
    scanf("%d", &input);

    switch (input) {
        case 1:
            printf("You've chosen Warrior!\n");
            player.class = Warrior;
            break;
        case 2:
            printf("You've chosen Mage!\n");
            player.class = Mage;
            break;
        case 3:
            printf("You've chosen Rogue!\n");
            player.class = Rogue;
            break;
        case 4:
            printf("You've chosen Cleric!\n");
            player.class = Cleric;
            break;
        default:
            printf("Invalid choice.\n");
            return chooseClassPlayer();
    }
    return player;
}


Player createPlayer() {
    Player player;
    char pname[MAX_NAME_SIZE];
    write("What is your name: \n");
    scanf("%s", pname);

    char msg[100];
    sprintf(msg, "Welcome %s\n", pname);
    write(msg);

    player = chooseClassPlayer();

    // assigning values to Player structure
    strcpy(player.name, pname);
    player.hp = PLAYER_START_HEALTH;
    player.attack = PLAYER_START_ATTACK;
    player.xp = 0;

    return player;
}


// true/false if player is alive
bool isAlivePlayer(Player *player) {
    return player->hp > 0;
}
