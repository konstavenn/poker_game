#ifndef poker_game
#define poker_game

#include "deck.h"
#include "pair.h"
#include "player.h"


void init_game();
void game_loop();

class game_t {
    public:
        game_t() {}

        deck_t InDeck;
        deck_t OutDeck;
        pair_t hand;
        std::vector<player_t> players;

        void print_player_count();

};


#endif //game.h