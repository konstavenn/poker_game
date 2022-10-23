#include <iostream>

#include "card.h"
#include "pair.h"





void pair_t::fill_pair(card_t first, card_t second) {
    //card_pair = std::make_pair(first, second); 
    first_card = first;
    second_card = second;
    isset = true;
}
void pair_t::empty_pair() {
    //card_pair = {};
    card_t first_card;
    card_t second_card;
    isset = false;
}
void pair_t::print_pair() {
    if (!isset) {
        std::cout << "pair is empty.\n";
        return;
    }
    std::cout << card_to_string(first_card) << " and " << card_to_string(second_card) << '\n';
}

int is_better(pair_t first, pair_t second) {
    // first has 2
    if (static_cast<int>(first.first_card.rank) * static_cast<int>(first.second_card.rank) == 0) {
        //second has 2
        if (static_cast<int>(second.first_card.rank) * static_cast<int>(second.second_card.rank) == 0) {
            //first has 7-2
            if (static_cast<int>(first.first_card.rank) + static_cast<int>(first.second_card.rank) == 5) {
                //second has 7-2
                if (static_cast<int>(second.first_card.rank) + static_cast<int>(second.second_card.rank) == 5) {
                    return 0;
                }
                //only first has 7-2
                return 1;   
            }
            //only second has 7-2
            if (static_cast<int>(second.first_card.rank) + static_cast<int>(second.second_card.rank) == 5) {
                return -1;
            }

            //first has bigger 2x
            if (static_cast<int>(first.first_card.rank) + static_cast<int>(first.second_card.rank) > static_cast<int>(second.first_card.rank) + static_cast<int>(second.second_card.rank)) {
                return 1;
            }
            //second has bigger 2x
            else if (static_cast<int>(first.first_card.rank) + static_cast<int>(first.second_card.rank) < static_cast<int>(second.first_card.rank) + static_cast<int>(second.second_card.rank)) {
                return -1;
            }
            //same 2x hand
            return 0;
        }
        //only first has 7-2
        return 1;
    }

    //second has 2, first doesnt
    if (static_cast<int>(second.first_card.rank) * static_cast<int>(second.second_card.rank) == 0) {
        return -1;
    }
    
    //noone has 2
    
    // first has pair
    if (static_cast<int>(first.first_card.rank) == static_cast<int>(first.second_card.rank)) {
        // second has pair
        if (static_cast<int>(second.first_card.rank) == static_cast<int>(second.second_card.rank)) {
            //first has bigger pair
            if (static_cast<int>(first.first_card.rank) > static_cast<int>(second.first_card.rank)) {
                return 1;
            }
            //second has bigger pair
            else if (static_cast<int>(first.first_card.rank) < static_cast<int>(second.first_card.rank))
            {
                return -1;
            }
            //both have same pair
            return 0;
            
        }
        //first has bigger pair
        return 1;
    }

    // second has pair, first doesnt
    if (static_cast<int>(second.first_card.rank) == static_cast<int>(second.second_card.rank)) {
        return -1;
    }

    //noone has 2 or pair

    //compare bigger card
    int bigger_first = (static_cast<int>(first.first_card.rank) > static_cast<int>(first.second_card.rank)) ? static_cast<int>(first.first_card.rank) : static_cast<int>(first.second_card.rank);
    int bigger_second = (static_cast<int>(second.first_card.rank) > static_cast<int>(second.second_card.rank)) ? static_cast<int>(second.first_card.rank) : static_cast<int>(second.second_card.rank);
    if (bigger_first > bigger_second) {
        return 1;
    }
    if (bigger_first < bigger_second) {
        return -1;
    }

    //compare smaller card
    int smaller_first = (static_cast<int>(first.first_card.rank) < static_cast<int>(first.second_card.rank)) ? static_cast<int>(first.first_card.rank) : static_cast<int>(first.second_card.rank);
    int smaller_second = (static_cast<int>(second.first_card.rank) < static_cast<int>(second.second_card.rank)) ? static_cast<int>(second.first_card.rank) : static_cast<int>(second.second_card.rank);
    if (smaller_first > smaller_second) {
        return 1;
    }
    if (smaller_first < smaller_second) {
        return -1;
    }

    //same hand
    return 0;
}