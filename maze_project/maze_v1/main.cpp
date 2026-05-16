#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    string map[] = {
        "##########",
        "#P   #   #",
        "# ## # # #",
        "#    # # #",
        "####   #E#",
        "##########"
    };

    int height = 6;
    int playerX = 1;
    int playerY = 1;

    while (true) {
        system("cls");

        for (int y = 0; y < height; y++) {
            cout << map[y] << endl;
        }

        cout << endl;
        cout << "WASD - move, Q - exit" << endl;

        char key = _getch();

        if (key == 'q' || key == 'Q') {
            break;
        }

        int newX = playerX;
        int newY = playerY;

        if (key == 'w' || key == 'W') newY--;
        if (key == 's' || key == 'S') newY++;
        if (key == 'a' || key == 'A') newX--;
        if (key == 'd' || key == 'D') newX++;

        if (map[newY][newX] == '#') {
            continue;
        }

        if (map[newY][newX] == 'E') {
            system("cls");
            cout << "Ty proshel labirint!" << endl;
            break;
        }

        map[playerY][playerX] = ' ';
        playerX = newX;
        playerY = newY;
        map[playerY][playerX] = 'P';
    }

    return 0;
}
