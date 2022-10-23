#include "deck.h"
#include "game.h"
#include "pair.h"
#include "card.h"
#include "player.h"

#include <iostream>


void init_game() {
    std::cout << "init\n";

    game_t game;
    deck_t in, out;
    pair_t hand;
    pair_t other_hand;

    game.InDeck = in;
    game.InDeck.fill_deck();
    game.InDeck.shuffle();

    hand = game.InDeck.remove_pair();
    other_hand = game.InDeck.remove_pair();


    int a = is_better(hand, other_hand);

    std::cout << a << '\n';
    
    hand.print_pair();
    other_hand.print_pair();


    /*

    game.InDeck.print_deck_count();

    game.OutDeck = out;
    game.hand = hand;

    hand = game.InDeck.remove_pair(hand);
    game.InDeck.print_deck();
    game.InDeck.print_deck_count();
    hand.print_pair();
    
    //game.OutDeck.add_card(game.InDeck.remove_card());

    for (int i=0; i<5; i++) {
        static player_t player;
        game.players.push_back(player);
    }
    game.print_player_count();*/
}



void game_loop() {
    std::cout << "loop\n";

}




void game_t::print_player_count() {
    std::cout << players.size() << " players in the game.\n";
}