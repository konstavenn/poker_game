
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <random>

#include "card.h"
#include "deck.h"
#include "hand.h"

void deck_t::fill_deck() {
    for (char i=0; i<static_cast<int>(suit_t::len); i++) {
        for (char j=0; j<static_cast<int>(rank_t::len); j++) {
            static card_t kortti;
            kortti.rank = static_cast<rank_t>(j);
            kortti.suit = static_cast<suit_t>(i);
            deck.push_back(kortti);
            deck_count++;
            //std::cout << card_to_string(kortti) << '\n';
        }
    }
    //std::cout << DeckCount << " cards in deck.\n";
};

void deck_t::empty_deck() {
    deck.clear();
}

void deck_t::print_deck() {
    for (std::vector<card_t>::iterator it = deck.begin() ; it != deck.end(); ++it)
        std::cout << card_to_string(*it) << '\n';
    if (deck.size() == 0) {
        std::cout << "Deck is empty.\n";
    }
}

void deck_t::print_deck_count() {
    std::cout << deck_count << " cards in deck.\n";
}
void deck_t::shuffle() {
    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    std::shuffle(deck.begin(), deck.end(), rng);
}

card_t deck_t::draw_card() {
    card_t card = deck.back(); //seg fault
    deck.pop_back();
    deck_count--;
    return card;
}

hand_t deck_t::draw_two_cards() {
    card_t a = draw_card();
    card_t b = draw_card();
    hand_t pair;
    pair.fill_hand(a, b);
    return pair;
}

void deck_t::add_card(card_t card) {
    deck.insert(deck.begin(), card);
    deck_count++;
}

void deck_t::add_two_cards(hand_t hand) {
    add_card(pair.second_card);
    add_card(pair.second_card);
    
}