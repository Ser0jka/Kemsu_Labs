#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// Аналог _kbhit() для macOS/Linux
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

// Аналог _getch()
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int main() {
    std::cout << "Нажмите клавишу (Q для выхода):\n";
    
    while (true) {
        if (kbhit()) {
            char key = getch();
            
            if (key == 'q' || key == 'Q') break;
            
            std::cout << "Нажато: " << key 
                      << " (код: " << (int)key << ")\n";
        }
        // Небольшая пауза, чтобы не нагружать процессор на 100%
        usleep(10000); 
    }
    return 0;
}
