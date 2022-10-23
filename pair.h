#ifndef poker_pair
#define poker_pair

#include <vector>
#include "card.h"


class pair_t {
    public:
        pair_t() {}

        void fill_pair(card_t first, card_t second);

        card_t replace_first(card_t first);
        card_t replace_second(card_t second);
        pair_t replace_both(pair_t pair);
        
        void empty_pair();
        void print_pair();
        card_t first_card;
        card_t second_card;
        bool isset = false;
};

int is_better(pair_t first, pair_t second);

#endif //poker_pair