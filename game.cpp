#include "deck.h"
#include "game.h"
#include "hand.h"
#include "card.h"
#include "player.h"

#include <iostream>


void game_t::init_game() {
    int player_count;
    std::cout << "How many players?\n";
    std::cin >> player_count;

    for (int i=0; i<player_count; i++) {
        std::string name;
        std::cin >> name;
        add_player(name);
    }
    std::cout << "\n\n\n";
    print_player_count();
    print_player_names();
    InDeck.fill_deck();
    InDeck.shuffle();
    //InDeck.print_deck();

    it = std::begin(players);
    std::cout << "First player to get cards: " << it->name << '\n';
}



int game_t::game_loop() {
    char val;
    it++;

    std::cout << "Player in turn:" << it->name << '\n';
    std::cout << "Do you believe previous player? (y/n)\n";
    std::cin >> val;
    if (val == 'n') {
        std::cout << "Did " << (it--)->name << "lie? (y/n)\n";
        std::cin >> val;
        if (val == 'y') {
            players.erase(it);
        } else {
            players.erase(it++);
        }
    }

    std::cout << "Players left: \n";
    print_player_names();
    std::cout << "Before round ends palyer in turn is: " << it->name << '\n';
    std::cout << "Round ends\n\n\n\n";


    if (it == std::end(players)-1) {
        it = std::begin(players);
    }

    if (val == 'e') {
        return 0;
    }
    return 1;
}


void game_t::print_player_names() {
    for (auto player : players) {
        std::cout << player.name << "\n";
    }
    
}

void game_t::print_player_count() {
    std::cout << players.size() << " players in the game.\n";
}

void game_t::add_player(std::string name) {
    player_t player(name);
    players.push_back(player);
}



/*
konsta
jaakko
pekka
kakku


init
    konstalle kortit

loop
    konsta antaa kortit jakelle
    jaakon vuoro
    is bigger() = 1


*/








    /*

    hand = game.InDeck.draw_two_cards();
    other_hand = game.InDeck.draw_two_cards();


    int a = is_better(hand, other_hand);

    std::cout << a << '\n';
    
    hand.print_hand();
    other_hand.print_hand();



    game.InDeck.print_deck_count();

    game.OutDeck = out;
    game.hand = hand;

    hand = game.InDeck.draw_two_cards(hand);
    game.InDeck.print_deck();
    game.InDeck.print_deck_count();
    hand.print_hand();
    
    //game.OutDeck.add_card(game.InDeck.draw_card());

    for (int i=0; i<5; i++) {
        static player_t player;
        game.players.push_back(player);
    }
    game.print_player_count();*/