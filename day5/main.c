#include <stdio.h>
#include <stdlib.h>

// Brute force is acceptable, n < 200 and m = 4000
typedef unsigned long long int llu;

typedef struct {
    llu a;
    llu b;
} range;

int main(void) {

    int rcount = 0;
    range ranges[500];

    while (scanf("%llu-%llu", &ranges[rcount].a, &ranges[rcount].b) == 2) {
        rcount++;
    };

    llu id;
    int fresh = 0;
    while (scanf("%llu", &id) == 1) {
        for (int i = 0; i < rcount; i++) {
            if (id >= ranges[i].a && id <= ranges[i].b) {
                fresh++;
                break;
            } 
        }
    }
    printf("There are %i fresh materials\n", fresh);
}