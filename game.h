#ifndef poker_game
#define poker_game

#include <vector>
#include <string>
#include "deck.h"
#include "hand.h"
#include "player.h"

class game_t {
public:
    game_t() = default;

    // Game components
    deck_t InDeck;
    deck_t OutDeck;
    hand_t hand;
    std::vector<player_t> players;
    std::vector<player_t>::iterator it;

    // Game management
    void init_game();
    int game_loop();

    // Player management
    void add_player(std::string name);
    void print_player_count();
    void print_player_names();
};

#endif //game.h