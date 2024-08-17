#ifndef poker_card
#define poker_card

#include <string>

// Enumerate card ranks from Two to Ace
enum class rank_t : unsigned char {
    two   = 0,
    three = 1,
    four  = 2,
    five  = 3,
    six   = 4,
    seven = 5,
    eight = 6,
    nine  = 7,
    ten   = 8,
    jack  = 9,
    queen = 10,
    king  = 11,
    ace   = 12,
    len   = 13  // Useful for iteration and array sizing
};

// Enumerate card suits
enum class suit_t : unsigned char {
    hearts,
    diamonds,
    clubs,
    spades,
    len  // Useful for iteration and array sizing
};

// Struct to represent a card with rank and suit
struct card_t {
    rank_t rank;
    suit_t suit;
    constexpr auto operator==(card_t const&) const noexcept -> bool = default;
};

// Function declarations for string conversions
std::string suit_to_string(suit_t s);
std::string rank_to_string(rank_t s);
std::string card_to_string(card_t s);

#endif //poker_card