#include "headers.hpp"

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void generateMaze(string map[HEIGHT]) {
    int playerX = 1;
    int playerY = 1;
    int exitX = WIDTH - 2;
    int exitY = HEIGHT - 2;

    for (int y = 0; y < HEIGHT; y++) {
        map[y] = "";
        for (int x = 0; x < WIDTH; x++) {
            map[y] += '#';
        }
    }

    int stackX[HEIGHT * WIDTH];
    int stackY[HEIGHT * WIDTH];
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

            if (newX > 0 && newX < WIDTH - 1 && newY > 0 && newY < HEIGHT - 1 && map[newY][newX] == '#') {
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
}

void drawMap(string map[HEIGHT], int steps, time_t startTime) {
    system("cls");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < map[y].size(); x++) {
            if (map[y][x] == '#') {
                cout << "\033[44m  \033[0m";
            }
            if (map[y][x] == ' ') {
                cout << "\033[40m  \033[0m";
            }
            if (map[y][x] == 'P') {
                cout << "\033[42mP \033[0m";
            }
            if (map[y][x] == 'E') {
                cout << "\033[43mE \033[0m";
            }
        }
        cout << endl;
    }

    cout << endl;
    cout << "\033[36mWASD\033[0m - move, ";
    cout << "\033[31mQ\033[0m - exit" << endl;
    cout << "Steps: " << steps << endl;
    cout << "Time: " << difftime(time(0), startTime) << " sec" << endl;
}

int findMinPath(string map[HEIGHT], int startX, int startY, int exitX, int exitY) {
    int dist[HEIGHT][WIDTH];
    int queueX[HEIGHT * WIDTH];
    int queueY[HEIGHT * WIDTH];
    int first = 0;
    int last = 1;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            dist[y][x] = -1;
        }
    }

    queueX[0] = startX;
    queueY[0] = startY;
    dist[startY][startX] = 0;

    while (first < last) {
        int x = queueX[first];
        int y = queueY[first];
        first++;

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) {
                if (map[newY][newX] != '#' && dist[newY][newX] == -1) {
                    dist[newY][newX] = dist[y][x] + 1;
                    queueX[last] = newX;
                    queueY[last] = newY;
                    last++;
                }
            }
        }
    }

    return dist[exitY][exitX];
}

void playGame(string map[HEIGHT]) {
    int playerX = 1;
    int playerY = 1;
    int exitX = WIDTH - 2;
    int exitY = HEIGHT - 2;
    int steps = 0;
    int minPath = findMinPath(map, playerX, playerY, exitX, exitY);
    bool needDraw = true;
    time_t startTime = time(0);

    while (true) {
        if (needDraw) {
            drawMap(map, steps, startTime);
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

        if (map[newY][newX] == '#') {
            continue;
        }

        if (map[newY][newX] == 'E') {
            steps++;
            double seconds = difftime(time(0), startTime);
            if (seconds < 1) {
                seconds = 1;
            }

            double score = 1000.0 / ((double(steps) / minPath) * seconds);

            system("cls");
            cout << "\033[32mTy proshel labirint!\033[0m" << endl;
            cout << "Time: " << seconds << " sec" << endl;
            cout << "Steps: " << steps << endl;
            cout << "Minimal path: " << minPath << endl;
            cout << fixed << setprecision(2);
            cout << "Score: " << score << endl;
            cout << "\nNazhmite lubuyu klavishu dlya vyhoda...";
            _getch();
            break;
        }

        map[playerY][playerX] = ' ';
        playerX = newX;
        playerY = newY;
        map[playerY][playerX] = 'P';
        steps++;
        needDraw = true;
    }
}
