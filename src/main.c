#include <stdio.h>
#include "game.h"

int main() {
    printf("=== MiniGameDemo ===\nPress any key to start...\n");
    getchar();
    gameLoop();
    printf("\nGame Over\n");
    return 0;
}

