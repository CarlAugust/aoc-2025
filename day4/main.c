#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Hardcoded sizes for easy
#define W 136
#define H 136

bool boundCheck(int y, int x, int w, int h) {
    if (y < 0 || y > h - 1) return false;
    if (x < 0 || x > w - 1) return false;
    return true;
}

int main(void) {
    int count = 0;
    int access[H][W] = {0};
    char map[H][W + 1]; // + 1 for null

    for (int i = 0; i < H; i++) {
        scanf("%s\n", map[i]);
    }

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (map[y][x] != '@') continue;
            int rolls = -1;
            // i for y and j for x
            for (int i = y - 1; i < y + 2; i++) {
                for (int j = x - 1; j < x + 2; j++) {
                    if (!boundCheck(i, j, W, H)) continue;
                    if (map[i][j] == '@') rolls++;
                }
            }

            if (rolls < 4) {
                count++; 
            }
        }
    }
    printf("Count: %i\n", count);
    return 0;

}