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
    u64 beam[len];
    memset(beam, 0, len * sizeof(u64));


    for (int i = 0; i < len; i++) {
        if (buffer[i] == 'S') beam[i]++;
    }
    u64 tsum = 0;

    while (fgets(buffer, 256, stdin)) {
        assert(strlen(buffer) == len);

        for (int i = 0; i < len; i++) {
            if (buffer[i] == '^' && beam[i] != 0) {
                if (i > 0) beam[i - 1] += beam[i];
                if (i < len - 1) beam[i + 1] += beam[i];
                beam[i] = 0;
            }
        }
        tsum = 0;
        for (int i = 0; i < len; i++) {
            printf("%lu ", beam[i]);
            tsum += beam[i];
        } 
        printf("\n");
    }

    u64 sum = 0;
    for (int i = 0; i < len; i++) {
        printf("%lu ", beam[i]);
        sum += beam[i];
    } 
    printf("\n");
    printf("Timelines %lu\n", sum);

    return 0;
}
