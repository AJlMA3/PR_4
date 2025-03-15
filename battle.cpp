#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

struct Character {
    std::string name;
    int health;
    int attack;
    int defense;

    void attackTarget(Character &target) {
    int damage = rand() % 25 + 10; 
    std::cout << name << " атакует " << target.name << " и наносит "
              << damage << " единиц урона!\n";
    target.health -= damage;
    }
};

void printStatus(const Character &hero, const Character &monster) {
    std::cout << "\n--- Статус боя ---\n";
    std::cout << hero.name << " (Здоровье: " << hero.health << ", Защита: " << hero.defense << ")\n";
    std::cout << monster.name << " (Здоровье: " << monster.health << ", Защита: " << monster.defense << ")\n";
    std::cout << "-------------------------\n";
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int getPlayerChoice() {
    int choice;
    while (true) {
        std::cout << "Выберите действие: (1) Атаковать, (2) Пропустить ход: ";
        std::cin >> choice;
        if (std::cin.fail() || (choice != 1 && choice != 2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод! Попробуйте снова.\n";
        } else {
            return choice;
        }
    }
}

int main() {
    std::srand(std::time(nullptr));
    char playAgain;

    do {
        Character hero = {"Герой", 100, 15 + std::rand() % 10, 5};
        Character monster = {"Монстр", 80, 10 + std::rand() % 10, 3};

        while (hero.health > 0 && monster.health > 0) {
            clearScreen();
            printStatus(hero, monster);
            
            int choice = getPlayerChoice();
            if (choice == 1) {
                hero.attackTarget(monster);
            }
            
            if (monster.health > 0) {
                monster.attackTarget(hero);
            }
        }

        clearScreen();
        printStatus(hero, monster);

        if (hero.health > 0) {
            std::cout << "Герой победил!\n";
        } else {
            std::cout << "Монстр победил... Попробуйте снова!\n";
        }

        std::cout << "Хотите сыграть ещё раз? (Y/N): ";
        std::cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    std::cout << "Спасибо за игру!\n";
    return 0;
}
