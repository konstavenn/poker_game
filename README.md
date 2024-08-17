# Poker Game

This is a C++ implementation of a custom poker game. The game follows specific rules where players draw cards, make claims about their hands, and can challenge each other's claims.

## Project Structure

The project consists of the following files:

- `main.cpp`: The entry point of the program
- `game.cpp` / `game.h`: Defines the main game logic
- `player.cpp` / `player.h`: Represents a player in the game
- `deck.cpp` / `deck.h`: Manages the deck of cards
- `hand.cpp` / `hand.h`: Represents a player's hand
- `card.cpp` / `card.h`: Defines individual cards

## Building the Project

This project uses CMake as its build system. To build the project:

1. Make sure you have CMake installed (version 3.13 or higher)
2. Navigate to the project root directory
3. Create a build directory: `mkdir build && cd build`
4. Generate the build files: `cmake ..`
5. Build the project: `make`

## Running the Game

After building, you can run the game by executing the `poker` binary in the build directory:

```
./poker
```

## Game Rules

The game follows these rules:

1. The first player draws 2 cards.
2. They state a poker hand they claim to have and pass the cards to the next player.
3. The next player can either:
   a. Believe the claim and draw 0, 1, or 2 new cards, then make a stronger claim.
   b. Challenge the claim. If the hand is worse than claimed, the previous player is out. Otherwise, the challenging player is out.
4. Each time the hand is passed, the claimed poker hand must be stronger.
5. A 2 is considered a joker, and 7-2 is the best possible hand.

## Contributing

Contributions to this project are welcome. Please ensure you follow the existing code style and include appropriate tests for any new features.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.