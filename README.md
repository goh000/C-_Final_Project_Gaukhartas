# RPG Text-Based Game

## Description
This project is a text-based RPG (Role-Playing Game) developed in C++. Players create a character, explore different locations, engage in battles, collect items, and level up. Decisions are made via text commands, affecting the storyline and character progression.

## Features
- Character creation with customizable classes (Warrior, Mage, Archer).
- Turn-based combat system with random damage and critical hits.
- Inventory system with potions and item drops.
- Exploration of a forest and a dungeon with progressive challenges.
- Leveling system with improved stats.
- Color-coded messages for an enhanced terminal experience.

## Requirements
- C++ compiler supporting C++11 or higher (e.g., g++, clang++)
- Terminal or command-line interface
- (Optional) Make utility for simplified compilation

## How to Compile
### Using g++ (Command Line)
1. Save the code into a file named `main.cpp`.
2. Open your terminal or command prompt and navigate to the project directory.
3. Compile the code:
   ```bash
   g++ -std=c++11 -o rpg_game main.cpp  # Compile the main.cpp file into an executable named rpg_game
   ```
4. On successful compilation, an executable named `rpg_game` (or `rpg_game.exe` on Windows) will be created.

### Using Makefile (Optional)
If you have a `Makefile`, you can compile by simply running:
```bash
make  # Automates the compilation process using the provided Makefile
```

## How to Run
After compiling, execute the game with:
```bash
./rpg_game      # On Linux/macOS to run the game
rpg_game.exe    # On Windows to run the game
```
Follow the on-screen instructions to play.

## Game Instructions
- **Create Character**: Enter your character’s name and choose a class:
  - **Warrior**: Balanced stats with a special attack "Power Strike."
  - **Mage**: High attack power with "Fireball."
  - **Archer**: High defense with "Double Shot."
- **Explore the Forest**: Encounter random events or battle a Goblin. Defeating the Goblin grants a sword.
- **Enter the Dungeon**: Requires the sword to challenge the Dark Lord.
- **Battle Options**:
  - *Attack*: Inflict damage on the enemy.
  - *Use Potion*: Restore 20 HP (if available).
- **Leveling Up**: Earn EXP from battles. Gain improved stats every 50 EXP.

## Project Structure
```
rpg_game/
├── main.cpp      # Core game logic with comments explaining each line of code
├── Makefile      # (Optional) For simplified build process
└── README.md     # Project documentation
```

## Code Comments Overview
Each line in `main.cpp` includes comments explaining its purpose:
- **Headers and Libraries**:
  - `#include <iostream>`: Handles input and output streams.
  - `#include <cstdlib>`: Provides functions like `rand()` and `srand()` for randomness.
  - `#include <ctime>`: Used to seed the random number generator.
  - `#include <limits>`: Clears input buffer to avoid input issues.
  - `#include <string>`: Enables string usage for character names and messages.

- **Functions**:
  - `printMessage()`: Prints messages with optional colors for better terminal readability.
  - `createCharacter()`: Prompts the user to create and customize a character.
  - `showStatus()`: Displays the player's current stats and inventory.
  - `levelUp()`: Increases player stats upon reaching experience milestones.
  - `battle()`: Handles combat logic, including damage calculation and victory conditions.
  - `forest()`: Simulates forest exploration with a chance of encountering a Goblin.
  - `dungeon()`: Introduces a challenging boss fight, accessible after obtaining a sword.

- **Main Game Loop**:
  - Prompts user choices: explore, check status, fight, or exit.
  - Continues until the player chooses to quit or the character’s health reaches zero.

## Example Gameplay
```bash
Enter your character's name: Aria  # User inputs character name
Choose your class:                # Prompt to select character class
1. Warrior  2. Mage  3. Archer
> 2                               # Player selects Mage class
LEVEL UP! Your stats have improved!  # Character levels up after gaining enough EXP
A wild Goblin appears!            # Random encounter with an enemy
1. Attack  2. Use Potion          # Player selects an action during battle
> 1                               # Attacking the enemy
You hit the Goblin for 12 damage! # Combat result displayed
Goblin hits you for 8 damage!     # Enemy counterattack
```

## Contributing
Contributions are welcome! Fork the repo and submit pull requests for improvements or new features.

## License
This project is licensed under the MIT License. See `LICENSE` for details.


