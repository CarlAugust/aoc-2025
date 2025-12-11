#include <math.h>
#include <stdio.h>
#include <vector>
#include <assert.h>
#include <stdint.h>
#include <algorithm>

typedef uint64_t u64;
typedef struct {
    long x;
    long y;
} v2;


/*

    I: No other point is inside of the area
    II: All corners are valid
    
    I:  X## ##X Here the top most left corner with the right bottom would not be valid 
        X#X#X#X

    I:  X##X Here the top most left corner with the right bottom would not be valid
        ###X
        X##X
           X

    

*/

bool InsideTwoPointRectangle(v2 v01, v2 v02, v2 u) {
    // which points is first?

    long maxx = v01.x > v02.x ? v01.x : v02.x;
    long maxy = v01.y > v02.y ? v01.y : v02.y;
    long minx = v01.x < v02.x ? v01.x : v02.x;
    long miny = v01.y < v02.y ? v01.y : v02.y;

    return u.x > minx && u.x < maxx && u.y > miny && u.y < maxy;
}

long Area(v2 u, v2 v) {
    return (abs(u.x - v.x) + 1) * (abs(u.y - v.y) + 1);
}

void printv2(v2 v) {
    printf("x: %li, y: %li\n", v.x, v.y);
}

using namespace std;
int main() {
    vector<v2> v;
    v2 v1;

    v2 v2; // For vertical or horizontal proof
    bool step = false;
    while (scanf("%li,%li\n", &v1.x, &v1.y) == 2) {

        // Proving that next points is always horizontal or vertical thus we can use inside rectangle algorithm
        if (step) assert(v1.x == v2.x || v2.y == v2.y);
        step = true;
        v2 = v1;
        // --------- >

        v.push_back(v1);
    }

    long m = -1;
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {

            bool valid = true;

            for (int k = 0; k < v.size(); k++) {
                if (InsideTwoPointRectangle(v[i], v[j], v[k])) {
                    valid = false;
                    break;
                }

            }
            if (valid) {
                m = max(Area(v[i], v[j]), m);
                printf("%li\n", m);
                printv2(v[i]);
                printv2(v[j]);
                printf("\n");
            }
        }
    }

    printf("Max: %li\n", m);

    return 0;
}