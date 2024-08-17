#ifndef poker_deck
#define poker_deck

#include <vector>
#include "card.h"
#include "hand.h"

class deck_t {
public:
    deck_t() {}  // Default constructor

    // Deck management
    void fill_deck();    // Populate the deck with cards
    void empty_deck();   // Remove all cards from the deck
    void shuffle();      // Randomize the order of cards in the deck

    // Card operations
    card_t draw_card();              // Draw a single card from the deck
    hand_t draw_two_cards();         // Draw two cards to form a hand
    void add_card(card_t card);      // Add a single card to the deck
    void add_two_cards(hand_t hand); // Add two cards from a hand to the deck

    // Deck information
    void print_deck();       // Display all cards in the deck
    void print_deck_count(); // Display the number of cards in the deck

private:
    int deck_count = 0;
    std::vector<card_t> deck;
};

#endif //poker_deck