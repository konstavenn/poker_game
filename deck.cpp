#include <iostream>
#include <algorithm>
#include <random>
#include "card.h"
#include "deck.h"
#include "hand.h"

void deck_t::fill_deck() {
    for (int i = 0; i < static_cast<int>(suit_t::len); i++) {
        for (int j = 0; j < static_cast<int>(rank_t::len); j++) {
            card_t card;
            card.rank = static_cast<rank_t>(j);
            card.suit = static_cast<suit_t>(i);
            deck.push_back(card);
            deck_count++;
        }
    }
}

void deck_t::empty_deck() {
    deck.clear();
    deck_count = 0;
}

void deck_t::print_deck() {
    if (deck.empty()) {
        std::cout << "Deck is empty.\n";
        return;
    }
    for (const auto& card : deck) {
        std::cout << card_to_string(card) << '\n';
    }
}

void deck_t::print_deck_count() {
    std::cout << deck_count << " cards in deck.\n";
}

void deck_t::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

card_t deck_t::draw_card() {
    if (deck.empty()) {
        throw std::runtime_error("Cannot draw from an empty deck");
    }
    card_t card = deck.back();
    deck.pop_back();
    deck_count--;
    return card;
}

hand_t deck_t::draw_two_cards() {
    if (deck_count < 2) {
        throw std::runtime_error("Not enough cards in the deck to draw two");
    }
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
    add_card(hand.second_card);
    add_card(hand.first_card);
}