#ifndef HEADERS_HPP
#define HEADERS_HPP

#include <string>
#include <ctime>

using namespace std;

const int HEIGHT = 21;
const int WIDTH = 31;

void generateMaze(string map[HEIGHT]);
void drawMap(string map[HEIGHT], int steps, time_t startTime);
int findMinPath(string map[HEIGHT], int startX, int startY, int exitX, int exitY);
void playGame(string map[HEIGHT]);

#endif
