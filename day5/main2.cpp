#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

// Brute force is acceptable, n < 200 and m = 4000
typedef unsigned long long int llu;

typedef struct {
    llu a;
    llu b;
    bool active;
} range;

bool comp(range a, range b) {
    return a.a < b.a;
}

int main(void) {

    int rcount = 0;
    range ranges[500] = {0};

    while (scanf("%llu-%llu", &ranges[rcount].a, &ranges[rcount].b) == 2) {
        ranges[rcount].active = true;
        rcount++;
    };

    std::sort(ranges, ranges+rcount, comp);

    for (int i = 0; i < rcount - 1; i++) {

        if (ranges[i].b >= ranges[i + 1].a) {
            ranges[i].active = false;
            ranges[i + 1].b = std::max(ranges[i].b, ranges[i + 1].b);
            ranges[i + 1].a = ranges[i].a;
        }
    }

    llu validIds = 0;
    for (int i = 0; i < rcount; i++) {
        if (ranges[i].active) { 
            validIds += ranges[i].b - ranges[i].a + 1;
        }
    }

    printf("There are %llu validIds\n", validIds);
}