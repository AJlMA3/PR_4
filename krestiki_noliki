#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void printField(const vector<char>& field) {
    system("cls"); 
    cout << " " << field[0] << " | " << field[1] << " | " << field[2] << "\n";
    cout << "---+---+---\n";
    cout << " " << field[3] << " | " << field[4] << " | " << field[5] << "\n";
    cout << "---+---+---\n";
    cout << " " << field[6] << " | " << field[7] << " | " << field[8] << "\n";
}

bool checkWin(const vector<char>& field, char player) {
    const int winCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}             
    };
    
    for (auto& combo : winCombos) {
        if (field[combo[0]] == player && field[combo[1]] == player && field[combo[2]] == player) {
            return true;
        }
    }
    return false;
}

// Функция для обработки ввода игрока
int getPlayerMove(const vector<char>& field) {
    int move;
    while (true) {
        cout << "Введите номер клетки (1-9): ";
        cin >> move;
        
        if (cin.fail() || move < 1 || move > 9 || field[move - 1] == 'X' || field[move - 1] == 'O') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Попробуйте снова.\n";
        } else {
            break;
        }
    }
    return move - 1;
}

// Основной игровой цикл
void playGame() {
    vector<char> field = {'1','2','3','4','5','6','7','8','9'};
    char currentPlayer = 'X';
    int moveCount = 0;
    
    while (true) {
        printField(field);
        cout << "Ход игрока " << currentPlayer << "\n";
        
        int move = getPlayerMove(field);
        field[move] = currentPlayer;
        moveCount++;
        
        if (checkWin(field, currentPlayer)) {
            printField(field);
            cout << "Игрок " << currentPlayer << " победил!\n";
            break;
        }
        
        if (moveCount == 9) {
            printField(field);
            cout << "Ничья!\n";
            break;
        }
        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Хотите сыграть ещё раз? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
    
    cout << "Спасибо за игру!\n";
    return 0;
}
