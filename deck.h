#ifndef poker_deck
#define poker_deck

#include <vector>
#include "card.h"
#include "hand.h"


class deck_t {
    public:
        deck_t() {}

        void fill_deck();
        void empty_deck();
        void print_deck();
        void print_deck_count();
        void shuffle();
        card_t draw_card();
        hand_t draw_two_cards();
        void add_card(card_t card);
        void add_two_cards(hand_t hand);

    private:
        int deck_count=0;
        std::vector<card_t> deck;
};

#endif //poker_deck