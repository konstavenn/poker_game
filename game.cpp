#include <iostream>
#include "deck.h"
#include "game.h"
#include "hand.h"
#include "card.h"
#include "player.h"

void game_t::init_game() {
    int player_count;
    std::cout << "How many players?\n";
    std::cin >> player_count;

    for (int i = 0; i < player_count; i++) {
        std::string name;
        std::cout << "Enter name for player " << i + 1 << ": ";
        std::cin >> name;
        add_player(name);
    }
    
    std::cout << "\n\n";
    print_player_count();
    print_player_names();
    
    InDeck.fill_deck();
    InDeck.shuffle();

    it = players.begin();
    std::cout << "First player to get cards: " << it->name << '\n';
}

int game_t::game_loop() {
    char val;
    it++;
    if (it == players.end()) {
        it = players.begin();
    }

    std::cout << "Player in turn: " << it->name << '\n';
    std::cout << "Do you believe previous player? (y/n)\n";
    std::cin >> val;
    
    if (val == 'n') {
        auto prev_player = (it == players.begin()) ? std::prev(players.end()) : std::prev(it);
        std::cout << "Did " << prev_player->name << " lie? (y/n)\n";
        std::cin >> val;
        if (val == 'y') {
            players.erase(prev_player);
        } else {
            players.erase(it++);
            if (it == players.end()) {
                it = players.begin();
            }
        }
    }

    std::cout << "Players left: \n";
    print_player_names();
    std::cout << "Before round ends player in turn is: " << it->name << '\n';
    std::cout << "Round ends\n\n\n";

    return (val != 'e');
}

void game_t::print_player_names() {
    for (const auto& player : players) {
        std::cout << player.name << "\n";
    }
}

void game_t::print_player_count() {
    std::cout << players.size() << " players in the game.\n";
}

void game_t::add_player(std::string name) {
    players.emplace_back(std::move(name));
}