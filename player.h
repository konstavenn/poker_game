#ifndef poker_player
#define poker_player

#include "hand.h"

class player_t {
    public:
        player_t(std::string player_name) {name = player_name;}

        hand_t hand;
        std::string name;

};

#endif //player.h