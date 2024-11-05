#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>

void drawGrid(int grid[7][6]);
bool playTurn(int grid[7][6], int column, int player);
void ia(int grille[7][6]);

int main(int argc, char** argv) {
    int score1 = 0, score2 = 0;
    int grille[7][6] = {};
    std::string choix;

    int player = 1;
    drawGrid(grille);

    int type;
    std::cout << "Bienvenu dans P4 affichage console " << std::endl;
    std::cout << "Entrer:\n 1-player_1 vs player_2\n 2-player_1 vs CPU\nReponse: ";
    std::cin >> type;
    if (type == 1) {
        while (true) {
            std::cout << "player_" << player << " -> col :";
            std::cin >> choix;

            if (choix == "exit") {
                break;
            }

            bool success = false;

            if (choix.size() == 1) {
                if (choix[0] >= '0' && choix[0] <= '7') {
                    int col = choix[0] - '0';

                    success = playTurn(grille, col, player);
                }
            }

            system("CLS");

            if (!success) {
                std::cout << "votre choix est incorrect\n";
                std::cout << "Taper <exit> si vous voullez quitter puis recommencer" << std::endl;
            }
            else {
                if (player == 1) player = 2;
                else player = 1;
            }
            drawGrid(grille);
            for (int i = 6; i >= 0; i--) {
                for (int j = 5; j >= 0; j--) {
                    if (grille[i][j] == 1 && grille[i + 1][j] == 1 && grille[i + 2][j] == 1 && grille[i + 3][j] == 1) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is player_1\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 2 && grille[i + 1][j] == 2 && grille[i + 2][j] == 2 && grille[i + 3][j] == 2) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is Player_2\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 1 && grille[i][j + 1] == 1 && grille[i][j + 2] == 1 && grille[i][j + 3] == 1) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is player_1\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 2 && grille[i][j + 1] == 2 && grille[i][j + 2] == 2 && grille[i][j + 3] == 2) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is Player_2\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 1 && grille[i - 1][j + 1] == 1 && grille[i - 2][j + 2] == 1 && grille[i - 3][j + 3] == 1) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is player_1\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 1 && grille[i - 1][j - 1] == 1 && grille[i - 2][j - 2] == 1 && grille[i - 3][j - 3] == 1) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is player_1\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 2 && grille[i - 1][j + 1] == 2 && grille[i - 2][j + 2] == 2 && grille[i - 3][j + 3] == 2) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is player_2\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 2 && grille[i - 1][j - 1] == 2 && grille[i - 2][j - 2] == 2 && grille[i - 3][j - 3] == 2) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is player_2\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                }
            }
        }
    }
    else if (type == 2) {
        while (true) {
            std::cout << "player_" << player << " -> col :";
            std::cin >> choix;

            if (choix == "exit") {
                break;
            }

            bool success = false;

            if (choix.size() == 1) {
                if (choix[0] >= '0' && choix[0] <= '7') {
                    int col = choix[0] - '0';

                    success = playTurn(grille, col, player);
                }
            }

            system("CLS");

            if (!success) {
                std::cout << "votre choix est incorrect\n";
                std::cout << "Taper <exit> si vous voullez quitter puis recommencer" << std::endl;
            }
            else {
                if (player == 1) ia(grille);
                else player = 1;
            }
            drawGrid(grille);
            for (int i = 6; i >= 0; i--) {
                for (int j = 5; j >= 0; j--) {
                    if (grille[i][j] == 1 && grille[i + 1][j] == 1 && grille[i + 2][j] == 1 && grille[i + 3][j] == 1) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is player_1\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 2 && grille[i + 1][j] == 2 && grille[i + 2][j] == 2 && grille[i + 3][j] == 2) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is CPU\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 1 && grille[i][j + 1] == 1 && grille[i][j + 2] == 1 && grille[i][j + 3] == 1) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is player_1\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 2 && grille[i][j + 1] == 2 && grille[i][j + 2] == 2 && grille[i][j + 3] == 2) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is CPU\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 1 && grille[i - 1][j + 1] == 1 && grille[i - 2][j + 2] == 1 && grille[i - 3][j + 3] == 1) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is player_1\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 1 && grille[i - 1][j - 1] == 1 && grille[i - 2][j - 2] == 1 && grille[i - 3][j - 3] == 1) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is player_1\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 2 && grille[i - 1][j + 1] == 2 && grille[i - 2][j + 2] == 2 && grille[i - 3][j + 3] == 2) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is CPU\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                    if (grille[i][j] == 2 && grille[i - 1][j - 1] == 2 && grille[i - 2][j - 2] == 2 && grille[i - 3][j - 3] == 2) {
                        system("CLS");
                        std::cout << "\n";
                        std::cout << "Winner is CPU\n" << std::endl;
                        std::cout << "Taper <exit> pour sortir\n" << std::endl;
                    }
                }
            }
        }
    }
    return 0;
}


// 0, 1, 2
void drawGrid(int grille[7][6]) {
    for (int ligne = 0; ligne < 6; ligne++) {
        std::cout << "|";
        for (int col = 0; col < 7; col++) {
            if (grille[col][ligne] == 1) {
                std::cout << "\033[31m*\033[37m";
            }
            else
                if (grille[col][ligne] == 2) {
                    std::cout << "\033[32m*\033[37m";
                }
                else {
                    std::cout << "\033[37m*\033[37m";
                }
            std::cout << "|";
        }
        std::cout << "\n";
    }
}

bool playTurn(int grid[7][6], int column, int player) {
    for (int line = 5; line >= 0; line--) {
        if (grid[column - 1][line] == 0) {
            grid[column - 1][line] = player;
            return true;
        }
    }
    return false;
}

void ia(int grille[7][6]) {

    srand(static_cast<unsigned int>(time(0)));

    int random;

    bool success = false;

    while(!success) {
        random = rand() % 9;
        int col = random;
        success = playTurn(grille, col, 2);
    }
}

