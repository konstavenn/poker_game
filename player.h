#ifndef poker_player
#define poker_player

#include <string>
#include "hand.h"

class player_t {
public:
    // Constructor that takes a player name
    explicit player_t(std::string player_name) : name(std::move(player_name)) {}

    // The player's current hand
    hand_t hand;

    // The player's name
    std::string name;
};

#endif //player.h