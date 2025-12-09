#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

/*
    Basic idea:
        have an array of all current beams, and if next layer containts a splitter current beam stops and both adjecent gets a beam
        edge cases:
        neigbouring splitters, simply check if the splitter has a neighbouring splitter and dont create a beam there, THOUGH I ASSUME THIS IS NEVER THE CASE
        double beam, double beams can simply be ignored as overwriting | with | has no effect.

*/

typedef size_t u64;

int main(void) {
    char buffer[256];    

    if (!fgets(buffer, 256, stdin)) return 1;
    
    u64 len = strlen(buffer);
    bool beam[len];
    memset(beam, false, len);


    for (int i = 0; i < len; i++) {
        if (buffer[i] == 'S') beam[i] = true;
    }

    u64 sum = 0;
    while (fgets(buffer, 256, stdin)) {
        printf("%s\n", buffer);
        printf("strlen(buffer)=%zu, len=%zu\n", strlen(buffer), len);
        assert(strlen(buffer) == len);

        for (int i = 0; i < len; i++) {
            if (buffer[i] == '^' && beam[i]) {
                sum++;
                beam[i] = false;
                if (i > 0) beam[i - 1] = true;
                if (i < len - 1) beam[i + 1] = true;
            }
        }
    }

    
    printf("Splits %lu\n", sum);

    return 0;
}