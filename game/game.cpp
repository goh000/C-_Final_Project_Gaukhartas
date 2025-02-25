#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>  // For input cleaning
#include <string>

using namespace std;

void printMessage(const string& message, const string& color = "default") {
    if (color == "red") cout << "\033[1;31m" << message << "\033[0m" << endl;
    else if (color == "green") cout << "\033[1;32m" << message << "\033[0m" << endl;
    else if (color == "yellow") cout << "\033[1;33m" << message << "\033[0m" << endl;
    else if (color == "cyan") cout << "\033[1;36m" << message << "\033[0m" << endl;
    else cout << message << endl;
}

struct Character {
    string name;
    string role;
    int health, maxHealth, attack, defense, potions, level, exp, gold;
    bool hasSword;
};

struct Enemy {
    string name;
    int health, attack, defense;
};

Character createCharacter() {
    Character player;
    printMessage("Enter your character's name: ", "cyan");
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    getline(cin, player.name); // Use getline for names with spaces

    printMessage("\nChoose your class:", "yellow");
    printMessage("1. Warrior (Balanced - 'Power Strike')");
    printMessage("2. Mage (High Attack - 'Fireball')");
    printMessage("3. Archer (High Defense - 'Double Shot')");

    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        printMessage("Invalid choice. Enter 1, 2, or 3:", "red");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (choice == 1) {
        player.role = "Warrior";
        player.health = player.maxHealth = 100;
        player.attack = 15; player.defense = 10;
    }
    else if (choice == 2) {
        player.role = "Mage";
        player.health = player.maxHealth = 80;
        player.attack = 20; player.defense = 5;
    }
    else {
        player.role = "Archer";
        player.health = player.maxHealth = 90;
        player.attack = 17; player.defense = 8;
    }

    player.potions = 5;
    player.level = 1;
    player.exp = 0;
    player.gold = 50;
    player.hasSword = false;

    return player;
}

void showStatus(const Character& player) {
    printMessage("\n=== PLAYER STATUS ===", "cyan");
    cout << "Name: " << player.name << " (" << player.role << ")\n";
    cout << "HP: " << player.health << "/" << player.maxHealth << "\n";
    cout << "Attack: " << player.attack << " | Defense: " << player.defense << "\n";
    cout << "Potions: " << player.potions << " | Gold: " << player.gold << "\n";
    cout << "Level: " << player.level << " | EXP: " << player.exp << "/50\n";
    cout << "Has Sword: " << (player.hasSword ? "Yes" : "No") << endl;
}

void levelUp(Character& player) {
    player.level++;
    player.exp = 0;
    player.maxHealth += 10;
    player.health = player.maxHealth;
    player.attack += 3;
    player.defense += 2;
    printMessage("LEVEL UP! Your stats have improved!", "cyan");
}

void battle(Character& player, Enemy enemy) {
    printMessage("A wild " + enemy.name + " appears!", "red");

    while (player.health > 0 && enemy.health > 0) {
        printMessage("\n1. Attack  2. Use Potion", "yellow");
        int choice;
        cin >> choice;

        if (choice == 1) {
            int damage = max(0, (player.attack - enemy.defense) + (rand() % 7 - 3));
            printMessage("You hit the " + enemy.name + " for " + to_string(damage) + " damage!", "green");
            enemy.health -= damage;

            if (enemy.health <= 0) {
                printMessage("You defeated the " + enemy.name + "!", "green");
                player.exp += 20; player.gold += 20;

                if (enemy.name == "Goblin" && !player.hasSword) {
                    printMessage("The goblin dropped a sword! You take it.", "yellow");
                    player.hasSword = true;
                }

                if (player.exp >= 50) levelUp(player);
                return;
            }
        }
        else if (choice == 2) {
            if (player.potions > 0) {
                player.potions--;
                player.health = min(player.maxHealth, player.health + 20);
                printMessage("You used a potion! (+20 HP)", "yellow");
            }
            else {
                printMessage("You have no potions left!", "red");
                continue;
            }
        }
        else {
            printMessage("Invalid choice! Try again.", "red");
            continue;
        }

        int enemyDamage = max(0, (enemy.attack - player.defense) + (rand() % 7 - 3));
        if (rand() % 5 == 0) {
            enemyDamage *= 2;
            printMessage(enemy.name + " lands a CRITICAL HIT!", "red");
        }

        printMessage(enemy.name + " hits you for " + to_string(enemyDamage) + " damage!", "red");
        player.health -= enemyDamage;

        if (player.health <= 0) printMessage("You have been defeated...", "red");
    }
}

void forest(Character& player) {
    printMessage("\nYou venture into the forest...", "cyan");
    if (rand() % 2 == 0) {
        Enemy goblin = { "Goblin", 35, 12, 3 };
        battle(player, goblin);
    }
    else {
        printMessage("The forest is eerily quiet... Nothing happens.", "yellow");
    }
}

void dungeon(Character& player) {
    if (!player.hasSword) {
        printMessage("You feel unprepared. Maybe explore the forest first!", "red");
        return;
    }

    printMessage("\nYou descend into the dark dungeon...", "cyan");
    Enemy darkLord = { "Dark Lord", 120, 25, 7 };
    battle(player, darkLord);

    if (player.health > 0) printMessage("You vanquished the Dark Lord! Peace returns to the land.", "green");
}

int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed randomness

    Character player = createCharacter();

    while (player.health > 0) {
        printMessage("\nWhat do you want to do?", "yellow");
        printMessage("1. Explore the forest");
        printMessage("2. Enter the dungeon");
        printMessage("3. Show status");
        printMessage("4. Exit game");

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: forest(player); break;
        case 2: dungeon(player); break;
        case 3: showStatus(player); break;
        case 4: printMessage("Thanks for playing!", "cyan"); return 0;
        default: printMessage("Invalid choice! Try again.", "red");
        }
    }

    printMessage("Game over. Better luck next time!", "red");
    return 0;
}
