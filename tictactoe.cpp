#include <iostream>
#include <ctime>

void drawboard(char *spaces);
void playermove(char*spaces, char player, char computer);
void computermove(char *spaces, char computer);
bool checkwinner(char *spaces, char player);
bool checktie(char *spaces);

int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';

    drawboard(spaces);

    while(true) {
        playermove(spaces, player, computer);
        drawboard(spaces);

        if(checkwinner(spaces, player)) {
            break;
        }
        else if(checktie(spaces)) {
            break;
        }

        computermove(spaces, computer);
        drawboard(spaces);

        if(checkwinner(spaces, player)) {
            break;
        }
        else if(checktie(spaces)) {
            break;
        }
    }

    std::cout << "Thanks for playing\n";
}

void drawboard(char *spaces) {
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}
void playermove(char*spaces, char player, char computer) {
    int num;

    do {
        std::cout << "Enter a spot to place marker(1-9): ";
        std::cin >> num;
        num--;
    }while(num <0 || num >8 || spaces[num] == computer);

    spaces[num] = player;
}
void computermove(char *spaces, char computer) {
    int num;
    srand(time(0));

    while(true) {
        num = rand() % 9;
        if(spaces[num] == ' ') {
            spaces[num] = computer;
            break;
        }
    }
}
bool checkwinner(char *spaces, char player) {
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOST!\n";
        return true;
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
        spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOST!\n";
        return true;
    }
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
        spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOST!\n";
        return true;
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOST!\n";
        return true;
    }
    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
        spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOST!\n";
        return true;
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOST!\n";
        return true;
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOST!\n";
        return true;
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOST!\n";
        return true;
    }

    return false;
}
bool checktie(char *spaces) {
    for(int i = 0; i < 9; i++) {
        if(spaces[i] == ' ') {
            return false;
        }
    }

    std::cout << "IT'S A TIE\n";
    return true;
}