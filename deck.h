#ifndef poker_deck
#define poker_deck

#include <vector>
#include "card.h"
#include "pair.h"


class deck_t {
    public:
        deck_t() {}

        void fill_deck();
        void empty_deck();
        void print_deck();
        void print_deck_count();
        void shuffle();
        card_t remove_card();
        pair_t remove_pair();
        void add_card(card_t card);
        void add_pair(pair_t pair);

    private:
        int deck_count=0;
        std::vector<card_t> deck;
};

#endif //poker_deck