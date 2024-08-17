#ifndef poker_hand
#define poker_hand

#include <vector>
#include "card.h"


class hand_t {
    public:
        hand_t() {}

        void fill_hand(card_t first, card_t second);

        card_t replace_first(card_t first);
        card_t replace_second(card_t second);
        hand_t replace_both(hand_t hand);
        
        void empty_hand();
        void print_hand();
        card_t first_card;
        card_t second_card;
    private:
        bool hand_not_empty = false;
};

int is_better(hand_t first, hand_t second);

#endif //poker_hand