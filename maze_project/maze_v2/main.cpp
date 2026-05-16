#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    string map[] = {
        "####################",
        "#P     #          ##",
        "# ### ### #######  #",
        "#   #     #     #  #",
        "### ##### # ### # ##",
        "#     #   # #   #  #",
        "# ### # ### # #### #",
        "# #   #     #      #",
        "# # ######### ######",
        "# #        #       #",
        "# ######## # ##### #",
        "#          #     #E#",
        "####################"
    };

    int height = 13;
    int playerX = 1;
    int playerY = 1;
    bool needDraw = true;

    while (true) {
        if (needDraw) {
            system("cls");

            for (int y = 0; y < height; y++) {
                for (int x = 0; x < map[y].size(); x++) {
                    if (map[y][x] == '#') cout << "\033[44m  \033[0m";
                    if (map[y][x] == ' ') cout << "\033[40m  \033[0m";
                    if (map[y][x] == 'P') cout << "\033[42mP \033[0m";
                    if (map[y][x] == 'E') cout << "\033[43mE \033[0m";
                }
                cout << endl;
            }

            cout << endl;
            cout << "\033[36mWASD\033[0m - move, ";
            cout << "\033[31mQ\033[0m - exit" << endl;
            needDraw = false;
        }

        char key = _getch();

        if (key == 'q' || key == 'Q') {
            break;
        }

        int newX = playerX;
        int newY = playerY;

        if ((key == 'w' || key == 'W') && map[newY - 1][newX] != '#') newY--;
        if ((key == 's' || key == 'S') && map[newY + 1][newX] != '#') newY++;
        if ((key == 'a' || key == 'A') && map[newY][newX - 1] != '#') newX--;
        if ((key == 'd' || key == 'D') && map[newY][newX + 1] != '#') newX++;

        if (newX == playerX && newY == playerY) {
            continue;
        }

        if (map[newY][newX] == 'E') {
            system("cls");
            cout << "\033[32mTy proshel labirint!\033[0m" << endl;
            break;
        }

        map[playerY][playerX] = ' ';
        playerX = newX;
        playerY = newY;
        map[playerY][playerX] = 'P';
        needDraw = true;
    }

    return 0;
}
