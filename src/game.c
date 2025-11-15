#include <stdio.h>
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
int _getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}
#endif
#include "game.h"

char map[10][21] = {
    "####################",
    "#..................#",
    "#..................#",
    "#..................#",
    "#..................#",
    "#..................#",
    "#..................#",
    "#..................#",
    "#..................#",
    "####################"
};

void drawMap(int x, int y) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == y && j == x) printf("@");
            else printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("\nUse W A S D to move, Q to quit.\n");
}

void gameLoop() {
    int x = 5, y = 5;
    drawMap(x, y);
    while (1) {
        char c = _getch();
        if (c == 'q' || c == 'Q') break;
        if ((c == 'w' || c == 'W') && map[y-1][x] != '#') y--;
        if ((c == 's' || c == 'S') && map[y+1][x] != '#') y++;
        if ((c == 'a' || c == 'A') && map[y][x-1] != '#') x--;
        if ((c == 'd' || c == 'D') && map[y][x+1] != '#') x++;
        drawMap(x, y);
    }
}

