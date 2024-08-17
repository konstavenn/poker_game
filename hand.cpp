#include <iostream>
#include "card.h"
#include "hand.h"

void hand_t::fill_hand(card_t first, card_t second) {
    first_card = first;
    second_card = second;
    hand_not_empty = true;
}

void hand_t::empty_hand() {
    first_card = card_t();
    second_card = card_t();
    hand_not_empty = false;
}

void hand_t::print_hand() {
    if (!hand_not_empty) {
        std::cout << "Hand is empty.\n";
        return;
    }
    std::cout << card_to_string(first_card) << " and " << card_to_string(second_card) << '\n';
}

// TODO: replace_first, replace_second, and replace_both methods 

int is_better(hand_t first, hand_t second) {
    // Helper function to check if a hand has a 2 (joker)
    auto has_two = [](const hand_t& h) {
        return static_cast<int>(h.first_card.rank) == 0 || static_cast<int>(h.second_card.rank) == 0;
    };

    // Helper function to get the sum of ranks in a hand
    auto rank_sum = [](const hand_t& h) {
        return static_cast<int>(h.first_card.rank) + static_cast<int>(h.second_card.rank);
    };

    // Check for hands with 2 (joker)
    if (has_two(first)) {
        if (has_two(second)) {
            // Both hands have a 2
            if (rank_sum(first) == 5 && rank_sum(second) == 5) return 0;  // Both have 7-2
            if (rank_sum(first) == 5) return 1;  // Only first has 7-2
            if (rank_sum(second) == 5) return -1;  // Only second has 7-2
            return rank_sum(first) > rank_sum(second) ? 1 : (rank_sum(first) < rank_sum(second) ? -1 : 0);
        }
        return 1;  // Only first has a 2
    }
    if (has_two(second)) return -1;  // Only second has a 2

    // Check for pairs
    bool first_pair = first.first_card.rank == first.second_card.rank;
    bool second_pair = second.first_card.rank == second.second_card.rank;
    if (first_pair && second_pair) {
        return static_cast<int>(first.first_card.rank) - static_cast<int>(second.first_card.rank);
    }
    if (first_pair) return 1;
    if (second_pair) return -1;

    // Compare high cards, then low cards
    int first_high = std::max(static_cast<int>(first.first_card.rank), static_cast<int>(first.second_card.rank));
    int second_high = std::max(static_cast<int>(second.first_card.rank), static_cast<int>(second.second_card.rank));
    if (first_high != second_high) return first_high - second_high;

    int first_low = std::min(static_cast<int>(first.first_card.rank), static_cast<int>(first.second_card.rank));
    int second_low = std::min(static_cast<int>(second.first_card.rank), static_cast<int>(second.second_card.rank));
    return first_low - second_low;
}