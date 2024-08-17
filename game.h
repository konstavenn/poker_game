#ifndef poker_game
#define poker_game

#include "deck.h"
#include "hand.h"
#include "player.h"

class game_t {
    public:
        game_t() {}

        deck_t InDeck;
        deck_t OutDeck;
        hand_t hand;
        std::vector<player_t> players;

        void print_player_count();
        void print_player_names();
        void init_game();
        int game_loop();
        void add_player(std::string name);
        std::vector<player_t>::iterator it;
};


#endif //game.h