#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int main() {
    int height = 13;
    int width = 21;
    string map[13];
    int playerX = 1;
    int playerY = 1;
    int exitX = width - 2;
    int exitY = height - 2;
    bool needDraw = true;

    srand(time(0));

    for (int y = 0; y < height; y++) {
        map[y] = "";
        for (int x = 0; x < width; x++) {
            map[y] += '#';
        }
    }

    int pathX = playerX;
    int pathY = playerY;
    map[pathY][pathX] = ' ';

    while (pathX != exitX || pathY != exitY) {
        if (pathX < exitX && rand() % 2 == 0) pathX++;
        else if (pathY < exitY) pathY++;
        else if (pathX < exitX) pathX++;

        map[pathY][pathX] = ' ';
    }

    for (int i = 0; i < 55; i++) {
        int x = 1 + rand() % (width - 2);
        int y = 1 + rand() % (height - 2);
        map[y][x] = ' ';
    }

    map[playerY][playerX] = 'P';
    map[exitY][exitX] = 'E';

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
