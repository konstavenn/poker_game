#include "card.h"
#include <iostream>

std::string suit_to_string(suit_t s) {
    switch (s) {
    case suit_t::hearts:
        return "hearts";
    case suit_t::diamonds:
        return "diamonds";
    case suit_t::clubs:
        return "clubs";
    case suit_t::spades:
        return "spades";
    default:
        return "Unknown";  // Handle unexpected cases
    }
}

std::string rank_to_string(rank_t s) {
    switch (s) {
        case rank_t::ace:   return "A";
        case rank_t::two:   return "2";
        case rank_t::three: return "3";
        case rank_t::four:  return "4";
        case rank_t::five:  return "5";
        case rank_t::six:   return "6";
        case rank_t::seven: return "7";
        case rank_t::eight: return "8";
        case rank_t::nine:  return "9";
        case rank_t::ten:   return "10";
        case rank_t::jack:  return "J";
        case rank_t::queen: return "Q";
        case rank_t::king:  return "K";
        default:            return "Unknown";  // Handle unexpected cases
    }
}

std::string card_to_string(card_t s) {
    return rank_to_string(s.rank) + " of " + suit_to_string(s.suit);
}