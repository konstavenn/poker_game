#include <iostream>

#include "game.h"


int main() {
    game_t game;
    game.init_game();


    while(true) {
        int ret = game.game_loop();
        if (ret == 0) {break;}
    }
    return 0;
}