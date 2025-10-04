#include <stdlib.h>
#include <time.h>
#include "game.h"

int main() {
    srand(time(NULL));
    gameLoop();
    return 0;
}
