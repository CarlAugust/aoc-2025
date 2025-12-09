#include <math.h>
#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>

typedef uint64_t u64;
typedef struct {
    long x;
    long y;
} v2;

using namespace std;
int main() {
    vector<v2> vs;
    v2 v;
    long m = -1;
    while (scanf("%li,%li\n", &v.x, &v.y) == 2) {
        for (auto u : vs) {
            m = max((abs(u.x - v.x) + 1) * (abs(u.y - v.y) + 1), m);
        } 
        vs.push_back(v);
    }

    printf("%li\n", m);
}