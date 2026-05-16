#include "headers.hpp"

#include <cstdlib>
#include <ctime>

int main() {
    string map[HEIGHT];

    srand(time(0));
    generateMaze(map);
    playGame(map);

    return 0;
}
