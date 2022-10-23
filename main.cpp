#include <iostream>

#include "game.h"


int main() {
    init_game();


    while(true) {
        game_loop();
        break;
    }
    return 0;
}