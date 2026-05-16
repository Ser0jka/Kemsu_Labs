#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int main() {
    const int height = 21;
    const int width = 31;
    string map[height];
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

    int stackX[height * width];
    int stackY[height * width];
    int stackSize = 1;

    stackX[0] = playerX;
    stackY[0] = playerY;
    map[playerY][playerX] = ' ';

    while (stackSize > 0) {
        int x = stackX[stackSize - 1];
        int y = stackY[stackSize - 1];
        int dirs[] = {0, 1, 2, 3};
        bool moved = false;

        for (int i = 0; i < 4; i++) {
            int r = rand() % 4;
            int temp = dirs[i];
            dirs[i] = dirs[r];
            dirs[r] = temp;
        }

        for (int i = 0; i < 4; i++) {
            int dx = 0;
            int dy = 0;

            if (dirs[i] == 0) dy = -1;
            if (dirs[i] == 1) dy = 1;
            if (dirs[i] == 2) dx = -1;
            if (dirs[i] == 3) dx = 1;

            int newX = x + dx * 2;
            int newY = y + dy * 2;

            if (newX > 0 && newX < width - 1 && newY > 0 && newY < height - 1 && map[newY][newX] == '#') {
                map[y + dy][x + dx] = ' ';
                map[newY][newX] = ' ';

                stackX[stackSize] = newX;
                stackY[stackSize] = newY;
                stackSize++;
                moved = true;
                break;
            }
        }

        if (!moved) {
            stackSize--;
        }
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
            cout << "\033[36mWASD\033[0m - dvizhenie, ";
            cout << "\033[31mQ\033[0m - vyhod" << endl;
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
